#include "UI.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../structures/parser.h"
#include "parser.tab.h"
#include "../parser/semantic/semantic.h"
// Callback para el botón "Nuevo"
void on_new_clicked(GtkToolButton *button, gpointer user_data)
{
    if (global_widgets && global_widgets->text_view)
    {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(global_widgets->text_view));
        gtk_text_buffer_set_text(buffer, "", -1);

        // Actualizar status bar
        if (global_widgets->status_bar)
        {
            update_cursor_position(buffer, global_widgets->status_bar);
        }
    }
}

// Callback para el botón "Abrir"
void on_open_clicked(GtkToolButton *button, gpointer user_data)
{
    if (!global_widgets || !global_widgets->text_view || !global_widgets->window)
    {
        return;
    }

    GtkWidget *dialog = gtk_file_chooser_dialog_new("Abrir archivo USL",
                                                    GTK_WINDOW(global_widgets->window),
                                                    GTK_FILE_CHOOSER_ACTION_OPEN,
                                                    "_Cancelar", GTK_RESPONSE_CANCEL,
                                                    "_Abrir", GTK_RESPONSE_ACCEPT,
                                                    NULL);

    // Filtro para archivos .usl
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Archivos USL (*.usl)");
    gtk_file_filter_add_pattern(filter, "*.usl");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    // Filtro para todos los archivos
    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Todos los archivos");
    gtk_file_filter_add_pattern(filter, "*");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        // Leer el archivo
        GError *error = NULL;
        gchar *contents;
        gsize length;

        if (g_file_get_contents(filename, &contents, &length, &error))
        {
            GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(global_widgets->text_view));
            gtk_text_buffer_set_text(buffer, contents, length);
            g_free(contents);

            // Actualizar status bar
            if (global_widgets->status_bar)
            {
                update_cursor_position(buffer, global_widgets->status_bar);
            }
        }
        else
        {
            // Mostrar error
            GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(global_widgets->window),
                                                             GTK_DIALOG_DESTROY_WITH_PARENT,
                                                             GTK_MESSAGE_ERROR,
                                                             GTK_BUTTONS_CLOSE,
                                                             "Error al abrir el archivo:\n%s",
                                                             error->message);
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
            g_error_free(error);
        }

        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

// Callback para el botón "Guardar"
void on_save_clicked(GtkToolButton *button, gpointer user_data)
{
    if (!global_widgets || !global_widgets->text_view || !global_widgets->window)
    {
        return;
    }

    GtkWidget *dialog = gtk_file_chooser_dialog_new("Guardar archivo USL",
                                                    GTK_WINDOW(global_widgets->window),
                                                    GTK_FILE_CHOOSER_ACTION_SAVE,
                                                    "_Cancelar", GTK_RESPONSE_CANCEL,
                                                    "_Guardar", GTK_RESPONSE_ACCEPT,
                                                    NULL);

    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);

    // Filtro para archivos .usl
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Archivos USL (*.usl)");
    gtk_file_filter_add_pattern(filter, "*.usl");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    // Sugerir extensión .usl
    gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "nuevo_archivo.usl");

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        // Obtener el contenido del buffer
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(global_widgets->text_view));
        GtkTextIter start, end;
        gtk_text_buffer_get_bounds(buffer, &start, &end);
        gchar *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

        // Guardar el archivo
        GError *error = NULL;
        if (!g_file_set_contents(filename, text, -1, &error))
        {
            // Mostrar error
            GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(global_widgets->window),
                                                             GTK_DIALOG_DESTROY_WITH_PARENT,
                                                             GTK_MESSAGE_ERROR,
                                                             GTK_BUTTONS_CLOSE,
                                                             "Error al guardar el archivo:\n%s",
                                                             error->message);
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
            g_error_free(error);
        }

        g_free(text);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

// Función para crear la barra de herramientas
GtkWidget *create_toolbar()
{
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);

    GtkToolItem *new_btn = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    GtkToolItem *open_btn = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    GtkToolItem *save_btn = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    GtkToolItem *separator = gtk_separator_tool_item_new();
    GtkToolItem *run_btn = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PLAY);

    gtk_tool_button_set_label(GTK_TOOL_BUTTON(run_btn), "Run");

    // Conectar señales de los botones
    g_signal_connect(new_btn, "clicked", G_CALLBACK(on_new_clicked), NULL);
    g_signal_connect(open_btn, "clicked", G_CALLBACK(on_open_clicked), NULL);
    g_signal_connect(save_btn, "clicked", G_CALLBACK(on_save_clicked), NULL);
    g_signal_connect(run_btn, "clicked", G_CALLBACK(on_run_clicked), NULL);

    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new_btn, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), open_btn, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save_btn, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), run_btn, -1);

    return toolbar;
}

