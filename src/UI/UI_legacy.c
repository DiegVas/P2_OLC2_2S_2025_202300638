#include <stdio.h>
#include <gtk/gtk.h>
#include <pango-1.0/pango/pango-attributes.h>

// Estructura para mantener referencias a los widgets principales
typedef struct
{
    GtkWidget *window;
    GtkWidget *right_paned;
    GtkWidget *text_editor;
    GtkWidget *console_view;
    GtkWidget *ast_view;
    GtkWidget *symbols_view;
    GtkWidget *errors_view;
    GtkWidget *status_bar;
} AppWidgets;

// Función para crear el menú (sin menús)
static GtkWidget *create_menubar()
{
    GtkWidget *menubar = gtk_menu_bar_new();

    // Sin menús - barra vacía

    return menubar;
}

// Función para crear la barra de herramientas
static GtkWidget *create_toolbar()
{
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);

    GtkToolItem *new_btn = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    GtkToolItem *open_btn = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    GtkToolItem *save_btn = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    GtkToolItem *separator = gtk_separator_tool_item_new();
    GtkToolItem *run_btn = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PLAY);

    gtk_tool_button_set_label(GTK_TOOL_BUTTON(run_btn), "Run");

    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new_btn, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), open_btn, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save_btn, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), run_btn, -1);

    return toolbar;
}

/*
// Función para crear el árbol de archivos (ELIMINADA)
static GtkWidget* create_file_tree() {
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkListStore *store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    GtkWidget *tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
        "Files", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree), column);

    // Archivos de ejemplo
    GtkTreeIter iter;
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "📁 src", 1, "folder", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "  📄 Main.usl", 1, "file", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "  📄 Utils.usl", 1, "file", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "📁 examples", 1, "folder", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "  📄 test1.usl", 1, "file", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "  📄 test2.usl", 1, "file", -1);

    g_object_unref(store);

    gtk_container_add(GTK_CONTAINER(scrolled), tree);

    return scrolled;
}

// Función para crear el panel de proyectos (ELIMINADA)
static GtkWidget* create_project_tree() {
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkListStore *store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    GtkWidget *tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
        "Projects", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree), column);

    // Proyectos de ejemplo
    GtkTreeIter iter;
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "🚀 JavaLang Interpreter", 1, "project", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "📦 Calculator App", 1, "project", -1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "🔧 Utils Library", 1, "project", -1);

    g_object_unref(store);

    gtk_container_add(GTK_CONTAINER(scrolled), tree);

    return scrolled;
}
*/

