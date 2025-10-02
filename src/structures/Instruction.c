// --- Estructura Instruccion ---
#include <stdlib.h>
#include "parser.h"

// Crear la lista
InstruccionList *InstruccionList_create()
{
    InstruccionList *list = (InstruccionList *)malloc(sizeof(InstruccionList));
    list->head = NULL;
    return list;
}

// Insertar instrucción al final
void InstruccionList_insert(InstruccionList *list, Instruccion *instr)
{
    InstruccionNode *node = (InstruccionNode *)malloc(sizeof(InstruccionNode));
    node->instr = instr;
    node->next = NULL;
    if (!list->head)
    {
        list->head = node;
    }
    else
    {
        InstruccionNode *curr = list->head;
        while (curr->next)
            curr = curr->next;
        curr->next = node;
    }
}

void InstruccionList_print(InstruccionList *list)
{
    InstruccionNode *curr = list->head;
    while (curr)
    {
        Instruccion *inst = curr->instr;
        if (inst)
        {
            fprintf(stderr, "Tipo: %s, ID: %s, DataType: %s, Línea: %d, Columna: %d\n",
                    inst->type ? inst->type : "NULL",
                    inst->id ? inst->id : "NULL",
                    inst->InstType ? inst->InstType : "NULL",
                    inst->line,
                    inst->column);

            fprintf(stderr, "Expresión: %s Valor: %s \n", inst->value->type, inst->value->value);
        }
        curr = curr->next;
    }
}

// Liberar lista
void InstruccionList_destroy(InstruccionList *list)
{
    InstruccionNode *curr = list->head;
    while (curr)
    {
        InstruccionNode *next = curr->next;
        // Aquí deberías liberar la instrucción si corresponde
        free(curr);
        curr = next;
    }
    free(list);
}