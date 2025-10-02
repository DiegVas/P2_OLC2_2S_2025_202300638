
%{
#include <stdio.h>
#include <string.h>
#include "../structures/parser.h"

int yylex();
int yyerror(const char *s);

	extern InstruccionList *list_tokens;
    extern ErrorList *list_errors;

%}

%define parse.error verbose

%code requires {
    typedef struct InstruccionList InstruccionList;
    typedef struct Instruccion Instruccion;
    typedef struct Expression Expression;
    typedef struct IfNodeList IfNodeList;
    typedef struct IfData IfData;
    typedef struct SwitchData SwitchData;
    typedef struct CaseNodeList CaseNodeList;
    typedef struct List List;
    typedef struct ListData ListData;
    typedef struct VectorList VectorList;
    typedef struct MatrixList MatrixList;
    typedef struct ExpressionList ExpressionList;
    typedef struct paramsList paramsList;
    typedef struct DimensionsList DimensionsList;
}

%locations

%union {
    char* sval;
    int ival;
    Instruccion* instr;
    InstruccionList* instrList;
    Expression* expr;
    ExpressionList* exprList;
    IfData* ifdata;
    IfNodeList* ifnodelist;
    CaseNodeList* casenodelist;
    SwitchData* switchdata;
    List* list;
    ListData* listdata;
    VectorList* VList;
    MatrixList* MList;
    paramsList* paramlist;
    DimensionsList* dimlist;
}

/* Tokens */

/* Valores */

%token <sval> STR CHR BOOLEAN ID OTHER NUM DEC DECF
%token BREAK_LINE

/* Palabras reservadas */

%token <sval> INT STRING CHAR FLOAT DOUBLE BOOL FINAL PRINTLN
%token NULL_EXP
%token IF ELSE SWITCH CASE BREAK DEFAULT CONTINUE
%token WHILE FOR
%token EQUALS_OP
%token NEW
%token INTEGER_OBJ PARSEINT DOUBLE_OBJ PARSEDOUBLE FLOAT_OBJ PARSEFLOAT VALUEOF JOIN
%token RETURN VOID

/* Simboloes dobles o mas */

%token PUBLIC STATIC MAIN
%token LEFT_SHIFT RIGHT_SHIFT
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN 
%token AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN
%token EQUALS NOT_EQUALS
%token AND OR NOT
%token GREATER_EQUALS LESS_EQUALS
%token INCREMENT
%token ARRAYS INDEXOF LENGTH ADD

/* Tipo de los no-terminales que llevan valor */
%type <instrList> program sentences
%type <instr> sentence instruction
%type <instr> declaration assignment WHILE_STATEMENT
%type <sval> primitive_types
%type <expr> primitive_values
%type <expr> expression;
%type <exprList> exprList dimensions_expressions;
%type <instr> assignment_expression;
%type <ifdata> IF_STATEMENT
%type <instrList> ELSE_STATEMENT
%type <ifnodelist> IF_LIST
%type <switchdata> SWITCH_STATEMENT
%type <casenodelist> CASES
%type <instrList> DEFAULT_CASE
%type <instr> FOR_STATEMENT FOREACH_STATEMENT
%type <ival> dimensions;
%type<list> dimension_values_list dimension_expression
%type<listdata> dimension_value
%type optional_newlines
%type <VList> vectorList
%type <MList> matrixList
%type <paramlist> paramsList
%type <dimlist> dimensions_value_list


/* Precedencias y asociatividades */

/* Asignación (más baja, derecha‑asociativa) */
%right '=' PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%right AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN

/* Lógicas */
%left OR          /* || */
%left AND         /* && */

/* Bitwise */
%left '|'         /* | */
%left '^'         /* ^ */
%left '&'         /* & */

/* Comparaciones */
%nonassoc EQUALS NOT_EQUALS          /* == != */
%nonassoc '<' '>' LESS_EQUALS GREATER_EQUALS  /* < > <= >= */

/* Shifts */
%left LEFT_SHIFT RIGHT_SHIFT         /* << >> */

/* Aritmética binaria */
%left '+' '-' 
%left '*' '/' '%'

