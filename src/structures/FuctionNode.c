#include "parser.h"

paramsList *createParamsList()
{
    paramsList *list = (paramsList *)malloc(sizeof(paramsList));
    list->head = NULL;
    return list;
}

void addParam(paramsList *list, char *type, char *id)
{
    params *newParam = (params *)malloc(sizeof(params));
    newParam->type = type;
    newParam->id = id;
    newParam->next = NULL;

    if (list->head == NULL)
    {
        list->head = newParam;
    }
    else
    {
        params *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newParam;
    }
}