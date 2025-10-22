#include "semantic.h"
#include "../structures/parser.h"
#include "../ARM/arm.h"
#include <string.h>

extern ARM_data *arm_global_data;

symbol *perform_comparative_operation(Expression *exprIZQ, Expression *exprDER, Context *context, char *operator)
{
    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    exprIZQ->num_register = 1;
    exprDER->num_register = 2;

    symbol *left = evaluate_expression(exprIZQ, context);

    symbol *right = evaluate_expression(exprDER, context);

    ConvertedValue cv_left = convert_operand(left);
    ConvertedValue cv_right = convert_operand(right);

    // Manejar comparaciones con NULL
    if (strcmp(left->dataType, "NULL") == 0 || strcmp(right->dataType, "NULL") == 0)
    {
        if (strcmp(operator, "==") == 0)
        {
            result->value = (strcmp(left->dataType, "NULL") == 0 && strcmp(right->dataType, "NULL") == 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "!=") == 0)
        {
            result->value = (strcmp(left->dataType, "NULL") == 0 && strcmp(right->dataType, "NULL") == 0) ? strdup("false") : strdup("true");
        }
        else
        {
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Only '==' and '!=' operators are supported for NULL type");
            return result;
        }
        result->dataType = strdup("BOOLEAN");
        return result;
    }

    if (strcmp(left->dataType, right->dataType) != 0)
    {
        fprintf(stderr, "Comparative operation requires both operands to be of the same type: left is %s, right is %s\n", left->dataType, right->dataType);
        fprintf(stderr, "Left value: %s, Right value: %s\n", left->value, right->value);
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Comparative operation requires both operands to be of the same type");
        return result;
    }

    if (strcmp(left->dataType, "BOOLEAN") == 0)
    {
        bool left_bool = boolean_value(left->value);
        bool right_bool = boolean_value(right->value);

        char bufferARM[256];
        char *armOperation = "";

        result->data_section = arm_data_add(result->data_section, left->data_section);
        result->text_section = arm_data_add(result->text_section, left->text_section);
        result->data_section = arm_data_add(result->data_section, right->data_section);
        result->text_section = arm_data_add(result->text_section, right->text_section);

        if (strcmp(operator, "==") == 0)
        {
            armOperation = "eq";
            result->value = left_bool == right_bool ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "!=") == 0)
        {
            armOperation = "ne";
            result->value = left_bool != right_bool ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "&&") == 0)
        {
            armOperation = "and";
            result->value = left_bool && right_bool ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "||") == 0)
        {
            armOperation = "orr";
            result->value = left_bool || right_bool ? strdup("true") : strdup("false");
        }
        else
        {
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Only '==' and '!=' operators are supported for BOOLEAN type");
            return result;
        }

        if (strcmp(armOperation, "and") == 0 || strcmp(armOperation, "orr") == 0)
        {
            snprintf(bufferARM, sizeof(bufferARM), "%s w0, w%d, w%d\n", armOperation, left->num_register, right->num_register);
            result->text_section = arm_data_add(result->text_section, bufferARM);
        }
        else
        {

            snprintf(bufferARM, sizeof(bufferARM), "cmp w%d, w%d\n", left->num_register, right->num_register);
            result->text_section = arm_data_add(result->text_section, bufferARM);
            snprintf(bufferARM, sizeof(bufferARM), "cset w0, %s\n", armOperation);
            result->text_section = arm_data_add(result->text_section, bufferARM);
        }

        snprintf(bufferARM, sizeof(bufferARM), "mov w%d, w0\n", left->num_register);
        result->text_section = arm_data_add(result->text_section, bufferARM);
    }
    else if (cv_left.result_type == TYPE_STRING)
    {

        left->text_section = remove_last_instruction(left->text_section);
        right->text_section = remove_last_instruction(right->text_section);

        result->data_section = arm_data_add(result->data_section, left->data_section);
        result->text_section = arm_data_add(result->text_section, left->text_section);
        result->data_section = arm_data_add(result->data_section, right->data_section);
        result->text_section = arm_data_add(result->text_section, right->text_section);

        char bufferARM[256];
        char *cmpARM = "cmp";
        char *registerType = "w";
        char *opARM = "ne";

        if (strcmp(operator, "==") == 0 | strcmp(operator, ".equals") == 0)
        {
            result->dataType = strdup("BOOLEAN");
            result->value = (strcmp(cv_left.str_value, cv_right.str_value) == 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "!=") == 0)
        {
            result->dataType = strdup("BOOLEAN");
            result->value = (strcmp(cv_left.str_value, cv_right.str_value) != 0) ? strdup("true") : strdup("false");
        }
        else
        {
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Only '==' and '!=' operators are supported for STRING type");
            fprintf(stderr, "Only '==' and '!=' operators are supported for STRING type\n");
            return result;
        }

        snprintf(bufferARM, sizeof(bufferARM), "bl string_compare \n");
        result->num_register = 1;
        result->text_section = arm_data_add(result->text_section, bufferARM);
    }
    else if (cv_left.result_type == TYPE_INTEGER || cv_left.result_type == TYPE_FLOAT || cv_left.result_type == TYPE_DOUBLE | cv_left.result_type == TYPE_CHARACTER)
    {
        int comparison;
        if (cv_left.num_value < cv_right.num_value)
            comparison = -1;
        else if (cv_left.num_value > cv_right.num_value)
            comparison = 1;
        else
            comparison = 0;

        result->data_section = arm_data_add(result->data_section, left->data_section);
        result->text_section = arm_data_add(result->text_section, left->text_section);
        result->data_section = arm_data_add(result->data_section, right->data_section);
        result->text_section = arm_data_add(result->text_section, right->text_section);

        char bufferARM[256];
        char *cmpARM = "cmp";
        char *registerType = "w";
        char *opARM = "ne";

        if (strcmp(left->dataType, "FLOAT") == 0 || strcmp(left->dataType, "DOUBLE") == 0)
        {
            cmpARM = "fcmp";
            registerType = "d";
        }

        if (strcmp(operator, "==") == 0)
        {
            opARM = "eq";
            result->value = (comparison == 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "!=") == 0)
        {
            opARM = "ne";
            result->value = (comparison != 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "<") == 0)
        {
            opARM = "lt";
            result->value = (comparison < 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, "<=") == 0)
        {
            opARM = "le";
            result->value = (comparison <= 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, ">") == 0)
        {
            opARM = "gt";
            result->value = (comparison > 0) ? strdup("true") : strdup("false");
        }
        else if (strcmp(operator, ">=") == 0)
        {
            opARM = "ge";
            result->value = (comparison >= 0) ? strdup("true") : strdup("false");
        }
        else
        {
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Unknown comparative operator");
            fprintf(stderr, "Unknown comparative operator: %s\n", operator);
            return result;
        }

        snprintf(bufferARM, sizeof(bufferARM), "%s %s%d, %s%d\n", cmpARM, registerType, exprIZQ->num_register, registerType, exprDER->num_register);
        result->text_section = arm_data_add(result->text_section, bufferARM);
        snprintf(bufferARM, sizeof(bufferARM), "cset w0, %s\n", opARM);
        result->text_section = arm_data_add(result->text_section, bufferARM);

        result->num_register = exprIZQ->num_register + arm_global_data->count_arithmetic_temps++;

        snprintf(bufferARM, sizeof(bufferARM), "mov w%d, w0\n", result->num_register);
        result->text_section = arm_data_add(result->text_section, bufferARM);
    }
    else
    {
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Comparative operation requires both operands to be of a comparable type");
        fprintf(stderr, "Comparative operation requires both operands to be of a comparable type\n");
        return result;
    }
    result->dataType = strdup("BOOLEAN");
    return result;
}
