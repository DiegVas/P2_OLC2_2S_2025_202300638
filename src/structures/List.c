#include "parser.h"
#include <string.h>

//* Para vectores

VectorList *VectorList_create()
{
    VectorList *list = (VectorList *)malloc(sizeof(VectorList));
    list->head = NULL;
    return list;
}

void VectorList_addExp(VectorList *list, Expression *exprData)
{
    VectorNode *newNode = (VectorNode *)malloc(sizeof(VectorNode));
    newNode->exprData = exprData;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        VectorNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void VectorList_addSym(VectorList *list, symbol *sym)
{
    VectorNode *newNode = (VectorNode *)malloc(sizeof(VectorNode));
    newNode->value = sym;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        VectorNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//* Para matrices

void MatrixList_add(MatrixList *matrix, VectorList *vectorList)
{
    matrixNode *newNode = (matrixNode *)malloc(sizeof(matrixNode));
    newNode->vector = vectorList;
    newNode->next = NULL;

    if (matrix->head == NULL)
    {
        matrix->head = newNode;
    }
    else
    {
        matrixNode *current = matrix->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

MatrixList *MatrixList_create()
{
    MatrixList *list = (MatrixList *)malloc(sizeof(MatrixList));
    list->head = NULL;
    return list;
}

List *
List_create()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    return list;
}
void List_add(List *list, ListData *listData)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->listData = listData;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        ListNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void List_destroy(List *list)
{
    ListNode *current = list->head;
    while (current != NULL)
    {
        ListNode *temp = current;
        current = current->next;
        free(temp->listData->exprData);
        free(temp->listData);
        free(temp);
    }
    free(list);
}

// Función para crear una expresión UNDEFINED
Expression *create_undefined_expression(const char *dataType)
{
    Expression *expr = (Expression *)calloc(1, sizeof(Expression));
    expr->type = strdup(dataType);
    expr->value = strdup("UNDEFINED");
    expr->line = 0;
    expr->column = 0;
    expr->left = NULL;
    expr->right = NULL;
    expr->list = NULL;
    return expr;
}

// Función recursiva para crear listas multidimensionales
List *create_multidimensional_list(int *dimensions, int num_dimensions, int current_depth, const char *dataType)
{
    if (current_depth >= num_dimensions)
    {
        return NULL; // No más dimensiones
    }

    List *list = List_create();
    int current_dimension_size = dimensions[current_depth];

    for (int i = 0; i < current_dimension_size; i++)
    {
        ListData *listData = (ListData *)calloc(1, sizeof(ListData));

        if (current_depth == num_dimensions - 1)
        {
            // Última dimensión: crear expresiones UNDEFINED
            listData->exprData = create_undefined_expression(dataType);
            listData->symData = NULL;
            listData->listData = NULL;
        }
        else
        {
            // Dimensiones intermedias: crear sublistas recursivamente
            listData->exprData = NULL;
            listData->symData = NULL;
            listData->listData = create_multidimensional_list(dimensions, num_dimensions, current_depth + 1, dataType);
        }

        List_add(list, listData);
    }

    return list;
}

// Función wrapper para crear arreglos multidimensionales
List *create_multidimensional_array(int *dimensions, int num_dimensions, const char *dataType)
{
    if (!dimensions || num_dimensions <= 0)
    {
        return NULL;
    }

    printf("DEBUG: Creando arreglo multidimensional con %d dimensiones de tipo %s\n", num_dimensions, dataType);
    for (int i = 0; i < num_dimensions; i++)
    {
        printf("DEBUG: Dimensión %d: tamaño %d\n", i, dimensions[i]);
    }

    return create_multidimensional_list(dimensions, num_dimensions, 0, dataType);
}