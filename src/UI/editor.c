#include "UI.h"

// Estructura para mantener referencias necesarias para números de línea dinámicos
typedef struct {
    GtkWidget *line_numbers_view;
    GtkTextBuffer *main_buffer;
} LineNumberData;

// Callback para actualizar números de línea cuando cambia el texto
static void update_line_numbers(GtkTextBuffer *buffer, gpointer user_data) {
    LineNumberData *data = (LineNumberData*)user_data;
    
    // Verificar que los datos sean válidos
    if (!data || !GTK_IS_TEXT_VIEW(data->line_numbers_view) || !GTK_IS_TEXT_BUFFER(buffer)) {
        return;
    }
    
    // Contar líneas actuales
    int line_count = gtk_text_buffer_get_line_count(buffer);
    
    // Generar números de línea
    GString *line_numbers_text = g_string_new("");
    for (int i = 1; i <= line_count; i++) {
        g_string_append_printf(line_numbers_text, "%d\n", i);
    }
    
    // Obtener y verificar el buffer de números de línea
    GtkTextBuffer *line_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data->line_numbers_view));
    if (GTK_IS_TEXT_BUFFER(line_buffer)) {
        gtk_text_buffer_set_text(line_buffer, line_numbers_text->str, -1);
    }
    g_string_free(line_numbers_text, TRUE);
}

// Callback para inicialización con timeout
static gboolean init_line_numbers(gpointer user_data) {
    LineNumberData *data = (LineNumberData*)user_data;
    update_line_numbers(data->main_buffer, user_data);
    return FALSE; // No repetir el timeout
}

// Estructura para el callback del cursor
typedef struct {
    GtkTextBuffer *buffer;
    GtkWidget *status_bar;
} CursorData;

// Callback para inicializar posición del cursor
static gboolean init_cursor_position(gpointer user_data) {
    CursorData *data = (CursorData*)user_data;
    update_cursor_position(data->buffer, data->status_bar);
    g_free(data); // Liberar la estructura temporal
    return FALSE; // No repetir el timeout
}

// Callback para eventos de teclado
static gboolean on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    GtkWidget *status_bar = (GtkWidget*)user_data;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
    update_cursor_position(buffer, status_bar);
    return FALSE; // Continuar propagando el evento
}

// Callback para eventos de mouse
static gboolean on_button_release(GtkWidget *widget, GdkEventButton *event, gpointer user_data) {
    GtkWidget *status_bar = (GtkWidget*)user_data;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
    update_cursor_position(buffer, status_bar);
    return FALSE; // Continuar propagando el evento
}

// Función para crear el editor de código con números de línea
GtkWidget* create_code_editor(GtkWidget *status_bar, GtkWidget **out_text_view) {
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(text_view), TRUE);
    
    // Devolver el text_view si se solicita
    if (out_text_view) {
        *out_text_view = text_view;
    }
    
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
    
    // Crear estructura para datos compartidos
    LineNumberData *line_data = g_malloc(sizeof(LineNumberData));
    line_data->line_numbers_view = line_numbers;
    line_data->main_buffer = buffer;
    
    // Configurar números de línea iniciales usando un timeout para asegurar inicialización completa
    g_timeout_add(1, init_line_numbers, line_data);
    
    // Conectar señales para actualización dinámica
    g_signal_connect_after(buffer, "changed", G_CALLBACK(update_line_numbers), line_data);
    
    // Liberar memoria cuando se destruya el widget
    g_signal_connect_swapped(text_view, "destroy", G_CALLBACK(g_free), line_data);
    
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
    
    // Conectar señales para actualizar la posición del cursor en el status bar
    if (status_bar) {
        // Señales del buffer para cambios de texto y cursor
        g_signal_connect(buffer, "notify::cursor-position", G_CALLBACK(update_cursor_position), status_bar);
        g_signal_connect(buffer, "mark-set", G_CALLBACK(update_cursor_position), status_bar);
        g_signal_connect(buffer, "changed", G_CALLBACK(update_cursor_position), status_bar);
        
        // Señales del text_view para movimientos del cursor con teclado y mouse
        g_signal_connect(text_view, "key-release-event", G_CALLBACK(on_key_release), status_bar);
        g_signal_connect(text_view, "button-release-event", G_CALLBACK(on_button_release), status_bar);
        
        // Actualizar posición inicial con timeout
        CursorData *cursor_data = g_malloc(sizeof(CursorData));
        cursor_data->buffer = buffer;
        cursor_data->status_bar = status_bar;
        g_timeout_add(50, init_cursor_position, cursor_data);
    }
    
    return scrolled;
}
