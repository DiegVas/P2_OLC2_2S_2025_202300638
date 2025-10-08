#include "arm.h"

char *arm_register_type(const char *dataType)
{
    if (strcmp(dataType, "DOUBLE") == 0)
    {
        return "d";
    }
    else if (strcmp(dataType, "FLOAT") == 0)
    {
        return "s";
    }
    else if (strcmp(dataType, "INTEGER") == 0 || strcmp(dataType, "CHARACTER") == 0 || strcmp(dataType, "BOOLEAN") == 0)
    {
        return "w";
    }
    else
    {
        return "x"; // Default for pointers and other types
    }
}