// Función para crear el editor de código con números de línea
static GtkWidget *create_code_editor()
{
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(text_view), TRUE);

    // Configurar el buffer con código de ejemplo
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    const char *sample_code =
        "// JavaLang Sample Code\n"
        "public class Main {\n"
        "    public static void main() {\n"
        "        int x = 10;\n"
        "        float y = 3.14f;\n"
        "        String message = \"Hello, JavaLang!\";\n"
        "        \n"
        "        System.out.println(message);\n"
        "        System.out.println(\"x = \" + x);\n"
        "        \n"
        "        if (x > 5) {\n"
        "            System.out.println(\"x is greater than 5\");\n"
        "        }\n"
        "        \n"
        "        int[] numbers = {1, 2, 3, 4, 5};\n"
        "        for (int i = 0; i < numbers.length; i++) {\n"
        "            System.out.println(\"Number: \" + numbers[i]);\n"
        "        }\n"
        "    }\n"
        "}\n";

    gtk_text_buffer_set_text(buffer, sample_code, -1);

    // Crear una vista con números de línea
    GtkWidget *line_numbers = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(line_numbers), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(line_numbers), FALSE);
    gtk_widget_set_size_request(line_numbers, 50, -1);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(line_numbers), TRUE);

    // Contar líneas y generar números
    int line_count = gtk_text_buffer_get_line_count(buffer);
    GString *line_numbers_text = g_string_new("");
    for (int i = 1; i <= line_count; i++)
    {
        g_string_append_printf(line_numbers_text, "%d\n", i);
    }

    GtkTextBuffer *line_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(line_numbers));
    gtk_text_buffer_set_text(line_buffer, line_numbers_text->str, -1);
    g_string_free(line_numbers_text, TRUE);

    // Aplicar tema oscuro consistente
    GdkRGBA bg_color, fg_color, border_color;
    gdk_rgba_parse(&bg_color, "#151515");
    gdk_rgba_parse(&fg_color, "#ffffff");
    gdk_rgba_parse(&border_color, "#ffffff");

    // Estilo para el editor principal
    gtk_widget_override_background_color(text_view, GTK_STATE_FLAG_NORMAL, &bg_color);
    gtk_widget_override_color(text_view, GTK_STATE_FLAG_NORMAL, &fg_color);

    // Estilo para números de línea
    gdk_rgba_parse(&fg_color, "#888888");
    gtk_widget_override_background_color(line_numbers, GTK_STATE_FLAG_NORMAL, &bg_color);
    gtk_widget_override_color(line_numbers, GTK_STATE_FLAG_NORMAL, &fg_color);

    // Crear un contenedor horizontal para números de línea + editor
    GtkWidget *editor_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(editor_hbox), line_numbers, FALSE, FALSE, 0);

    // Agregar separador vertical blanco
    GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    gtk_box_pack_start(GTK_BOX(editor_hbox), separator, FALSE, FALSE, 1);

    gtk_box_pack_start(GTK_BOX(editor_hbox), text_view, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(scrolled), editor_hbox);

    return scrolled;
}

// Función para crear la consola
static GtkWidget *create_console()
{
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(text_view), TRUE);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);

    // Agregar padding interno al texto de la consola
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(text_view), 15);
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(text_view), 15);
    gtk_text_view_set_top_margin(GTK_TEXT_VIEW(text_view), 15);
    gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(text_view), 15);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer,
                             "JavaLang Interpreter Console\n"
                             "Ready to execute .usl files...\n"
                             ">>> Compilation started\n"
                             ">>> Lexical analysis: OK\n"
                             ">>> Syntax analysis: OK\n"
                             ">>> Semantic analysis: OK\n"
                             ">>> Execution started\n"
                             "Hello, JavaLang!\n"
                             "x = 10\n"
                             "x is greater than 5\n"
                             "Number: 1\n"
                             "Number: 2\n"
                             "Number: 3\n"
                             "Number: 4\n"
                             "Number: 5\n"
                             ">>> Execution completed successfully\n",
                             -1);

    // Aplicar tema oscuro consistente
    GdkRGBA bg_color, fg_color;
    gdk_rgba_parse(&bg_color, "#0A0A0A");
    gdk_rgba_parse(&fg_color, "#00ff00");
    gtk_widget_override_background_color(text_view, GTK_STATE_FLAG_NORMAL, &bg_color);
    gtk_widget_override_color(text_view, GTK_STATE_FLAG_NORMAL, &fg_color);

    gtk_container_add(GTK_CONTAINER(scrolled), text_view);

    return scrolled;
}

