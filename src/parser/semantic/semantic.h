#include "../structures/parser.h"
#include <string.h>

void semantic_analysis();
void semantic_analysis_execute(Instruccion *instruction, Context *context);

typedef enum
{
    TYPE_CHARACTER = 0,
    TYPE_INTEGER = 1,
    TYPE_FLOAT = 2,
    TYPE_DOUBLE = 3,
    TYPE_STRING = 4,
    TYPE_NULL = 5,
    TYPE_UNDEFINED = 6

} OperativeType;

typedef struct
{
    double num_value;
    char *str_value;
    OperativeType result_type;
} ConvertedValue;

typedef enum ExecuteType
{
    DECLARATION,
    ASSIGNMENT,
    EXP_PRINTLN,
    IF_STATEMENT,
    SWITCH_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    FOREACH_STATEMENT,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,
    RETURN_STATEMENT,
    VOID_CALL,
    BLOCK_STATEMENT,
    UNKNOWN
} ExecuteType;

typedef enum ExpressionType
{
    EXP_NULL,
    EXP_INTEGER,
    EXP_FLOAT,
    EXP_STRING,
    EXP_BOOLEAN,
    EXP_CHARACTER,
    EXP_DOUBLE,
    EXP_SUM,
    EXP_SUBTRACT,
    EXP_MULTIPLICATION,
    EXP_DIVIDE,
    EXP_NEGATIVE,
    EXP_MODULO,
    EXP_CASTING,
    EXP_ID,
    EXP_BITWISE_AND,
    EXP_BITWISE_OR,
    EXP_BITWISE_XOR,
    EXP_BITWISE_LEFT_SHIFT,
    EXP_BITWISE_RIGHT_SHIFT,
    EXP_EQUALS_OP,
    EXP_EQUALS,
    EXP_NOT_EQUALS,
    EXP_LOGICAL_AND,
    EXP_LOGICAL_OR,
    EXP_LOGICAL_NOT,
    EXP_LESS,
    EXP_GREATER,
    EXP_LESS_EQUALS,
    EXP_GREATER_EQUALS,
    EXP_VECTOR_ACCESS,
    EXP_MATRIX_ACCESS,
    EXP_PARSEINT,
    EXP_PARSEDOUBLE,
    EXP_PARSEFLOAT,
    EXP_VALUEOF,
    EXP_JOIN,
    EXP_INDEXOF,
    EXP_LENGTH,
    EXP_ADD,
    EXP_FUNCTION_CALL,
    EXP_ARRAY_ACCESS,
    EXP_UNKNOWN
} ExpressionType;

symbol *evaluate_expression(Expression *expr, Context *context);
ExecuteType get_instruction_type(const char *type_str);
ExpressionType get_expression_type(const char *type_str);
symbol *perform_arithmetic_operation(Expression *left, Expression *right, Context *context, char operation);
symbol *apply_casting_auto(symbol *value, const char *target_type);
symbol *apply_casting_manual(symbol *value, const char *target_type);
ConvertedValue convert_operand(symbol *operand);
char *process_escape_sequences(const char *input);
symbol *perform_comparative_operation(Expression *exprIZQ, Expression *exprDER, Context *context, char *operator);
bool boolean_value(const char *bool_str);

symbol *perfom_BITWISE(Expression *exp_left, Expression *exp_right, Context *context, char *operation);

ExecuteType get_instruction_type(const char *type_str);
OperativeType get_operativeType(const char *type_str);
ExpressionType
get_expression_type(const char *type_str);

List *evaluate_list(List *list, Context *evaluateContext);
char *printArray(List *list);

VectorList *evaluate_vector(char *dataType, VectorList *vec, Context *evaluateContext);
char *printVector(VectorList *vec);

void Error_exists(char *message, char *environment, Instruccion *instruccion);

symbol **get_VectorElementPointer(Context *context, Expression *index_exp, VectorList *vector);
symbol **get_MatrixElementPointer(Context *context, Expression *row_exp, Expression *col_exp, MatrixList *matrix);

symbol *get_legth_of_vector(VectorList *vector);
symbol *get_legth_of_matrix(MatrixList *matrix);
// Función para acceso a arreglos multidimensionales
symbol *access_multidimensional_array(List *array, ExpressionList *indices, Context *context, int expected_dimensions);

// Función para asignación en arreglos multidimensionales
bool assign_multidimensional_array(List *array, ExpressionList *indices, Context *context, symbol *new_value, int expected_dimensions);

// AST relacionado