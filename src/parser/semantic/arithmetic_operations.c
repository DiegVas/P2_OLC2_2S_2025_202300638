#include "semantic.h"
#include "../ARM/arm.h"
#include <math.h>

ConvertedValue convert_operand(symbol *operand)
{
    ConvertedValue cv = {0};

    if (operand == NULL)
    {
        cv.result_type = TYPE_UNDEFINED;
        return cv;
    }

    if (strcmp(operand->dataType, "STRING") == 0)
    {
        cv.str_value = operand->value;
        cv.result_type = TYPE_STRING;
    }
    else if (strcmp(operand->dataType, "NULL") == 0)
    {
        cv.str_value = "null";
        cv.num_value = 0;
        cv.result_type = TYPE_NULL;
    }
    else if (strcmp(operand->dataType, "INTEGER") == 0)
    {
        cv.num_value = atoi(operand->value);
        cv.result_type = TYPE_INTEGER;
    }
    else if (strcmp(operand->dataType, "FLOAT") == 0)
    {
        cv.num_value = atof(operand->value);
        cv.result_type = TYPE_FLOAT;
    }
    else if (strcmp(operand->dataType, "DOUBLE") == 0)
    {
        cv.num_value = atof(operand->value);
        cv.result_type = TYPE_DOUBLE;
    }
    else if (strcmp(operand->dataType, "CHARACTER") == 0)
    {
        fprintf(stderr, "Converting CHARACTER with value: %s\n", operand->value); // Debug line
        if (strlen(operand->value) == 1)
        {
            cv.num_value = (int)operand->value[0];
        }
        else if (strlen(operand->value) == 3 && operand->value[0] == '\'' && operand->value[2] == '\'')
        {
            cv.num_value = (int)operand->value[1];
        }
        else
        {
            cv.num_value = 0; // Valor por defecto en caso de formato inesperado
        }
        cv.result_type = TYPE_INTEGER; // Promover CHARACTER a INTEGER
    }

    return cv;
}

// Función genérica para operaciones aritméticas
symbol *perform_arithmetic_operation(Expression *exp_left, Expression *exp_right, Context *context, char operation)
{

    exp_left->num_register = 1;
    exp_right->num_register = 2;

    symbol *left = evaluate_expression(exp_left, context);
    symbol *right = evaluate_expression(exp_right, context);

    // Verificar que ambos operandos sean válidos
    if (left == NULL || right == NULL)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Error: null operand in arithmetic operation");
        return result;
    }

    ConvertedValue cv_left = convert_operand(left);
    ConvertedValue cv_right = convert_operand(right);

    // Verificar que la conversión fue exitosa
    if (cv_left.result_type == TYPE_UNDEFINED || cv_right.result_type == TYPE_UNDEFINED)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Error: invalid operand types in arithmetic operation");
        return result;
    }

    // Verificar operaciones con NULL
    if (cv_left.result_type == TYPE_NULL || cv_right.result_type == TYPE_NULL)
    {
        symbol *result = (symbol *)calloc(1, sizeof(symbol));
        result->dataType = strdup("NULL");
        result->value = strdup("null");
        return result;
    }

    symbol *result = (symbol *)calloc(1, sizeof(symbol));

    // Si alguno es string, concatenar (solo para suma)
    if (operation == '+' && (cv_left.result_type == TYPE_STRING || cv_right.result_type == TYPE_STRING))
    {
        result->dataType = strdup("STRING");
        char *left_str = (cv_left.result_type == TYPE_STRING) ? cv_left.str_value : left->value;
        char *right_str = (cv_right.result_type == TYPE_STRING) ? cv_right.str_value : right->value;

        result->value = (char *)calloc(strlen(left_str) + strlen(right_str) + 1, sizeof(char));
        strcpy(result->value, left_str);
        strcat(result->value, right_str);
        return result;
    }

    // Determinar el tipo de resultado (el más "grande")
    OperativeType result_type = (cv_left.result_type > cv_right.result_type) ? cv_left.result_type : cv_right.result_type;

    {

        // Codigo arm promver a double si alguno es char, int o float
        if (result_type == TYPE_DOUBLE)
        {
            if (cv_left.result_type != TYPE_DOUBLE)
            {
                promote_to_double_arm(left, cv_left.result_type);
            }
            if (cv_right.result_type != TYPE_DOUBLE)
            {
                promote_to_double_arm(right, cv_right.result_type);
            }
        }
        else if (result_type == TYPE_FLOAT)
        {
            if (cv_left.result_type != TYPE_FLOAT)
            {
                promote_to_double_arm(left, cv_left.result_type);
            }
            if (cv_right.result_type != TYPE_FLOAT)
            {
                promote_to_double_arm(right, cv_right.result_type);
            }
        }

        result->text_section = arm_data_add(result->text_section, left->text_section);
        result->text_section = arm_data_add(result->text_section, right->text_section);

        char buffer[128];
        char *operation_arm = "";
        char *register_type = "";

        get_arm_op_and_reg(operation, result_type, &operation_arm, &register_type);

        snprintf(buffer, sizeof(buffer), "%s    %s0, %s%d, %s%d\n", operation_arm, register_type, register_type, left->num_register, register_type, right->num_register);
        result->text_section = arm_data_add(result->text_section, buffer);
    }

    // Realizar la operación
    double final_result;
    switch (operation)
    {
    case '+':
        final_result = cv_left.num_value + cv_right.num_value;
        break;
    case '-':
        final_result = cv_left.num_value - cv_right.num_value;
        break;
    case '*':
        final_result = cv_left.num_value * cv_right.num_value;
        break;
    case '/':
        if (cv_right.num_value == 0)
        {
            // Manejar división por cero
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Division by zero");
            return result;
        }

        final_result = cv_left.num_value / cv_right.num_value;

        if (final_result != floor(final_result))
            result_type = TYPE_DOUBLE; // Promover a DOUBLE si hay decimales
        break;

    case '%':
        if (cv_right.num_value == 0)
        {
            // Manejar módulo por cero
            result->dataType = strdup("UNDEFINED");
            result->value = strdup("Modulo by zero");
            return result;
        }
        final_result = (int)cv_left.num_value % (int)cv_right.num_value;
        break;
    default:
        result->dataType = strdup("UNDEFINED");
        result->value = strdup("Unknown operation");
        return result;
    }

    // Formatear resultado según el tipo
    result->value = (char *)calloc(50, sizeof(char)); // Suficiente espacio

    fprintf(stderr, "Final result before formatting: %f\n", final_result); // Debug line
    fprintf(stderr, "Result type: %d\n", result_type);                     // Debug line

    switch (result_type)
    {
    case TYPE_INTEGER:
        result->dataType = strdup("INTEGER");
        sprintf(result->value, "%d", (int)final_result);
        break;
    case TYPE_FLOAT:
        result->dataType = strdup("FLOAT");
        sprintf(result->value, "%.2f", final_result);
        break;
    case TYPE_DOUBLE:
        result->dataType = strdup("DOUBLE");
        sprintf(result->value, "%.6f", final_result);
        break;
    default:
        result->dataType = strdup("INTEGER");
        sprintf(result->value, "%d", (int)final_result);
        break;
    }

    return result;
}
