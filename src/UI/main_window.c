#include "UI.h"

// Variable global para mantener el contexto del status bar
static guint status_context_id;

// Variable global para acceder a los widgets desde los callbacks
AppWidgets *global_widgets = NULL;

// Función para actualizar la posición del cursor en el status bar
void update_cursor_position(GtkTextBuffer *buffer, GtkWidget *status_bar) {
    if (!GTK_IS_STATUSBAR(status_bar) || !GTK_IS_TEXT_BUFFER(buffer)) {
        return;
    }
    
    // Obtener la posición del cursor
    GtkTextIter iter;
    GtkTextMark *mark = gtk_text_buffer_get_insert(buffer);
    gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
    
    int line = gtk_text_iter_get_line(&iter) + 1; // Las líneas comienzan en 0
    int column = gtk_text_iter_get_line_offset(&iter) + 1; // Las columnas comienzan en 0
    
    // Limpiar el status bar y agregar la nueva información
    gtk_statusbar_remove_all(GTK_STATUSBAR(status_bar), status_context_id);
    
    gchar *status_text = g_strdup_printf("JavaLang Interpreter v1.0 | Line: %d, Column: %d", line, column);
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), status_context_id, status_text);
    g_free(status_text);
}

// Función para crear la barra de estado
GtkWidget* create_status_bar() {
    GtkWidget *status_bar = gtk_statusbar_new();
    status_context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(status_bar), "main");
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), status_context_id, "JavaLang Interpreter v1.0 | Line: 1, Column: 1");
    
    return status_bar;
}

// Callback para cerrar la aplicación
void on_window_destroy(GtkWidget *widget, gpointer data) {
    GApplication *app = G_APPLICATION(data);
    g_application_quit(app);
}

// Función principal para crear la ventana
void create_main_window(GtkApplication *app, gpointer user_data) {
    AppWidgets *widgets = g_malloc(sizeof(AppWidgets));
    global_widgets = widgets; // Asignar la referencia global
    
    // Ventana principal
    widgets->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(widgets->window), "JavaLang Interpreter");
    gtk_window_set_default_size(GTK_WINDOW(widgets->window), 1200, 800);
    gtk_window_set_position(GTK_WINDOW(widgets->window), GTK_WIN_POS_CENTER);
    
    g_signal_connect(widgets->window, "destroy", G_CALLBACK(on_window_destroy), app);
    
    // Aplicar estilos CSS globales
    apply_global_styles();
    
    // Contenedor principal vertical
    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(main_vbox), 40);
    gtk_container_add(GTK_CONTAINER(widgets->window), main_vbox);
    
    // Menú y toolbar
    GtkWidget *menubar = create_menubar();
    GtkWidget *toolbar = create_toolbar();
    
    gtk_box_pack_start(GTK_BOX(main_vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_vbox), toolbar, FALSE, FALSE, 5);
    
    // Panel principal (editor izquierda, consola y reportes derecha)
    widgets->right_paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    
    // Barra de estado (crear antes del editor para poder pasarla como parámetro)
    widgets->status_bar = create_status_bar();
    
    // Editor de código con referencia al status bar
    widgets->text_editor = create_code_editor(widgets->status_bar, &widgets->text_view);
    
    // Panel derecho con pestañas (consola y reportes)
    GtkWidget *right_notebook = gtk_notebook_new();
    
    // Consola
    GtkWidget *console_scrolled = create_console(&widgets->console_view);
    gtk_notebook_append_page(GTK_NOTEBOOK(right_notebook), console_scrolled, 
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
    
    // Agregar la barra de estado ya creada
    gtk_box_pack_start(GTK_BOX(main_vbox), widgets->status_bar, FALSE, FALSE, 0);
    
    gtk_widget_show_all(widgets->window);
}

// Función principal
int launch_ui_application(int argc, char *argv[]) {
    GtkApplication *app;
    int status;
    
    app = gtk_application_new("com.usac.javalang", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(create_main_window), NULL);
    
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}
