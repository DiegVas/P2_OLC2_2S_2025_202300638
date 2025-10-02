#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <gtk/gtk.h>
#include <pango-1.0/pango/pango-attributes.h>
#include "parser.tab.h"
#include "../structures/parser.h"

// Declaraciones del lexer/parser
extern int yyparse(void);
extern FILE *yyin;
extern char *yytext;

// Estructura para mantener referencias a los widgets principales
typedef struct
{
    GtkWidget *window;
    GtkWidget *right_paned;
    GtkWidget *text_editor;
    GtkWidget *text_view;    // Agregar referencia al text view interno
    GtkWidget *console_view; // Referencia al text view de la consola
    GtkWidget *ast_view;
    GtkWidget *symbols_view;
    GtkWidget *errors_view;
    GtkWidget *status_bar;
    GtkListStore *symbols_store; // Almacén para la tabla de símbolos
    GtkListStore *errors_store;  // Almacén para la tabla de errores
} AppWidgets;

// Variable global para acceder a los widgets desde los callbacks
extern AppWidgets *global_widgets;

// Declaraciones de funciones - menu.c
GtkWidget *create_menubar();

// Declaraciones de funciones - toolbar.c
GtkWidget *create_toolbar();
void on_new_clicked(GtkToolButton *button, gpointer user_data);
void on_open_clicked(GtkToolButton *button, gpointer user_data);
void on_save_clicked(GtkToolButton *button, gpointer user_data);
void on_run_clicked(GtkToolButton *button, gpointer user_data);

// Declaraciones de funciones - editor.c
GtkWidget *create_code_editor(GtkWidget *status_bar, GtkWidget **out_text_view);

// Declaraciones de funciones - console.c
GtkWidget *create_console(GtkWidget **out_text_view);

// Declaraciones de funciones - reports.c
GtkWidget *create_reports_panel();
void update_symbols_table_safe(GtkListStore *store, symbol_table *table);
void update_errors_table_safe(GtkListStore *store, ErrorList *list);
void update_ast_report();

// Declaraciones de funciones - styles.c
void apply_global_styles();

// Declaraciones de funciones - main_window.c
void create_main_window(GtkApplication *app, gpointer user_data);
GtkWidget *create_status_bar();
void update_cursor_position(GtkTextBuffer *buffer, GtkWidget *status_bar);

// Callback para cerrar la aplicación
void on_window_destroy(GtkWidget *widget, gpointer data);

// Función principal
int launch_terminal_ui(int argc, char *argv[]);
int launch_ui_application(int argc, char *argv[]);

#endif // UI_H
