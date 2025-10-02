#include "semantic.h"
#include "../structures/parser.h"

void Error_exists(char *message, char *environment, Instruccion *instruccion)
{
    extern ErrorList *list_errors;

    // Error: Evaluación de expresión fallida
    Error *new_error = (Error *)malloc(sizeof(Error));
    new_error->type = "Semantic";
    new_error->environment = environment;
    new_error->message = message;
    new_error->line = instruccion->line;
    new_error->column = instruccion->column;
    insertError(list_errors, new_error);
};