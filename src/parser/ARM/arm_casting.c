#include "arm.h"

void promote_to_double_arm(symbol *operand, OperativeType type)
{
    char *arm_register = "d";
    char *arm_intruction = "scvtf";

    if (type == TYPE_INTEGER || type == TYPE_CHARACTER)
    {
        arm_register = "w";
    }
    else if (type == TYPE_FLOAT)
    {
        arm_register = "s";
        arm_intruction = "fcvt";
    }

    char buffer[128];
    snprintf(buffer, sizeof(buffer), "%s   d%d, %s%d\n", arm_intruction, operand->num_register, arm_register, operand->num_register);
    operand->text_section = arm_data_add(operand->text_section, buffer);
    operand->declared_in_arm = true;
}

void promote_to_float_arm(symbol *operand, OperativeType type)
{
    char *arm_register = "s";
    char *arm_intruction = "scvtf";

    if (type == TYPE_INTEGER || type == TYPE_CHARACTER)
    {
        arm_register = "w";
    }
    else if (type == TYPE_DOUBLE)
    {
        arm_register = "d";
        arm_intruction = "fcvt";
    }

    char buffer[128];
    snprintf(buffer, sizeof(buffer), "%s   s%d, %s%d\n", arm_intruction, operand->num_register, arm_register, operand->num_register);
    operand->text_section = arm_data_add(operand->text_section, buffer);
    operand->declared_in_arm = true;
}