// Función para crear el panel de reportes con pestañas
static GtkWidget *create_reports_panel()
{
    GtkWidget *notebook = gtk_notebook_new();

    // Pestaña AST
    GtkWidget *ast_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ast_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *ast_view = gtk_text_view_new();
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(ast_view), TRUE);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(ast_view), FALSE);

    // Agregar padding al AST
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(ast_view), 15);
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(ast_view), 15);
    gtk_text_view_set_top_margin(GTK_TEXT_VIEW(ast_view), 15);
    gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(ast_view), 15);

    // Aplicar fondo más oscuro al AST
    GdkRGBA ast_bg_color, ast_fg_color;
    gdk_rgba_parse(&ast_bg_color, "#0A0A0A");
    gdk_rgba_parse(&ast_fg_color, "#ffffff");
    gtk_widget_override_background_color(ast_view, GTK_STATE_FLAG_NORMAL, &ast_bg_color);
    gtk_widget_override_color(ast_view, GTK_STATE_FLAG_NORMAL, &ast_fg_color);

    GtkTextBuffer *ast_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(ast_view));
    gtk_text_buffer_set_text(ast_buffer,
                             "Abstract Syntax Tree (AST)\n"
                             "=========================\n\n"
                             "Program\n"
                             "├── ClassDeclaration: Main\n"
                             "│   └── MethodDeclaration: main\n"
                             "│       └── Block\n"
                             "│           ├── VariableDeclaration: int x = 10\n"
                             "│           ├── VariableDeclaration: float y = 3.14f\n"
                             "│           ├── VariableDeclaration: String message = \"Hello, JavaLang!\"\n"
                             "│           ├── MethodCall: System.out.println(message)\n"
                             "│           ├── MethodCall: System.out.println(\"x = \" + x)\n"
                             "│           ├── IfStatement\n"
                             "│           │   ├── Condition: x > 5\n"
                             "│           │   └── Block\n"
                             "│           │       └── MethodCall: System.out.println(\"x is greater than 5\")\n"
                             "│           ├── VariableDeclaration: int[] numbers = {1, 2, 3, 4, 5}\n"
                             "│           └── ForLoop\n"
                             "│               ├── Init: int i = 0\n"
                             "│               ├── Condition: i < numbers.length\n"
                             "│               ├── Increment: i++\n"
                             "│               └── Block\n"
                             "│                   └── MethodCall: System.out.println(\"Number: \" + numbers[i])",
                             -1);

    gtk_container_add(GTK_CONTAINER(ast_scrolled), ast_view);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), ast_scrolled, gtk_label_new("AST"));

    // Pestaña Tabla de Símbolos
    GtkWidget *symbols_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(symbols_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // Crear contenedor con padding para la tabla de símbolos
    GtkWidget *symbols_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(symbols_container), 15);

    // Aplicar fondo más oscuro al contenedor de símbolos
    GdkRGBA symbols_container_bg;
    gdk_rgba_parse(&symbols_container_bg, "#0A0A0A");
    gtk_widget_override_background_color(symbols_container, GTK_STATE_FLAG_NORMAL, &symbols_container_bg);

    GtkListStore *symbols_store = gtk_list_store_new(6, G_TYPE_STRING, G_TYPE_STRING,
                                                     G_TYPE_STRING, G_TYPE_STRING,
                                                     G_TYPE_INT, G_TYPE_INT);
    GtkWidget *symbols_tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(symbols_store));

    // Columnas para la tabla de símbolos
    const char *symbols_columns[] = {"ID", "Tipo símbolo", "Tipo dato", "Ámbito", "Línea", "Columna"};
    for (int i = 0; i < 6; i++)
    {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
        GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
            symbols_columns[i], renderer, "text", i, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(symbols_tree), column);
    }

    // Datos de ejemplo
    GtkTreeIter iter;
    gtk_list_store_append(symbols_store, &iter);
    gtk_list_store_set(symbols_store, &iter, 0, "x", 1, "Variable", 2, "int", 3, "main", 4, 4, 5, 13, -1);

    gtk_list_store_append(symbols_store, &iter);
    gtk_list_store_set(symbols_store, &iter, 0, "y", 1, "Variable", 2, "float", 3, "main", 4, 5, 5, 15, -1);

    gtk_list_store_append(symbols_store, &iter);
    gtk_list_store_set(symbols_store, &iter, 0, "message", 1, "Variable", 2, "String", 3, "main", 4, 6, 5, 16, -1);

    gtk_list_store_append(symbols_store, &iter);
    gtk_list_store_set(symbols_store, &iter, 0, "numbers", 1, "Variable", 2, "int[]", 3, "main", 4, 15, 5, 13, -1);

    gtk_list_store_append(symbols_store, &iter);
    gtk_list_store_set(symbols_store, &iter, 0, "i", 1, "Variable", 2, "int", 3, "for_loop", 4, 16, 5, 18, -1);

    // Aplicar fondo más oscuro a la tabla de símbolos
    GdkRGBA symbols_bg_color, symbols_fg_color;
    gdk_rgba_parse(&symbols_bg_color, "#0A0A0A");
    gdk_rgba_parse(&symbols_fg_color, "#ffffff");
    gtk_widget_override_background_color(symbols_tree, GTK_STATE_FLAG_NORMAL, &symbols_bg_color);
    gtk_widget_override_color(symbols_tree, GTK_STATE_FLAG_NORMAL, &symbols_fg_color);

    gtk_box_pack_start(GTK_BOX(symbols_container), symbols_tree, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(symbols_scrolled), symbols_container);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), symbols_scrolled, gtk_label_new("Symbols"));

    // Pestaña Errores
    GtkWidget *errors_scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(errors_scrolled),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // Crear contenedor con padding para errores
    GtkWidget *errors_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(errors_container), 15);

    // Aplicar fondo más oscuro al contenedor de errores
    GdkRGBA errors_container_bg;
    gdk_rgba_parse(&errors_container_bg, "#0A0A0A");
    gtk_widget_override_background_color(errors_container, GTK_STATE_FLAG_NORMAL, &errors_container_bg);

    GtkListStore *errors_store = gtk_list_store_new(5, G_TYPE_INT, G_TYPE_STRING,
                                                    G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
    GtkWidget *errors_tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(errors_store));

    // Columnas para errores
    const char *error_columns[] = {"No.", "Descripción", "Ámbito", "Línea", "Columna"};
    for (int i = 0; i < 5; i++)
    {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
        GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
            error_columns[i], renderer, "text", i, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(errors_tree), column);
    }

    // Sin errores por ahora
    GtkWidget *no_errors_label = gtk_label_new("✅ No errors found in the current file.");
    gtk_widget_set_halign(no_errors_label, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(no_errors_label, GTK_ALIGN_CENTER);

    // Aplicar fondo más oscuro a la sección de errores
    GdkRGBA errors_bg_color, errors_fg_color;
    gdk_rgba_parse(&errors_bg_color, "#0A0A0A");
    gdk_rgba_parse(&errors_fg_color, "#ffffff");
    gtk_widget_override_background_color(no_errors_label, GTK_STATE_FLAG_NORMAL, &errors_bg_color);
    gtk_widget_override_color(no_errors_label, GTK_STATE_FLAG_NORMAL, &errors_fg_color);

    gtk_box_pack_start(GTK_BOX(errors_container), no_errors_label, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(errors_scrolled), errors_container);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), errors_scrolled, gtk_label_new("Errors"));

    return notebook;
}

