
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "UI/UI.h"
#include "../structures/parser.h"
#include "parser/semantic/semantic.h"
#include "parser.tab.h"

InstruccionList *list_tokens = NULL;

ErrorList *list_errors = NULL;
symbol_table *SymbolTable_General = NULL;

// Función para procesar archivo desde línea de comandos con captura de stderr
int process_file_with_debug(const char *filename)
{
    // Redirigir stderr a archivo
    int stderr_backup = dup(STDERR_FILENO);
    char debug_filename[] = "reports/debug_messages.txt";
    int debug_fd = open(debug_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (debug_fd != -1)
    {
        dup2(debug_fd, STDERR_FILENO);
        close(debug_fd);

        // Escribir encabezado en el archivo de debug
        fprintf(stderr, "=== MENSAJES DE DEBUG DEL ANÁLISIS SEMÁNTICO ===\n");
        fprintf(stderr, "Archivo: %s\n", filename);
        fprintf(stderr, "================================================\n\n");
    }

    // Abrir archivo de entrada
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        // Restaurar stderr
        dup2(stderr_backup, STDERR_FILENO);
        close(stderr_backup);

        printf("Error: No se pudo abrir el archivo %s\n", filename);
        return 1;
    }

    // Configurar yyin
    extern FILE *yyin;
    yyin = file;

    // Reinicializar parser
    extern void reset_parser_state(void);
    reset_parser_state();

    extern void yyrestart(FILE *);
    yyrestart(yyin);

    // Limpiar variables globales
    if (list_tokens)
    {
        InstruccionList_destroy(list_tokens);
    }
    list_tokens = InstruccionList_create();

    if (list_errors)
    {
        ErrorList_destroy(list_errors);
    }
    list_errors = createErrorList();

    if (SymbolTable_General)
    {
        Symbol_table_destroy(SymbolTable_General);
    }
    SymbolTable_General = Symbol_table_create();

    // Ejecutar parser y análisis semántico
    printf("Ejecutando análisis léxico y sintáctico para: %s\n", filename);
    int parse_result = yyparse();

    if (parse_result == 0)
    {
        printf("✓ Análisis sintáctico completado exitosamente\n");
        printf("Ejecutando análisis semántico...\n");
        semantic_analysis();
        printf("✓ Análisis semántico completado\n");
    }
    else
    {
        printf("✗ Error en el análisis sintáctico\n");
    }

    fclose(file);

    // Restaurar stderr
    dup2(stderr_backup, STDERR_FILENO);
    close(stderr_backup);

    printf("📄 Mensajes de debug guardados en: %s\n", debug_filename);

    return parse_result;
}

int main(int argc, char *argv[])
{
    list_tokens = InstruccionList_create();
    list_errors = createErrorList();
    SymbolTable_General = Symbol_table_create();

    // Si se proporciona un archivo como argumento, procesarlo con debug
    if (argc > 1)
    {
        printf("Modo línea de comandos - procesando archivo: %s\n", argv[1]);
        return process_file_with_debug(argv[1]);
    }

    // Si no hay argumentos, lanzar interfaz gráfica
    printf("Iniciando la interfaz de usuario...\n");
    return launch_terminal_ui(argc, argv);
}
