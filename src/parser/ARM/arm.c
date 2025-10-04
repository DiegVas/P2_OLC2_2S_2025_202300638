#include "arm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ARM_data *arm_data_create()
{
    ARM_data *data = malloc(sizeof(ARM_data));
    data->data = ".data \n";
    data->text = ".text \n .global _start \n_start: \n";
    data->roadata = ".rodata \n";
    data->bss = ".bss \n";
    return data;
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

char *arm_text_exit()
{
    char *exit_code = malloc(50);
    strcpy(exit_code, "mov x0, 0 \n");
    strcat(exit_code, "mov x8, 93 \n");
    strcat(exit_code, "svc 0 \n");
    return exit_code;
}
