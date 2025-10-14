#include "arm.h"

void promote_to_double_arm(symbol *operand, OperativeType type)
{

    char *arm_intruction = "scvtf";
    char buffer[128];

    if (type == TYPE_INTEGER || type == TYPE_CHARACTER)
    {
        char *arm_register = "w";
        snprintf(buffer, sizeof(buffer), "%s   d%d, %s%d\n", arm_intruction, operand->num_register, arm_register, operand->num_register);
        operand->text_section = arm_data_add(operand->text_section, buffer);
    }

    operand->declared_in_arm = true;
}
