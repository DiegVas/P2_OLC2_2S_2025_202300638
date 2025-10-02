#include "parser.h"

IfNodeList *createIfNodeList()
{
    IfNodeList *list = malloc(sizeof(IfNodeList));
    list->head = NULL;
    return list;
}

void insertIfNode(IfNodeList *list, IfData *ifData)
{
    IfNode *newNode = malloc(sizeof(IfNode));
    newNode->IfData = ifData;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        IfNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void IfNodeList_destroy(IfNodeList *list)
{
    IfNode *current = list->head;
    while (current != NULL)
    {
        IfNode *next = current->next;
        free(current->IfData);
        free(current);
        current = next;
    }
    free(list);
}