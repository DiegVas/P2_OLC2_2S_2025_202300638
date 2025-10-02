# Casos de Uso y Ejemplos Prácticos - Módulos JavaLang

## Tabla de Contenidos

1. [Flujo Completo de Compilación](#1-flujo-completo-de-compilación)
2. [Casos de Uso por Módulo](#2-casos-de-uso-por-módulo)
3. [Ejemplos de Integración](#3-ejemplos-de-integración)
4. [Manejo de Errores](#4-manejo-de-errores)
5. [Extensibilidad](#5-extensibilidad)

---

## 1. Flujo Completo de Compilación

### 1.1 Ejemplo de Código JavaLang

```java
public class Main {
    public static void main(String[] args) {
        int x = 10;
        float y = 3.14f;
        String message = "Hello, JavaLang!";
        
        System.out.println(message);
        System.out.println("x = " + x);
        
        if (x > 5) {
            System.out.println("x es mayor que 5");
        }
    }
}
```

### 1.2 Procesamiento por Módulo

#### Paso 1: Lexer - Tokenización
```text
Token: PUBLIC (public)
Token: STATIC (static) 
Token: MAIN (main)
Token: '(' 
Token: STRING (String)
Token: '[' 
Token: ']'
Token: ID (args)
Token: ')'
Token: '{'
Token: INT (int)
Token: ID (x)
Token: '='
Token: NUM (10)
Token: ';'
// ... más tokens
```

#### Paso 2: Parser - Construcción AST
```text
Program
├── ClassDeclaration: Main
│   └── MethodDeclaration: main
│       └── Block
│           ├── Declaration: int x = 10
│           ├── Declaration: float y = 3.14f
│           ├── Declaration: String message = "Hello, JavaLang!"
│           ├── PrintlnStatement: System.out.println(message)
│           └── IfStatement
│               ├── Condition: x > 5
│               └── Block
│                   └── PrintlnStatement: ...
```

#### Paso 3: Semántico - Análisis y Ejecución
```text
Contexto: Global
  └── Símbolos:
      ├── x: int, valor=10, línea=3, mutable=true
      ├── y: float, valor=3.14, línea=4, mutable=true
      └── message: String, valor="Hello, JavaLang!", línea=5, mutable=true

Ejecución:
  ├── Declaración de x ✓
  ├── Declaración de y ✓ 
  ├── Declaración de message ✓
  ├── Println: "Hello, JavaLang!"
  ├── Evaluación: "x = " + x → "x = 10"
  ├── Println: "x = 10"
  ├── Evaluación condición: x > 5 → 10 > 5 → true
  └── Println: "x es mayor que 5"
```

#### Paso 4: GUI - Visualización
- **Editor**: Código fuente con resaltado
- **Consola**: Salida del programa
- **AST**: Diagrama visual del árbol
- **Símbolos**: Tabla con variables declaradas
- **Errores**: Lista vacía (compilación exitosa)

---

## 2. Casos de Uso por Módulo

### 2.1 Módulo Lexer

#### Caso 1: Identificación de Tokens Válidos
```c
Entrada: "int x = 42;"
Salida: [INT] [ID:x] [=] [NUM:42] [;]
```

#### Caso 2: Manejo de Errores Léxicos
```c
Entrada: "int @ = 42;"
Error: "Carácter no reconocido '@' en línea 1, columna 5"
```

#### Caso 3: Cadenas con Escape
```c
Entrada: "String s = \"Hello\\nWorld\";"
Token: STR con valor procesado "Hello\nWorld"
```

### 2.2 Módulo Parser

#### Caso 1: Expresiones Aritméticas
```java
// Código
int result = (10 + 20) * 3 - 5;

// AST generado
Assignment
├── ID: result
└── Subtract
    ├── Multiply
    │   ├── Add
    │   │   ├── NUM: 10
    │   │   └── NUM: 20
    │   └── NUM: 3
    └── NUM: 5
```

#### Caso 2: Estructuras de Control
```java
// Código
if (x > 0) {
    System.out.println("Positivo");
} else {
    System.out.println("No positivo");
}

// AST generado
IfStatement
├── Condition: Greater
│   ├── ID: x
│   └── NUM: 0
├── ThenBlock
│   └── PrintlnStatement: "Positivo"
└── ElseBlock
    └── PrintlnStatement: "No positivo"
```

### 2.3 Módulo Semántico

#### Caso 1: Verificación de Tipos
```java
int x = 10;
float y = x;      // Casting automático int → float ✓
String s = x;     // Error: incompatible types ❌
```

#### Caso 2: Scope de Variables
```java
{
    int x = 10;    // Contexto local
    {
        int y = x; // Acceso a x del contexto padre ✓
    }
    int z = y;     // Error: y no existe en este contexto ❌
}
```

#### Caso 3: Evaluación de Expresiones
```java
int a = 5;
int b = 3;
int result = a * b + 2;  // Evaluación: 5 * 3 + 2 = 17
```

### 2.4 Módulo GUI

#### Caso 1: Interacción Usuario-Sistema
```text
Usuario escribe código → Editor actualiza → Botón "Ejecutar" → 
Procesamiento → Actualización de paneles (Consola, AST, Símbolos, Errores)
```

#### Caso 2: Visualización de Errores
```text
Error encontrado → Marca en editor → Entrada en tabla de errores →
Mensaje en consola → Destaque visual del problema
```

---

## 3. Ejemplos de Integración

### 3.1 Flujo de Datos Entre Módulos

```c
// 1. main.c - Inicialización
int main(int argc, char *argv[]) {
    list_tokens = InstruccionList_create();
    list_errors = createErrorList();
    SymbolTable_General = Symbol_table_create();
    
    return launch_terminal_ui(argc, argv);
}

// 2. GUI - Callback de ejecución
void on_run_clicked(GtkToolButton *button, gpointer user_data) {
    char *source_code = get_editor_text();
    
    // 3. Lexer/Parser - Análisis
    yyin = create_temp_file(source_code);
    int parse_result = yyparse();
    
    // 4. Semántico - Procesamiento
    semantic_analysis();
    
    // 5. GUI - Actualización
    update_symbols_table_safe(global_widgets->symbols_store, SymbolTable_General);
    update_errors_table_safe(global_widgets->errors_store, list_errors);
    update_ast_report();
}

// 6. Semántico - Análisis principal
void semantic_analysis() {
    Context *contextGlobal = create_global_context();
    generate_simple_ast(list_tokens);
    
    InstruccionNode *curr = list_tokens->head;
    while (curr) {
        semantic_analysis_execute(curr->instr, contextGlobal);
        curr = curr->next;
    }
}
```

### 3.2 Comunicación Módulo AST - GUI

```c
// AST - Generación de diagrama
void generate_simple_ast(InstruccionList *list) {
    FILE *dot_file = fopen("reports/ast.dot", "w");
    
    // Generar DOT notation
    fprintf(dot_file, "digraph AST {\n");
    generate_ast_nodes(dot_file, list);
    fprintf(dot_file, "}\n");
    
    fclose(dot_file);
    
    // Convertir a PNG
    system("dot -Tpng reports/ast.dot -o reports/ast.png");
}

// GUI - Actualización de imagen AST
void update_ast_report() {
    if (global_widgets && global_widgets->ast_view) {
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("reports/ast.png", NULL);
        if (pixbuf) {
            gtk_image_set_from_pixbuf(GTK_IMAGE(global_widgets->ast_view), pixbuf);
            g_object_unref(pixbuf);
        }
    }
}
```

### 3.3 Manejo de Estado Global

```c
// Variables globales compartidas entre módulos
InstruccionList *list_tokens = NULL;      // Parser → Semántico → AST
ErrorList *list_errors = NULL;            // Lexer/Parser → GUI
symbol_table *SymbolTable_General = NULL; // Semántico → GUI
AppWidgets *global_widgets = NULL;        // GUI interno

// Función de limpieza entre ejecuciones
void reset_compiler_state() {
    InstruccionList_clear(list_tokens);
    ErrorList_clear(list_errors);
    Symbol_table_destroy(SymbolTable_General);
    SymbolTable_General = Symbol_table_create();
}
```

---

## 4. Manejo de Errores

### 4.1 Errores Léxicos

```c
// lexer.l - Manejo de caracteres no válidos
.               { showError(); }

void showError() {
    Error *error = Error_create(
        "Léxico",
        "Global",
        "Carácter no reconocido",
        yylineno,
        yycolumn
    );
    ErrorList_addError(list_errors, error);
}
```

### 4.2 Errores Sintácticos

```c
// parser.y - Manejo de errores de sintaxis
int yyerror(const char *s) {
    Error *error = Error_create(
        "Sintáctico",
        "Parser",
        s,
        yylloc.first_line,
        yylloc.first_column
    );
    ErrorList_addError(list_errors, error);
    return 0;
}
```

### 4.3 Errores Semánticos

```c
// semantic/execute.c - Errores de tipos
void execute_assignment(Instruccion *instr, Context *context) {
    symbol *var = Symbol_table_getSymbol(context->symbols_context, instr->value2);
    
    if (!var) {
        Error *error = Error_create(
            "Semántico",
            context->nombre,
            "Variable no declarada",
            instr->line,
            instr->column
        );
        ErrorList_addError(list_errors, error);
        return;
    }
    
    symbol *value = evaluate_expression(instr->expr, context);
    
    if (!is_compatible_types(var->type, value->type)) {
        Error *error = Error_create(
            "Semántico",
            context->nombre,
            "Tipos incompatibles en asignación",
            instr->line,
            instr->column
        );
        ErrorList_addError(list_errors, error);
        return;
    }
    
    // Asignación exitosa
    symbol_update_value(var, value->value);
}
```

### 4.4 Visualización de Errores en GUI

```c
void update_errors_table_safe(GtkListStore *store, ErrorList *list) {
    gtk_list_store_clear(store);
    
    ErrorNode *current = list->head;
    while (current) {
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
            0, current->Error->type,
            1, current->Error->environment,
            2, current->Error->message,
            3, g_strdup_printf("Línea %d, Columna %d", 
                              current->Error->line, 
                              current->Error->column),
            -1);
        current = current->next;
    }
}
```

---

## 5. Extensibilidad

### 5.1 Agregar Nuevos Tokens

```c
// lexer.l - Nuevos tokens
"foreach"       return FOREACH;
"try"           return TRY;
"catch"         return CATCH;
"finally"       return FINALLY;
```

### 5.2 Agregar Nuevas Reglas Gramaticales

```c
// parser.y - Nuevas construcciones sintácticas
try_statement: TRY '{' instrucciones '}' catch_clauses {
    $$ = create_instruction("TRY_STATEMENT", NULL, NULL, NULL, @1.first_line, @1.first_column);
    $$->list = $3;
    $$->list2 = $5;
};

catch_clauses: catch_clauses catch_clause {
    $$ = InstruccionList_append($1, $2);
} | catch_clause {
    $$ = InstruccionList_create();
    $$ = InstruccionList_append($$, $1);
};
```

### 5.3 Agregar Nuevas Operaciones Semánticas

```c
// semantic/execute.c - Nuevas instrucciones
void semantic_analysis_execute(Instruccion *instruction, Context *context) {
    ExecuteType type = get_instruction_type(instruction->type);
    
    switch (type) {
        case TRY_STATEMENT:
            execute_try_statement(instruction, context);
            break;
        case FOREACH_STATEMENT:
            execute_foreach_statement(instruction, context);
            break;
        // ... casos existentes
    }
}

void execute_try_statement(Instruccion *instr, Context *context) {
    // Implementación del manejo de excepciones
    Context *try_context = create_child_context(context, "Try Block");
    
    // Ejecutar bloque try
    execute_instruction_list(instr->list, try_context);
    
    // Manejar catch clauses si hay errores
    if (try_context->has_exception) {
        execute_instruction_list(instr->list2, try_context);
    }
}
```

### 5.4 Agregar Nuevos Paneles GUI

```c
// UI/reports.c - Nuevo panel de debugging
GtkWidget *create_debug_panel() {
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    GtkWidget *text_view = gtk_text_view_new();
    
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(text_view), TRUE);
    
    // Configurar buffer para información de debug
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, "Debug Information:\n", -1);
    
    gtk_container_add(GTK_CONTAINER(scrolled), text_view);
    return scrolled;
}

// Integración en el notebook principal
void add_debug_tab(GtkWidget *notebook) {
    GtkWidget *debug_panel = create_debug_panel();
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), debug_panel, 
                           gtk_label_new("Debug"));
}
```

### 5.5 Sistema de Plugins

```c
// Estructura para plugins
typedef struct Plugin {
    char *name;
    char *version;
    void (*initialize)(void);
    void (*finalize)(void);
    void (*process_ast)(ASTVal *node);
} Plugin;

// Registro de plugins
typedef struct PluginRegistry {
    Plugin **plugins;
    int count;
    int capacity;
} PluginRegistry;

// Carga dinámica de plugins
void load_plugin(const char *plugin_path) {
    void *handle = dlopen(plugin_path, RTLD_LAZY);
    if (!handle) return;
    
    Plugin *(*get_plugin_info)() = dlsym(handle, "get_plugin_info");
    if (get_plugin_info) {
        Plugin *plugin = get_plugin_info();
        register_plugin(plugin);
        plugin->initialize();
    }
}
```

---

## Conclusiones

Los módulos del compilador JavaLang están diseñados para:

1. **Modularidad**: Cada módulo tiene responsabilidades claras
2. **Comunicación efectiva**: Interfaces bien definidas entre módulos
3. **Manejo robusto de errores**: Sistema integral de detección y reporte
4. **Extensibilidad**: Fácil adición de nuevas características
5. **Usabilidad**: Interfaz gráfica intuitiva y completa

Esta arquitectura permite desarrollo, mantenimiento y extensión eficientes del compilador.
