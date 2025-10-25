#include "../../structures/parser.h"
#include "../ARM/arm.h"
#include "semantic.h"
#include <string.h>

extern symbol_table *SymbolTable_General;
extern ARM_data *arm_global_data;

void semantic_analysis_execute(Instruccion *instruction, Context *context)
{

    // * Tabla de simbolos del contexto
    symbol_table *symbolTable_C = context->symbols_context;
    arm_global_data->count_arithmetic_temps = 2;
    arm_global_data->count_comparative_temps = 2;

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
                symbol *vec_values_add = evaluate_expression(vec_values->head->exprData, context);
                symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
                size_t id_len = strlen(instruction->id) + strlen(context->nombre) + 2; // +2 para "_" y '\0'
                new_symbol->id = (char *)malloc(id_len);
                snprintf(new_symbol->id, id_len, "%s_%s", instruction->id, context->nombre);

                char *vec_str = printVector(vec_values_add->vectorValues);

                char bufferName[256];
                snprintf(bufferName, sizeof(bufferName), "%s: .space 400\n", new_symbol->id);
                arm_global_data->data = arm_data_add(arm_global_data->data, bufferName);

                snprintf(bufferName, sizeof(bufferName), "%s_length: .word 0\n", new_symbol->id);
                arm_global_data->data = arm_data_add(arm_global_data->data, bufferName);

                char bufferComment[128];
                snprintf(bufferComment, sizeof(bufferComment), "\n// Declaración de vector con add %s\n", instruction->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "adrp x2, %s\n", new_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "add x2, x2, :lo12:%s\n", new_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "adr x3, %s_length\n", new_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                arm_global_data->data = arm_data_add(arm_global_data->data, vec_values_add->data_section);
                arm_global_data->text = arm_text_add(arm_global_data->text, vec_values_add->text_section);

                if (strcmp(instruction->type, "STRING") == 0)
                {
                    snprintf(bufferComment, sizeof(bufferComment), "bl append_to_string_array");
                }
                else
                {
                    snprintf(bufferComment, sizeof(bufferComment), "bl append_to_array_integer");
                }

                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                new_symbol->dataType = instruction->type;
                new_symbol->type = instruction->symbolType;
                new_symbol->vectorValues = vec_values_add->vectorValues;
                new_symbol->environment = context->nombre;
                new_symbol->line = &(instruction->line);
                new_symbol->column = &(instruction->column);

                fprintf(stderr, "Nuevo símbolo de tipo vector: %s, Tipo: %s, Valor: %s\n",
                        new_symbol->id, new_symbol->dataType, new_symbol->value);

                Symbol_table_insert(symbolTable_C, new_symbol);
                return;
            }
            else
            {
                vec_values = evaluate_vector(instruction->type, vec_values, context);
            }

            char *vec_str = printVector(vec_values);
            int total_length = 0;
            char size_id[512];

            if (strcmp(instruction->type, "STRING") == 0)
            {
                VectorNode *current = vec_values->head;
                int elem_count = 0;
                char *strings_ids = (char *)calloc(1024, sizeof(char));
                char *data_temp = "";
                // Crear ID con el nombre del contexto
                char full_id[256];
                snprintf(full_id, sizeof(full_id), "%s_%s", instruction->id, context->nombre);

                while (current)
                {
                    char id_list_string[512];
                    snprintf(id_list_string, sizeof(id_list_string), "%s_elem_%d", full_id, elem_count++);
                    data_temp = arm_data_add(data_temp, arm_declarate_string(id_list_string, current->value->value));

                    strcat(strings_ids, id_list_string);
                    if (current->next)
                        strcat(strings_ids, ", ");

                    total_length++;
                    current = current->next;
                }
                vec_str = strings_ids;
                arm_global_data->data = arm_data_add(arm_global_data->data, arm_declarate_list(full_id, instruction->type, vec_str));
                arm_global_data->data = arm_data_add(arm_global_data->data, data_temp);
            }
            else
            {
                total_length = count_commas(vec_str) + 1;
                // Crear ID con el nombre del contexto
                char full_id[256];
                snprintf(full_id, sizeof(full_id), "%s_%s", instruction->id, context->nombre);
                arm_global_data->data = arm_data_add(arm_global_data->data, arm_declarate_list(full_id, instruction->type, vec_str));
            }
            // Crear ID con el nombre del contexto para size_id también
            char full_id[256];
            snprintf(full_id, sizeof(full_id), "%s_%s", instruction->id, context->nombre);
            snprintf(size_id, sizeof(size_id), "%s_length", full_id);

            arm_global_data->data = arm_data_add(arm_global_data->data, arm_declarate_int(size_id, total_length));

            symbol *new_symbol = (symbol *)calloc(1, sizeof(symbol));
            new_symbol->value = vec_str;
            new_symbol->dataType = instruction->type;
            new_symbol->type = instruction->symbolType;
            // Crear un nuevo buffer con suficiente espacio para id + "_" + nombre
            size_t id_len = strlen(instruction->id) + strlen(context->nombre) + 2; // +2 para "_" y '\0'
            new_symbol->id = (char *)malloc(id_len);
            snprintf(new_symbol->id, id_len, "%s_%s", instruction->id, context->nombre);
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

        symbol *evaluated_value = evaluate_expression(instruction->value, context);

        // Validar que la evaluación no retornó NULL
        if (!evaluated_value)
        {
            Error_exists("Expression evaluation failed", context->nombre, instruction);
            return;
        }

        evaluated_value = apply_casting_auto(evaluated_value, instruction->type, context);

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
        // Crear un nuevo buffer con suficiente espacio para id + "_" + nombre
        size_t id_len = strlen(instruction->id) + strlen(context->nombre) + 2; // +2 para "_" y '\0'
        new_symbol->id = (char *)malloc(id_len);
        snprintf(new_symbol->id, id_len, "%s_%s", instruction->id, context->nombre);
        new_symbol->environment = context->nombre;
        new_symbol->line = &(instruction->line);
        new_symbol->column = &(instruction->column);

        char bufferComment[128];
        snprintf(bufferComment, sizeof(bufferComment), "\n// Declaración de variable %s\n", new_symbol->id);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        arm_global_data->text = arm_text_add(arm_global_data->text, evaluated_value->text_section);
        arm_global_data->data = arm_data_add(arm_global_data->data, evaluated_value->data_section);
        arm_global_data->bss = arm_data_add(arm_global_data->bss, arm_declarate_bss(new_symbol->id, new_symbol->dataType));

        {

            char *register_type = "x";
            if (strcmp(new_symbol->dataType, "DOUBLE") == 0 || strcmp(new_symbol->dataType, "FLOAT") == 0)
                register_type = "d";

            char buffer[128];

            snprintf(buffer, sizeof(buffer), "ldr x1, =%s\n", new_symbol->id);
            arm_global_data->text = arm_text_add(arm_global_data->text, buffer);

            snprintf(buffer, sizeof(buffer), "str %s%d, [x1]\n\n", register_type, evaluated_value->num_register);
            arm_global_data->text = arm_text_add(arm_global_data->text, buffer);
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
        char *original_id = strdup(instruction->id);

        while (ctx)
        {

            char new_id[256]; // Ajusta el tamaño según sea necesario
            snprintf(new_id, sizeof(new_id), "%s_%s", original_id, ctx->nombre);

            if (SearchID(ctx->symbols_context, new_id))
            {
                symbol *sym_to_update = SearchSymbol(ctx->symbols_context, new_id);

                if (evaluated_assign->type && strcmp(evaluated_assign->type, "VECTOR") == 0)
                {

                    sym_to_update->vectorValues = evaluated_assign->vectorValues;
                    sym_to_update->value = evaluated_assign->value;
                    char bufferComment[128];
                    snprintf(bufferComment, sizeof(bufferComment), "\n// reasignacion de vector con add %s\n", instruction->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    snprintf(bufferComment, sizeof(bufferComment), "adrp x2, %s\n", sym_to_update->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    snprintf(bufferComment, sizeof(bufferComment), "add x2, x2, :lo12:%s\n", sym_to_update->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    snprintf(bufferComment, sizeof(bufferComment), "adr x3, %s_length\n", sym_to_update->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    arm_global_data->text = arm_text_add(arm_global_data->text, evaluated_assign->text_section);
                    arm_global_data->data = arm_data_add(arm_global_data->data, evaluated_assign->data_section);

                    if (strcmp(evaluated_assign->dataType, "STRING") == 0)
                    {
                        snprintf(bufferComment, sizeof(bufferComment), "bl append_to_string_array");
                    }
                    else
                    {
                        snprintf(bufferComment, sizeof(bufferComment), "bl append_to_array_integer");
                    }

                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    return;
                }

                if (strcmp(sym_to_update->type, "VECTOR") == 0 && instruction->IndexVector)
                {
                    instruction->IndexVector->num_register = 2;
                    symbol *index_eval = evaluate_expression(instruction->IndexVector, context);

                    if (index_eval == NULL || strcmp(index_eval->dataType, "INTEGER") != 0)
                    {
                        fprintf(stderr, "Error: evaluate_expression returned NULL or not is INTEGER for vector index\n");
                        return;
                    }

                    arm_global_data->text = arm_text_add(arm_global_data->text, index_eval->text_section);
                    arm_global_data->data = arm_data_add(arm_global_data->data, index_eval->data_section);

                    // Obtener puntero directo al elemento del vector
                    symbol **vector_element_ptr = get_VectorElementPointer(ctx, index_eval, sym_to_update->vectorValues);

                    if (!vector_element_ptr)
                        return Error_exists("Vector index must be INTEGER or out of bounds", ctx->nombre, instruction);

                    symbol *vector_element = *vector_element_ptr;

                    // Modificar directamente el valor en el vector
                    vector_element->value = evaluated_assign->value;

                    arm_global_data->text = arm_text_add(arm_global_data->text, evaluated_assign->text_section);
                    arm_global_data->data = arm_data_add(arm_global_data->data, evaluated_assign->data_section);

                    char bufferComment[128];
                    snprintf(bufferComment, sizeof(bufferComment), "\n// Asignación de vector %s[%s]\n", sym_to_update->id, index_eval->value);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    snprintf(bufferComment, sizeof(bufferComment), "\n// Carga de variable %s de tipo %s\n", sym_to_update->id, sym_to_update->dataType);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    snprintf(bufferComment, sizeof(bufferComment), "adrp   x1, %s\n", sym_to_update->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    snprintf(bufferComment, sizeof(bufferComment), "add    x1, x1, :lo12:%s\n", sym_to_update->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    if (strcmp(sym_to_update->dataType, "INTEGER") == 0 || strcmp(sym_to_update->dataType, "BOOLEAN") == 0)
                    {
                        snprintf(bufferComment, sizeof(bufferComment), "str    w%d, [x1, x%d, lsl #2]\n", sym_to_update->num_register, index_eval->num_register);
                        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
                    }
                    else if (strcmp(sym_to_update->dataType, "DOUBLE") == 0 || strcmp(sym_to_update->dataType, "FLOAT") == 0)
                    {
                        snprintf(bufferComment, sizeof(bufferComment), "str    d%d, [x1, x%d, lsl #3]\n", sym_to_update->num_register, index_eval->num_register);
                        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
                    }
                    else if (strcmp(sym_to_update->dataType, "CHARACTER") == 0)
                    {
                        snprintf(bufferComment, sizeof(bufferComment), "strb    w%d, [x1, x%d, lsl #0]\n", sym_to_update->num_register, index_eval->num_register);
                        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
                    }
                    else if (strcmp(sym_to_update->dataType, "STRING") == 0)
                    {
                        snprintf(bufferComment, sizeof(bufferComment), "str    x%d, [x1, x%d, lsl #3]\n", sym_to_update->num_register, index_eval->num_register);
                        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
                    }

                    // Actualizar la representación string del vector completo
                    sym_to_update->value = printVector(sym_to_update->vectorValues);
                    return;
                }

                if (strcmp(sym_to_update->type, "MATRIX") == 0 && instruction->IndexMatrix)
                {
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

                char bufferComment[128];
                snprintf(bufferComment, sizeof(bufferComment), "\n// Asignación de variable %s\n", sym_to_update->id);

                arm_global_data->text = arm_text_add(arm_global_data->text, evaluated_value->text_section);
                arm_global_data->data = arm_data_add(arm_global_data->data, evaluated_value->data_section);

                char *register_type = "w";
                if (strcmp(sym_to_update->dataType, "DOUBLE") == 0 || strcmp(sym_to_update->dataType, "FLOAT") == 0)
                    register_type = "d";
                else if (strcmp(sym_to_update->dataType, "STRING") == 0)
                    register_type = "x";

                if (evaluated_value->num_register != 0)
                {
                    snprintf(bufferComment, sizeof(bufferComment), "\n// Asignación de variable %s\n", sym_to_update->id);
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                    char buffer[128];
                    snprintf(buffer, sizeof(buffer), "mov    %s0, %s%d\n", register_type, register_type, evaluated_value->num_register);
                    arm_global_data->text = arm_text_add(arm_global_data->text, buffer);
                }

                char buffer[128];
                snprintf(buffer, sizeof(buffer), "ldr x1, =%s\n", sym_to_update->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, buffer);

                snprintf(buffer, sizeof(buffer), "str %s0, [x1]\n\n", register_type);
                arm_global_data->text = arm_text_add(arm_global_data->text, buffer);

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
        instruction->value->num_register = 1;

        char bufferComment[128];
        snprintf(bufferComment, sizeof(bufferComment), "\n// Instrucción de impresión\n");
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

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

        char bufferArm[128];

        if (strcmp(print_value->dataType, "STRING") == 0)
        {
            char *processed_string = process_escape_sequences(print_value->value);

            {
                arm_global_data->text = arm_text_add(arm_global_data->text, print_value->text_section);
                arm_global_data->data = arm_data_add(arm_global_data->data, print_value->data_section);

                if (print_value->num_register == 0)
                {
                    snprintf(bufferArm, sizeof(bufferArm), "mov x1, x0\n");
                    arm_global_data->text = arm_text_add(arm_global_data->text, bufferArm);
                }
            }

            printf("%s\n", processed_string);
        }
        else
        {

            arm_global_data->text = arm_text_add(arm_global_data->text, print_value->text_section);
            arm_global_data->data = arm_data_add(arm_global_data->data, print_value->data_section);

            if (print_value->num_register == 0)
            {
                snprintf(bufferArm, sizeof(bufferArm), "mov x1, x0\n");
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferArm);
            }

            printf("%s\n", print_value->value);
        }

        snprintf(bufferArm, sizeof(bufferArm), "adr x0, print\n");
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferArm);
        arm_global_data->text = arm_text_add(arm_global_data->text, "bl printf\n\n");

        break;
    }
    case IF_STATEMENT:
    {

        Expression *condition = instruction->ifData->condition;

        //* if
        InstruccionList *if_block = instruction->ifData->block;

        //* else
        InstruccionList *else_block = instruction->ifData->elseBlock;

        //* else if
        IfNodeList *else_ifs = instruction->ifData->elseIfs;
        IfNode *curr_node = else_ifs ? else_ifs->head : NULL;

        condition->num_register = 0;
        symbol *if_condition_value = evaluate_expression(condition, context);
        if (strcmp(if_condition_value->dataType, "UNDEFINED") == 0)
            return Error_exists(if_condition_value->value, context->nombre, instruction);

        bool condition_value = boolean_value(if_condition_value->value);

        Context *ctx_if = calloc(1, sizeof(Context));
        ctx_if->after = context;
        ctx_if->symbols_context = Symbol_table_create();
        ctx_if->nombre = "If";

        arm_global_data->text = arm_text_add(arm_global_data->text, if_condition_value->text_section);
        arm_global_data->data = arm_data_add(arm_global_data->data, if_condition_value->data_section);
        arm_global_data->count_if++;
        char bufferComment[128];
        snprintf(bufferComment, sizeof(bufferComment), "\n// Instrucción IF %d\n", arm_global_data->count_if);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        char if_label[32];
        if (curr_node != NULL)
        {
            snprintf(if_label, sizeof(if_label), "cbz w%d, elseif_%d\n", if_condition_value->num_register, arm_global_data->count_elseif);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);
        }
        else if (else_block != NULL)
        {
            snprintf(if_label, sizeof(if_label), "cbz w%d, else_%d\n", if_condition_value->num_register, arm_global_data->count_else);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);
        }
        else
        {
            snprintf(if_label, sizeof(if_label), "cbz w%d, end_if_%d\n", if_condition_value->num_register, arm_global_data->count_if);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);
        }

        char end_if_label[32];

        InstruccionNode *curr = if_block->head;
        while (curr)
        {
            semantic_analysis_execute(curr->instr, ctx_if);
            if (strcmp(curr->instr->InstType, "RETURN") == 0)
                break;
            curr = curr->next;
        }

        //* Fin del if
        snprintf(if_label, sizeof(if_label), "b end_if_%d\n", arm_global_data->count_if);
        arm_global_data->text = arm_text_add(arm_global_data->text, if_label);

        //* Inicio else ifs
        while (curr_node)
        {

            snprintf(if_label, sizeof(if_label), "\n// ELSE IF %d\n", arm_global_data->count_elseif);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);

            snprintf(if_label, sizeof(if_label), "elseif_%d:\n", arm_global_data->count_elseif);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);
            arm_global_data->count_elseif++;

            curr_node->IfData->condition->num_register = 0;
            symbol *elseif_condition = evaluate_expression(curr_node->IfData->condition, context);
            if (strcmp(elseif_condition->dataType, "UNDEFINED") == 0)
                return Error_exists(elseif_condition->value, context->nombre, instruction);

            bool elseif_condition_value = boolean_value(elseif_condition->value);

            arm_global_data->text = arm_text_add(arm_global_data->text, elseif_condition->text_section);
            arm_global_data->data = arm_data_add(arm_global_data->data, elseif_condition->data_section);

            if (curr_node != NULL && curr_node->next == NULL && else_block == NULL)
                snprintf(if_label, sizeof(if_label), "cbz w%d, end_if_%d\n", elseif_condition->num_register, arm_global_data->count_if);
            else if (curr_node != NULL && curr_node->next == NULL && else_block != NULL)
                snprintf(if_label, sizeof(if_label), "cbz w%d, else_%d\n", elseif_condition->num_register, arm_global_data->count_else);
            else
                snprintf(if_label, sizeof(if_label), "cbz w%d, elseif_%d\n", elseif_condition->num_register, arm_global_data->count_elseif);

            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);

            InstruccionNode *curr = curr_node->IfData->block->head;
            while (curr)
            {
                semantic_analysis_execute(curr->instr, ctx_if);
                if (strcmp(curr->instr->InstType, "RETURN") == 0)
                {
                    break;
                }

                curr = curr->next;
            }

            //* Fin de un else if
            snprintf(if_label, sizeof(if_label), "b end_if_%d\n", arm_global_data->count_if);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);

            curr_node = curr_node->next;
        }

        if (else_block)
        {
            snprintf(if_label, sizeof(if_label), "\n// ELSE%d\n", arm_global_data->count_elseif);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);

            //* Inicio else
            snprintf(if_label, sizeof(if_label), "else_%d:\n", arm_global_data->count_else);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);
            arm_global_data->count_else++;

            InstruccionNode *curr = else_block->head;
            while (curr)
            {
                if (strcmp(curr->instr->InstType, "RETURN") == 0)
                    break;

                semantic_analysis_execute(curr->instr, ctx_if);
                curr = curr->next;
            }

            //* Fin de else
            snprintf(if_label, sizeof(if_label), "b end_if_%d\n", arm_global_data->count_if);
            arm_global_data->text = arm_text_add(arm_global_data->text, if_label);
        }

        snprintf(end_if_label, sizeof(end_if_label), "end_if_%d:\n", arm_global_data->count_if);
        arm_global_data->text = arm_text_add(arm_global_data->text, end_if_label);

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

        char bufferComment[128];
        snprintf(bufferComment, sizeof(bufferComment), "\n// Instrucción SWITCH\n");
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        if (strcmp(switch_value->dataType, "UNDEFINED") == 0)
            return Error_exists("ID no declarado en switch", context->nombre, instruction);

        Expression *exp_condition = (Expression *)calloc(1, sizeof(Expression));
        exp_condition->type = "EQUALS";
        exp_condition->value = strdup("==");
        exp_condition->left = switch_id_value;

        CaseNode *curr_case = instruction->switchData->cases ? instruction->switchData->cases->head : NULL;

        while (curr_case)
        {

            exp_condition->right = curr_case->caseData->condition;

            snprintf(bufferComment, sizeof(bufferComment), "// SWITCH CASE\n");
            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

            snprintf(bufferComment, sizeof(bufferComment), "switch_case_%d:\n", arm_global_data->count_case);
            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
            arm_global_data->count_case++;

            symbol *case_condition = evaluate_expression(exp_condition, context);

            arm_global_data->data = arm_data_add(arm_global_data->data, case_condition->data_section);
            arm_global_data->text = arm_text_add(arm_global_data->text, case_condition->text_section);

            if (curr_case != NULL && curr_case->next == NULL && instruction->switchData->defaultCase != NULL)
            {
                snprintf(bufferComment, sizeof(bufferComment), "cbz w%d, switch_default_%d\n", case_condition->num_register, arm_global_data->count_case);
            }
            else
            {
                snprintf(bufferComment, sizeof(bufferComment), "cbz w%d, switch_case_%d\n", case_condition->num_register, arm_global_data->count_case);
            }

            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

            bool case_condition_bool = boolean_value(case_condition->value);

            ctx_switch->nombre = "Case";

            InstruccionNode *curr_instr = curr_case->caseData->block->head;
            while (curr_instr)
            {
                if (strcmp(curr_instr->instr->InstType, "RETURN") == 0)
                    break;

                semantic_analysis_execute(curr_instr->instr, ctx_switch);
                curr_instr = curr_instr->next;
            }

            snprintf(bufferComment, sizeof(bufferComment), "b end_switch_%d\n", arm_global_data->count_switch);
            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

            curr_case = curr_case->next;
        }

        if (instruction->switchData->defaultCase)
        {
            snprintf(bufferComment, sizeof(bufferComment), "// DEFAULT CASE\n");
            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
            snprintf(bufferComment, sizeof(bufferComment), "switch_default_%d: \n", arm_global_data->count_case);
            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

            arm_global_data->count_case++;
            ctx_switch->nombre = "Default";

            InstruccionNode *curr_instr = instruction->switchData->defaultCase->head;
            while (curr_instr)
            {
                semantic_analysis_execute(curr_instr->instr, ctx_switch);
                curr_instr = curr_instr->next;
            }

            snprintf(bufferComment, sizeof(bufferComment), "b end_switch_%d\n", arm_global_data->count_switch);
            arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
        }

        snprintf(bufferComment, sizeof(bufferComment), "\nend_switch_%d:\n", arm_global_data->count_switch);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
        arm_global_data->count_switch++;

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

        char ctx_name[32];
        snprintf(ctx_name, sizeof(ctx_name), "While%d", arm_global_data->count_while);
        ctx_while->nombre = strdup(ctx_name);

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

        //* ARM WHILE
        char bufferComment[128];
        snprintf(bufferComment, sizeof(bufferComment), "\n// Instrucción WHILE %d\n", arm_global_data->count_while);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        snprintf(bufferComment, sizeof(bufferComment), "while_%d:\n", arm_global_data->count_while);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        arm_global_data->text = arm_text_add(arm_global_data->text, evaluated_while->text_section);
        arm_global_data->data = arm_data_add(arm_global_data->data, evaluated_while->data_section);
        snprintf(bufferComment, sizeof(bufferComment), "cbz w%d, end_while_%d\n", evaluated_while->num_register, arm_global_data->count_while);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);
        InstruccionNode *curr = while_block->head;

        while (curr)
        {
            semantic_analysis_execute(curr->instr, ctx_while);
            curr = curr->next;
        }

        if (ctx_while->break_instruction)
            break;

        snprintf(bufferComment, sizeof(bufferComment), "b while_%d\n", arm_global_data->count_while);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        snprintf(bufferComment, sizeof(bufferComment), "end_while_%d:\n", arm_global_data->count_while);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        curr = while_block->head;
        while (curr)
        {
            semantic_analysis_execute(curr->instr, ctx_while);
            curr = curr->next;
        }

        arm_global_data->count_while++;

        Symbol_table_insertContext(SymbolTable_General, ctx_while->symbols_context);
        break;
    }
    case FOREACH_STATEMENT:
    {
        Context *ctx_foreach = calloc(1, sizeof(Context));
        ctx_foreach->after = context;
        ctx_foreach->symbols_context = Symbol_table_create();
        char ctx_name[32];
        snprintf(ctx_name, sizeof(ctx_name), "Foreach%d", arm_global_data->count_foreach);
        ctx_foreach->nombre = strdup(ctx_name);
        char *orignal_id = strdup(instruction->forEachData->array);
        Context *search_ctx = context;
        while (search_ctx)
        {
            char search_id[256];
            snprintf(search_id, sizeof(search_id), "%s_%s", orignal_id, search_ctx->nombre);

            if (SearchID(search_ctx->symbols_context, search_id))
            {
                symbol *array_symbol = SearchSymbol(search_ctx->symbols_context, search_id);

                if (strcmp(array_symbol->type, "VECTOR") != 0)
                    return Error_exists("FOREACH solo soporta vectores", context->nombre, instruction);

                VectorList *vector_values = array_symbol->vectorValues;
                if (!vector_values || !vector_values->head)
                {
                    fprintf(stderr, "Vector vacío o inválido para foreach\n");
                    return;
                }

                VectorNode *vector_node = vector_values->head;
                fprintf(stderr, "DEBUG: Foreach - Procesando elemento del vector\n");

                symbol *loop_symbol = (symbol *)calloc(1, sizeof(symbol));
                loop_symbol->id = strcat(strcat(instruction->forEachData->item, "_"), ctx_foreach->nombre);
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

                char bufferComment[128];
                snprintf(bufferComment, sizeof(bufferComment), "\n// Instrucción FOREACH\n");
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "adr x21, %s_length \n", array_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "ldr w21, [x21]\n");
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "mov x22, #0\n");
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "adrp x19, %s\n", array_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "add x19, x19, :lo12:%s\n", array_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "foreach_%d:\n", arm_global_data->count_foreach);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "cmp x22, x21\n");
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "bge end_foreach_%d\n", arm_global_data->count_foreach);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                if (strcmp(array_symbol->dataType, "INTEGER") == 0 || strcmp(array_symbol->dataType, "BOOLEAN") == 0)
                    snprintf(bufferComment, sizeof(bufferComment), "ldr    w20, [x19, x22, lsl #2]\n");
                else if (strcmp(array_symbol->dataType, "DOUBLE") == 0 || strcmp(array_symbol->dataType, "FLOAT") == 0)
                    snprintf(bufferComment, sizeof(bufferComment), "ldr    d20, [x19, x22, lsl #3]\n");
                else if (strcmp(array_symbol->dataType, "CHARACTER") == 0)
                    snprintf(bufferComment, sizeof(bufferComment), "ldrb    w20, [x19, x22, lsl #0]\n");
                else if (strcmp(array_symbol->dataType, "STRING") == 0)
                    snprintf(bufferComment, sizeof(bufferComment), "ldr    x20, [x19, x22, lsl #3]\n");
                arm_global_data->text = arm_data_add(arm_global_data->text, bufferComment);

                arm_global_data->bss = arm_data_add(arm_global_data->bss, arm_declarate_bss(loop_symbol->id, loop_symbol->dataType));

                char *register_type = "w";
                if (strcmp(loop_symbol->dataType, "DOUBLE") == 0 || strcmp(loop_symbol->dataType, "FLOAT") == 0)
                    register_type = "d";
                else if (strcmp(loop_symbol->dataType, "STRING") == 0)
                    register_type = "x";

                //* ARM FOREACH STORE LOOP VARIABLE
                char buffer[128];
                snprintf(buffer, sizeof(buffer), "ldr x1, =%s\n", loop_symbol->id);
                arm_global_data->text = arm_text_add(arm_global_data->text, buffer);

                snprintf(buffer, sizeof(buffer), "str %s20, [x1]\n", register_type);
                arm_global_data->text = arm_text_add(arm_global_data->text, buffer);

                InstruccionNode *curr = instruction->forEachData->block->head;

                while (curr)
                {
                    semantic_analysis_execute(curr->instr, ctx_foreach);
                    curr = curr->next;
                }

                snprintf(bufferComment, sizeof(bufferComment), " add x22, x22, #1\n");
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "b foreach_%d\n", arm_global_data->count_foreach);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                snprintf(bufferComment, sizeof(bufferComment), "end_foreach_%d:\n", arm_global_data->count_foreach);
                arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

                arm_global_data->count_foreach++;

                return;
            }

            fprintf(stderr, "DEBUG: Foreach - Buscando en contexto: %s\n", search_ctx->nombre);
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

        char ctx_name[32];
        snprintf(ctx_name, sizeof(ctx_name), "For%d", arm_global_data->count_for);

        ctx_for->nombre = strdup(ctx_name);

        semantic_analysis_execute(init, ctx_for);

        symbol *evaluated_for = evaluate_expression(condition, ctx_for);
        bool condition_value = boolean_value(evaluated_for->value);

        //* ARM FOR
        int for_register = arm_global_data->count_for;
        arm_global_data->count_for++;
        char bufferComment[128];
        snprintf(bufferComment, sizeof(bufferComment), "\n// Instrucción FOR %d\n", for_register);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        snprintf(bufferComment, sizeof(bufferComment), "for_%d:\n", for_register);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        arm_global_data->text = arm_text_add(arm_global_data->text, evaluated_for->text_section);
        arm_global_data->data = arm_data_add(arm_global_data->data, evaluated_for->data_section);

        snprintf(bufferComment, sizeof(bufferComment), "cbz w%d, end_for_%d\n", evaluated_for->num_register, for_register);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        InstruccionNode *curr = for_block->head;
        while (curr)
        {
            semantic_analysis_execute(curr->instr, ctx_for);
            curr = curr->next;
        }

        // Ejecutar actualización
        snprintf(bufferComment, sizeof(bufferComment), "update_for_%d:\n", for_register);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        semantic_analysis_execute(update, ctx_for);
        symbol *updated_condition = evaluate_expression(condition, ctx_for);
        condition_value = boolean_value(updated_condition->value);

        arm_global_data->text = arm_text_add(arm_global_data->text, updated_condition->text_section);
        arm_global_data->data = arm_data_add(arm_global_data->data, updated_condition->data_section);

        snprintf(bufferComment, sizeof(bufferComment), "b for_%d\n", for_register);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

        snprintf(bufferComment, sizeof(bufferComment), "end_for_%d:\n", for_register);
        arm_global_data->text = arm_text_add(arm_global_data->text, bufferComment);

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

            char arm_buffer[128];

            if (strncmp(ctx->nombre, "For", 3) == 0)
            {
                found_loop = true;
                snprintf(arm_buffer, sizeof(arm_buffer), "// break For: %s\n", ctx->nombre);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                snprintf(arm_buffer, sizeof(arm_buffer), "b end_for_%d\n", arm_global_data->count_for - 1);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                break;
            }
            else if (strncmp(ctx->nombre, "While", 5) == 0)
            {
                found_loop = true;
                snprintf(arm_buffer, sizeof(arm_buffer), "// break While: %s\n", ctx->nombre);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                snprintf(arm_buffer, sizeof(arm_buffer), "b end_while_%d\n", arm_global_data->count_while);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                break;
            }
            else if (strncmp(ctx->nombre, "Switch", 6) == 0)
            {
                found_loop = true;
                break;
            }
            else if (strncmp(ctx->nombre, "Foreach", 7) == 0)
            {
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
            char arm_buffer[128];

            if (strncmp(ctx->nombre, "For", 3) == 0)
            {
                found_loop = true;
                snprintf(arm_buffer, sizeof(arm_buffer), "// continue For: %s\n", ctx->nombre);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                snprintf(arm_buffer, sizeof(arm_buffer), "b update_for_%d\n", arm_global_data->count_for - 1);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                break;
            }
            else if (strncmp(ctx->nombre, "While", 5) == 0)
            {
                found_loop = true;
                snprintf(arm_buffer, sizeof(arm_buffer), "// continue While: %s\n", ctx->nombre);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                snprintf(arm_buffer, sizeof(arm_buffer), "b while_%d\n", arm_global_data->count_while);
                arm_global_data->text = arm_text_add(arm_global_data->text, arm_buffer);

                break;
            }
            else if (strncmp(ctx->nombre, "Switch", 6) == 0)
            {
                found_loop = true;
                break;
            }
            else if (strncmp(ctx->nombre, "Foreach", 7) == 0)
            {
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
        char block_name[256];
        snprintf(block_name, sizeof(block_name), "Block%d", arm_global_data->count_block);
        ctx_block->nombre = block_name;

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
