#include "../structures/parser.h"
#include <stdio.h>

// Forward declarations
typedef struct ASTNode ASTNode;
typedef struct ASTList ASTList;

typedef struct ASTVal
{
    char *id;
    char *value;
    ASTList *children;
} ASTVal;

struct ASTNode
{
    ASTVal *value;
    ASTNode *next;
};

struct ASTList
{
    ASTNode *head;
};

void generate_simple_ast(InstruccionList *list);
ASTVal *create_ast_node(const char *value);
ASTVal *ast_execute(Instruccion *instr);
void add_child(ASTVal *parent, ASTVal *child);
ASTVal *ast_evaluate(Expression *expr);