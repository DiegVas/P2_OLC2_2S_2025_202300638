#include "semantic.h"
#include "../reports/ast.h"
#include "../ARM/arm.h"

Context *contextGlobal = NULL;

ARM_data *arm_global_data = NULL;

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

    arm_global_data = arm_data_create();

    generate_simple_ast(list_tokens);

    InstruccionNode *curr = list_tokens->head;
    while (curr)
    {

        semantic_analysis_execute(curr->instr, contextGlobal);
        curr = curr->next;
    }

    Symbol_table_insertContext(SymbolTable_General, contextGlobal->symbols_context);

    arm_global_data->text = arm_text_add(arm_global_data->text, arm_text_exit());
    arm_global_data->text = arm_data_add(arm_global_data->text, "\n");
    fprintf(stderr, "%s\n", arm_global_data->data);
    fprintf(stderr, "%s\n", arm_global_data->bss);
    fprintf(stderr, "%s\n", arm_global_data->text);
    fprintf(stderr, "%s\n", arm_global_data->auxiliar_functions);
}