/* Unarios (más alta) */
%right NOT INCREMENT                 /* ! ++ (prefijo) */
%right UMINUS                        /* para - unario */

/* Acceso a arrays (más alta precedencia) */
%left '[' ']'

%%

%start program;


program
    : sentences { 
        printf("Programa completo\n");
        // Copiar todas las instrucciones a la lista global
        if ($1 && $1->head) {
            InstruccionNode *curr = $1->head;
            while (curr) {
                InstruccionList_insert(list_tokens, curr->instr);
                curr = curr->next;
            }
        }
        $$ = $1;
     }
    | sentences PUBLIC STATIC VOID MAIN '(' ')' '{' sentences '}' {
        // Código antes del main + main
        // $1 son las instrucciones antes del main
        // $9 son las instrucciones dentro del main
        printf("Programa con main y código previo\n");
        
        // Combinar ambas listas de instrucciones
        if ($1 && $1->head) {
            InstruccionNode *curr = $1->head;
            while (curr) {
                InstruccionList_insert(list_tokens, curr->instr);
                curr = curr->next;
            }
        }
        if ($9 && $9->head) {
            InstruccionNode *curr = $9->head;
            while (curr) {
                InstruccionList_insert(list_tokens, curr->instr);
                curr = curr->next;
            }
        }
        $$ = $1;
    };

sentences
    : sentences sentence
        { 
            if ($2 != NULL) {
                InstruccionList_insert($1, $2);
                $$ = $1;
            } else {
                $$ = $1;
            }
        }
    | /* empty */ 
        { 
            $$ = InstruccionList_create();
        };

sentence
    : instruction separator{
        $$ = $1;
    }
    | separator {
        $$ = NULL;
    }
    | error separator {
        // Recuperación de error: saltar hasta el siguiente separador
        yyerrok;
        $$ = NULL;
    };

separator
    : BREAK_LINE {}
    | ';' { /* skip */ };


instruction:
    '{' sentences '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "BLOCK";
        instP->id = "BLOCK";
        instP->body = $2;
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP; }
    | ID '(' ')' {
        fprintf(stderr, "Función void llamada: %s\n", $1);
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "VOID_CALL";
        instP->id = $1;
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP;
    }
    | declaration {
        $1->InstType = "DECLARATION";
        $1->line = @1.first_line;
        $$ = $1;
    }
    | PRINTLN '(' expression ')' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "PRINTLN";
        instP->value = $3;
        instP->line = @1.first_line;
        $$ = instP;
    }
    | PRINTLN '(' ')' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "PRINTLN";
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("CHARACTER");
        exp->value = strdup("\n");
        instP->value = exp;
        instP->line = @1.first_line;
        $$ = instP;
    }
    | assignment {
        $1->InstType = "ASSIGNMENT";
        $1->line = @1.first_line;
        $$ = $1;
    }
    | IF_STATEMENT {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "IF_STATEMENT";
        instP->ifData = $1;
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP;
    }
    | SWITCH_STATEMENT {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "SWITCH_STATEMENT";
        instP->switchData = $1;
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP;
    }
    | WHILE_STATEMENT {
        $1->InstType = "WHILE_STATEMENT";
        $1->line = @1.first_line;
        $$ = $1; 
    }
    | FOREACH_STATEMENT{
        $1->InstType = "FOREACH_STATEMENT";
        $1->line = @1.first_line;
        $$ = $1;
    }
    | FOR_STATEMENT {
        $1->InstType = "FOR_STATEMENT";
        $1->line = @1.first_line;
        $$ = $1; 
    }
    | BREAK {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "BREAK";
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP;
    }
    | CONTINUE {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "CONTINUE";
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP;
    } 
    | RETURN expression {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "RETURN";
        instP->value = $2;
        instP->line = @1.first_line;
        instP->column = @1.first_column;
        $$ = instP;
    }
    
    ;

//* Asignacion de valores a variables ya existentes

