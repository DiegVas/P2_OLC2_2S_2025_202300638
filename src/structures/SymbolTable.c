#include "parser.h"
#include <stdbool.h>
#include <string.h>

symbol_table *Symbol_table_create()
{
    symbol_table *table = (symbol_table *)malloc(sizeof(symbol_table));
    table->head = NULL;
    return table;
}

bool SearchID(symbol_table *table, char *id)
{

    symbol_node *current = table->head;
    while (current != NULL)
    {
        if (strcmp(current->data->id, id) == 0)
        {
            // fprintf(stderr, "ID encontrado en la tabla de símbolos: %s\n", id);
            return true; // ID encontrado
        }
        current = current->next;
    }
    return false;
}

symbol *SearchSymbol(symbol_table *table, char *id)
{
    symbol_node *current = table->head;
    while (current != NULL)
    {
        if (strcmp(current->data->id, id) == 0)
        {
            return current->data; // ID encontrado
        }
        current = current->next;
    }
    return NULL; // No encontrado
}

void Symbol_table_insert(symbol_table *table, symbol *sym)
{
    symbol_node *new_node = (symbol_node *)malloc(sizeof(symbol_node));
    new_node->data = sym;
    new_node->next = table->head;
    table->head = new_node;
}

void Symbol_table_insertContext(symbol_table *global_table, symbol_table *new_context)
{

    symbol_node *current = new_context->head;
    while (current != NULL)
    {
        Symbol_table_insert(global_table, current->data);
        current = current->next;
    }
}

// Función auxiliar para copiar VectorList
VectorList *copy_VectorList(VectorList *original)
{
    if (!original)
        return NULL;

    VectorList *copy = VectorList_create();
    VectorNode *current = original->head;

    while (current)
    {
        if (current->value)
        {
            VectorList_addSym(copy, copy_symbol(current->value));
        }
        else if (current->exprData)
        {
            VectorList_addExp(copy, current->exprData); // Asumimos que Expression no necesita copia profunda
        }
        current = current->next;
    }

    return copy;
}

// Función auxiliar para copiar MatrixList
MatrixList *copy_MatrixList(MatrixList *original)
{
    if (!original)
        return NULL;

    MatrixList *copy = MatrixList_create();
    matrixNode *current = original->head;

    while (current)
    {
        VectorList *vector_copy = copy_VectorList(current->vector);
        MatrixList_add(copy, vector_copy);
        current = current->next;
    }

    return copy;
}

// Función auxiliar para copiar List
List *copy_List(List *original)
{
    if (!original)
        return NULL;

    List *copy = List_create();
    ListNode *current = original->head;

    while (current)
    {
        List_add(copy, current->listData); // Asumimos que ListData no necesita copia profunda
        current = current->next;
    }

    return copy;
}

// Función principal para copiar un símbolo
symbol *copy_symbol(symbol *original)
{
    if (!original)
        return NULL;

    symbol *copy = (symbol *)calloc(1, sizeof(symbol));

    // Copiar cadenas
    copy->dataType = original->dataType ? strdup(original->dataType) : NULL;
    copy->type = original->type ? strdup(original->type) : NULL;
    copy->subType = original->subType ? strdup(original->subType) : NULL;
    copy->environment = original->environment ? strdup(original->environment) : NULL;
    copy->value = original->value ? strdup(original->value) : NULL;
    copy->id = original->id ? strdup(original->id) : NULL;

    // Copiar estructuras complejas
    copy->arrayValues = copy_List(original->arrayValues);
    copy->vectorValues = copy_VectorList(original->vectorValues);
    copy->matrixValues = copy_MatrixList(original->matrixValues);

    // Copiar valores primitivos
    copy->dimensions = original->dimensions;

    // Copiar punteros a enteros (si son válidos)
    if (original->line)
    {
        copy->line = (int *)malloc(sizeof(int));
        *(copy->line) = *(original->line);
    }

    if (original->column)
    {
        copy->column = (int *)malloc(sizeof(int));
        *(copy->column) = *(original->column);
    }

    return copy;
}

void Symbol_table_destroy(symbol_table *table)
{
    symbol_node *current = table->head;
    while (current != NULL)
    {
        symbol_node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(table);
}