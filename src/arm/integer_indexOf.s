.global buscar_entero
.align 2

.text

// Función: buscar_entero
// Parámetros:
//   x0 = puntero al array de enteros (word/int32)
//   x1 = tamaño del array
//   x2 = valor a buscar
// Retorna:
//   x0 = índice de la primera ocurrencia, o -1 si no se encuentra
buscar_entero:
    mov     x3, #0                  // x3 = índice actual
    
buscar_loop:
    cmp     x3, x1                  // Comparar índice con tamaño
    b.ge    no_encontrado           // Si índice >= tamaño, no encontrado
    
    ldr     w4, [x0, x3, lsl #2]    // Cargar entero en posición actual
    cmp     w4, w2                  // Comparar con valor buscado
    b.eq    encontrado              // Si son iguales, encontrado
    
    add     x3, x3, #1              // Incrementar índice
    b       buscar_loop             // Continuar búsqueda
    
encontrado:
    mov     x0, x3                  // Retornar índice
    ret
    
no_encontrado:
    mov     x0, #-1                 // Retornar -1
    ret

