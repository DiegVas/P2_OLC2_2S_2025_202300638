#include "semantic.h"
#include "../ARM/arm.h"
#include <math.h>

symbol *perfom_BITWISE(Expression *exp_left, Expression *exp_right, Context *context, char *operation)
{

    exp_left->num_register = 1;
    exp_right->num_register = 2;

    symbol *left = evaluate_expression(exp_left, context);
    symbol *right = evaluate_expression(exp_right, context);

    ConvertedValue cv_left = convert_operand(left);
    ConvertedValue cv_right = convert_operand(right);

    if (cv_left.result_type != TYPE_INTEGER || cv_right.result_type != TYPE_INTEGER)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Bitwise operations do not support non-integer");
        return result;
    }

    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    int left_val = (int)cv_left.num_value;
    int right_val = (int)cv_right.num_value;
    int final_result;

    char bufferARM[128];

    if (strcmp(operation, "&") == 0)
    {
        final_result = left_val & right_val;

        snprintf(bufferARM, sizeof(bufferARM), "AND    w0, w%d, w%d\n", left->num_register, right->num_register);
    }
    else if (strcmp(operation, "|") == 0)
    {
        final_result = left_val | right_val;

        snprintf(bufferARM, sizeof(bufferARM), "ORR    w0, w%d, w%d\n", left->num_register, right->num_register);
    }
    else if (strcmp(operation, "^") == 0)
    {
        final_result = left_val ^ right_val;

        snprintf(bufferARM, sizeof(bufferARM), "EOR    w0, w%d, w%d\n", left->num_register, right->num_register);
    }
    else if (strcmp(operation, ">>") == 0)
    {

        final_result = left_val >> right_val;

        snprintf(bufferARM, sizeof(bufferARM), "LSR    w0, w%d, #%d\n", left->num_register, right_val);
    }
    else if (strcmp(operation, "<<") == 0)
    {
        final_result = left_val << right_val;

        snprintf(bufferARM, sizeof(bufferARM), "LSL    w0, w%d, #%d\n", left->num_register, right_val);
    }
    else
    {
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Unknown bitwise operation");
        return result;
    }
    result->text_section = arm_data_add(result->text_section, left->text_section);
    result->dataType = strdup("INTEGER");
    result->value = (char *)calloc(50, sizeof(char));
    sprintf(result->value, "%d", final_result);

    return result;
}
