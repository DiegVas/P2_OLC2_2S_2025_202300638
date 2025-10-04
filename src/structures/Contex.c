#include "parser.h"

void add_text_section(char **original, const char *to_add)
{
    size_t len = strlen(*original) + strlen(to_add) + 2 * strlen(to_add) + 1;
    char *new_text = malloc(len);
    strcpy(new_text, *original);

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

    free(*original);
    *original = new_text;
}