.global string_join
    .align 2

// Función: string_join
// Une un array de strings con un separador
// Entrada: x0 = puntero al separador (string)
//          x1 = puntero al array de strings (punteros)
//          x2 = número de elementos en el array
//          x3 = puntero al buffer de salida
// Salida: x0 = puntero al string resultante (mismo que x3)

string_join:
    stp     x29, x30, [sp, #-64]!
    mov     x29, sp
    
    // Guardar registros
    stp     x19, x20, [sp, #16]
    stp     x21, x22, [sp, #32]
    stp     x23, x24, [sp, #48]
    
    mov     x19, x0              // Separador
    mov     x20, x1              // Array de strings
    mov     x21, x2              // Número de elementos
    mov     x22, x3              // Buffer de salida
    mov     x23, x3              // Puntero actual en el buffer
    
    // Si no hay elementos, retornar string vacío
    cbz     x21, empty_result
    
    mov     x24, #0              // Índice actual
    
join_loop:
    // Copiar el string actual
    ldr     x0, [x20, x24, lsl #3]  // Cargar puntero al string
    mov     x1, x23                  // Destino
    bl      copy_string
    mov     x23, x0                  // Actualizar posición
    
    // Incrementar índice
    add     x24, x24, #1
    
    // Si es el último elemento, no agregar separador
    cmp     x24, x21
    b.ge    finish
    
    // Copiar el separador
    mov     x0, x19              // Separador
    mov     x1, x23              // Destino
    bl      copy_string
    mov     x23, x0              // Actualizar posición
    
    b       join_loop
    
finish:
    // Agregar terminador nulo
    strb    wzr, [x23]
    mov     x0, x22              // Retornar puntero al buffer
    b       return
    
empty_result:
    strb    wzr, [x22]           // String vacío
    mov     x0, x22
    
return:
    // Restaurar registros
    ldp     x23, x24, [sp, #48]
    ldp     x21, x22, [sp, #32]
    ldp     x19, x20, [sp, #16]
    ldp     x29, x30, [sp], #64
    ret

// Función auxiliar: copy_string
// Copia un string de origen a destino
// Entrada: x0 = string origen
//          x1 = string destino
// Salida: x0 = puntero al final del string destino (después del último carácter copiado)
copy_string:
    mov     x2, x1               // Guardar inicio del destino
    
copy_loop:
    ldrb    w3, [x0], #1         // Cargar byte y avanzar
    cbz     w3, copy_done        // Si es '\0', terminar
    strb    w3, [x1], #1         // Guardar byte y avanzar
    b       copy_loop
    
copy_done:
    mov     x0, x1               // Retornar posición final
    ret

    .size string_join, .-string_join