// Callback para el botón "Run"
void on_run_clicked(GtkToolButton *button, gpointer user_data)
{
    if (!global_widgets || !global_widgets->text_view || !global_widgets->console_view)
    {
        return;
    }

    // Obtener el contenido del editor
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(global_widgets->text_view));
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *source_code = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    if (!source_code || strlen(source_code) == 0)
    {
        g_free(source_code);
        return;
    }

    // Obtener el buffer de la consola
    GtkTextBuffer *console_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(global_widgets->console_view));

    // Limpiar la consola
    gtk_text_buffer_set_text(console_buffer, "", -1);

    // Mostrar mensaje de inicio del análisis
    gtk_text_buffer_insert_at_cursor(console_buffer, "=== Ejecutando análisis léxico y sintáctico ===\n", -1);
    gtk_text_buffer_insert_at_cursor(console_buffer, "\n=== Resultado del análisis ===\n", -1);

    // Crear archivo temporal para el código fuente
    char temp_filename[] = "/tmp/javalang_temp_XXXXXX";
    int temp_fd = mkstemp(temp_filename);

    if (temp_fd != -1)
    {
        // Escribir el código al archivo temporal
        write(temp_fd, source_code, strlen(source_code));
        close(temp_fd);

        // Redirigir stdout para capturar la salida del parser
        int stdout_backup = dup(STDOUT_FILENO);
        char output_filename[] = "/tmp/javalang_output_XXXXXX";
        int output_fd = mkstemp(output_filename);

        if (output_fd != -1)
        {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);

            // Configurar yyin para leer del archivo temporal
            FILE *temp_file = fopen(temp_filename, "r");
            if (temp_file)
            {
                // Reinicializar completamente el estado del lexer/parser
                yyin = temp_file;

                // Usar la función de reinicialización del parser
                extern void reset_parser_state(void);
                reset_parser_state();

                // Limpiar el buffer del lexer
                extern void yyrestart(FILE *);
                yyrestart(yyin);

                // Limpiar variables globales del parser
                extern InstruccionList *list_tokens;
                if (list_tokens)
                {
                    InstruccionList_destroy(list_tokens);
                }
                list_tokens = InstruccionList_create();

                extern ErrorList *list_errors;
                if (list_errors)
                {
                    ErrorList_destroy(list_errors);
                }
                list_errors = createErrorList();

                // Limpiar tabla de símbolos
                extern symbol_table *SymbolTable_General;
                if (SymbolTable_General)
                {
                    Symbol_table_destroy(SymbolTable_General);
                }
                SymbolTable_General = Symbol_table_create();

                // Ejecutar el parser
                int parse_result = yyparse();

                semantic_analysis();

                extern symbol_table *SymbolTable_General;
                update_symbols_table_safe(global_widgets->symbols_store, SymbolTable_General);
                update_errors_table_safe(global_widgets->errors_store, list_errors);

                // Actualizar el AST con el ejemplo
                // ! aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
                update_ast_report();

                fclose(temp_file);

                // Restaurar stdout
                dup2(stdout_backup, STDOUT_FILENO);
                close(stdout_backup);

                // Leer la salida capturada
                FILE *output_file = fopen(output_filename, "r");
                if (output_file)
                {
                    char line[10024];
                    while (fgets(line, sizeof(line), output_file))
                    {
                        gtk_text_buffer_insert_at_cursor(console_buffer, line, -1);
                    }
                    fclose(output_file);
                }

                // Agregar resultado del parsing
                if (parse_result == 0)
                {
                    gtk_text_buffer_insert_at_cursor(console_buffer, "\n✓ Análisis completado exitosamente\n", -1);
                }
                else
                {
                    gtk_text_buffer_insert_at_cursor(console_buffer, "\n✗ Error en el análisis sintáctico\n", -1);
                }

                // Limpiar archivos temporales
                unlink(output_filename);
            }
            else
            {
                dup2(stdout_backup, STDOUT_FILENO);
                close(stdout_backup);
                gtk_text_buffer_insert_at_cursor(console_buffer, "Error: No se pudo abrir el archivo temporal\n", -1);
            }
        }

        // Limpiar archivo temporal
        unlink(temp_filename);
    }
    else
    {
        gtk_text_buffer_insert_at_cursor(console_buffer, "Error: No se pudo crear archivo temporal\n", -1);
    }

    g_free(source_code);

    // Hacer scroll hacia abajo en la consola
    GtkTextIter console_end;
    gtk_text_buffer_get_end_iter(console_buffer, &console_end);
    GtkTextMark *mark = gtk_text_buffer_get_insert(console_buffer);
    gtk_text_buffer_place_cursor(console_buffer, &console_end);
    gtk_text_view_scroll_mark_onscreen(GTK_TEXT_VIEW(global_widgets->console_view), mark);
}
