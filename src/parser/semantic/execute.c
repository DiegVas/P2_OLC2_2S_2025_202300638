#include "../structures/parser.h"
#include "../ARM/arm.h"
#include "semantic.h"
#include <string.h>

extern symbol_table *SymbolTable_General;
extern ARM_data *arm_global_data;

void semantic_analysis_execute(Instruccion *instruction, Context *context)
{

    // * Tabla de simbolos del contexto
    symbol_table *symbolTable_C = context->symbols_context;

    // ! Tabla de errores del contexto
    extern ErrorList *list_errors;

    ExecuteType instruction_type = get_instruction_type(instruction->InstType);

    switch (instruction_type)
    {
    case DECLARATION:
    {

        // ! Ya existe el mismo id en el conxteo

        if (SearchID(symbolTable_C, instruction->id))
            // Error: ID ya declarado en este contexto
            return Error_exists("ID ya declarado en este contexto", context->nombre, instruction);

        if (strcmp(instruction->symbolType, "FUNCTION") == 0)
        {
            symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
            new_symbol->id = instruction->id;
            new_symbol->dataType = instruction->type;
            new_symbol->type = instruction->symbolType;
            new_symbol->functionValues = instruction->functionData;
            new_symbol->environment = context->nombre;
            new_symbol->line = &(instruction->line);
            new_symbol->column = &(instruction->column);

            fprintf(stderr, "Nuevo símbolo de tipo función: %s, Tipo: %s\n",
                    new_symbol->id, new_symbol->dataType);

            Symbol_table_insert(symbolTable_C, new_symbol);
            return;
        }

        if (strcmp(instruction->symbolType, "VOID") == 0)
        {
            fprintf(stderr, "Declaración de función void detectada para ID: %s\n", instruction->id);
            symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
            new_symbol->id = instruction->id;
            new_symbol->type = instruction->symbolType;
            new_symbol->functionValues = instruction->functionData;
            new_symbol->environment = context->nombre;
            new_symbol->line = &(instruction->line);
            new_symbol->column = &(instruction->column);

            fprintf(stderr, "Nuevo símbolo de tipo función: %s, Tipo: %s\n",
                    new_symbol->id, new_symbol->dataType);

            Symbol_table_insert(symbolTable_C, new_symbol);
            return;
        }

        if (strcmp(instruction->symbolType, "LIST") == 0)
        {
            fprintf(stderr, "Declaración de lista detectada para ID: %s\n", instruction->id);
            List *list_values = instruction->arrayValues->values;
            list_values = evaluate_list(list_values, context);
            // Insertar el nuevo símbolo en la tabla de símbolos del contexto actual
            symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
            new_symbol->value = printArray(list_values);
            new_symbol->dataType = instruction->type;
            new_symbol->type = instruction->symbolType;
            new_symbol->id = instruction->id;
            new_symbol->environment = context->nombre;
            new_symbol->line = &(instruction->line);
            new_symbol->column = &(instruction->column);
            new_symbol->arrayValues = list_values;
            new_symbol->dimensions = instruction->arrayValues->dimension;

            fprintf(stderr, "Nuevo array: %s, Tipo: %s, Valor: %s\n",
                    new_symbol->id, new_symbol->dataType, new_symbol->value);

            Symbol_table_insert(symbolTable_C, new_symbol);
            return;
        }

        if (strcmp(instruction->symbolType, "VECTOR") == 0)
        {
            VectorList *vec_values = instruction->vectorValues;

            if (strcmp(vec_values->head->exprData->type, "ADD") == 0)
            {
                vec_values = evaluate_expression(vec_values->head->exprData, context)->vectorValues;
            }
            else
            {
                vec_values = evaluate_vector(instruction->type, vec_values, context);
            }

            char *vec_str = printVector(vec_values);

            symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
            new_symbol->value = vec_str;
            new_symbol->dataType = instruction->type;
            new_symbol->type = instruction->symbolType;
            new_symbol->id = instruction->id;
            new_symbol->vectorValues = vec_values;
            new_symbol->environment = context->nombre;
            new_symbol->line = &(instruction->line);
            new_symbol->column = &(instruction->column);

            fprintf(stderr, "Nuevo símbolo de tipo vector: %s, Tipo: %s, Valor: %s\n",
                    new_symbol->id, new_symbol->dataType, new_symbol->value);

            Symbol_table_insert(symbolTable_C, new_symbol);
            return;
        }

        if (strcmp(instruction->symbolType, "MATRIX") == 0)
        {
            matrixNode *curr = instruction->matrixValues->head;
            char *matrix_str = (char *)calloc(2048, sizeof(char)); // Ajusta el tamaño según lo que necesites
            strcat(matrix_str, "{");
            while (curr)
            {
                curr->vector = evaluate_vector(instruction->type, curr->vector, context);
                char *vec_str = printVector(curr->vector);

                strcat(matrix_str, vec_str);
                curr = curr->next;
            }
            strcat(matrix_str, "}");
            symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
            new_symbol->value = strdup(matrix_str);
            new_symbol->dataType = instruction->type;
            new_symbol->type = instruction->symbolType;
            new_symbol->id = instruction->id;
            new_symbol->matrixValues = instruction->matrixValues;
            new_symbol->environment = context->nombre;
            new_symbol->line = &(instruction->line);
            new_symbol->column = &(instruction->column);

            fprintf(stderr, "Nuevo símbolo de tipo matriz: %s, Tipo: %s, Valor: %s\n",
                    instruction->id, instruction->type, matrix_str);

            Symbol_table_insert(symbolTable_C, new_symbol);
            free(matrix_str);
            return;
        }

        reset_registers(context);

        fprintf(stderr, "Declaración de variable detectada para ID: %s\n", instruction->id);

        symbol *evaluated_value = evaluate_expression(instruction->value, context);

        // fprintf(stderr, "Arm code after evaluating expression:\n%s\n", evaluated_value->text_section);

        // Validar que la evaluación no retornó NULL
        if (!evaluated_value)
        {
            Error_exists("Expression evaluation failed", context->nombre, instruction);
            return;
        }

        fprintf(stderr, "Evaluated value: %s of type %s\n", evaluated_value->value, evaluated_value->dataType);

        evaluated_value = apply_casting_auto(evaluated_value, instruction->type, context);

        fprintf(stderr, "After casting, value: %s of type %s\n", evaluated_value->value, evaluated_value->dataType);

        if (strcmp(evaluated_value->dataType, "UNDEFINED") == 0)
            // Error: Evaluación de expresión fallida
            return Error_exists(evaluated_value->value, context->nombre, instruction);

        if (strcmp(evaluated_value->dataType, instruction->type) != 0)
        {

            // Error: Tipo de dato no coincide
            Error *new_error = (Error *)malloc(sizeof(Error));
            new_error->type = "Semantic";
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Tipo de dato no coincide: %s vs %s", evaluated_value->dataType, instruction->type);
            new_error->message = strdup(buffer);
            new_error->environment = strdup(context->nombre);
            new_error->line = instruction->line;
            new_error->column = instruction->column;
            insertError(list_errors, new_error);
            return;
        }

        // Insertar el nuevo símbolo en la tabla de símbolos del contexto actual
        symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
        new_symbol->value = evaluated_value->value;
        new_symbol->dataType = instruction->type;
        new_symbol->type = instruction->symbolType;
        new_symbol->id = instruction->id;
        new_symbol->environment = context->nombre;
        new_symbol->line = &(instruction->line);
        new_symbol->column = &(instruction->column);

        fprintf(stderr, "Evaluated value before ARM declaration: %s of type %s\n", evaluated_value->value, evaluated_value->dataType);

        if (evaluated_value->declared_in_arm)
        {
            arm_global_data->data = arm_data_add(arm_global_data->data, arm_declarate(new_symbol->id, new_symbol->dataType, new_symbol->value));
        }
        else
        {
            arm_global_data->text = arm_data_add(arm_global_data->text, evaluated_value->text_section);
            arm_global_data->bss = arm_data_add(arm_global_data->bss, arm_declarate_bss(new_symbol->id, new_symbol->dataType));

            //* Asignar el ultimo registro usado para la variable

            char *arm_register = "";
            int arm_num_register = -1;

            if (strcmp(new_symbol->dataType, "INTEGER") == 0 || strcmp(new_symbol->dataType, "CHARACTER") == 0 || strcmp(new_symbol->dataType, "BOOLEAN") == 0)
            {
                arm_register = "w";
                arm_num_register = context->num_register_w;
            }
            else if (strcmp(new_symbol->dataType, "FLOAT") == 0)
            {
                arm_register = "s";
                arm_num_register = context->num_register_s;
            }
            else if (strcmp(new_symbol->dataType, "DOUBLE") == 0)
            {
                arm_register = "d";
                arm_num_register = context->num_register_d == 0 ? 1 : context->num_register_d;
            }
            else
            {
                arm_register = "x";
                arm_num_register = context->num_register_x;
            }
            {

                char buffer[128];
                snprintf(buffer, sizeof(buffer), "ldr x%d, =%s\n", context->num_register_x, new_symbol->id);
                arm_global_data->text = arm_data_add(arm_global_data->text, buffer);

                snprintf(buffer, sizeof(buffer), "str %s%d, [x%d]\n", arm_register, arm_num_register - 1, context->num_register_x);
                arm_global_data->text = arm_data_add(arm_global_data->text, buffer);

                arm_global_data->text = arm_text_add(arm_global_data->text, "svc 0 \n"); // llamada al sistema para reservar espacio en bss
                fprintf(stderr, "La variable %s no se declara en ARM porque su valor no es literal.\n", new_symbol->id);
            }
        }
        fprintf(stderr, "Nuevo símbolo: %s, Tipo: %s, Valor: %s\n",
                new_symbol->id, new_symbol->dataType, new_symbol->value);

        Symbol_table_insert(symbolTable_C, new_symbol);
        break;
    }
    case ASSIGNMENT:
    {
        symbol *evaluated_assign = evaluate_expression(instruction->value, context);

        // Validar que la evaluación no retornó NULL
        if (!evaluated_assign)
        {
            Error_exists("Assignment expression evaluation failed", context->nombre, instruction);
            return;
        }

        if (strcmp(evaluated_assign->dataType, "UNDEFINED") == 0)
            //! Error: Evaluación de expresión fallida
            return Error_exists(evaluated_assign->value, context->nombre, instruction);

        Context *ctx = context;
        while (ctx)
        {
            if (SearchID(ctx->symbols_context, instruction->id))
            {
                symbol *sym_to_update = SearchSymbol(ctx->symbols_context, instruction->id);

                if (strcmp(sym_to_update->type, "VECTOR") == 0 && instruction->IndexVector)
                {
                    fprintf(stderr, "Asignación a elemento de vector detectada para ID: %s\n", instruction->id);

                    // Obtener puntero directo al elemento del vector
                    symbol **vector_element_ptr = get_VectorElementPointer(ctx, instruction->IndexVector, sym_to_update->vectorValues);

                    if (!vector_element_ptr)
                        return Error_exists("Vector index must be INTEGER or out of bounds", ctx->nombre, instruction);

                    symbol *vector_element = *vector_element_ptr;

                    // Modificar directamente el valor en el vector
                    vector_element->value = evaluated_assign->value;

                    // Actualizar la representación string del vector completo
                    sym_to_update->value = printVector(sym_to_update->vectorValues);
                    fprintf(stderr, "Vector completo actualizado: %s\n", sym_to_update->value);
                    return;
                }

                if (strcmp(sym_to_update->type, "MATRIX") == 0 && instruction->IndexMatrix)
                {
                    fprintf(stderr, "Asignación a elemento de matriz detectada para ID: %s\n", instruction->id);
                    symbol **matrix_element_ptr = get_MatrixElementPointer(ctx, instruction->IndexMatrix, instruction->IndexVector, sym_to_update->matrixValues);

                    if (!matrix_element_ptr)
                        return Error_exists("Matrix index must be INTEGER or out of bounds", ctx->nombre, instruction);
                    symbol *matrix_element = *matrix_element_ptr;

                    // Modificar directamente el valor en la matriz
                    matrix_element->value = evaluated_assign->value;

                    // Actualizar la representación string de la matriz completa

                    char *matrix_str = (char *)calloc(2048, sizeof(char)); // Ajusta el tamaño según lo que necesites
                    strcat(matrix_str, "{");
                    matrixNode *curr = sym_to_update->matrixValues ? sym_to_update->matrixValues->head : NULL;
                    while (curr)
                    {
                        char *vec_str = printVector(curr->vector);
                        strcat(matrix_str, vec_str);
                        curr = curr->next;
                    }
                    strcat(matrix_str, "}");
                    sym_to_update->value = matrix_str;
                    fprintf(stderr, "Matriz completa actualizada: %s\n", sym_to_update->value);
                    return;
                }

                if (strcmp(sym_to_update->type, "LIST") == 0 && instruction->indexList)
                {
                    fprintf(stderr, "Asignación a elemento de arreglo multidimensional detectada para ID: %s\n", instruction->id);

                    // Validar que el número de índices coincida con las dimensiones
                    int provided_indices = 0;
                    ExpressionNode *idx_node = instruction->indexList->head;
                    while (idx_node)
                    {
                        provided_indices++;
                        idx_node = idx_node->next;
                    }

                    if (provided_indices != sym_to_update->dimensions)
                    {
                        char error_msg[256];
                        snprintf(error_msg, sizeof(error_msg),
                                 "Index count mismatch for assignment: expected %d indices, got %d",
                                 sym_to_update->dimensions, provided_indices);
                        Error_exists(error_msg, context->nombre, instruction);
                        return;
                    }

                    // Validar que los índices sean de tipo entero
                    idx_node = instruction->indexList->head;
                    int idx_count = 0;
                    while (idx_node)
                    {
                        if (!idx_node->expr)
                        {
                            Error_exists("Invalid index expression in assignment", context->nombre, instruction);
                            return;
                        }

                        symbol *idx_val = evaluate_expression(idx_node->expr, context);
                        if (!idx_val)
                        {
                            Error_exists("Failed to evaluate index expression in assignment", context->nombre, instruction);
                            return;
                        }

                        if (!idx_val->dataType || strcmp(idx_val->dataType, "INTEGER") != 0)
                        {
                            Error_exists("Array indices must be of type INTEGER in assignment", context->nombre, instruction);
                            return;
                        }

                        idx_count++;
                        idx_node = idx_node->next;
                    }

                    // Realizar la asignación
                    bool assignment_success = assign_multidimensional_array(
                        sym_to_update->arrayValues,
                        instruction->indexList,
                        context,
                        evaluated_assign,
                        sym_to_update->dimensions);

                    if (!assignment_success)
                    {
                        Error_exists("Failed to assign value to multidimensional array element", context->nombre, instruction);
                        return;
                    }

                    // Actualizar la representación string del arreglo completo
                    if (sym_to_update->value)
                        free(sym_to_update->value);
                    sym_to_update->value = printArray(sym_to_update->arrayValues);

                    fprintf(stderr, "Arreglo multidimensional actualizado: %s\n", sym_to_update->value);
                    return;
                }

                symbol *evaluated_value = apply_casting_auto(evaluated_assign, sym_to_update->dataType, context);
                if (strcmp(sym_to_update->dataType, evaluated_value->dataType) != 0)
                {
                    //! Error: Tipo de dato no coincide
                    char buffer[256];
                    snprintf(buffer, sizeof(buffer), "Tipo de dato no coincide en asignación: %s vs %s", sym_to_update->dataType, evaluated_assign->type);
                    return Error_exists(strdup(buffer), context->nombre, instruction);
                }

                if (strcmp(sym_to_update->type, "CONSTANT") == 0)
                {
                    // Error: No se puede modificar una constante
                    Error *new_error = (Error *)malloc(sizeof(Error));
                    new_error->type = "Semantic";
                    new_error->environment = context->nombre;
                    new_error->message = "No se puede modificar una constante";
                    new_error->line = instruction->line;
                    new_error->column = instruction->column;
                    insertError(list_errors, new_error);
                    return;
                }
                sym_to_update->value = evaluated_assign->value;
                return;
            }
            ctx = ctx->after;
        }

        // Error: ID no declarado
        return Error_exists("ID no declarado", context->nombre, instruction);

        break;
    }
    case EXP_PRINTLN:
    {
        symbol *print_value = evaluate_expression(instruction->value, context);

        // Validar que la evaluación no retornó NULL
        if (!print_value)
        {
            Error_exists("Print expression evaluation failed", context->nombre, instruction);
            return;
        }

        // Validar que dataType no sea NULL y sea un puntero válido antes de usar strcmp
        if (!print_value->dataType ||
            print_value->dataType == (char *)0xbebebebebebebebe ||
            strlen(print_value->dataType) == 0)
        {
            Error_exists("Print expression has invalid dataType", context->nombre, instruction);
            return;
        }

        if (strcmp(print_value->dataType, "UNDEFINED") == 0)
        {
            if (print_value->value && print_value->value != (char *)0xbebebebebebebebe)
                return Error_exists(print_value->value, context->nombre, instruction);
            else
                return Error_exists("Undefined expression with corrupted value", context->nombre, instruction);
        }

        // Verificar que value sea válido antes de usarlo
        if (!print_value->value || print_value->value == (char *)0xbebebebebebebebe)
        {
            Error_exists("Print expression has invalid value", context->nombre, instruction);
            return;
        }

        // Si es string, procesar secuencias de escape
        if (strcmp(print_value->dataType, "STRING") == 0)
        {
            char *processed_string = process_escape_sequences(print_value->value);
            printf("%s\n", processed_string);
            free(processed_string);
        }
        else
        {
            printf("%s\n", print_value->value);
        }
        break;
    }
    case IF_STATEMENT:
    {

        Expression *condition = instruction->ifData->condition;
        InstruccionList *if_block = instruction->ifData->block;
        InstruccionList *else_block = instruction->ifData->elseBlock;
        IfNodeList *else_ifs = instruction->ifData->elseIfs;

        symbol *if_condition_value = evaluate_expression(condition, context);
        if (strcmp(if_condition_value->dataType, "UNDEFINED") == 0)
            return Error_exists(if_condition_value->value, context->nombre, instruction);

        bool condition_value = boolean_value(if_condition_value->value);

        //  fprintf(stderr, "Valor de la condición IF: %s (bool: %d)\n", if_condition_value->value, condition_value);

        Context *ctx_if = calloc(1, sizeof(Context));
        ctx_if->after = context;
        ctx_if->symbols_context = Symbol_table_create();
        ctx_if->nombre = "If";

        if (condition_value)
        {
            InstruccionNode *curr = if_block->head;
            while (curr)
            {
                semantic_analysis_execute(curr->instr, ctx_if);
                if (strcmp(curr->instr->InstType, "RETURN") == 0)
                    break;
                curr = curr->next;
            }
        }
        else
        {
            //     fprintf(stderr, "Valor de la condición ELSE: %s (bool: %d)\n", if_condition_value->value, condition_value);
            bool executed_elseif = false;
            IfNodeList *curr_elseif = else_ifs;
            IfNode *curr_node = curr_elseif ? curr_elseif->head : NULL;
            while (curr_node && !executed_elseif)
            {
                bool elseif_condition_value = boolean_value(evaluate_expression(curr_node->IfData->condition, context)->value);
                if (elseif_condition_value)
                {
                    InstruccionNode *curr = curr_node->IfData->block->head;
                    while (curr)
                    {
                        semantic_analysis_execute(curr->instr, ctx_if);
                        if (strcmp(curr->instr->InstType, "RETURN") == 0)
                        {
                            executed_elseif = true;
                            break;
                        }

                        curr = curr->next;
                    }
                    executed_elseif = true;
                }
                curr_node = curr_node->next;
            }

            if (!executed_elseif && else_block)
            {

                InstruccionNode *curr = else_block->head;
                while (curr)
                {
                    if (strcmp(curr->instr->InstType, "RETURN") == 0)
                        break;

                    semantic_analysis_execute(curr->instr, ctx_if);
                    curr = curr->next;
                }
            }
        }
        Symbol_table_insertContext(SymbolTable_General, ctx_if->symbols_context);

        break;
    }
    case SWITCH_STATEMENT:
    {
        char *switch_id = instruction->switchData->condition;

        Expression *switch_id_value = (Expression *)calloc(1, sizeof(Expression));
        switch_id_value->type = "ID";
        switch_id_value->value = switch_id;

        Context *ctx_switch = calloc(1, sizeof(Context));
        ctx_switch->after = context;
        ctx_switch->symbols_context = Symbol_table_create();
        ctx_switch->nombre = "Switch";

        symbol *switch_value = evaluate_expression(switch_id_value, context);

        if (strcmp(switch_value->dataType, "UNDEFINED") == 0)
            return Error_exists("ID no declarado en switch", context->nombre, instruction);

        bool case_executed = false;

        Expression *exp_condition = (Expression *)calloc(1, sizeof(Expression));
        exp_condition->type = "EQUALS";
        exp_condition->value = strdup("==");
        exp_condition->left = switch_id_value;

        CaseNode *curr_case = instruction->switchData->cases ? instruction->switchData->cases->head : NULL;
        while (curr_case && !case_executed)
        {

            exp_condition->right = curr_case->caseData->condition;

            symbol *case_condition = evaluate_expression(exp_condition, context);

            bool case_condition_bool = boolean_value(case_condition->value);

            if (case_condition_bool)
            {

                ctx_switch->nombre = "Case";

                InstruccionNode *curr_instr = curr_case->caseData->block->head;
                while (curr_instr)
                {
                    if (strcmp(curr_instr->instr->InstType, "RETURN") == 0)
                        break;

                    semantic_analysis_execute(curr_instr->instr, ctx_switch);
                    curr_instr = curr_instr->next;
                }
                case_executed = true;
            }
            curr_case = curr_case->next;
        }

        if (!case_executed && instruction->switchData->defaultCase)
        {
            ctx_switch->nombre = "Default";

            InstruccionNode *curr_instr = instruction->switchData->defaultCase->head;
            while (curr_instr)
            {
                semantic_analysis_execute(curr_instr->instr, ctx_switch);
                curr_instr = curr_instr->next;
            }
        }
        Symbol_table_insertContext(SymbolTable_General, ctx_switch->symbols_context);
        break;
    }
    case WHILE_STATEMENT:
    {
        Expression *condition = instruction->whileData->condition;
        InstruccionList *while_block = instruction->whileData->block;

        Context *ctx_while = calloc(1, sizeof(Context));
        ctx_while->after = context;
        ctx_while->symbols_context = Symbol_table_create();
        ctx_while->nombre = "While";

        symbol *evaluated_while = evaluate_expression(condition, ctx_while);
        if (strcmp(evaluated_while->dataType, "UNDEFINED") == 0)
        {
            Error *new_error = (Error *)malloc(sizeof(Error));
            new_error->type = "Semantic";
            new_error->environment = context->nombre;
            new_error->message = evaluated_while->value;
            new_error->line = instruction->line;
            new_error->column = instruction->column;
            insertError(list_errors, new_error);
            return;
        }
        bool condition_value = boolean_value(evaluated_while->value);

        while (condition_value)
        {
            InstruccionNode *curr = while_block->head;

            Context *inner_ctx = calloc(1, sizeof(Context));
            inner_ctx->after = ctx_while;
            inner_ctx->symbols_context = Symbol_table_create();
            inner_ctx->nombre = "Inner_While";

            while (curr)
            {
                semantic_analysis_execute(curr->instr, inner_ctx);
                if (inner_ctx->break_instruction)
                    break;

                if (inner_ctx->continue_instruction)
                {
                    inner_ctx->continue_instruction = false;
                    break;
                }

                curr = curr->next;
            }

            if (inner_ctx->break_instruction)
                break;

            condition_value = boolean_value(evaluate_expression(condition, context)->value);
        }
        Symbol_table_insertContext(SymbolTable_General, ctx_while->symbols_context);
        break;
    }
    case FOREACH_STATEMENT:
    {
        Context *ctx_foreach = calloc(1, sizeof(Context));
        ctx_foreach->after = context;
        ctx_foreach->symbols_context = Symbol_table_create();
        ctx_foreach->nombre = "Foreach";

        Context *search_ctx = context;
        while (search_ctx)
        {

            if (SearchID(search_ctx->symbols_context, instruction->forEachData->array))
            {
                symbol *array_symbol = SearchSymbol(search_ctx->symbols_context, instruction->forEachData->array);

                if (strcmp(array_symbol->type, "VECTOR") != 0)
                    return Error_exists("FOREACH solo soporta vectores", context->nombre, instruction);

                VectorList *vector_values = array_symbol->vectorValues;
                if (!vector_values || !vector_values->head)
                {
                    fprintf(stderr, "Vector vacío o inválido para foreach\n");
                    return;
                }

                // Iterar sobre cada elemento del vector
                VectorNode *vector_node = vector_values->head;
                while (vector_node)
                {
                    fprintf(stderr, "DEBUG: Foreach - Procesando elemento del vector\n");

                    // Crear o actualizar el símbolo de iteración para el elemento actual
                    symbol *loop_symbol = (symbol *)calloc(1, sizeof(symbol));
                    loop_symbol->id = instruction->forEachData->item;
                    loop_symbol->dataType = instruction->forEachData->type;
                    loop_symbol->type = "VARIABLE";
                    loop_symbol->environment = ctx_foreach->nombre;
                    loop_symbol->line = &(instruction->line);
                    loop_symbol->column = &(instruction->column);

                    // Asignar el valor del elemento actual
                    if (vector_node->value)
                    {
                        loop_symbol->value = vector_node->value->value ? strdup(vector_node->value->value) : strdup("NULL");
                        fprintf(stderr, "DEBUG: Foreach - Variable '%s' = '%s'\n",
                                loop_symbol->id, loop_symbol->value);
                    }
                    else if (vector_node->exprData)
                    {
                        symbol *eval_expr = evaluate_expression(vector_node->exprData, context);
                        if (eval_expr)
                        {
                            loop_symbol->value = eval_expr->value ? strdup(eval_expr->value) : strdup("NULL");
                            fprintf(stderr, "DEBUG: Foreach - Variable '%s' = '%s' (from expression)\n",
                                    loop_symbol->id, loop_symbol->value);
                        }
                        else
                        {
                            loop_symbol->value = strdup("NULL");
                        }
                    }
                    else
                    {
                        loop_symbol->value = strdup("NULL");
                    }

                    // Insertar la variable de iteración en el contexto del foreach
                    Symbol_table_insert(ctx_foreach->symbols_context, loop_symbol);

                    // Ejecutar todo el bloque de instrucciones con el elemento actual
                    InstruccionNode *curr = instruction->forEachData->block->head;
                    while (curr)
                    {
                        semantic_analysis_execute(curr->instr, ctx_foreach);

                        if (ctx_foreach->break_instruction)
                            break;

                        if (ctx_foreach->continue_instruction)
                        {
                            ctx_foreach->continue_instruction = false;
                            break;
                        }

                        curr = curr->next;
                    }

                    if (ctx_foreach->break_instruction)
                        break;

                    // Limpiar la tabla de símbolos para la siguiente iteración
                    // (mantener solo los símbolos que no sean la variable de iteración)
                    ctx_foreach->symbols_context = Symbol_table_create();

                    vector_node = vector_node->next;
                }
                Symbol_table_insertContext(SymbolTable_General, ctx_foreach->symbols_context);
                return;
            }

            search_ctx = search_ctx->after;
        }

        return Error_exists("FOREACH no implementado aún", context->nombre, instruction);
    }
    case FOR_STATEMENT:
    {
        Instruccion *init = instruction->forData->init;
        Expression *condition = instruction->forData->condition;
        Instruccion *update = instruction->forData->update;
        InstruccionList *for_block = instruction->forData->block;

        Context *ctx_for = calloc(1, sizeof(Context));
        ctx_for->after = context;
        ctx_for->symbols_context = Symbol_table_create();
        ctx_for->nombre = "For";

        semantic_analysis_execute(init, ctx_for);

        symbol *evaluated_for = evaluate_expression(condition, ctx_for);
        bool condition_value = boolean_value(evaluated_for->value);

        while (condition_value)
        {

            Context *inner_ctx = calloc(1, sizeof(Context));
            inner_ctx->after = ctx_for;
            inner_ctx->symbols_context = Symbol_table_create();
            inner_ctx->nombre = "Inner_For";

            InstruccionNode *curr = for_block->head;
            while (curr)
            {

                semantic_analysis_execute(curr->instr, inner_ctx);

                if (inner_ctx->break_instruction)
                    break;

                if (inner_ctx->continue_instruction)
                {
                    inner_ctx->continue_instruction = false;
                    break;
                }

                curr = curr->next;
            }

            // Ejecutar actualización

            if (ctx_for->break_instruction)
                break;

            semantic_analysis_execute(update, ctx_for);
            condition_value = boolean_value(evaluate_expression(condition, ctx_for)->value);
        }
        Symbol_table_insertContext(SymbolTable_General, ctx_for->symbols_context);
        break;
    }
    case BREAK_STATEMENT:
    {
        // Manejo de la instrucción BREAK
        Context *ctx = context;
        bool found_loop = false;
        while (ctx)
        {
            fprintf(stderr, "---------------------\n");
            fprintf(stderr, "DEBUG: Buscando contexto para BREAK, contexto actual: %s\n", ctx->nombre);
            fprintf(stderr, "Nombre del contexto: %s\n", ctx->nombre);
            if (strcmp(ctx->nombre, "For") == 0 || strcmp(ctx->nombre, "While") == 0 || strcmp(ctx->nombre, "Switch") == 0 || strcmp(ctx->nombre, "Inner_While") == 0 || strcmp(ctx->nombre, "Inner_For") == 0 || strcmp(ctx->nombre, "Foreach") == 0)
            {
                ctx->break_instruction = true;
                found_loop = true;
                break;
            }
            ctx = ctx->after;
        }

        if (!found_loop)
            return Error_exists("BREAK fuera de un contexto de bucle o switch", context->nombre, instruction);

        break;
    }
    case CONTINUE_STATEMENT:
    {
        // Manejo de la instrucción CONTINUE
        Context *ctx = context;
        bool found_loop = false;
        while (ctx)
        {
            if (strcmp(ctx->nombre, "For") == 0 || strcmp(ctx->nombre, "While") == 0 || strcmp(ctx->nombre, "Inner_While") == 0 || strcmp(ctx->nombre, "Inner_For") == 0 || strcmp(ctx->nombre, "Foreach") == 0)
            {

                ctx->continue_instruction = true;
                found_loop = true;
                break;
            }
            ctx = ctx->after;
        }

        if (!found_loop)
            return Error_exists("CONTINUE fuera de un contexto de bucle", context->nombre, instruction);

        break;
    }
    case RETURN_STATEMENT:
    {
        // Manejo de la instrucción RETURN
        Context *ctx = context;
        bool found_function = false;
        while (ctx)
        {
            if (strcmp(ctx->nombre, "Function_Call") == 0)
            {
                symbol *return_value = evaluate_expression(instruction->value, context);
                if (strcmp(return_value->dataType, "UNDEFINED") == 0)
                    return Error_exists(return_value->value, context->nombre, instruction);
                ctx->return_value = return_value;
                found_function = true;
                break;
            }
            else if (strcmp(ctx->nombre, "Void_Call") == 0)
            {
                found_function = true;
                break;
            }

            ctx = ctx->after;
        }

        if (!found_function)
            return Error_exists("RETURN fuera de un contexto de función", context->nombre, instruction);

        break;
    }
    case VOID_CALL:
    {
        fprintf(stderr, "Llamada a función void detectada para ID: %s\n", instruction->id);

        Context *ctx_func = malloc(sizeof(Context));
        ctx_func->after = context;
        ctx_func->symbols_context = Symbol_table_create();
        ctx_func->nombre = "Void_Call";

        symbol *func_symbol = SearchSymbol(context->symbols_context, instruction->id);
        if (!func_symbol)
            return Error_exists("ID de función no declarado", context->nombre, instruction);

        if (strcmp(func_symbol->type, "VOID") != 0)
            return Error_exists("ID no es de tipo función void", context->nombre, instruction);

        InstruccionNode *curr = func_symbol->functionValues->body->head;
        while (curr)
        {

            semantic_analysis_execute(curr->instr, ctx_func);
            if (strcmp(ctx_func->nombre, "Return") == 0)
                break;

            curr = curr->next;
        }
        Symbol_table_insertContext(SymbolTable_General, ctx_func->symbols_context);
        break;
    }
    case BLOCK_STATEMENT:
    {
        InstruccionNode *curr = instruction->body->head;

        Context *ctx_block = calloc(1, sizeof(Context));
        ctx_block->after = context;
        ctx_block->symbols_context = Symbol_table_create();
        ctx_block->nombre = "Block";

        while (curr)
        {
            semantic_analysis_execute(curr->instr, ctx_block);
            if (strcmp(curr->instr->InstType, "RETURN") == 0)
                break;

            curr = curr->next;
        }
        Symbol_table_insertContext(SymbolTable_General, ctx_block->symbols_context);
        break;
    }
    default:
        fprintf(stderr, "Instrucción no manejada en análisis semántico: %s\n", instruction->InstType);
        break;
    }
}
