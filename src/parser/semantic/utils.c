#include "semantic.h"
#include <math.h>

ConvertedValue convert_operand(symbol *operand)
{
    ConvertedValue cv = {0};

    if (operand == NULL)
    {
        cv.result_type = TYPE_UNDEFINED;
        return cv;
    }

    if (strcmp(operand->dataType, "STRING") == 0)
    {
        cv.str_value = operand->value;
        cv.result_type = TYPE_STRING;
    }
    else if (strcmp(operand->dataType, "NULL") == 0)
    {
        cv.str_value = "null";
        cv.num_value = 0;
        cv.result_type = TYPE_NULL;
    }
    else if (strcmp(operand->dataType, "INTEGER") == 0)
    {
        cv.num_value = atoi(operand->value);
        cv.result_type = TYPE_INTEGER;
    }
    else if (strcmp(operand->dataType, "FLOAT") == 0)
    {
        cv.num_value = atof(operand->value);
        cv.result_type = TYPE_FLOAT;
    }
    else if (strcmp(operand->dataType, "DOUBLE") == 0)
    {
        cv.num_value = atof(operand->value);
        cv.result_type = TYPE_DOUBLE;
    }

    return cv;
}

// Función genérica para operaciones aritméticas
symbol *perform_arithmetic_operation(Expression *exp_left, Expression *exp_right, Context *context, char operation)
{

    symbol *left = evaluate_expression(exp_left, context);
    symbol *right = evaluate_expression(exp_right, context);

    // Verificar que ambos operandos sean válidos
    if (left == NULL || right == NULL)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Error: null operand in arithmetic operation");
        return result;
    }

    ConvertedValue cv_left = convert_operand(left);
    ConvertedValue cv_right = convert_operand(right);

    // Verificar que la conversión fue exitosa
    if (cv_left.result_type == TYPE_UNDEFINED || cv_right.result_type == TYPE_UNDEFINED)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Error: invalid operand types in arithmetic operation");
        return result;
    }

    // Verificar operaciones con NULL
    if (cv_left.result_type == TYPE_NULL || cv_right.result_type == TYPE_NULL)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("NULL");
        result->value = strdup("null");
        return result;
    }

    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    // Si alguno es string, concatenar (solo para suma)
    if (operation == '+' && (cv_left.result_type == TYPE_STRING || cv_right.result_type == TYPE_STRING))
    {
        result->dataType = strdup("STRING");
        char *left_str = (cv_left.result_type == TYPE_STRING) ? cv_left.str_value : left->value;
        char *right_str = (cv_right.result_type == TYPE_STRING) ? cv_right.str_value : right->value;

        result->value = (char *)calloc(strlen(left_str) + strlen(right_str) + 1, sizeof(char));
        strcpy(result->value, left_str);
        strcat(result->value, right_str);
        return result;
    }

    // Determinar el tipo de resultado (el más "grande")
    OperativeType result_type = (cv_left.result_type > cv_right.result_type) ? cv_left.result_type : cv_right.result_type;

    // Realizar la operación
    double final_result;
    switch (operation)
    {
    case '+':
        final_result = cv_left.num_value + cv_right.num_value;
        break;
    case '-':
        final_result = cv_left.num_value - cv_right.num_value;
        break;
    case '*':
        final_result = cv_left.num_value * cv_right.num_value;
        break;
    case '/':
        if (cv_right.num_value == 0)
        {
            // Manejar división por cero
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Division by zero");
            return result;
        }

        final_result = cv_left.num_value / cv_right.num_value;

        if (final_result != floor(final_result))
            result_type = TYPE_DOUBLE; // Promover a DOUBLE si hay decimales

        break;
    case '%':
        if (cv_right.num_value == 0)
        {
            // Manejar módulo por cero
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Modulo by zero");
            return result;
        }
        final_result = (int)cv_left.num_value % (int)cv_right.num_value;
        break;
    default:
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Unknown operation");
        return result;
    }

    // Formatear resultado según el tipo
    result->value = (char *)calloc(50, sizeof(char)); // Suficiente espacio

    fprintf(stderr, "Final result before formatting: %f\n", final_result); // Debug line
    fprintf(stderr, "Result type: %d\n", result_type);                     // Debug line

    switch (result_type)
    {
    case TYPE_INTEGER:
        result->dataType = strdup("INTEGER");
        sprintf(result->value, "%d", (int)final_result);
        break;
    case TYPE_FLOAT:
        result->dataType = strdup("FLOAT");
        sprintf(result->value, "%.2f", final_result);
        break;
    case TYPE_DOUBLE:
        result->dataType = strdup("DOUBLE");
        sprintf(result->value, "%.6f", final_result);
        break;
    default:
        result->dataType = strdup("INTEGER");
        sprintf(result->value, "%d", (int)final_result);
        break;
    }

    return result;
}

