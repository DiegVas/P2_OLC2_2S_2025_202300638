#include "parser.h"

ExpressionList *create_expression_list()
{
    ExpressionList *list = (ExpressionList *)calloc(1, sizeof(ExpressionList));
    list->head = NULL;
    return list;
}

void ExpressionList_add(ExpressionList *list, Expression *expr)
{
    ExpressionNode *newNode = (ExpressionNode *)calloc(1, sizeof(ExpressionNode));
    newNode->expr = expr;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        ExpressionNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Función para obtener el tamaño de la lista
int ExpressionList_size(ExpressionList *list)
{
    if (list == NULL || list->head == NULL)
        return 0;

    int count = 0;
    ExpressionNode *current = list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Función para obtener una expresión por índice
Expression *ExpressionList_get(ExpressionList *list, int index)
{
    if (list == NULL || list->head == NULL || index < 0)
        return NULL;

    ExpressionNode *current = list->head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index)
    {
        current = current->next;
        currentIndex++;
    }

    return (current != NULL) ? current->expr : NULL;
}