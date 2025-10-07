#include "arm.h"
void get_arm_op_and_reg(char operation, OperativeType result_type, char **operation_arm, char **register_type)
{
    switch (result_type)
    {
    case TYPE_DOUBLE:
        *register_type = "d";
        *operation_arm = (operation == '+') ? "fadd" : (operation == '-') ? "fsub"
                                                   : (operation == '*')   ? "fmul"
                                                   : (operation == '/')   ? "fdiv"
                                                                          : "";
        break;
    case TYPE_FLOAT:
        *register_type = "s";
        *operation_arm = (operation == '+') ? "fadd" : (operation == '-') ? "fsub"
                                                   : (operation == '*')   ? "fmul"
                                                   : (operation == '/')   ? "fdiv"
                                                                          : "";
        break;
    default: // INTEGER
        *register_type = "w";
        *operation_arm = (operation == '+') ? "add" : (operation == '-') ? "sub"
                                                  : (operation == '*')   ? "mul"
                                                  : (operation == '/')   ? "sdiv"
                                                  : (operation == '%')   ? "srem"
                                                                         : "";
        break;
    }
}