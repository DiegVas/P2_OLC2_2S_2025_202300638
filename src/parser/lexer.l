
%{

#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
#include <stdbool.h>
#include "../structures/parser.h"

void showError();

extern ErrorList *list_errors;

int yycolumn = 1;
int inside_array = 0;



/* Se ejecuta antes de cada accion, actualiza yylloc y columna */
#define YY_USER_ACTION                                   \
    yylloc.first_line   = yylineno;                      \
    yylloc.first_column = yycolumn;                      \
    yylloc.last_line    = yylineno;                      \
    yylloc.last_column  = yycolumn + yyleng - 1;         \
    yycolumn           += yyleng;


%}

%option noyywrap yylineno

/* Definiciones */

NUM [0-9]+
DEC [0-9]+"."[0-9]+
DECF [0-9]+"."[0-9]+"f"
ID [A-Za-z][A-Za-z0-9_]*
STR \"([^\\"]|\\.)*\"
CHR \'([^\\']|\\.)*\'
BLANK [ \r\t]+
BREAK_LINE \n

%%

"//"[^\n]*      { /* Ignorar comentarios de una línea */ }

"/*"            { /* Inicio de comentario multilínea */
    int c;
    while ((c = input()) != 0) {
        if (c == '\n') {
            yylineno++;
            yycolumn = 1;
        } else {
            yycolumn++;
        }
        if (c == '*') {
            if ((c = input()) == '/') {
                yycolumn++;
                break;
            } else {
                unput(c);
            }
        }
    }
}

";" return ';';
":" return ':';
"," return ',';
"." return '.';

"==" return EQUALS;

"=" return '=';

"(" return '(';

")" return ')';

"{" return '{';

"}" return '}';

"[" return '[';
"]" return ']';

"++" return INCREMENT;

"&&" return AND;

"||" return OR;

">=" return GREATER_EQUALS;

"<=" return LESS_EQUALS;

"<<" return LEFT_SHIFT;

">>" return RIGHT_SHIFT;

"+=" return PLUS_ASSIGN;

"-=" return MINUS_ASSIGN;

"*=" return MULT_ASSIGN;

"/=" return DIV_ASSIGN;

"%=" return MOD_ASSIGN;

"&=" return AND_ASSIGN;

"|=" return OR_ASSIGN;

"^=" return XOR_ASSIGN;

"<<=" return LEFT_SHIFT_ASSIGN;

">>=" return RIGHT_SHIFT_ASSIGN;

"!=" return NOT_EQUALS;

"!" return NOT;

"+" return '+';

"-" return '-';

"*" return '*';

"/" return '/';

"%" return '%';

"&" return '&';

"|" return '|';

"^" return '^';

"<" return '<';

">" return '>';

"int" return INT;

"float" return FLOAT;

"double" return DOUBLE;

"String" return STRING;

"boolean" return BOOL;

"char" return CHAR;

"null" return NULL_EXP;

"final" return FINAL;

"if" return IF;

"else" return ELSE;

"System.out.println" return PRINTLN;

".equals" return EQUALS_OP;

"switch" return SWITCH;

"case" return CASE;

"break" return BREAK;

"continue" return CONTINUE;

"default" return DEFAULT;

"while" return WHILE;

"for" return FOR;

"new" return NEW;

"Integer" return INTEGER_OBJ;

"parseInt" return PARSEINT;

"Double" return DOUBLE_OBJ;

"parseDouble" return PARSEDOUBLE;

"Float" return FLOAT_OBJ;

"parseFloat" return PARSEFLOAT;

"valueOf" return VALUEOF;

"join" return JOIN;

"Arrays" return ARRAYS;

"indexOf" return INDEXOF;

"length" return LENGTH;

"add" return ADD;

"return" return RETURN;

"void" return VOID;

"public" return PUBLIC;

"static" return STATIC;

"main" return MAIN;

"true" {
    yylval.sval = strdup(yytext);
    return BOOLEAN;
}

"false" {
    yylval.sval = strdup(yytext);
    return BOOLEAN;
}

{NUM}      {
    yylval.sval = strdup(yytext);
    return NUM;
}

{DEC}      {
    yylval.sval = strdup(yytext);
    return DEC;
}

{DECF} {
    yylval.sval = strdup(yytext);
    return DECF;
}

{ID}       {
    yylval.sval = strdup(yytext);
    return ID;
}

{STR} {
    size_t len = strlen(yytext);
    char *sin_comillas = (char *)malloc(len - 1); 
    strncpy(sin_comillas, yytext + 1, len - 2);
    sin_comillas[len - 2] = '\0';
    yylval.sval = sin_comillas;
    return STR;
}

{CHR} {
    size_t len = strlen(yytext);
    char *sin_comillas = (char *)malloc(len - 1);
    strncpy(sin_comillas, yytext + 1, len - 2);
    sin_comillas[len - 2] = '\0';
    yylval.sval = sin_comillas;
    return CHR;
}

{BREAK_LINE}    {
    yycolumn = 1; // Reinicia la columna al inicio de cada línea
    return BREAK_LINE;
}

{BLANK}    { /* Ignorar espacios en blanco */ }

.       { showError(); printf("Error léxico: carácter inesperado '%s'\n", yytext); return(OTHER); }


%%


void showError(){
    printf("Other input");
    Error *error = malloc(sizeof(Error));
    error->environment = strdup("-");
    error->type = strdup("Léxico");
    error->message = strdup("Error léxico: carácter inesperado");
    error->line = yylloc.first_line;
    error->column = yylloc.first_column;
    insertError(list_errors, error);
}