assignment: 
    ID '=' expression {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $1;
        instP->value = $3;
        instP->column = @1.first_column;
        $$ = instP; }
    //* ID[expression][expression]... = expression (asignación a arrays multidimensionales)
    | ID dimensions_expressions '=' expression {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $1;
        instP->column = @1.first_column;
        instP->value = $4;
        
        // Manejar según el número de dimensiones
        int size = ExpressionList_size($2);
        if (size == 1) {
            instP->IndexVector = ExpressionList_get($2, 0);
        } else if (size == 2) {
            instP->IndexVector = ExpressionList_get($2, 1); // Segunda dimensión
            instP->IndexMatrix = ExpressionList_get($2, 0); // Primera dimensión
        } else {
            instP->indexList = $2; // Múltiples dimensiones
        }
        
        $$ = instP; }
    //* ID += expression
    | assignment_expression PLUS_ASSIGN expression {
        $1->value->type = "SUM";
        $1->value->value = strdup("+");
        $1->value->right = $3;
        $$ = $1; }
    //* ID -= expression
    | assignment_expression MINUS_ASSIGN expression {
        $1->value->type = "SUBTRACT";
        $1->value->value = strdup("-");
        $1->value->right = $3;
        $$ = $1; }
    //* ID *= expression
    | assignment_expression MULT_ASSIGN expression {
        $1->value->type = "MULTIPLICATION";
        $1->value->value = strdup("*");
        $1->value->right = $3;
        $$ = $1; }
    //* ID /= expression
    | assignment_expression DIV_ASSIGN expression {
        $1->value->type = "DIVIDE";
        $1->value->value = strdup("/");
        $1->value->right = $3;
        $$ = $1; }
    //* ID %= expression
    | assignment_expression MOD_ASSIGN expression {
        $1->value->type = "MODULO";
        $1->value->value = strdup("%");
        $1->value->right = $3;
        $$ = $1; }
    //* ID &= expression
    | assignment_expression AND_ASSIGN expression {
        $1->value->type = "BITWISE_AND";
        $1->value->value = strdup("&");
        $1->value->right = $3;
        $$ = $1; }
    //* ID |= expression
    | assignment_expression OR_ASSIGN expression {
        $1->value->type = "BITWISE_OR";
        $1->value->value = strdup("|");
        $1->value->right = $3;
        $$ = $1; }
    //* ID ^= expression
    | assignment_expression XOR_ASSIGN expression {
        $1->value->type = "BITWISE_XOR";
        $1->value->value = strdup("^");
        $1->value->right = $3;
        $$ = $1; }
    //* ID <<= expression
    | assignment_expression LEFT_SHIFT_ASSIGN expression {
        $1->value->type = "BITWISE_LEFT_SHIFT";
        $1->value->value = strdup("<<");
        $1->value->right = $3;
        $$ = $1; }
    //* ID >>= expression
    | assignment_expression RIGHT_SHIFT_ASSIGN expression {
        $1->value->type = "BITWISE_RIGHT_SHIFT";
        $1->value->value = strdup(">>");
        $1->value->right = $3;
        $$ = $1; }
    //* ID++
    | assignment_expression INCREMENT {
        $1->value->type = "SUM";
        $1->value->value = strdup("+");
        $1->value->right = (Expression*)calloc(1, sizeof(Expression));
        $1->value->right->type = "INTEGER";
        $1->value->right->value = strdup("1");
        $$ = $1; };

assignment_expression: 
    ID {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $1;
        instP->column = @1.first_column;

        instP->value = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left->type = "ID";
        instP->value->left->value = strdup($1);
        $$ = instP;
        }
    | ID '[' expression ']' {
        
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $1;
        instP->IndexVector = $3;
        instP->column = @1.first_column;

        
        instP->value = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left->type = "VECTOR_ACCESS";
        instP->value->left->value = strdup($1);
        instP->value->left->left = $3;

    

        $$ = instP;
        };



//* Declaracion de variables y constantes

