#include "semantic.h"
#include <string.h>

ExecuteType get_instruction_type(const char *type_str)
{

    if (strcmp(type_str, "DECLARATION") == 0)
        return DECLARATION;
    if (strcmp(type_str, "ASSIGNMENT") == 0)
        return ASSIGNMENT;
    if (strcmp(type_str, "PRINTLN") == 0)
        return EXP_PRINTLN;
    if (strcmp(type_str, "IF_STATEMENT") == 0)
        return IF_STATEMENT;
    if (strcmp(type_str, "SWITCH_STATEMENT") == 0)
        return SWITCH_STATEMENT;
    if (strcmp(type_str, "WHILE_STATEMENT") == 0)
        return WHILE_STATEMENT;
    if (strcmp(type_str, "FOR_STATEMENT") == 0)
        return FOR_STATEMENT;
    if (strcmp(type_str, "FOREACH_STATEMENT") == 0)
        return FOREACH_STATEMENT;
    if (strcmp(type_str, "BREAK") == 0)
        return BREAK_STATEMENT;
    if (strcmp(type_str, "CONTINUE") == 0)
        return CONTINUE_STATEMENT;
    if (strcmp(type_str, "RETURN") == 0)
        return RETURN_STATEMENT;
    if (strcmp(type_str, "VOID_CALL") == 0)
        return VOID_CALL;
    if (strcmp(type_str, "BLOCK") == 0)
        return BLOCK_STATEMENT;
    return UNKNOWN;
}

OperativeType get_operativeType(const char *type_str)
{
    if (strcmp(type_str, "CHARACTER") == 0)
        return TYPE_CHARACTER;
    if (strcmp(type_str, "INTEGER") == 0)
        return TYPE_INTEGER;
    if (strcmp(type_str, "FLOAT") == 0)
        return TYPE_FLOAT;
    if (strcmp(type_str, "DOUBLE") == 0)
        return TYPE_DOUBLE;
    if (strcmp(type_str, "STRING") == 0)
        return TYPE_STRING;
    return -1;
}

bool boolean_value(const char *bool_str)
{
    return (strcmp(bool_str, "true") == 0) ? true : false;
}

ExpressionType
get_expression_type(const char *type_str)
{
    if (strcmp(type_str, "NULL") == 0)
        return EXP_NULL;
    if (strcmp(type_str, "ID") == 0)
        return EXP_ID;
    if (strcmp(type_str, "INTEGER") == 0)
        return EXP_INTEGER;
    if (strcmp(type_str, "FLOAT") == 0)
        return EXP_FLOAT;
    if (strcmp(type_str, "STRING") == 0)
        return EXP_STRING;
    if (strcmp(type_str, "BOOLEAN") == 0)
        return EXP_BOOLEAN;
    if (strcmp(type_str, "CHARACTER") == 0)
        return EXP_CHARACTER;
    if (strcmp(type_str, "DOUBLE") == 0)
        return EXP_DOUBLE;
    if (strcmp(type_str, "SUM") == 0)
        return EXP_SUM;
    if (strcmp(type_str, "SUBTRACT") == 0)
        return EXP_SUBTRACT;
    if (strcmp(type_str, "MULTIPLICATION") == 0)
        return EXP_MULTIPLICATION;
    if (strcmp(type_str, "DIVIDE") == 0)
        return EXP_DIVIDE;
    if (strcmp(type_str, "MODULO") == 0)
        return EXP_MODULO;
    if (strcmp(type_str, "NEGATIVE") == 0)
        return EXP_NEGATIVE;
    if (strcmp(type_str, "CASTING") == 0)
        return EXP_CASTING;
    if (strcmp(type_str, "BITWISE_AND") == 0)
        return EXP_BITWISE_AND;
    if (strcmp(type_str, "BITWISE_OR") == 0)
        return EXP_BITWISE_OR;
    if (strcmp(type_str, "BITWISE_XOR") == 0)
        return EXP_BITWISE_XOR;
    if (strcmp(type_str, "BITWISE_LEFT_SHIFT") == 0)
        return EXP_BITWISE_LEFT_SHIFT;
    if (strcmp(type_str, "BITWISE_RIGHT_SHIFT") == 0)
        return EXP_BITWISE_RIGHT_SHIFT;
    if (strcmp(type_str, "EQUALS_OP") == 0)
        return EXP_EQUALS_OP;
    if (strcmp(type_str, "EQUALS") == 0)
        return EXP_EQUALS;
    if (strcmp(type_str, "NOT_EQUALS") == 0)
        return EXP_NOT_EQUALS;
    if (strcmp(type_str, "LOGICAL_AND") == 0)
        return EXP_LOGICAL_AND;
    if (strcmp(type_str, "LOGICAL_OR") == 0)
        return EXP_LOGICAL_OR;
    if (strcmp(type_str, "LOGICAL_NOT") == 0)
        return EXP_LOGICAL_NOT;
    if (strcmp(type_str, "LESS") == 0)
        return EXP_LESS;
    if (strcmp(type_str, "GREATER") == 0)
        return EXP_GREATER;
    if (strcmp(type_str, "LESS_EQUALS") == 0)
        return EXP_LESS_EQUALS;
    if (strcmp(type_str, "GREATER_EQUALS") == 0)
        return EXP_GREATER_EQUALS;
    if (strcmp(type_str, "VECTOR_ACCESS") == 0)
        return EXP_VECTOR_ACCESS;
    if (strcmp(type_str, "MATRIX_ACCESS") == 0)
        return EXP_MATRIX_ACCESS;
    if (strcmp(type_str, "PARSEINT") == 0)
        return EXP_PARSEINT;
    if (strcmp(type_str, "PARSEDOUBLE") == 0)
        return EXP_PARSEDOUBLE;
    if (strcmp(type_str, "PARSEFLOAT") == 0)
        return EXP_PARSEFLOAT;
    if (strcmp(type_str, "VALUEOF") == 0)
        return EXP_VALUEOF;
    if (strcmp(type_str, "JOIN") == 0)
        return EXP_JOIN;
    if (strcmp(type_str, "INDEXOF") == 0)
        return EXP_INDEXOF;
    if (strcmp(type_str, "LENGTH") == 0)
        return EXP_LENGTH;
    if (strcmp(type_str, "ADD") == 0)
        return EXP_ADD;
    if (strcmp(type_str, "FUNCTION_CALL") == 0)
        return EXP_FUNCTION_CALL;
    if (strcmp(type_str, "ARRAY_ACCESS") == 0)
        return EXP_ARRAY_ACCESS;

    return EXP_UNKNOWN;
}
