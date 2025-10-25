.global string_to_double
    .align 2

// Función: string_to_double
// Convierte un string a double (formato IEEE 754)
// Entrada: x0 = puntero al string
// Salida: d0 = valor double resultante
//         x0 = 1 si éxito, 0 si error

string_to_double:
    stp     x29, x30, [sp, #-64]!
    mov     x29, sp
    
    // Guardar registros
    stp     x19, x20, [sp, #16]
    stp     x21, x22, [sp, #32]
    str     d8, [sp, #48]
    
    mov     x19, x0              // Guardar puntero al string
    
    // Inicializar variables
    mov     x1, #0
    fmov    d8, x1               // Resultado = 0.0
    mov     x20, #0              // Signo (0 = positivo, 1 = negativo)
    mov     x21, #0              // Bandera de punto decimal
    mov     x1, #10
    scvtf   d1, x1               // Base decimal = 10.0
    mov     x1, #1
    scvtf   d2, x1               // Divisor para decimales = 1.0
    
    // Verificar signo
    ldrb    w1, [x19]
    cmp     w1, #'-'
    b.ne    check_plus
    mov     x20, #1              // Es negativo
    add     x19, x19, #1         // Avanzar puntero
    b       parse_loop
    
check_plus:
    cmp     w1, #'+'
    b.ne    parse_loop
    add     x19, x19, #1         // Avanzar puntero
    
parse_loop:
    ldrb    w1, [x19]            // Cargar carácter
    cbz     w1, finish           // Si es '\0', terminar
    
    // Verificar si es punto decimal
    cmp     w1, #'.'
    b.ne    check_digit
    mov     x21, #1              // Activar bandera de decimal
    add     x19, x19, #1
    b       parse_loop
    
check_digit:
    // Verificar si es dígito (0-9)
    cmp     w1, #'0'
    b.lt    error
    cmp     w1, #'9'
    b.gt    error
    
    // Convertir carácter a número
    sub     w1, w1, #'0'
    scvtf   d3, w1               // Convertir a double
    
    cbnz    x21, decimal_part    // Si hay punto, es parte decimal
    
    // Parte entera: resultado = resultado * 10 + dígito
    fmul    d8, d8, d1
    fadd    d8, d8, d3
    b       next_char
    
decimal_part:
    // Parte decimal: dígito / (10^posición)
    fmul    d2, d2, d1           // Incrementar divisor
    fdiv    d3, d3, d2           // dígito / divisor
    fadd    d8, d8, d3           // Sumar a resultado
    
next_char:
    add     x19, x19, #1
    b       parse_loop
    
finish:
    // Aplicar signo si es negativo
    cbnz    x20, apply_negative
    fmov    d0, d8
    mov     x0, #1               // Éxito
    b       return
    
apply_negative:
    fneg    d0, d8
    mov     x0, #1               // Éxito
    b       return
    
error:
    mov     x1, #0
    fmov    d0, x1               // d0 = 0.0
    mov     x0, #0               // Error
    
return:
    // Restaurar registros
    ldr     d8, [sp, #48]
    ldp     x21, x22, [sp, #32]
    ldp     x19, x20, [sp, #16]
    ldp     x29, x30, [sp], #64
    ret

    .size string_to_double, .-string_to_double