declaration: 
    //* int ID = 15
    primitive_types ID '=' expression {

        // ? Crear instrucción

        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $2;
        instP->type = $1;
        instP->column = @2.first_column;
        instP->symbolType = "VARIABLE";
        instP->value = $4;
        $$ = instP; }  
    // * int x
    | primitive_types ID {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $2;
        instP->type = $1;
        instP->column = @2.first_column;
        instP->symbolType = "VARIABLE";

        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = $1;
        exp->value = strdup("UNDEFINED");

        instP->value = exp;
        $$ = instP; }
    // * final int ID = 15
    | FINAL primitive_types ID '=' expression {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $3;
        instP->type = $2;
        instP->column = @3.first_column;
        instP->symbolType = "CONSTANT";
        instP->value = $5;
        $$ = instP; }
    //* int[] id = {1,2,3}
    | primitive_types '[' ']' ID '=' '{' vectorList '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $4;
        instP->type = $1;
        instP->column = @3.first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = $7;
        $$ = instP; }
    //* int[] id = new int[expr]
    | primitive_types '[' ']' ID '=' NEW primitive_types '[' NUM ']' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $4;
        instP->type = $1;
        instP->column = @3.first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = (VectorList*)calloc(1, sizeof(VectorList));
        for (int i = 0; i < atoi($9); i++) {
            Expression* exp = (Expression*)calloc(1, sizeof(Expression));
            exp->type = $7;
            exp->value = strdup("UNDEFINED");
            VectorList_addExp(instP->vectorValues, exp);
        }
        $$ = instP; }
    //* int[] id = id.add(expr)
    | primitive_types '[' ']' ID '=' ID '.' ADD '(' expression ')' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $4;
        instP->type = $1;
        instP->column = @3.first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = (VectorList*)calloc(1, sizeof(VectorList));
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ADD";
        exp->value = strdup($6);
        exp->left = $10;
        VectorList_addExp(instP->vectorValues, exp);
        $$ = instP; }
    | //* int[][] id = {{},{}}
    primitive_types '[' ']' '[' ']' ID '=' '{' optional_newlines matrixList '}'{
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $6;
        instP->type = $1;
        instP->column = @5.first_column;
        instP->symbolType = "MATRIX";
        instP->matrixValues = $10;
        $$ = instP;
    }
    | //* int[][] id = new int[expr][expr]
    primitive_types '[' ']' '[' ']' ID '=' NEW primitive_types '[' NUM ']' '[' NUM ']' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $6;
        instP->type = $1;
        instP->column = @5.first_column;
        instP->symbolType = "MATRIX";
        instP->matrixValues = (MatrixList*)calloc(1, sizeof(MatrixList));
        for (int i = 0; i < atoi($11); i++) {
            VectorList* vecList = (VectorList*)calloc(1, sizeof(VectorList));
            for (int j = 0; j < atoi($14); j++) {
                Expression* exp = (Expression*)calloc(1, sizeof(Expression));
                exp->type = $9;
                exp->value = strdup("UNDEFINED");
                VectorList_addExp(vecList, exp);
            }
            MatrixList_add(instP->matrixValues, vecList);
            }
        $$ = instP; }
    //* int id (params) { ... }
    | primitive_types ID '(' paramsList ')' '{' BREAK_LINE sentences '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $2;
        instP->type = $1;
        instP->column = @2.first_column;
        instP->symbolType = "FUNCTION";
        instP->functionData = (Function*)calloc(1, sizeof(Function));
        instP->functionData->parameters = $4;
        instP->functionData->body = $8;
        $$ = instP; }
    //* void id { ... }
    | VOID ID '(' ')' '{' BREAK_LINE sentences '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $2;
        instP->column = @2.first_column;
        instP->symbolType = "VOID";
        instP->functionData = (Function*)calloc(1, sizeof(Function));
        instP->functionData->body = $7;
        $$ = instP; }
    //* int ID[] = expression
    | primitive_types ID dimensions '=' dimension_expression {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $2;
        instP->type = $1;
        instP->arrayValues = (SymbolList*)calloc(1, sizeof(SymbolList));
        instP->arrayValues->dimension = $3;
        instP->arrayValues->values = $5;
        instP->column = @3.first_column;
        instP->symbolType = "LIST";
        $$ = instP; }
    | primitive_types ID dimensions '=' NEW primitive_types dimensions_value_list {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = $2;
        instP->type = $1;
        instP->arrayValues = (SymbolList*)calloc(1, sizeof(SymbolList));
        instP->arrayValues->dimension = $3;
        
        // Usar la función multidimensional para crear la estructura
        instP->arrayValues->values = create_multidimensional_array($7->dimensions, $7->count, $6);
        
        // Liberar la estructura temporal
        free($7->dimensions);
        free($7);
        
        instP->column = @3.first_column;
        instP->symbolType = "LIST";
        $$ = instP; 
    }

