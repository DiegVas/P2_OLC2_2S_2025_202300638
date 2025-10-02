#include "ast.h"
#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaración de función
char *generar_uuid();

ASTList *create_ast_list()
{
    ASTList *list = (ASTList *)malloc(sizeof(ASTList));
    list->head = NULL;
    return list;
}

ASTVal *create_ast_value(const char *value)
{
    ASTVal *ast_value = (ASTVal *)malloc(sizeof(ASTVal));
    ast_value->id = generar_uuid();
    ast_value->value = strdup(value);
    ast_value->children = create_ast_list();
    return ast_value;
}

char *generar_uuid()
{
    uuid_t uuid;
    char uuid_str[37];
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);
    return strdup(uuid_str);
}
