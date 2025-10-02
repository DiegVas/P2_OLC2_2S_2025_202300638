#include "semantic.h"
#include "../structures/parser.h"

List *evaluate_list(List *list, Context *evaluateContext)
{
    List *evaluated_list = List_create();
    ListNode *current = list->head;

    while (current)
    {
        ListData *data = current->listData;
        if (data->listData)
        {
            data->listData = evaluate_list(data->listData, evaluateContext);
        }
        if (data->exprData)
        {
            symbol *da = evaluate_expression(data->exprData, evaluateContext);
            if (da != NULL)
            {
                data->symData = da;
                data->exprData = NULL; // Clear exprData after evaluation
            }
            else
            {
                fprintf(stderr, "Error: evaluate_expression returned NULL for list data\n");
                data->symData = NULL;
                data->exprData = NULL; // Clear exprData even on error
            }
        }

        List_add(evaluated_list, data);
        current = current->next;
    }

    return evaluated_list;
}

char *printArray(List *list)
{
    char *result = (char *)calloc(1024, sizeof(char));
    strcat(result, "[");

    ListNode *current = list->head;
    while (current)
    {
        ListData *data = current->listData;
        if (data->symData)
        {
            strcat(result, data->symData->value);
        }
        else if (data->listData)
        {
            char *nested_array_str = printArray(data->listData);
            strcat(result, nested_array_str);
            free(nested_array_str);
        }

        if (current->next)
        {
            strcat(result, ", ");
        }
        current = current->next;
    }

    strcat(result, "]");
    return result;
}

VectorList *evaluate_vector(char *dataType, VectorList *vec, Context *evaluateContext)
{
    VectorList *evaluated_vector = VectorList_create();
    VectorNode *current = vec->head;

    while (current)
    {
        if (current->exprData)
        {
            symbol *da = evaluate_expression(current->exprData, evaluateContext);
            if (da != NULL)
            {
                da = apply_casting_auto(da, dataType);
                current->value = da;
            }
            else
            {
                fprintf(stderr, "Error: evaluate_expression returned NULL\n");
                // Crear un símbolo por defecto o manejar el error
                current->value = NULL;
            }
            // Limpiar exprData después de procesarlo para evitar accesos inválidos
            current->exprData = NULL;
        }

        VectorList_addSym(evaluated_vector, current->value);
        current = current->next;
    }

    return evaluated_vector;
}

symbol **get_VectorElementPointer(Context *context, Expression *index_exp, VectorList *vector)
{
    symbol *index_access = evaluate_expression(index_exp, context);

    if (index_access == NULL)
    {
        fprintf(stderr, "Error: evaluate_expression returned NULL for vector index\n");
        return NULL;
    }

    if (strcmp(index_access->dataType, "INTEGER") != 0)
        return NULL;

    int index = atoi(index_access->value);

    VectorNode *curr = vector->head;
    int curr_index = 0;
    while (curr)
    {
        if (index == curr_index)
        {
            return &(curr->value);
        }
        curr = curr->next;
        curr_index++;
    }
    return NULL;
}

symbol **get_MatrixElementPointer(Context *context, Expression *row_exp, Expression *col_exp, MatrixList *matrix)
{
    symbol *row_access = evaluate_expression(row_exp, context);
    symbol *col_access = evaluate_expression(col_exp, context);

    if (row_access == NULL || col_access == NULL)
    {
        fprintf(stderr, "Error: evaluate_expression returned NULL for matrix indices\n");
        return NULL;
    }

    if (strcmp(row_access->dataType, "INTEGER") != 0 || strcmp(col_access->dataType, "INTEGER") != 0)
        return NULL;

    int row = atoi(row_access->value);
    matrixNode *curr_row = matrix->head;

    int curr_row_index = 0;
    while (curr_row)
    {
        if (row == curr_row_index)
        {

            symbol **curr_col = get_VectorElementPointer(context, col_exp, curr_row->vector);

            if (!curr_col)
                return NULL;

            return curr_col;
        }
        curr_row = curr_row->next;
        curr_row_index++;
    }
    return NULL;
}

symbol *get_VectorElement(Context *context, Expression *index_exp, char *id)
{
    symbol *index_access = evaluate_expression(index_exp, context);

    symbol *result = (symbol *)calloc(1, sizeof(symbol));

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
        if (SearchID(ctx_search->symbols_context, id))
        {
            symbol *sym = SearchSymbol(ctx_search->symbols_context, id);
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
            fprintf(stderr, "Accessed vector element: ID=%s, Index=%d, Type=%s, Value=%s\n",
                    id, index, found_symbol->dataType, found_symbol->value);
            return found_symbol;
        }

        ctx_search = ctx_search->after;
    }
}

char *printVector(VectorList *vec)
{
    char *result = (char *)calloc(1024, sizeof(char));
    strcat(result, "[");

    VectorNode *current = vec->head;
    while (current)
    {
        if (current->value && current->value->value)
        {
            strcat(result, current->value->value);
        }
        else if (current->exprData)
        {
            // Solo acceder a exprData si el puntero parece válido
            // Normalmente, exprData debería ser NULL después de la evaluación
            if (current->exprData != NULL &&
                current->exprData != (void *)0xbebebebebebebebe &&
                current->exprData->value != NULL)
            {
                strcat(result, current->exprData->value);
            }
            else
            {
                strcat(result, "UNDEFINED");
            }
        }
        else
        {
            strcat(result, "NULL");
        }

        if (current->next)
        {
            strcat(result, ", ");
        }
        current = current->next;
    }

    strcat(result, "]");
    return result;
}