symbol *perfom_BITWISE(Expression *exp_left, Expression *exp_right, Context *context, char *operation)
{
    symbol *left = evaluate_expression(exp_left, context);
    symbol *right = evaluate_expression(exp_right, context);

    ConvertedValue cv_left = convert_operand(left);
    ConvertedValue cv_right = convert_operand(right);

    if (cv_left.result_type != TYPE_INTEGER || cv_right.result_type != TYPE_INTEGER)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Bitwise operations do not support non-integer");
        return result;
    }

    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    int left_val = (int)cv_left.num_value;
    int right_val = (int)cv_right.num_value;
    int final_result;

    if (strcmp(operation, "&") == 0)
        final_result = left_val & right_val;
    else if (strcmp(operation, "|") == 0)
        final_result = left_val | right_val;
    else if (strcmp(operation, "^") == 0)
        final_result = left_val ^ right_val;
    else if (strcmp(operation, ">>") == 0)
        final_result = left_val >> right_val;
    else if (strcmp(operation, "<<") == 0)
        final_result = left_val << right_val;
    else
    {
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Unknown bitwise operation");
        return result;
    }
    result->dataType = strdup("INTEGER");
    result->value = (char *)calloc(50, sizeof(char));
    sprintf(result->value, "%d", final_result);

    return result;
}

char *process_escape_sequences(const char *input)
{
    if (!input)
        return NULL;

    int len = strlen(input);
    char *result = (char *)malloc(len + 1); // En el peor caso, mismo tamaño
    int i = 0, j = 0;

    while (i < len)
    {
        if (input[i] == '\\' && i + 1 < len)
        {
            switch (input[i + 1])
            {
            case 'n':
                result[j++] = '\n';
                i += 2;
                break;
            case 't':
                result[j++] = '\t';
                i += 2;
                break;
            case 'r':
                result[j++] = '\r';
                i += 2;
                break;
            case '\\':
                result[j++] = '\\';
                i += 2;
                break;
            case '"':
                result[j++] = '"';
                i += 2;
                break;
            default:
                // Si no es una secuencia reconocida, mantener como está
                result[j++] = input[i++];
                break;
            }
        }
        else
        {
            result[j++] = input[i++];
        }
    }

    result[j] = '\0';
    return result;
}

symbol *get_legth_of_vector(VectorList *vector)
{
    symbol *result = calloc(1, sizeof(symbol));
    result->dataType = "INTEGER";
    int count = 0;
    VectorNode *current = vector->head;
    while (current)
    {
        count++;
        current = current->next;
    }
    result->value = (char *)calloc(20, sizeof(char));
    sprintf(result->value, "%d", count);
    return result;
}

symbol *get_legth_of_matrix(MatrixList *matrix)
{
    symbol *result = calloc(1, sizeof(symbol));
    result->dataType = "INTEGER";
    int row_count = 0;
    matrixNode *current_row = matrix->head;

    // Contar el número de filas (vectores) en la matriz
    while (current_row)
    {
        row_count++;
        current_row = current_row->next;
    }

    result->value = (char *)calloc(20, sizeof(char));
    sprintf(result->value, "%d", row_count);
    return result;
}

