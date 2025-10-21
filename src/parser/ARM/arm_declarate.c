#include "arm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *arm_declarate(char *id, char *type, char *value)
{
    if (strcmp(type, "CHARACTER") == 0)
    {
        return arm_declarate_char(id, value);
    }
    else if (strcmp(type, "INTEGER") == 0)
    {
        return arm_declarate_int(id, atoi(value));
    }
    else if (strcmp(type, "FLOAT") == 0)
    {
        return arm_declarate_double(id, atof(value));
    }
    else if (strcmp(type, "DOUBLE") == 0)
    {
        return arm_declarate_double(id, atof(value));
    }
    else if (strcmp(type, "STRING") == 0)
    {
        return arm_declarate_string(id, value);
    }
    else if (strcmp(type, "BOOLEAN") == 0)
    {
        return arm_declarate_boolean(id, atoi(value));
    }
    else
    {
        return "Error en la declaracion con la declaracion"; // Tipo no soportado
    }
}

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
    if (value)
    {
        sprintf(code,
                "%s: .word 1\n", // true
                id);
    }
    else
    {
        sprintf(code,
                "%s: .word 0\n", // false
                id);
    }
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