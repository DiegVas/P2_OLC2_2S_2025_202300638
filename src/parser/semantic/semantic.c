#include "semantic.h"
#include "../reports/ast.h"
Context *contextGlobal = NULL;

void semantic_analysis()
{

    extern InstruccionList *list_tokens;
    extern ErrorList *list_errors;
    extern symbol_table *SymbolTable_General;

    Symbol_table_destroy(SymbolTable_General);
    SymbolTable_General = Symbol_table_create();

    contextGlobal = malloc(sizeof(Context));
    contextGlobal->nombre = "Global";
    contextGlobal->symbols_context = Symbol_table_create();

    generate_simple_ast(list_tokens);

    InstruccionNode *curr = list_tokens->head;
    while (curr)
    {

        semantic_analysis_execute(curr->instr, contextGlobal);
        curr = curr->next;
    }

    Symbol_table_insertContext(SymbolTable_General, contextGlobal->symbols_context);
}