// Función recursiva para acceder a arreglos multidimensionales
symbol *access_multidimensional_array(List *array, ExpressionList *indices, Context *context, int expected_dimensions)
{
    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    if (!array || !indices || !indices->head)
    {

        return result;
    }

    // Evaluar el primer índice
    ExpressionNode *current_index = indices->head;
    if (!current_index || !current_index->expr)
    {
        result->dataType = "UNDEFINED";
        result->value = strdup("current_index or expr is NULL");

        return result;
    }

    symbol *index_symbol = evaluate_expression(current_index->expr, context);
    if (!index_symbol)
    {
        result->dataType = "UNDEFINED";
        result->value = strdup("evaluate_expression returned NULL");

        return result;
    }

    if (!index_symbol->dataType || strcmp(index_symbol->dataType, "INTEGER") != 0)
    {
        result->dataType = "UNDEFINED";
        result->value = strdup("Index must be of type INTEGER");

        return result;
    }

    if (!index_symbol->value)
    {
        result->dataType = "UNDEFINED";
        result->value = strdup("Index value is NULL");
        return result;
    }

    int index = atoi(index_symbol->value);

    // Contar elementos en la lista actual
    ListNode *current_node = array->head;
    int list_size = 0;
    while (current_node)
    {
        list_size++;
        current_node = current_node->next;
    }

    // Validar que el índice esté en rango
    if (index < 0 || index >= list_size)
    {
        // Error_exists("Array index out of bounds", context ? context->nombre : "Unknown", NULL);
        result->dataType = "UNDEFINED";
        result->value = strdup("Array index out of bounds");

        return result;
    }

    // Navegar al elemento en la posición index
    current_node = array->head;
    for (int i = 0; i < index && current_node; i++)
    {
        current_node = current_node->next;
    }

    if (!current_node)
    {
        result->dataType = "UNDEFINED";
        result->value = strdup("current_node is NULL after navigation");

        return result;
    }

    if (!current_node->listData)
    {
        result->dataType = "UNDEFINED";
        result->value = strdup("current_node is NULL after navigation");

        return result;
    }

    ListData *current_data = current_node->listData;

    // Si este es el último índice
    if (!current_index->next)
    {

        // Debemos estar en una expresión final, no en otra lista
        if (current_data->exprData)
        {

            if (!result)
            {
                result->dataType = "UNDEFINED";
                result->value = strdup("Error allocating result");

                return result;
            }

            result->dataType = current_data->exprData->type ? strdup(current_data->exprData->type) : strdup("UNDEFINED");
            result->value = current_data->exprData->value ? strdup(current_data->exprData->value) : strdup("NULL");
            result->type = strdup("VARIABLE");
            result->environment = context && context->nombre ? strdup(context->nombre) : strdup("Unknown");

            return result;
        }
        else if (current_data->listData)
        {
            // Error: todavía hay más dimensiones pero no más índices
            result->dataType = "UNDEFINED";
            result->value = strdup("Array index out of bounds");

            return result;
        }
        else if (current_data->symData)
        {

            // Retornar el símbolo directamente
            symbol *result = (symbol *)calloc(1, sizeof(symbol));
            if (!result)
            {
                result->dataType = "UNDEFINED";
                result->value = strdup("Error allocating result");

                return result;
            }

            result->dataType = current_data->symData->dataType ? strdup(current_data->symData->dataType) : strdup("UNDEFINED");
            result->value = current_data->symData->value ? strdup(current_data->symData->value) : strdup("NULL");
            result->type = current_data->symData->type ? strdup(current_data->symData->type) : strdup("VARIABLE");
            result->id = current_data->symData->id ? strdup(current_data->symData->id) : strdup("element");
            result->environment = context && context->nombre ? strdup(context->nombre) : strdup("Unknown");

            return result;
        }
        else
        {
        }
    }
    else
    {

        // Hay más índices, debemos continuar navegando
        if (current_data->listData)
        {

            // Crear una nueva lista de índices sin el primer elemento
            ExpressionList *remaining_indices = create_expression_list();
            if (!remaining_indices)
            {
                // Error_exists("Memory allocation error for remaining indices", context ? context->nombre : "Unknown", NULL);
                result->dataType = "UNDEFINED";
                result->value = strdup("Error allocating remaining indices");
                return result;
            }

            ExpressionNode *next_index = current_index->next;
            while (next_index)
            {
                if (next_index->expr) // Validación adicional
                {
                    ExpressionList_add(remaining_indices, next_index->expr);
                }
                next_index = next_index->next;
            }

            // Llamada recursiva con la sublista y los índices restantes
            symbol *recursive_result = access_multidimensional_array(
                current_data->listData,
                remaining_indices,
                context,
                expected_dimensions - 1);

            // Liberar la lista temporal de índices de manera segura
            if (remaining_indices)
            {
                ExpressionNode *current_node = remaining_indices->head;
                while (current_node)
                {
                    ExpressionNode *next_node = current_node->next;
                    free(current_node); // Solo liberamos el nodo, no la expresión
                    current_node = next_node;
                }
                free(remaining_indices);
            }

            return recursive_result;
        }
        else
        {
            // Error: tenemos más índices pero no más dimensiones
            result->dataType = "UNDEFINED";
            result->value = strdup("Array index out of bounds");

            return result;
        }
    }

    return NULL;
}

