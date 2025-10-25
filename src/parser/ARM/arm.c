#include "arm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ARM_data *arm_data_create()
{

    ARM_data *data = malloc(sizeof(ARM_data));

    data->extern_functions = ".global main \n"
                             ".extern printf \n"
                             ".extern itao \n"
                             ".extern ftoa \n"
                             ".extern booltoa \n"
                             ".extern string_compare \n"
                             ".extern string_concat \n"
                             ".extern chartoa \n"
                             ".extern buscar_entero \n"
                             ".extern buscar_string \n"
                             ".extern append_to_array_integer \n"
                             " .extern append_to_string_array \n"
                             ".extern string_to_double \n"
                             ".extern string_to_int \n";
    data->data = ".data \n"
                 "print: .asciz \"%s\\n\" \n";
    data->bss = ".bss \n";
    data->text = ".text \n"
                 "main: \n"
                 "STP X29, X30, [SP, #-16]! \n"
                 "MOV X29, SP \n";
    data->final_text = "MOV W0, #0 \n"
                       "LDP X29, X30, [SP], #16 \n"
                       "mov x8, 93 \n"
                       "svc 0 \n";

    data->count_doubles = 0;
    data->count_floats = 0;
    data->count_strings = 0;
    data->count_buffers = 0;
    data->count_int = 0;
    data->count_arithmetic_temps = 0;
    data->count_comparative_temps = 0;

    data->count_if = 0;
    data->count_else = 0;
    data->count_elseif = 0;

    data->count_case = 0;
    data->count_switch = 0;

    data->count_while = 0;
    data->count_for = 0;
    data->count_foreach = 0;

    data->count_block = 0;
    return data;
}

void print_arm(ARM_data *data)
{
    fprintf(stderr, "%s\n", data->extern_functions);
    fprintf(stderr, "%s\n", data->data);
    fprintf(stderr, "%s\n", data->bss);
    fprintf(stderr, "%s\n", data->text);
    fprintf(stderr, "%s\n", data->final_text);
}

char *arm_data_add(char *original, char *to_add)
{
    if (!original)
        original = "";
    if (!to_add)
        to_add = "";
    char *new_data = malloc(strlen(original) + strlen(to_add) + 1);
    strcpy(new_data, original);
    strcat(new_data, to_add);
    return new_data;
}

char *arm_text_add(char *original, char *to_add)
{
    if (!original)
        original = "";
    if (!to_add)
        to_add = "";
    size_t len = strlen(original) + strlen(to_add) + 2 * strlen(to_add) + 1;
    char *new_text = malloc(len);
    if (!new_text)
        return NULL;
    strcpy(new_text, original);

    const char *src = to_add;
    char *dst = new_text + strlen(new_text);

    // Agrega tabulación al inicio de la primera línea
    *dst++ = '\t';
    while (*src)
    {
        *dst++ = *src;
        if (*src == '\n' && *(src + 1) != '\0')
        {
            *dst++ = '\t';
        }
        src++;
    }
    *dst = '\0';
    return new_text;
}
