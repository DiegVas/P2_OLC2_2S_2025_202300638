#include "arm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *arm_declarate_list(char *id, char *type, char *value)
{
    char *code = malloc(1000);
    if (strcmp(type, "CHARACTER") == 0)
    {
        snprintf(code, 1000, "%s: .byte %s\n", id, value);
    }
    else if (strcmp(type, "INTEGER") == 0)
    {
        snprintf(code, 1000, "%s: .word %s\n", id, value);
    }
    else if (strcmp(type, "FLOAT") == 0)
    {
        snprintf(code, 1000, "%s: .float %s\n", id, value);
    }
    else if (strcmp(type, "DOUBLE") == 0)
    {
        snprintf(code, 1000, "%s: .double %s\n", id, value);
    }
    else if (strcmp(type, "STRING") == 0)
    {

        snprintf(code, 1000, "%s: .quad %s\n", id, value);
    }
    else if (strcmp(type, "BOOLEAN") == 0)
    {
        snprintf(code, 1000, "%s: .word %s\n", id, value);
    }
    else
    {
        return "Error en la declaracion con la declaracion"; // Tipo no soportado
    }
    return code;
};

char *arm_declarate_char(char *id, char *value)
{
    char *code = malloc(100);
    sprintf(code,
            "%s: .byte %s\n",
            id, value);
    return code;
}

char *arm_declarate_int(char *id, int value)
{
    char *code = malloc(100);
    sprintf(code,
            "%s: .word %d\n",
            id, value);
    return code;
}

char *arm_declarate_double(char *id, double value)
{
    char *code = malloc(100);
    sprintf(code,
            "%s: .double %lf\n",
            id, value);
    return code;
}
char *arm_declarate_string(char *id, char *value)
{
    char *code = malloc(strlen(value) + 50);
    sprintf(code,
            "%s: .asciz \"%s\"\n",
            id, value);
    return code;
}

char *arm_declarate_boolean(char *id, int value)
{
    char *code = malloc(100);

    sprintf(code,
            "%s: .word %d\n", // true
            id, value);

    return code;
}

char *arm_declarate_bss(char *id, char *type)
{
    char *code = malloc(100);
    if (strcmp(type, "CHARACTER") == 0)
    {
        sprintf(code,
                "%s: .space 1\n",
                id);
    }
    else if (strcmp(type, "INTEGER") == 0)
    {
        sprintf(code,
                "%s: .space 4\n",
                id);
    }
    else if (strcmp(type, "FLOAT") == 0)
    {
        sprintf(code,
                "%s: .space 8\n",
                id);
    }
    else if (strcmp(type, "DOUBLE") == 0)
    {
        sprintf(code,
                "%s: .space 32\n",
                id);
    }
    else if (strcmp(type, "STRING") == 0)
    {
        sprintf(code,
                "%s: .space 8\n", // Puntero a string
                id);
    }
    else if (strcmp(type, "BOOLEAN") == 0)
    {
        sprintf(code,
                "%s: .space 4\n",
                id);
    }
    else
    {
        sprintf(code, "Error en la declaracion en BSS"); // Tipo no soportado
    }
    return code;
}