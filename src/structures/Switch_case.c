#include "parser.h"

CaseNodeList *CaseNodeList_create()
{
    CaseNodeList *list = (CaseNodeList *)malloc(sizeof(CaseNodeList));
    list->head = NULL;
    return list;
}

void CaseNodeList_destroy(CaseNodeList *list)
{
    CaseNode *current = list->head;
    while (current != NULL)
    {
        CaseNode *temp = current;
        current = current->next;
        free(temp->caseData->condition);
        free(temp->caseData);
        free(temp);
    }
    free(list);
}

void CaseNodeList_add(CaseNodeList *list, CaseData *caseData)
{
    CaseNode *newNode = (CaseNode *)malloc(sizeof(CaseNode));
    newNode->caseData = caseData;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        CaseNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}