//* Tipos primitivos

primitive_types:
    INT { $$ = strdup("INTEGER"); }
    | STRING { $$ = strdup("STRING"); }
    | DOUBLE { $$ = strdup("DOUBLE"); }
    | FLOAT { $$ = strdup("FLOAT"); }
    | BOOL { $$ = strdup("BOOLEAN"); }
    | CHAR { $$ = strdup("CHARACTER"); };

//* Valores primitivos

primitive_values:
    NUM { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("INTEGER");
        exp->value = strdup($1);

        $$ = exp; }
    | STR { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("STRING");
        exp->value = strdup($1);

        $$ = exp; }
    | DEC { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("DOUBLE");
        exp->value = strdup($1);

        $$ = exp; }
    | DECF { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("FLOAT");
        exp->value = strdup($1);

        $$ = exp; }
    | BOOLEAN { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("BOOLEAN");
        exp->value = strdup($1);

        $$ = exp; }
    | CHR { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("CHARACTER");
        exp->value = strdup($1);
        $$ = exp; }
    | NULL_EXP { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("NULL");
        exp->value = strdup("null");
        $$ = exp; }
    ;



expression:
      primitive_values { $$ = $1; }
    | ID {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ID";
        exp->value = strdup($1);
        $$ = exp;
        }
    | '-' expression %prec '-' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "NEGATIVE";
        exp->value = strdup("-");
        exp->left = $2;
        $$ = exp; }
    | expression '+' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "SUM";
        exp->value = strdup("+");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | expression '-' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "SUBTRACT";
        exp->value = strdup("-");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | expression '*' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "MULTIPLICATION";
        exp->value = strdup("*");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | expression '/' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "DIVIDE";
        exp->value = strdup("/");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | expression '%' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "MODULO";
        exp->value = strdup("%");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | '(' expression ')' { $$ = $2; }
    | '(' primitive_types ')' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "CASTING";
        exp->value = $2;
        exp->left = $4;
        $$ = exp; }
        
    | expression '&' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_AND";
        exp->value = strdup("&");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | expression '|' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_OR";
        exp->value = strdup("|");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    | expression '^' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_XOR";
        exp->value = strdup("^");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression << expression
    | expression LEFT_SHIFT expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_LEFT_SHIFT";
        exp->value = strdup("<<");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    
    //* expression >> expression
    | expression RIGHT_SHIFT expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_RIGHT_SHIFT";
        exp->value = strdup(">>");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* ID.equals ( expression )
    | ID EQUALS_OP '(' expression ')' {
        Expression *exp = (Expression*)calloc(1, sizeof(Expression));   
        exp->type = "EQUALS_OP";
        exp->value = strdup(".equals");
        exp->left = (Expression*)calloc(1, sizeof(Expression));
        exp->left->type = "ID";
        exp->left->value = strdup($1);
        exp->right = $4;
        $$ = exp; }
    //* expression == expression
    | expression EQUALS expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "EQUALS";
        exp->value = strdup("==");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression != expression
    | expression NOT_EQUALS expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "NOT_EQUALS";
        exp->value = strdup("!=");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression > expression
    | expression '>' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "GREATER";
        exp->value = strdup(">");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression < expression
    | expression '<' expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LESS";
        exp->value = strdup("<");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression >= expression
    | expression GREATER_EQUALS expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "GREATER_EQUALS";
        exp->value = strdup(">=");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression <= expression
    | expression LESS_EQUALS expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LESS_EQUALS";
        exp->value = strdup("<=");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression && expression
    | expression AND expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_AND";
        exp->value = strdup("&&");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* expression || expression
    | expression OR expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_OR";
        exp->value = strdup("||");
        exp->left = $1;
        exp->right = $3;
        $$ = exp; }
    //* !expression
    | NOT expression {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_NOT";
        exp->value = strdup("!");
        exp->left = $2;
        $$ = exp; }
    //* Integer.parseInt(<cadena>);
    | INTEGER_OBJ '.' PARSEINT '(' expression ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEINT";
        exp->value = strdup("Integer.parseInt");
        exp->left = $5;
        $$ = exp; }
    //* Double.parseDouble(<cadena>);
    | DOUBLE_OBJ '.' PARSEDOUBLE '(' expression ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEDOUBLE";
        exp->value = strdup("Double.parseDouble");
        exp->left = $5;
        $$ = exp; }
    //* Float.parseFloat(<cadena>);
    | FLOAT_OBJ '.' PARSEFLOAT '(' expression ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEFLOAT";
        exp->value = strdup("Float.parseFloat");
        exp->left = $5;
        $$ = exp; }
    //* String.valueOf(<expresion>);
    | STRING '.' VALUEOF '(' expression ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "VALUEOF";
        exp->value = strdup("String.valueOf");
        exp->left = $5;
        $$ = exp; }
    //* String.join(<separador>, <listaExpresiones>);
    | STRING '.' JOIN '(' exprList ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "JOIN";
        exp->value = strdup("String.join");
        exp->list = $5;
        $$ = exp; }
    //* Arrays.indexOf(<arreglo>, <valor>);
    | ARRAYS '.' INDEXOF '(' ID ',' expression ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "INDEXOF";
        exp->value = $5;
        exp->left = $7;
        $$ = exp; }
    //* <arreglo>.length
    | ID '.' LENGTH {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LENGTH";
        exp->value = strdup($1);
        $$ = exp; }
    //* <arreglo>.add(<valor>);
    | ID '.' ADD '(' expression ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ADD";
        exp->value = strdup($1);
        exp->left = $5;
        $$ = exp; }
    //* ID[expression][expression]... - Acceso a arrays multidimensionales
    | ID dimensions_expressions {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        
        // Determinar el tipo según el número de dimensiones
        int size = ExpressionList_size($2);
        if (size == 1) {
            exp->type = "VECTOR_ACCESS";
            exp->left = ExpressionList_get($2, 0); // Primera dimensión
        } else if (size == 2) {
            exp->type = "MATRIX_ACCESS";
            exp->left = ExpressionList_get($2, 0);  // Primera dimensión
            exp->right = ExpressionList_get($2, 1); // Segunda dimensión
        } else {
            exp->type = "ARRAY_ACCESS";
            exp->list = $2; // Múltiples dimensiones
        }
        
        exp->value = $1;
        $$ = exp;
    }
    //* id(params)
    | ID '(' exprList ')' {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "FUNCTION_CALL";
        exp->value = strdup($1);
        exp->list = $3;
        $$ = exp;
    };

