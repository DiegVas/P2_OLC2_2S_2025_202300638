#include "semantic.h"
#include "../ARM/arm.h"
#include <math.h>
#include <sys/types.h>

char *remove_last_instruction(const char *text)
{
    if (!text)
        return NULL;
    size_t len = strlen(text);
    if (len == 0)
        return strdup("");

    // Elimina saltos de línea al final
    while (len > 0 && (text[len - 1] == '\n' || text[len - 1] == '\r'))
    {
        len--;
    }
    if (len == 0)
        return strdup("\n");

    // Busca el salto de línea anterior a la última instrucción (bucle manual)
    ssize_t last_nl_pos = -1;
    for (ssize_t i = len - 1; i >= 0; i--)
    {
        if (text[i] == '\n')
        {
            last_nl_pos = i;
            break;
        }
    }

    if (last_nl_pos == -1)
        return strdup("\n"); // Solo hay una instrucción

    size_t new_len = last_nl_pos + 1; // +1 para incluir el salto de línea
    char *result = (char *)calloc(new_len + 1, sizeof(char));
    strncpy(result, text, new_len);
    result[new_len] = '\0';

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
        return false;

    if (!indices->head)
        return false;

    ExpressionNode *current_index = indices->head;
    if (!current_index || !current_index->expr)
        return false;

    // Evaluar el primer índice
    symbol *index_symbol = evaluate_expression(current_index->expr, context);
    if (!index_symbol)
        return false;

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

int count_commas(const char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ',')
        {
            count++;
        }
    }
    return count;
}