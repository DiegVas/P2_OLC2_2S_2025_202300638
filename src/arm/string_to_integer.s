.global string_to_int
    .align 2

// Función: string_to_int
// Convierte un string a entero (signed int 32 bits)
// Entrada: x0 = puntero al string
// Salida: x0 = 1 si éxito, 0 si error
//         x1 = valor entero resultante

string_to_int:
    stp     x29, x30, [sp, #-48]!
    mov     x29, sp
    
    // Guardar registros
    stp     x19, x20, [sp, #16]
    stp     x21, x22, [sp, #32]
    
    mov     x19, x0              // Guardar puntero al string
    
    // Inicializar variables
    mov     x20, #0              // Resultado = 0
    mov     x21, #0              // Signo (0 = positivo, 1 = negativo)
    mov     x22, #10             // Base decimal
    
    // Verificar signo
    ldrb    w1, [x19]
    cmp     w1, #'-'
    b.ne    check_plus
    mov     x21, #1              // Es negativo
    add     x19, x19, #1         // Avanzar puntero
    b       parse_loop
    
check_plus:
    cmp     w1, #'+'
    b.ne    parse_loop
    add     x19, x19, #1         // Avanzar puntero
    
parse_loop:
    ldrb    w1, [x19]            // Cargar carácter
    cbz     w1, finish           // Si es '\0', terminar
    
    // Verificar si es dígito (0-9)
    cmp     w1, #'0'
    b.lt    error
    cmp     w1, #'9'
    b.gt    error
    
    // Convertir carácter a número
    sub     w1, w1, #'0'
    
    // Resultado = resultado * 10 + dígito
    mul     x20, x20, x22        // resultado * 10
    add     x20, x20, x1         // + dígito
    
    // Siguiente carácter
    add     x19, x19, #1
    b       parse_loop
    
finish:
    // Aplicar signo si es negativo
    cbnz    x21, apply_negative
    mov     x1, x20              // Resultado positivo
    mov     x0, #1               // Éxito
    b       return
    
apply_negative:
    neg     x1, x20              // Negar resultado
    mov     x0, #1               // Éxito
    b       return
    
error:
    mov     x1, #0               // Resultado = 0
    mov     x0, #0               // Error
    
return:
    // Restaurar registros
    ldp     x21, x22, [sp, #32]
    ldp     x19, x20, [sp, #16]
    ldp     x29, x30, [sp], #48
    ret

    .size string_to_int, .-string_to_int