exprList:
    /* empty */ { 
        ExpressionList* exprList = create_expression_list();
        $$ = exprList;
    }
    | expression {
        ExpressionList* exprList = create_expression_list();
        ExpressionList_add(exprList, $1);
        $$ = exprList;
     }
    | exprList ',' expression {
        ExpressionList_add($1, $3);
        $$ = $1;
     }


//* CONDICIONALES

// ? IF ELSE
IF_STATEMENT :
    IF '(' expression ')'  '{' BREAK_LINE  sentences '}' IF_LIST  ELSE_STATEMENT {
        IfData* ifdata = (IfData*)calloc(1, sizeof(IfData));
        ifdata->condition = $3;
        ifdata->block = $7;
        ifdata->elseIfs = $9;
        ifdata->elseBlock = $10;
        $$ = ifdata;
    };

IF_LIST : 
    /* empty */ { $$ = createIfNodeList(); }
    |IF_LIST  ELSE IF '(' expression ')'  '{' BREAK_LINE  sentences '}' {
        IfData* elseIfNode = (IfData*)malloc(sizeof(IfData));
        elseIfNode->condition = $5;
        elseIfNode->block = $9;
        insertIfNode($1, elseIfNode);
        $$ = $1;
    };

ELSE_STATEMENT: 
    /* empty */ { $$ = NULL; }
    | ELSE '{' BREAK_LINE sentences '}' { $$ = $4; };

