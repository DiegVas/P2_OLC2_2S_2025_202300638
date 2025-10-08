#include "arm.h"
void get_arm_op_and_reg(char operation, OperativeType result_type, char **operation_arm, char **register_type)
{

    *register_type = "w";
    *operation_arm = (operation == '+') ? "add" : (operation == '-') ? "sub"
                                              : (operation == '*')   ? "mul"
                                              : (operation == '/')   ? "sdiv"
                                              : (operation == '%')   ? "srem"
                                                                     : "";

    if (result_type == TYPE_DOUBLE || result_type == TYPE_FLOAT)
    {
        *register_type = "d";
        *operation_arm = (operation == '+') ? "fadd" : (operation == '-') ? "fsub"
                                                   : (operation == '*')   ? "fmul"
                                                   : (operation == '/')   ? "fdiv"
                                                                          : "";
    }
}