#include "../structures/parser.h"
#include "../semantic/semantic.h"

typedef struct ARM_data
{

    char *data;
    char *text;
    char *roadata;
    char *bss;

} ARM_data;

ARM_data *arm_data_create();

//* Metodos de agregacion global
char *arm_data_add(char *original, char *to_add);
char *arm_text_add(char *original, char *to_add);
char *arm_text_exit();

//* Declaraciones
char *arm_declarate(char *id, char *type, char *value);
char *arm_declarate_char(char *id, char *value);
char *arm_declarate_int(char *id, int value);
char *arm_declarate_float(char *id, float value);
char *arm_declarate_double(char *id, double value);
char *arm_declarate_string(char *id, char *value);
char *arm_declarate_boolean(char *id, int value);

// ? Declaracion en bss
char *arm_declarate_bss(char *id, char *type);

//* Operaciones Aritmeticas
void promote_to_double_arm(symbol *operand, OperativeType type);
void get_arm_op_and_reg(char operation, OperativeType result_type, char **operation_arm, char **register_type);
void promote_to_float_arm(symbol *operand, OperativeType type);