// ? SWITCH CASE
SWITCH_STATEMENT:
    SWITCH '(' ID ')' '{' BREAK_LINE CASES DEFAULT_CASE '}' {
        SwitchData* switchdata = (SwitchData*)malloc(sizeof(SwitchData));
        switchdata->condition = strdup($3);
        switchdata->cases = $7;
        switchdata->defaultCase = $8;
        $$ = switchdata;
    };



CASES:
    /* empty */ { $$ = CaseNodeList_create(); }
    | CASES CASE primitive_values ':' BREAK_LINE sentences BREAK ';' BREAK_LINE {
        CaseData* new_case = (CaseData*)malloc(sizeof(CaseData));
        new_case->condition = $3;
        new_case->block = $6;
        CaseNodeList_add($1, new_case);
        $$ = $1;
    };


DEFAULT_CASE:
    /* empty */ { $$ = NULL; }
    | DEFAULT ':' BREAK_LINE sentences { $$ = $4; };


// * BLUCLES

// ? WHILE

WHILE_STATEMENT:
    WHILE '(' expression ')' '{' BREAK_LINE sentences '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->whileData = (WhileData*)malloc(sizeof(WhileData));
        instP->whileData->condition = $3;
        instP->whileData->block = $7;
        instP->column = @1.first_column;
        $$ = instP;
    };

// ? FOR SIMPLE

FOR_STATEMENT:
    FOR '(' declaration ';' expression ';' ID INCREMENT ')' '{' BREAK_LINE sentences '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->forData = (ForData*)malloc(sizeof(ForData));
        instP->forData->init = $3;
        instP->forData->init->InstType = "DECLARATION";
        instP->forData->init->line = @1.first_line;
        instP->forData->condition = $5;

        Instruccion* updateInst = (Instruccion*)malloc(sizeof(Instruccion));
        updateInst->id = $7;
        updateInst->InstType = "ASSIGNMENT";
        updateInst->value = (Expression*)calloc(1, sizeof(Expression));
        updateInst->value->left = (Expression*)calloc(1, sizeof(Expression));
        updateInst->value->left->type = "ID";
        updateInst->value->left->value = strdup($7);
        updateInst->value->type = "SUM";
        updateInst->value->value = strdup("+");
        updateInst->value->right = (Expression*)calloc(1, sizeof(Expression));
        updateInst->value->right->type = "INTEGER";
        updateInst->value->right->value = strdup("1");

        instP->forData->update = updateInst;
        instP->forData->block = $12;
        instP->column = @1.first_column;
        $$ = instP;
    };

FOREACH_STATEMENT:
    FOR '(' primitive_types ID ':' ID ')' '{' BREAK_LINE sentences '}' {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->forEachData = (ForEachData*)malloc(sizeof(ForEachData));
        instP->forEachData->type = $3;
        instP->forEachData->item = $4;
        instP->forEachData->array = $6;
        instP->forEachData->block = $10;
        instP->column = @1.first_column;
        $$ = instP;
    };
//* Manejo de Arreglos

dimensions
    : /* empty */ { $$ = 0; }
    | dimensions '[' ']' { $$ = $1 + 1; };

dimensions_value_list
    : '[' NUM ']' { 
        DimensionsList* dimList = (DimensionsList*)malloc(sizeof(DimensionsList));
        dimList->dimensions = (int*)malloc(sizeof(int));
        dimList->dimensions[0] = atoi($2);
        dimList->count = 1;
        $$ = dimList;
    }
    | dimensions_value_list '[' NUM ']' { 
        $1->dimensions = (int*)realloc($1->dimensions, sizeof(int) * ($1->count + 1));
        $1->dimensions[$1->count] = atoi($3);
        $1->count += 1;
        $$ = $1;
    };