// Función para asignar valores en arreglos multidimensionales
bool assign_multidimensional_array(List *array, ExpressionList *indices, Context *context, symbol *new_value, int expected_dimensions)
{

    if (!array || !indices || !new_value || !context)
    {

        return false;
    }

    if (!indices->head)
    {

        return false;
    }

    ExpressionNode *current_index = indices->head;
    if (!current_index || !current_index->expr)
    {

        return false;
    }

    // Evaluar el primer índice
    symbol *index_symbol = evaluate_expression(current_index->expr, context);
    if (!index_symbol)
    {

        return false;
    }

    if (!index_symbol->dataType || strcmp(index_symbol->dataType, "INTEGER") != 0)
    {
        fprintf(stderr, "DEBUG: assign_multidimensional_array - Tipo de índice inválido\n");
        return false;
    }

    if (!index_symbol->value)
    {
        fprintf(stderr, "DEBUG: assign_multidimensional_array - Valor de índice es NULL\n");
        return false;
    }

    int index = atoi(index_symbol->value);
    // Contar elementos en la lista actual
    ListNode *current_node = array->head;
    int list_size = 0;
    while (current_node)
    {
        list_size++;
        current_node = current_node->next;
    }

    // Validar que el índice esté en rango
    if (index < 0 || index >= list_size)
    {
        fprintf(stderr, "DEBUG: Index %d out of bounds (size: %d) for assignment\n", index, list_size);
        return false;
    }

    // Navegar al elemento en la posición index
    current_node = array->head;
    for (int i = 0; i < index && current_node; i++)
    {
        current_node = current_node->next;
    }

    if (!current_node || !current_node->listData)
    {
        fprintf(stderr, "DEBUG: assign_multidimensional_array - Nodo o datos inválidos\n");
        return false;
    }

    ListData *current_data = current_node->listData;

    // Si este es el último índice
    if (!current_index->next)
    {

        // Debemos estar en una expresión final o símbolo, no en otra lista
        if (current_data->exprData)
        {

            // Actualizar la expresión directamente (sin liberar memoria previa para evitar errores)
            current_data->exprData->type = new_value->dataType ? strdup(new_value->dataType) : strdup("UNDEFINED");
            current_data->exprData->value = new_value->value ? strdup(new_value->value) : strdup("NULL");

            return true;
        }
        else if (current_data->symData)
        {

            // Actualizar el símbolo directamente (sin liberar memoria previa para evitar errores)
            current_data->symData->dataType = new_value->dataType ? strdup(new_value->dataType) : strdup("UNDEFINED");
            current_data->symData->value = new_value->value ? strdup(new_value->value) : strdup("NULL");
            return true;
        }
        else if (current_data->listData)
        {
            // Error: todavía hay más dimensiones pero no más índices
            fprintf(stderr, "DEBUG: assign_multidimensional_array - Error: insuficientes índices\n");
            return false;
        }
        else
        {
            fprintf(stderr, "DEBUG: assign_multidimensional_array - No hay datos para actualizar\n");
            return false;
        }
    }
    else
    {

        // Hay más índices, debemos continuar navegando
        if (current_data->listData)
        {

            // Crear una nueva lista de índices sin el primer elemento
            ExpressionList *remaining_indices = create_expression_list();
            if (!remaining_indices)
            {
                fprintf(stderr, "DEBUG: assign_multidimensional_array - Error creando remaining_indices\n");
                return false;
            }

            ExpressionNode *next_index = current_index->next;
            while (next_index)
            {
                if (next_index->expr) // Validación adicional
                {
                    ExpressionList_add(remaining_indices, next_index->expr);
                }
                next_index = next_index->next;
            }

            // Llamada recursiva con la sublista y los índices restantes
            bool recursive_result = assign_multidimensional_array(
                current_data->listData,
                remaining_indices,
                context,
                new_value,
                expected_dimensions - 1);

            // Liberar la lista temporal de índices
            free(remaining_indices);

            return recursive_result;
        }
        else
        {
            // Error: tenemos más índices pero no más dimensiones
            fprintf(stderr, "DEBUG: assign_multidimensional_array - Error: demasiados índices\n");
            return false;
        }
    }

    fprintf(stderr, "DEBUG: assign_multidimensional_array - Llegó al final sin retornar\n");
    return false;
}