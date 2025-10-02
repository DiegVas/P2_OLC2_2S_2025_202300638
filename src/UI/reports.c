#include "UI.h"
#include "../structures/parser.h"
#include "../reports/ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to safely check if a string pointer is valid
static bool is_valid_string(const char *str)
{
    if (!str)
        return false;

    // Check for common poison values used by memory debugging tools
    uintptr_t ptr_val = (uintptr_t)str;
    if (ptr_val == 0xbebebebebebebebe ||
        ptr_val == 0xdeadbeefdeadbeef ||
        ptr_val == 0xfefefefefefefefe ||
        ptr_val < 0x1000)
    { // Very low addresses are usually invalid
        return false;
    }

    return true;
}

// Safe string getter that returns a fallback if pointer is invalid
static const char *get_safe_string(const char *str, const char *fallback)
{
    return is_valid_string(str) ? str : fallback;
}

// Function to create the reports panel with tabs
GtkWidget *create_reports_panel()
{
    GtkWidget *notebook = gtk_notebook_new();

    // AST Tab with image viewer
    GtkWidget *ast_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ast_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // Create a viewport with padding for the AST image
    GtkWidget *ast_viewport = gtk_viewport_new(NULL, NULL);

    // Apply dark background to viewport
    GdkRGBA ast_bg_color;
    gdk_rgba_parse(&ast_bg_color, "#0A0A0A");
    gtk_widget_override_background_color(ast_viewport, GTK_STATE_FLAG_NORMAL, &ast_bg_color);

    // Create image widget for AST
    GtkWidget *ast_image = gtk_image_new();
    gtk_widget_set_margin_top(ast_image, 20);
    gtk_widget_set_margin_bottom(ast_image, 20);
    gtk_widget_set_margin_left(ast_image, 20);
    gtk_widget_set_margin_right(ast_image, 20);

    // Store AST image reference in global widgets
    if (global_widgets)
    {
        global_widgets->ast_view = ast_image;
    }

    gtk_container_add(GTK_CONTAINER(ast_viewport), ast_image);
    gtk_container_add(GTK_CONTAINER(ast_scrolled), ast_viewport);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), ast_scrolled, gtk_label_new("AST"));

    // Symbols Table Tab
    GtkWidget *symbols_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(symbols_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // Create container with padding for symbol table
    GtkWidget *symbols_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(symbols_container), 15);

    // Apply darker background to symbols container
    GdkRGBA symbols_container_bg;
    gdk_rgba_parse(&symbols_container_bg, "#0A0A0A");
    gtk_widget_override_background_color(symbols_container, GTK_STATE_FLAG_NORMAL, &symbols_container_bg);

    GtkListStore *symbols_store = gtk_list_store_new(7, G_TYPE_STRING, G_TYPE_STRING,
                                                     G_TYPE_STRING, G_TYPE_STRING,
                                                     G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);

    global_widgets->symbols_store = symbols_store;
    GtkWidget *symbols_tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(global_widgets->symbols_store));

    // Columns for symbol table
    const char *symbols_columns[] = {"ID", "Tipo símbolo", "Tipo dato", "Valor", "Ámbito", "Línea", "Columna"};
    for (int i = 0; i < 7; i++)
    {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
        GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
            symbols_columns[i], renderer, "text", i, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(symbols_tree), column);
    }

    // Apply darker background to symbol table
    GdkRGBA symbols_bg_color, symbols_fg_color;
    gdk_rgba_parse(&symbols_bg_color, "#0A0A0A");
    gdk_rgba_parse(&symbols_fg_color, "#ffffff");
    gtk_widget_override_background_color(symbols_tree, GTK_STATE_FLAG_NORMAL, &symbols_bg_color);
    gtk_widget_override_color(symbols_tree, GTK_STATE_FLAG_NORMAL, &symbols_fg_color);

    gtk_box_pack_start(GTK_BOX(symbols_container), symbols_tree, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(symbols_scrolled), symbols_container);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), symbols_scrolled, gtk_label_new("Symbols"));

    // Errors Tab
    GtkWidget *errors_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(errors_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // Create container with padding for errors
    GtkWidget *errors_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(errors_container), 15);

    // Apply darker background to errors container
    GdkRGBA errors_container_bg;
    gdk_rgba_parse(&errors_container_bg, "#0A0A0A");
    gtk_widget_override_background_color(errors_container, GTK_STATE_FLAG_NORMAL, &errors_container_bg);

    GtkListStore *errors_store = gtk_list_store_new(6, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,
                                                    G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
    global_widgets->errors_store = errors_store;
    GtkWidget *errors_tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(global_widgets->errors_store));

    // Columns for errors
    const char *error_columns[] = {"No.", "Tipo", "Descripción", "Ámbito", "Línea", "Columna"};
    for (int i = 0; i < 6; i++)
    {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
        GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
            error_columns[i], renderer, "text", i, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(errors_tree), column);
    }

    // Apply darker background to errors table
    GdkRGBA errors_bg_color, errors_fg_color;
    gdk_rgba_parse(&errors_bg_color, "#0A0A0A");
    gdk_rgba_parse(&errors_fg_color, "#ffffff");
    gtk_widget_override_background_color(errors_tree, GTK_STATE_FLAG_NORMAL, &errors_bg_color);
    gtk_widget_override_color(errors_tree, GTK_STATE_FLAG_NORMAL, &errors_fg_color);

    gtk_box_pack_start(GTK_BOX(errors_container), errors_tree, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(errors_scrolled), errors_container);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), errors_scrolled, gtk_label_new("Errors"));

    return notebook;
}

