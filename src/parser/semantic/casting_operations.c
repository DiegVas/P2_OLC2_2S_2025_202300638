#include "semantic.h"
#include "../ARM/arm.h"

bool is_valid_cast(OperativeType from, OperativeType to)
{
    // char puede castear a int, float, double
    if (from == TYPE_CHARACTER && (to == TYPE_INTEGER || to == TYPE_FLOAT || to == TYPE_DOUBLE))
    {
        return true;
    }
    // int puede castear a float, double
    if (from == TYPE_INTEGER && (to == TYPE_FLOAT || to == TYPE_DOUBLE))
    {
        return true;
    }
    // float puede castear a double
    if (from == TYPE_FLOAT && to == TYPE_DOUBLE)
    {
        return true;
    }
    // Tipos iguales son válidos
    if (from == to)
    {
        return true;
    }

    return false;
}

// Función para aplicar casting automático
symbol *apply_casting_auto(symbol *value, const char *target_type, Context *context)
{
    // Verificar que value no sea NULL
    if (value == NULL)
    {
        return NULL;
    }

    OperativeType from_type = get_operativeType(value->dataType);
    OperativeType to_type = get_operativeType(target_type);

    if (!is_valid_cast(from_type, to_type))
        return value;

    if (from_type == to_type)
        return value; // No necesita casting

    symbol *casted = (symbol *)calloc(1, sizeof(symbol));
    casted->dataType = strdup(target_type);
    casted->environment = value->environment ? strdup(value->environment) : NULL;
    casted->line = value->line;
    casted->column = value->column;

    // Realizar la conversión del valor
    char buffer[64];
    switch (to_type)
    {
    case TYPE_INTEGER:
        if (from_type == TYPE_CHARACTER)
        {
            sprintf(buffer, "%d", (int)value->value[0]); // char a int
        }
        break;

    case TYPE_FLOAT:
        if (from_type == TYPE_CHARACTER)
        {

            {
                //"scvtf   d1, s2"
                char bufferARM[128];
                snprintf(bufferARM, sizeof(bufferARM), "scvtf   s%d, w%d\n", context->num_register_s, context->num_register_w - 1);
                strcat(bufferARM, "\n");
                value->text_section = arm_data_add(value->text_section, bufferARM);
            }

            sprintf(buffer, "%.2f", (float)value->value[0]); // char a float
        }
        else if (from_type == TYPE_INTEGER)
        {

            {
                //"scvtf   d1, w2"
                char bufferARM[128];
                snprintf(bufferARM, sizeof(bufferARM), "scvtf   s%d, w%d\n", context->num_register_s, context->num_register_w - 1);
                strcat(bufferARM, "\n");
                value->text_section = arm_data_add(value->text_section, bufferARM);
            }

            sprintf(buffer, "%.2f", (float)atoi(value->value)); // int a float
        }
        break;

    case TYPE_DOUBLE:
        if (from_type == TYPE_CHARACTER)
        {

            {
                //"scvtf   d1, w2"
                char bufferARM[128];
                snprintf(bufferARM, sizeof(bufferARM), "scvtf   d%d, w%d\n", context->num_register_d, context->num_register_w - 1);
                strcat(bufferARM, "\n");
                value->text_section = arm_data_add(value->text_section, bufferARM);
            }

            sprintf(buffer, "%.6f", (double)value->value[0]); // char a double
        }
        else if (from_type == TYPE_INTEGER)
        {

            {
                //"scvtf   d1, w2"
                char bufferARM[128];
                snprintf(bufferARM, sizeof(bufferARM), "scvtf   d%d, w%d\n", context->num_register_d, context->num_register_w - 1);
                strcat(bufferARM, "\n");
                value->text_section = arm_data_add(value->text_section, bufferARM);
            }

            sprintf(buffer, "%.6f", (double)atoi(value->value)); // int a double
        }
        else if (from_type == TYPE_FLOAT)
        {

            {
                //"fcvt   d1, s2"
                char bufferARM[128];
                snprintf(bufferARM, sizeof(bufferARM), "fcvt   d%d, s%d\n", context->num_register_d, context->num_register_s - 1);
                strcat(bufferARM, "\n");
                value->text_section = arm_data_add(value->text_section, bufferARM);
            }

            sprintf(buffer, "%.6f", (double)atof(value->value)); // float a double
        }
        break;

    default:
        strcpy(buffer, value->value);
        break;
    }

    casted->value = strdup(buffer);
    casted->text_section = value->text_section ? strdup(value->text_section) : NULL;
    return casted;
}

// Función para verificar si el casting hacia abajo es válido
bool is_valid_downcast(OperativeType from, OperativeType to)
{
    // double puede castear a float, int, char
    if (from == TYPE_DOUBLE && (to == TYPE_FLOAT || to == TYPE_INTEGER || to == TYPE_CHARACTER))
    {
        return true;
    }
    // float puede castear a int, char
    if (from == TYPE_FLOAT && (to == TYPE_INTEGER || to == TYPE_CHARACTER))
    {
        return true;
    }
    // int puede castear a char
    if (from == TYPE_INTEGER && to == TYPE_CHARACTER)
    {
        return true;
    }
    // Tipos iguales son válidos
    if (from == to)
    {
        return true;
    }
    return false;
}

// Función para aplicar casting hacia abajo (explícito)
symbol *apply_casting_manual(symbol *value, const char *target_type)
{
    OperativeType from_type = get_operativeType(value->dataType);
    OperativeType to_type = get_operativeType(target_type);

    if (!is_valid_downcast(from_type, to_type))
    {
        return value;
    }

    if (from_type == to_type)
    {
        return value; // No necesita casting
    }

    symbol *casted = (symbol *)calloc(1, sizeof(symbol));
    casted->dataType = strdup(target_type);
    casted->environment = value->environment ? strdup(value->environment) : NULL;
    casted->line = value->line;
    casted->column = value->column;

    // Realizar la conversión del valor (con pérdida de precisión)
    char buffer[64];
    switch (to_type)
    {
    case TYPE_CHARACTER:
        if (from_type == TYPE_DOUBLE)
        {
            // double a char (toma la parte entera y convierte a ASCII)
            sprintf(buffer, "%c", (char)((int)atof(value->value)));
        }
        else if (from_type == TYPE_FLOAT)
        {
            // float a char
            sprintf(buffer, "%c", (char)((int)atof(value->value)));
        }
        else if (from_type == TYPE_INTEGER)
        {
            // int a char
            sprintf(buffer, "%c", (char)atoi(value->value));
        }
        break;

    case TYPE_INTEGER:
        if (from_type == TYPE_DOUBLE)
        {
            // double a int (trunca la parte decimal)
            sprintf(buffer, "%d", (int)atof(value->value));
        }
        else if (from_type == TYPE_FLOAT)
        {
            // float a int (trunca la parte decimal)
            sprintf(buffer, "%d", (int)atof(value->value));
        }
        break;

    case TYPE_FLOAT:
        if (from_type == TYPE_DOUBLE)
        {
            // double a float (puede perder precisión)
            sprintf(buffer, "%.2f", (float)atof(value->value));
        }
        break;

    default:
        strcpy(buffer, value->value);
        break;
    }

    casted->value = strdup(buffer);
    return casted;
}
