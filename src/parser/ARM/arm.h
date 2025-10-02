typedef struct ARM_data {

    char *data;
    char *text;
    char *roadata;
    char *bss;

} ARM_data;


ARM_data *arm_data_create();

//* Metodos de agregacion global
char *arm_data_add (char *original, char *to_add);
char *arm_text_add (char *original, char *to_add);
char *arm_text_exit();



//* Declaraciones
char *arm_declarate(char *id, char *type, char *value);
char *arm_declarate_char(char *id, char *value);
char *arm_declarate_int(char *id, int value);
char *arm_declarate_float(char *id, float value);
char *arm_declarate_double(char *id, double value);
char *arm_declarate_string(char *id, char *value);
char *arm_declarate_boolean(char *id, int value);