// Función para crear la barra de estado
static GtkWidget *create_status_bar()
{
    GtkWidget *status_bar = gtk_statusbar_new();
    guint context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(status_bar), "main");
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), context_id, "Ready | JavaLang Interpreter v1.0 | Line: 1, Column: 1");

    return status_bar;
}

// Callback para cerrar la aplicación
static void on_window_destroy(GtkWidget *widget, gpointer data)
{
    GApplication *app = G_APPLICATION(data);
    g_application_quit(app);
}

// Función principal para crear la ventana
static void create_main_window(GtkApplication *app, gpointer user_data)
{
    AppWidgets *widgets = g_malloc(sizeof(AppWidgets));

    // Ventana principal
    widgets->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(widgets->window), "JavaLang Interpreter");
    gtk_window_set_default_size(GTK_WINDOW(widgets->window), 1200, 800);
    gtk_window_set_position(GTK_WINDOW(widgets->window), GTK_WIN_POS_CENTER);

    g_signal_connect(widgets->window, "destroy", G_CALLBACK(on_window_destroy), app);

    // Aplicar tema oscuro global con CSS
    GtkCssProvider *css_provider = gtk_css_provider_new();
    const gchar *css_data =
        "* { "
        "  background-color: #151515; "
        "  color: #ffffff; "
        "  border-color: #ffffff; "
        "} "
        "GtkWindow { "
        "  padding: 0px; "
        "} "
        "GtkFrame { "
        "  border: none; "
        "} "
        "GtkNotebook { "
        "  background-color: #151515; "
        "  border: none; "
        "} "
        "GtkNotebook tab { "
        "  background-color: #077A7D; "
        "  color: #ffffff; "
        "  border: none; "
        "  padding: 8px 15px; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkNotebook tab:checked { "
        "  background-color: #0A9B9F; "
        "  color: #ffffff; "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkNotebook tab:hover { "
        "  background-color: #099A9D; "
        "  color: #ffffff; "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkNotebook tab label { "
        "  background-color: #077A7D; "
        "  color: #ffffff; "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkNotebook tab:checked label { "
        "  background-color: #0A9B9F; "
        "  color: #ffffff; "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkNotebook tab:hover label { "
        "  background-color: #099A9D; "
        "  color: #ffffff; "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkTreeView { "
        "  background-color: #151515; "
        "  color: #ffffff; "
        "} "
        "GtkScrolledWindow { "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "  outline: none; "
        "  box-shadow: none; "
        "  background-color: #151515; "
        "} "
        "GtkToolbar { "
        "  background-color: #151515; "
        "  border-top: 2px solid #ffffff; "
        "  border-bottom: 2px solid #ffffff; "
        "  border-left: none; "
        "  border-right: none; "
        "  padding: 10px 0; "
        "  margin: 8px 0; "
        "} "
        "GtkToolButton { "
        "  background-color: #151515; "
        "  border-width: 0px; "
        "  border-style: none; "
        "  border-color: transparent; "
        "  box-shadow: none; "
        "  outline-width: 0px; "
        "  outline-style: none; "
        "  padding: 8px 12px; "
        "  margin: 0 5px; "
        "} "
        "GtkToolButton:hover { "
        "  background-color: #2a2a2a; "
        "  border-width: 0px; "
        "  border-style: none; "
        "  border-color: transparent; "
        "} "
        "GtkToolButton:active { "
        "  background-color: #2a2a2a; "
        "  border-width: 0px; "
        "  border-style: none; "
        "  border-color: transparent; "
        "} "
        "GtkToolButton:focus { "
        "  border-width: 0px; "
        "  border-style: none; "
        "  border-color: transparent; "
        "  box-shadow: none; "
        "  outline-width: 0px; "
        "} "
        "button { "
        "  border-width: 0px; "
        "  border-style: none; "
        "  border-color: transparent; "
        "  box-shadow: none; "
        "  outline-width: 0px; "
        "  background-color: #151515; "
        "} "
        "button:hover { "
        "  background-color: #2a2a2a; "
        "  border-width: 0px; "
        "} "
        "GtkMenuBar { "
        "  background-color: #151515; "
        "  border: none; "
        "} "
        "GtkTextView { "
        "  border: none; "
        "} "
        "GtkBox { "
        "  border: none; "
        "} "
        "GtkPaned { "
        "  border: none; "
        "} "
        "GtkSeparatorToolItem { "
        "  border: none; "
        "  background-color: #151515; "
        "} "
        "GtkButton { "
        "  border-width: 0px; "
        "  border-style: none; "
        "  border-color: transparent; "
        "  box-shadow: none; "
        "  outline-width: 0px; "
        "  background-color: #151515; "
        "} "
        "GtkButton:hover { "
        "  background-color: #2a2a2a; "
        "  border-width: 0px; "
        "} "
        "GtkLabel { "
        "  border-width: 0px; "
        "  border: none; "
        "} "
        "tab label { "
        "  background-color: #077A7D; "
        "  color: #ffffff; "
        "  border: none; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkImage { "
        "  border-width: 0px; "
        "} "
        ".toolbar button { "
        "  border: none; "
        "  background-color: #151515; "
        "} "
        "toolbar button { "
        "  border: none; "
        "  background-color: #151515; "
        "} "
        "toolbar { "
        "  border-top: 2px solid #ffffff; "
        "  border-bottom: 2px solid #ffffff; "
        "  border-left: none; "
        "  border-right: none; "
        "  background-color: #151515; "
        "} "
        "notebook { "
        "  border: none; "
        "  background-color: #151515; "
        "  border-width: 0px; "
        "  border-style: none; "
        "  outline: none; "
        "  box-shadow: none; "
        "} "
        "GtkNotebook { "
        "  border: none; "
        "  background-color: #151515; "
        "  border-width: 0px; "
        "  border-style: none; "
        "  outline: none; "
        "  box-shadow: none; "
        "} "
        "GtkNotebook > header { "
        "  border: none; "
        "  background-color: #151515; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "GtkNotebook > stack { "
        "  border: none; "
        "  background-color: #151515; "
        "  border-width: 0px; "
        "  border-style: none; "
        "} "
        "tab { "
        "  border: none; "
        "  background-color: #077A7D; "
        "  color: #ffffff; "
        "  border-width: 0px; "
        "  border-style: none; "
        "}";
    gtk_css_provider_load_from_data(css_provider, css_data, -1, NULL);
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(css_provider);

    // Contenedor principal vertical
    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(main_vbox), 40);
    gtk_container_add(GTK_CONTAINER(widgets->window), main_vbox);

    // Menú y toolbar
    GtkWidget *menubar = create_menubar();
    GtkWidget *toolbar = create_toolbar();

    gtk_box_pack_start(GTK_BOX(main_vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_vbox), toolbar, FALSE, FALSE, 5);

    // Panel principal horizontal eliminado - usando directamente el panel derecho

    // Panel izquierdo eliminado - ya no hay explorador de archivos

    // Panel principal (editor izquierda, consola y reportes derecha)
    widgets->right_paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);

    // Editor de código
    widgets->text_editor = create_code_editor();

    // Panel derecho con pestañas (consola y reportes)
    GtkWidget *right_notebook = gtk_notebook_new();

    // Consola
    widgets->console_view = create_console();
    gtk_notebook_append_page(GTK_NOTEBOOK(right_notebook), widgets->console_view,
                             gtk_label_new("Console"));

    // Reportes
    GtkWidget *reports_panel = create_reports_panel();
    gtk_notebook_append_page(GTK_NOTEBOOK(right_notebook), reports_panel,
                             gtk_label_new("Reports"));

    // Configurar panel principal horizontal
    gtk_paned_pack1(GTK_PANED(widgets->right_paned), widgets->text_editor, TRUE, TRUE);
    gtk_paned_pack2(GTK_PANED(widgets->right_paned), right_notebook, FALSE, TRUE);
    gtk_paned_set_position(GTK_PANED(widgets->right_paned), 600); // Editor más ancho

    // Configurar panel principal - solo panel derecho (sin panel izquierdo)
    gtk_box_pack_start(GTK_BOX(main_vbox), widgets->right_paned, TRUE, TRUE, 5);

    // Barra de estado
    widgets->status_bar = create_status_bar();
    gtk_box_pack_start(GTK_BOX(main_vbox), widgets->status_bar, FALSE, FALSE, 0);

    gtk_widget_show_all(widgets->window);
}

// Función principal
int launch_terminal_ui(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.usac.javalang", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(create_main_window), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
