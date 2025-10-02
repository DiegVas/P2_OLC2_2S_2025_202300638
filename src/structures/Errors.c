#include "parser.h"

ErrorList *createErrorList()
{
    ErrorList *list = malloc(sizeof(ErrorList));
    list->head = NULL;
    return list;
}

void insertError(ErrorList *list, Error *error)
{
    ErrorNode *newNode = malloc(sizeof(ErrorNode));
    newNode->Error = error;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        ErrorNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void ErrorList_destroy(ErrorList *list)
{
    ErrorNode *current = list->head;
    while (current != NULL)
    {
        ErrorNode *next = current->next;
        free(current->Error);
        free(current);
        current = next;
    }
    free(list);
}