dimensions_expressions:
    '[' expression ']' { 
        ExpressionList* exprList = create_expression_list();
        ExpressionList_add(exprList, $2);
        $$ = exprList;
    }
    | dimensions_expressions '[' expression ']' {
        ExpressionList_add($1, $3);
        $$ = $1;
     }

//? Vectores
vectorList
    : /* empty */ { 
        VectorList* vecList = VectorList_create();
        $$ = vecList;
    }
    | expression {
        VectorList* vecList = VectorList_create();
        VectorList_addExp(vecList, $1);
        $$ = vecList;
     }
    | vectorList ',' expression {
        VectorList_addExp($1, $3);
        $$ = $1;
     }


//? Matrices
matrixList
    : /* empty */ { 
        MatrixList* matList = MatrixList_create();
        $$ = matList;
    }
    | '{'vectorList '}' optional_newlines {
        MatrixList* matList = MatrixList_create();
        MatrixList_add(matList, $2);
        $$ = matList;
     }
    |  matrixList ',' optional_newlines '{' vectorList '}'  optional_newlines{
        MatrixList_add($1, $5);
        $$ = $1;
     }

dimension_expression: 
    '{' optional_newlines dimension_values_list optional_newlines '}' {$$ = $3; };

dimension_values_list
    : /* empty */ {  $$ = List_create(); }
    | dimension_value optional_newlines { 
        List* list = List_create(); 
        List_add(list, $1); 
        $$ = list; 
    }
    | dimension_values_list ',' optional_newlines dimension_value optional_newlines {List_add($1, $4); $$ = $1;};

dimension_value:
    expression { ListData* data = (ListData*)calloc(1, sizeof(ListData));
                  data->exprData = $1;
                  $$ = data; }
    | dimension_expression {
        ListData* data = (ListData*)calloc(1, sizeof(ListData));
        data->listData = $1;
        $$ = data;
    };

    optional_newlines
    : /* empty */
    | optional_newlines BREAK_LINE
    ;


//* Manejo de funciones

paramsList: 
    /* empty */ { $$ = createParamsList(); }
    | primitive_types ID {
        paramsList* paramList = createParamsList();
        addParam(paramList, $1, $2);
        $$ = paramList;
     }
    | primitive_types '[' ']' ID {
        paramsList* paramList = createParamsList();
        // Puedes usar un tipo especial, por ejemplo: "VECTOR_INTEGER"
        char* vectorType = (char*)malloc(strlen($1) + 8);
        sprintf(vectorType, "VECTOR_%s", $1);
        addParam(paramList, vectorType, $4);
        $$ = paramList;
     }
    | paramsList ',' primitive_types ID {
        addParam($1, $3, $4);
        $$ = $1;
     }
    | paramsList ',' primitive_types '[' ']' ID {
        char* vectorType = (char*)malloc(strlen($3) + 8);
        sprintf(vectorType, "VECTOR_%s", $3);
        addParam($1, vectorType, $6);
        $$ = $1;
     }

%%

// Función para reinicializar el estado del parser
void reset_parser_state() {
    // Reinicializar solo las variables básicas del lexer
    extern int yylineno;
    extern int yycolumn; 
    yylineno = 1;
    yycolumn = 1;
}

int yyerror(const char *s)
{
    extern YYLTYPE yylloc;
    
    // Crear mensaje de error más detallado
    char detailed_message[512];
    snprintf(detailed_message, sizeof(detailed_message), 
             "%s en línea %d, columna %d", s, yylloc.first_line, yylloc.first_column);
    
    printf("Syntax Error: %s\n", detailed_message);
    
    // Verificar que list_errors esté inicializada
    if (list_errors == NULL) {
        list_errors = createErrorList();
    }
    
    Error *error = malloc(sizeof(Error));
    error->type = strdup("Sintáctico");
    error->environment = strdup("Global");
    error->message = strdup(detailed_message);
    error->line = yylloc.first_line;
    error->column = yylloc.first_column;
    
    insertError(list_errors, error);
    
    // Limpiar el estado del parser para mejor recuperación
    extern int yychar;
    yychar = YYEMPTY;
    
    // Continuar con el análisis (no abortar)
    return 0;
}