// Safe version of symbol table update function
void update_symbols_table_safe(GtkListStore *store, symbol_table *table)
{
    if (!store || !table)
    {

        return;
    }

    gtk_list_store_clear(store);

    if (!table->head)
    {

        return;
    }

    symbol_node *curr = table->head;
    int count = 0;

    while (curr && count < 100)
    { // Safety limit
        if (!curr->data)
        {

            curr = curr->next;
            count++;
            continue;
        }

        symbol *sym = curr->data;

        // Validate symbol pointer itself
        if ((uintptr_t)sym < 0x1000 || (uintptr_t)sym == 0xbebebebebebebebe)
        {

            curr = curr->next;
            count++;
            continue;
        }

        // Create safe copies of data with validation
        const char *safe_id = get_safe_string(sym->id, "N/A");
        const char *safe_type = get_safe_string(sym->dataType, "N/A");
        const char *safe_subtype = get_safe_string(sym->type, "N/A");
        const char *safe_value = get_safe_string(sym->value, "N/A");
        const char *safe_environment = get_safe_string(sym->environment, "global");

        // Safe line and column access
        int safe_line = 0;
        int safe_column = 0;

        if (sym->line && (uintptr_t)sym->line > 0x1000 &&
            (uintptr_t)sym->line != 0xbebebebebebebebe)
        {
            safe_line = *(sym->line);
        }

        if (sym->column && (uintptr_t)sym->column > 0x1000 &&
            (uintptr_t)sym->column != 0xbebebebebebebebe)
        {
            safe_column = *(sym->column);
        }

        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);

        // Use safe data for GTK list store
        gtk_list_store_set(store, &iter,
                           0, safe_id,
                           1, safe_type,
                           2, safe_subtype,
                           3, safe_value,
                           4, safe_environment,
                           5, safe_line,
                           6, safe_column,
                           -1);

        curr = curr->next;
        count++;
    }
}

// Function to manually add a test error (for debugging)
void add_test_error_to_table(GtkListStore *store)
{
    if (!store)
        return;

    GtkTreeIter iter;
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,
                       0, 1,
                       1, "Error de prueba - tabla funcionando",
                       2, "Test",
                       3, 1,
                       4, 1,
                       -1);
}

void update_errors_table_safe(GtkListStore *store, ErrorList *list)
{
    if (!store || !list)
    {
        return;
    }

    gtk_list_store_clear(store);

    if (!list->head)
    {
        return;
    }

    ErrorNode *curr = list->head;
    int error_num = 1;
    int count = 0;

    while (curr && count < 100)
    { // Safety limit
        if (!curr->Error)
        {
            curr = curr->next;
            count++;
            continue;
        }

        Error *err = curr->Error;

        // Validate error pointer
        if ((uintptr_t)err < 0x1000 || (uintptr_t)err == 0xbebebebebebebebe)
        {
            curr = curr->next;
            count++;
            continue;
        }

        // Safe string access for error data
        const char *safe_message = get_safe_string(err->message, "Unknown error");
        const char *safe_type = get_safe_string(err->type, "General");
        const char *safe_environment = get_safe_string(err->environment, "Global");

        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);

        gtk_list_store_set(store, &iter,
                           0, error_num,
                           1, safe_type,
                           2, safe_message,
                           3, safe_environment,
                           4, err->line,
                           5, err->column,
                           -1);

        error_num++;
        curr = curr->next;
        count++;
    }
}

// Función para actualizar el AST en la interfaz
void update_ast_report()
{
    if (!global_widgets || !global_widgets->ast_view)
        return;

    // Crear carpeta reports si no existe
    system("mkdir -p reports");

    // Generar archivos en la carpeta reports
    char dot_filename[] = "reports/ast.dot";
    char png_filename[] = "reports/ast.png";

    // Cargar la imagen en el widget
    gtk_image_set_from_file(GTK_IMAGE(global_widgets->ast_view), png_filename);
}
