.global buscar_string
.text
// Función: buscar_string
// Parámetros:
//   x0 = puntero al array de strings
//   x1 = tamaño del array
//   x2 = string a buscar
// Retorna:
//   x0 = índice de la primera ocurrencia, o -1 si no se encuentra
buscar_string:
    stp     x29, x30, [sp, #-48]!   // Guardar frame pointer y link register
    mov     x29, sp
    stp     x19, x20, [sp, #16]     // Guardar registros callee-saved
    stp     x21, x22, [sp, #32]
    
    mov     x19, x0                 // x19 = puntero al array
    mov     x20, x1                 // x20 = tamaño
    mov     x21, x2                 // x21 = string a buscar
    mov     x22, #0                 // x22 = índice actual
    
buscar_loop:
    cmp     x22, x20                // Comparar índice con tamaño
    b.ge    no_encontrado           // Si índice >= tamaño, no encontrado
    
    ldr     x0, [x19, x22, lsl #3]  // Cargar puntero al string actual
    mov     x1, x21                 // String a buscar
    bl      comparar_strings        // Comparar strings
    
    cmp     x0, #0                  // ¿Son iguales?
    b.eq    encontrado              // Si son iguales, encontrado
    
    add     x22, x22, #1            // Incrementar índice
    b       buscar_loop             // Continuar búsqueda
    
encontrado:
    mov     x0, x22                 // Retornar índice
    b       fin_buscar
    
no_encontrado:
    mov     x0, #-1                 // Retornar -1
    
fin_buscar:
    ldp     x21, x22, [sp, #32]     // Restaurar registros
    ldp     x19, x20, [sp, #16]
    ldp     x29, x30, [sp], #48
    ret

// Función: comparar_strings
// Parámetros:
//   x0 = string 1
//   x1 = string 2
// Retorna:
//   x0 = 0 si son iguales, diferente de 0 si son diferentes
comparar_strings:
    mov     x2, x0                  // x2 = string 1
    mov     x3, x1                  // x3 = string 2
    
comp_loop:
    ldrb    w4, [x2], #1            // Cargar byte de string 1 y avanzar
    ldrb    w5, [x3], #1            // Cargar byte de string 2 y avanzar
    
    cmp     w4, w5                  // Comparar bytes
    b.ne    comp_diferentes         // Si son diferentes, retornar
    
    cmp     w4, #0                  // ¿Es fin de string?
    b.ne    comp_loop               // Si no, continuar
    
    mov     x0, #0                  // Strings iguales
    ret
    
comp_diferentes:
    sub     x0, x4, x5              // Retornar diferencia
    ret
