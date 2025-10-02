
#include <stdio.h>
#include "UI/UI.h"
#include "../structures/parser.h"

InstruccionList *list_tokens = NULL;

ErrorList *list_errors = NULL;
symbol_table *SymbolTable_General = NULL;

int main(int argc, char *argv[])
{

    list_tokens = InstruccionList_create();
    list_errors = createErrorList();

    SymbolTable_General = Symbol_table_create();
    printf("Iniciando la interfaz de usuario...\n");

    return launch_terminal_ui(argc, argv);
}
