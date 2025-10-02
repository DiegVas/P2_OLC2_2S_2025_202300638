#include "semantic.h"
#include "../structures/parser.h"
#include <string.h>

symbol *evaluate_expression(Expression *expr, Context *context)
{
    // Verificar que expr no sea NULL
    if (!expr || !context)
    {
        symbol *error_result = (symbol *)calloc(1, sizeof(symbol));
        error_result->value = strdup("NULL expression or context");
        error_result->dataType = strdup("UNDEFINED");
        error_result->type = strdup("ERROR");
        error_result->environment = strdup("ERROR");
        error_result->id = strdup("ERROR");
        return error_result;
    }

    ExpressionType type = get_expression_type(expr->type);

    extern symbol_table *SymbolTable_General;

    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    // Inicializar siempre los campos básicos para evitar punteros corruptos
    result->value = strdup("UNDEFINED");
    result->dataType = strdup("UNDEFINED");
    result->type = strdup("UNDEFINED");
    result->environment = strdup("UNDEFINED");
    result->id = strdup("UNDEFINED");

    Expression *exprIZQ = expr->left;
    Expression *exprDER = expr->right;

    switch (type)
    {
    case EXP_INTEGER:
        free(result->value);
        free(result->dataType);
        result->value = strcmp(expr->value, "UNDEFINED") == 0 ? strdup("0") : strdup(expr->value);
        result->dataType = strdup("INTEGER");
        break;
    case EXP_FLOAT:
        result->value = strcmp(expr->value, "UNDEFINED") == 0 ? strdup("0.0") : strdup(expr->value);
        result->dataType = strdup("FLOAT");
        break;
    case EXP_STRING:
        result->value = strcmp(expr->value, "UNDEFINED") == 0 ? strdup("NULL") : strdup(expr->value);
        result->dataType = strdup("STRING");
        break;
    case EXP_BOOLEAN:
        result->value = strcmp(expr->value, "UNDEFINED") == 0 ? strdup("false") : strdup(expr->value);
        result->dataType = strdup("BOOLEAN");
        break;
    case EXP_CHARACTER:
    {
        if (strcmp(expr->value, "UNDEFINED") == 0)
        {
            result->value = strdup("'\0'");
        }
        else
        {
            // Procesar secuencias de escape Unicode y caracteres especiales
            char *formatted_char = (char *)calloc(16, sizeof(char));
            const char *input = expr->value;

            if (strncmp(input, "\\u", 2) == 0 && strlen(input) >= 6)
            {
                // Procesar secuencias Unicode como \u0082 o \u00164
                char hex_str[9] = {0};
                int hex_len = 0;

                // Extraer todos los dígitos hexadecimales después de \u
                for (int i = 2; i < strlen(input) && hex_len < 8; i++)
                {
                    char c = input[i];
                    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
                    {
                        hex_str[hex_len++] = c;
                    }
                    else
                    {
                        break;
                    }
                }
                hex_str[hex_len] = '\0';

                unsigned int unicode_val;
                if (sscanf(hex_str, "%x", &unicode_val) == 1)
                {
                    // Convertir directamente el valor Unicode a su carácter ASCII correspondiente
                    if (unicode_val <= 127)
                    {
                        // Carácter ASCII válido
                        sprintf(formatted_char, "'%c'", (char)unicode_val);
                    }
                    else
                    {
                        // Para valores fuera del rango ASCII, mantener como carácter si es imprimible
                        sprintf(formatted_char, "'%c'", (char)unicode_val);
                    }
                }
                else
                {
                    // Error en formato, usar valor original
                    formatted_char = strdup(input);
                }
            }
            else if (strncmp(input, "\\", 1) == 0 && strlen(input) >= 2)
            {
                // Otras secuencias de escape (\n, \t, \r, \\, \', etc.)
                char escape_char = input[1];
                switch (escape_char)
                {
                case 'n':
                    sprintf(formatted_char, "'\\n'");
                    break;
                case 't':
                    sprintf(formatted_char, "'\\t'");
                    break;
                case 'r':
                    sprintf(formatted_char, "'\\r'");
                    break;
                case '\\':
                    sprintf(formatted_char, "'\\\\'");
                    break;
                case '\'':
                    sprintf(formatted_char, "'\\''");
                    break;
                case '\"':
                    sprintf(formatted_char, "'\\\"'");
                    break;
                case '0':
                    sprintf(formatted_char, "'\\0'");
                    break;
                default:
                    // Secuencia desconocida, mantener original
                    formatted_char = strdup(input);
                    break;
                }
            }
            else
            {
                // Caracter normal, asegurar formato con comillas simples
                if (input[0] == '\'' && input[strlen(input) - 1] == '\'')
                {
                    formatted_char = strdup(input);
                }
                else
                {
                    sprintf(formatted_char, "'%s'", input);
                }
            }

            result->value = formatted_char;
        }
        result->dataType = "CHARACTER";
        break;
    }
    case EXP_DOUBLE:
        result->value = strcmp(expr->value, "UNDEFINED") == 0 ? strdup("0.0") : strdup(expr->value);
        result->dataType = "DOUBLE";
        break;
    case EXP_NULL:
        result->value = strdup("NULL");
        result->dataType = "NULL";
        break;
    case EXP_SUM:
        return perform_arithmetic_operation(exprIZQ, exprDER, context, '+');
    case EXP_SUBTRACT:
        return perform_arithmetic_operation(exprIZQ, exprDER, context, '-');
    case EXP_MULTIPLICATION:
        return perform_arithmetic_operation(exprIZQ, exprDER, context, '*');
    case EXP_DIVIDE:
        return perform_arithmetic_operation(exprIZQ, exprDER, context, '/');
    case EXP_MODULO:
        return perform_arithmetic_operation(exprIZQ, exprDER, context, '%');
    case EXP_NEGATIVE:
    {
        symbol *right = evaluate_expression(expr->left, context);
        ConvertedValue cv_right = convert_operand(right);

        if (cv_right.result_type != TYPE_INTEGER && cv_right.result_type != TYPE_FLOAT && cv_right.result_type != TYPE_DOUBLE)
        {
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Negative operation does not support non-numeric types");
            fprintf(stderr, "Negative operation does not support non-numeric types\n");
            fprintf(stderr, "Right type: %s\n", right->dataType);
            return result;
        }

        result->dataType = right->dataType;
        if (cv_right.result_type == TYPE_INTEGER)
        {
            int neg_value = -((int)cv_right.num_value);
            result->value = (char *)calloc(20, sizeof(char));
            sprintf(result->value, "%d", neg_value);
        }
        else
        {
            double neg_value = -cv_right.num_value;
            result->value = (char *)calloc(30, sizeof(char));
            sprintf(result->value, "%.6f", neg_value);
        }
        return result;
    }
    case EXP_CASTING:
        return apply_casting_manual(evaluate_expression(exprIZQ, context), expr->value);
    case EXP_BITWISE_AND:
        return perfom_BITWISE(exprIZQ, exprDER, context, "&");
    case EXP_BITWISE_OR:
        return perfom_BITWISE(exprIZQ, exprDER, context, "|");
    case EXP_BITWISE_XOR:
        return perfom_BITWISE(exprIZQ, exprDER, context, "^");
    case EXP_BITWISE_LEFT_SHIFT:
        return perfom_BITWISE(exprIZQ, exprDER, context, "<<");
    case EXP_BITWISE_RIGHT_SHIFT:
        return perfom_BITWISE(exprIZQ, exprDER, context, ">>");
    case EXP_EQUALS_OP:
        return perform_comparative_operation(exprIZQ, exprDER, context, ".equals");
    case EXP_EQUALS:
        return perform_comparative_operation(exprIZQ, exprDER, context, "==");
    case EXP_NOT_EQUALS:
        return perform_comparative_operation(exprIZQ, exprDER, context, "!=");
    case EXP_LOGICAL_AND:
        return perform_comparative_operation(exprIZQ, exprDER, context, "&&");
    case EXP_LOGICAL_OR:
        return perform_comparative_operation(exprIZQ, exprDER, context, "||");
    case EXP_LOGICAL_NOT:
    {
        symbol *left = evaluate_expression(expr->left, context);

        if (left == NULL || strcmp(left->dataType, "BOOLEAN") != 0)
        {
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Logical NOT operation requires a BOOLEAN type");
            fprintf(stderr, "Logical NOT operation requires a BOOLEAN type\n");
            fprintf(stderr, "left type: %s\n", left->dataType);
            return result;
        }

        bool cv_left = boolean_value(left->value);
        result->dataType = "BOOLEAN";
        result->value = (cv_left == true) ? strdup("false") : strdup("true");
        return result;
    }
    case EXP_LESS:
        return perform_comparative_operation(exprIZQ, exprDER, context, "<");
    case EXP_GREATER:
        return perform_comparative_operation(exprIZQ, exprDER, context, ">");
    case EXP_LESS_EQUALS:
        return perform_comparative_operation(exprIZQ, exprDER, context, "<=");
    case EXP_GREATER_EQUALS:
        return perform_comparative_operation(exprIZQ, exprDER, context, ">=");
    case EXP_PARSEINT:
    {
        symbol *to_parse = evaluate_expression(expr->left, context);
        if (to_parse == NULL || strcmp(to_parse->dataType, "STRING") != 0)
        {
            result->dataType = "UNDEFINED";
            result->value = "PARSEINT operation requires a STRING type";
            return result;
        }

        char *endptr;
        long parsed_value = strtol(to_parse->value, &endptr, 10);

        if (*endptr != '\0')
        {
            result->dataType = "UNDEFINED";
            result->value = "PARSEINT operation failed: invalid integer format";
            return result;
        }

        result->dataType = "INTEGER";
        result->value = (char *)calloc(20, sizeof(char));
        sprintf(result->value, "%ld", parsed_value);
        return result;

        break;
    }
    case EXP_PARSEDOUBLE:
    {
        symbol *to_parse = evaluate_expression(expr->left, context);
        if (to_parse == NULL || strcmp(to_parse->dataType, "STRING") != 0)
        {
            result->dataType = "UNDEFINED";
            result->value = "PARSEDOUBLE operation requires a STRING type";
            return result;
        }

        char *endptr;
        double parsed_value = strtod(to_parse->value, &endptr);

        if (*endptr != '\0')
        {
            result->dataType = "UNDEFINED";
            result->value = "PARSEDOUBLE operation failed: invalid double format";
            return result;
        }

        result->dataType = "DOUBLE";
        result->value = (char *)calloc(30, sizeof(char));
        sprintf(result->value, "%.6f", parsed_value);
        return result;

        break;
    }
    case EXP_PARSEFLOAT:
    {
        symbol *to_parse = evaluate_expression(expr->left, context);
        if (to_parse == NULL || strcmp(to_parse->dataType, "STRING") != 0)
        {
            result->dataType = "UNDEFINED";
            result->value = "PARSEFLOAT operation requires a STRING type";
            return result;
        }
        char *endptr;
        float parsed_value = strtof(to_parse->value, &endptr);
        if (*endptr != '\0')
        {
            result->dataType = "UNDEFINED";
            result->value = "PARSEFLOAT operation failed: invalid float format";
            return result;
        }
        result->dataType = "FLOAT";
        result->value = (char *)calloc(30, sizeof(char));
        sprintf(result->value, "%.6f", parsed_value);
        return result;
        break;
    }
    case EXP_VALUEOF:
    {
        symbol *to_convert = evaluate_expression(expr->left, context);
        result->dataType = "STRING";
        result->value = (char *)calloc(2 * strlen(to_convert->value) + 3, sizeof(char)); // Extra space for quotes and null terminator
        sprintf(result->value, "\"%s\"", to_convert->value);
        return result;
        break;
    }
    case EXP_JOIN:
    {
        symbol *to_join = evaluate_expression(expr->list->head->expr, context);

        char *joined_str = (char *)calloc(1, sizeof(char));
        joined_str[0] = '\0';
        ExpressionNode *current = expr->list->head->next;
        while (current)
        {
            symbol *elem = evaluate_expression(current->expr, context);
            if (strcmp(elem->dataType, "STRING") != 0)
            {
                result->dataType = "UNDEFINED";
                result->value = "JOIN operation requires all elements to be of type STRING";
                free(joined_str);
                return result;
            }
            if (joined_str[0] != '\0')
            {
                joined_str = (char *)realloc(joined_str, strlen(joined_str) + strlen(to_join->value) + 1);
                strcat(joined_str, to_join->value);
            }
            joined_str = (char *)realloc(joined_str, strlen(joined_str) + strlen(elem->value) + 1);
            strcat(joined_str, elem->value);
            current = current->next;
        }

        result->dataType = "STRING";
        result->value = joined_str;
        return result;
        break;
    }
    case EXP_INDEXOF:
    {

        Context *ctx_search = context;

        while (ctx_search)
        {
            if (SearchID(ctx_search->symbols_context, expr->value))
            {
                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);

                if (strcmp(sym->type, "VECTOR") == 0 && sym->vectorValues)
                {
                    symbol *to_find = evaluate_expression(expr->left, context);
                    int index = 0;
                    VectorNode *current = sym->vectorValues->head;
                    while (current)
                    {
                        if (strcmp(current->value->value, to_find->value) == 0 && strcmp(current->value->dataType, to_find->dataType) == 0)
                        {
                            result->dataType = "INTEGER";
                            result->value = (char *)calloc(20, sizeof(char));
                            sprintf(result->value, "%d", index);
                            return result;
                        }
                        index++;
                        current = current->next;
                    }
                    // Not found
                    result->dataType = "INTEGER";
                    result->value = (char *)calloc(20, sizeof(char));
                    sprintf(result->value, "-1");
                    return result;
                }

                result->dataType = "UNDEFINED";
                result->value = "INDEXOF operation requires a VECTOR type with values";
                return result;
            }
            ctx_search = ctx_search->after;
        }

        break;
    }
    case EXP_LENGTH:
    {

        Context *ctx_search = context;
        while (ctx_search)
        {
            if (SearchID(ctx_search->symbols_context, expr->value))
            {
                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);

                fprintf(stderr, "Getting length of symbol %s of type %s\n", sym->id, sym->type);
                fprintf(stderr, "Vector values: %p\n", (void *)sym->vectorValues);

                if (strcmp(sym->type, "VECTOR") == 0 && sym->vectorValues)
                    return get_legth_of_vector(sym->vectorValues);
                if (strcmp(sym->type, "MATRIX") == 0 && sym->matrixValues)
                    return get_legth_of_matrix(sym->matrixValues);

                result->dataType = "UNDEFINED";
                result->value = "LENGTH operation requires an ARRAY, VECTOR, or MATRIX type with values";
                return result;
            }
            ctx_search = ctx_search->after;
        }

        break;
    }
    case EXP_ADD:
    {
        Context *ctx_search = context;

        while (ctx_search)
        {

            if (SearchID(ctx_search->symbols_context, expr->value))
            {

                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);

                if (strcmp(sym->type, "VECTOR") == 0 && sym->vectorValues)
                {

                    symbol *to_add = evaluate_expression(expr->left, context);

                    if (!to_add)
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "ADD operation requires a valid expression";
                        return result;
                    }

                    if (strcmp(to_add->dataType, sym->dataType) != 0)
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "ADD operation type mismatch between vector subtype and expression type";
                        return result;
                    }

                    fprintf(stderr, "Adding element of type");

                    // Crear una copia del símbolo original
                    symbol *new_sym = copy_symbol(sym);

                    VectorNode *new_node = (VectorNode *)calloc(1, sizeof(VectorNode));
                    new_node->value = to_add;
                    new_node->next = NULL;

                    if (!new_sym->vectorValues->head)
                    {
                        new_sym->vectorValues->head = new_node;
                        new_sym->value = printVector(new_sym->vectorValues);
                    }
                    else
                    {
                        VectorList_addSym(new_sym->vectorValues, to_add);
                        new_sym->value = printVector(new_sym->vectorValues);
                    }

                    return new_sym;
                }

                result->dataType = "UNDEFINED";
                result->value = "ADD operation requires a VECTOR type with values";
                return result;
            }

            ctx_search = ctx_search->after;
        }
        break;
    }
    case EXP_VECTOR_ACCESS:

        symbol *index_access = evaluate_expression(expr->left, context);

        if (strcmp(index_access->dataType, "INTEGER") != 0)
        {
            result->dataType = "UNDEFINED";
            result->value = "Vector index must be of type INTEGER";
            return result;
        }

        int index = atoi(index_access->value);

        Context *ctx_search = context;
        while (ctx_search)
        {
            if (SearchID(ctx_search->symbols_context, expr->value))
            {
                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);
                if (strcmp(sym->type, "VECTOR") != 0 || !sym->vectorValues)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Symbol is not a vector or has no values";
                    return result;
                }

                VectorNode *curr = sym->vectorValues->head;
                int curr_index = 0;
                symbol *found_symbol = NULL;
                while (curr)
                {

                    if (index == curr_index)
                    {
                        found_symbol = curr->value;
                    }

                    curr = curr->next;
                    curr_index++;
                }

                if (!found_symbol)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Vector index out of bounds";
                    return result;
                }

                return found_symbol;
            }

            ctx_search = ctx_search->after;
        }
    case EXP_MATRIX_ACCESS:
    {
        symbol *row_access = evaluate_expression(expr->left, context);
        symbol *col_access = evaluate_expression(expr->right, context);

        if (strcmp(row_access->dataType, "INTEGER") != 0 || strcmp(col_access->dataType, "INTEGER") != 0)
        {
            result->dataType = "UNDEFINED";
            result->value = "Matrix indices must be of type INTEGER";
            return result;
        }

        Context *ctx_search = context;
        while (ctx_search)
        {
            if (SearchID(ctx_search->symbols_context, expr->value))
            {
                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);

                if (strcmp(sym->type, "MATRIX") != 0 || !sym->matrixValues)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Symbol is not a matrix or has no values";
                    return result;
                }

                symbol *result = *get_MatrixElementPointer(context, expr->left, expr->right, sym->matrixValues);

                if (!result)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Matrix index out of bounds";
                    return result;
                }

                return result;
            }

            ctx_search = ctx_search->after;
        }
        break;
    }
    case EXP_ARRAY_ACCESS:
    {

        // Acceso a arreglos multidimensionales usando lista de índices
        Context *ctx_search = context;
        while (ctx_search)
        {

            if (SearchID(ctx_search->symbols_context, expr->value))
            {

                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);
                if (!sym)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Symbol not found";
                    return result;
                }

                if (strcmp(sym->type, "LIST") != 0 || !sym->arrayValues || !sym->arrayValues->head)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Symbol is not a multidimensional array or has no values";
                    return result;
                }

                // Validar que tenemos suficientes índices
                if (!expr->list || !expr->list->head)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "No indices provided for array access";
                    return result;
                }

                // Evaluar todos los índices y validar que sean enteros
                ExpressionNode *index_node = expr->list->head;
                int index_count = 0;
                while (index_node)
                {
                    if (!index_node->expr)
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "Invalid index expression";
                        return result;
                    }

                    symbol *index_val = evaluate_expression(index_node->expr, context);
                    if (!index_val)
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "Failed to evaluate index expression";
                        return result;
                    }

                    if (!index_val->dataType || strcmp(index_val->dataType, "INTEGER") != 0)
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "Array indices must be of type INTEGER";
                        return result;
                    }
                    index_count++;
                    index_node = index_node->next;
                }

                // Validar que el número de índices coincida con las dimensiones
                if (index_count != sym->dimensions)
                {
                    char error_msg[256];
                    snprintf(error_msg, sizeof(error_msg),
                             "Index count mismatch: expected %d indices, got %d",
                             sym->dimensions, index_count);
                    result->dataType = "UNDEFINED";
                    result->value = strdup(error_msg);
                    return result;
                }

                // Navegar por la estructura multidimensional
                symbol *accessed_value = access_multidimensional_array(
                    sym->arrayValues, expr->list, context, sym->dimensions);

                if (!accessed_value)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Array index out of bounds or invalid access";
                    return result;
                }

                return accessed_value;
            }

            ctx_search = ctx_search->after;
        }

        result->dataType = "UNDEFINED";
        result->value = "Array variable not found";
        return result;
    }
    case EXP_ID:
    {
        Context *ctx_search = context;

        while (ctx_search)
        {
            // Verificar que ctx_search sea válido antes de usar
            if (ctx_search->symbols_context == NULL)
            {
                ctx_search = ctx_search->after;
                continue;
            }

            if (SearchID(ctx_search->symbols_context, expr->value))
            {
                symbol *sym = SearchSymbol(ctx_search->symbols_context, expr->value);

                // En lugar de crear una nueva expresión y evaluar recursivamente,
                // devolvemos directamente una copia del símbolo
                symbol *result_copy = (symbol *)calloc(1, sizeof(symbol));
                result_copy->value = strdup(sym->value);
                result_copy->dataType = strdup(sym->dataType);
                result_copy->type = strdup(sym->type);
                result_copy->id = strdup(sym->id);
                result_copy->environment = strdup(sym->environment);

                fprintf(stderr, "Copying symbol %s of type %s\n", sym->id, sym->type);

                if (strcmp(sym->type, "VECTOR") == 0 && sym->vectorValues)
                {
                    result_copy->vectorValues = copy_VectorList(sym->vectorValues);
                }
                else if (strcmp(sym->type, "MATRIX") == 0 && sym->matrixValues)
                {
                    result_copy->matrixValues = copy_MatrixList(sym->matrixValues);
                }

                return result_copy;
            }

            // Verificar que after sea válido antes de avanzar
            if (ctx_search->after == (Context *)0xbebebebebebebebe ||
                ctx_search->after == NULL)
            {
                break;
            }
            ctx_search = ctx_search->after;
        }
        result->dataType = "UNDEFINED";
        result->value = "Variable no definida";
        result->environment = context->nombre;
        return result;
    }
    case EXP_FUNCTION_CALL:
    {

        Context *ctx_func = calloc(1, sizeof(Context));
        ctx_func->after = context;
        ctx_func->symbols_context = Symbol_table_create();
        ctx_func->nombre = "Function_Call";

        ExpressionNode *current_param = expr->list ? expr->list->head : NULL;

        symbol *func_symbol = NULL;

        Context *ctx_search = context;
        while (ctx_search)
        {
            if (SearchID(ctx_search->symbols_context, expr->value))
            {
                func_symbol = SearchSymbol(ctx_search->symbols_context, expr->value);

                if (strcmp(func_symbol->type, "FUNCTION") != 0 || !func_symbol->functionValues)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Symbol is not a function or has no values";
                    return result;
                }

                if (!func_symbol->functionValues->parameters || !func_symbol->functionValues->parameters->head)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Function has no parameters defined";
                    return result;
                }

                params *param_node = func_symbol->functionValues->parameters->head;
                int param_index = 0;
                while (param_node && current_param)
                {
                    symbol *param_value = evaluate_expression(current_param->expr, context);
                    if (param_value == NULL || strcmp(param_value->dataType, "UNDEFINED") == 0)
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "Error evaluating function parameter expression";
                        return result;
                    }

                    if (strcmp(param_value->type, "VECTOR") == 0)
                    {

                        size_t len_val = strlen(param_value->type) + strlen("_") + strlen(param_value->dataType) + 1;
                        char *full_type_val = (char *)calloc(len_val, sizeof(char));
                        snprintf(full_type_val, len_val, "%s_%s", param_value->type, param_value->dataType);

                        if (strcmp(full_type_val, param_node->type) != 0)
                        {
                            result->dataType = "UNDEFINED";
                            result->value = "Function parameter type mismatch";
                            return result;
                        }

                        fprintf(stderr, "--------------------Vector values: %p\n", (void *)param_value->vectorValues);

                        // Insertar el parámetro en el contexto de la función
                        symbol *param_symbol = (symbol *)calloc(1, sizeof(symbol));
                        param_symbol->id = param_node->id;
                        param_symbol->dataType = param_value->dataType;
                        param_symbol->type = param_value->type;
                        param_symbol->value = param_value->value;
                        param_symbol->vectorValues = param_value->vectorValues;
                        param_symbol->environment = ctx_func->nombre;
                        param_symbol->line = &(current_param->expr->line);
                        param_symbol->column = &(current_param->expr->column);

                        Symbol_table_insert(ctx_func->symbols_context, param_symbol);

                        param_node = param_node->next;
                        current_param = current_param->next;
                        param_index++;
                    }
                    else if (strcmp(param_value->dataType, param_node->type) == 0)
                    {
                        // Insertar el parámetro en el contexto de la función
                        symbol *param_symbol = (symbol *)calloc(1, sizeof(symbol));
                        param_symbol->id = param_node->id;
                        param_symbol->dataType = param_value->dataType;
                        param_symbol->type = strdup("PARAMETER");
                        param_symbol->value = param_value->value;
                        param_symbol->environment = ctx_func->nombre;
                        param_symbol->line = &(current_param->expr->line);
                        param_symbol->column = &(current_param->expr->column);

                        Symbol_table_insert(ctx_func->symbols_context, param_symbol);

                        param_node = param_node->next;
                        current_param = current_param->next;
                        param_index++;
                    }
                    else
                    {
                        result->dataType = "UNDEFINED";
                        result->value = "Function parameter type mismatch";
                        return result;
                    }
                }

                if (current_param || param_node)
                {
                    result->dataType = "UNDEFINED";
                    result->value = "Function parameter count mismatch";
                    return result;
                }
            }

            ctx_search = ctx_search->after;
        }

        if (!func_symbol)
        {

            result->dataType = "UNDEFINED";
            result->value = "not implemented yet";
            return result;
        }

        InstruccionNode *curr = func_symbol->functionValues->body->head;
        while (curr)
        {
            semantic_analysis_execute(curr->instr, ctx_func);
            if (strcmp(curr->instr->InstType, "Return") == 0)
                break;
            else if (ctx_func->return_value)
            {
                fprintf(stderr, "Function returned with value: %s of type %s\n", ctx_func->return_value->value, ctx_func->return_value->dataType);
                break;
            }

            curr = curr->next;
        }

        if (!ctx_func->return_value)
        {
            result->dataType = "UNDEFINED";
            result->value = "Function did not return a value";
            return result;
        }

        Symbol_table_insertContext(SymbolTable_General, ctx_func->symbols_context);

        return ctx_func->return_value;
        break;
    }
    default:
        return NULL;
    }
}