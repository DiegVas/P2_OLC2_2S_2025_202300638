.global append_to_string_array

/*
=====================================
FUNCIÓN: append_to_string_array_generic
=====================================
Descripción: 
  Copia todos los punteros de un array base de strings a un array destino,
  incrementa el tamaño, y agrega un nuevo puntero al final.

Parámetros:
  x0 = dirección del array base de strings (fuente)
  w1 = tamaño actual del array base (número de elementos)
  x2 = dirección donde guardar la nueva lista (destino)
  x3 = dirección de la variable donde guardar el nuevo tamaño
  x4 = nuevo string a agregar (PUNTERO al string, no w4)

Retorno:
  w0 = nuevo tamaño de la lista (si fue exitoso)
  w0 = -1 si el array está lleno (capacidad máxima: 100 elementos)

*/

.text

append_to_string_array:
    // Guardar registros
    stp x29, x30, [sp, #-16]!
    stp x19, x20, [sp, #-16]!
    stp x21, x22, [sp, #-16]!
    stp x23, x24, [sp, #-16]!
    stp x25, x26, [sp, #-16]!
    mov x29, sp
    
    // Guardar parámetros en registros preservados
    mov x19, x0  // dirección array base (fuente)
    mov w20, w1  // tamaño actual
    mov x21, x2  // dirección array destino
    mov x22, x3  // dirección variable de tamaño
    mov x23, x4  // nuevo string (PUNTERO - 64 bits)
    
    // Paso 1: Verificar si hay espacio (capacidad máxima = 100)
    mov w24, #100
    cmp w20, w24
    bge array_full_string
    
    // Paso 2: Copiar todos los PUNTEROS del array base al array destino
    mov x25, x19        // x25 = fuente (array base)
    mov x26, x21        // x26 = destino (nuevo array)
    mov w27, w20        // w27 = contador (tamaño actual)
    
copy_loop_string:
    cbz w27, copy_done_string
    
    ldr x28, [x25], #8  // ⚠️ Cargar PUNTERO (8 bytes) y avanzar 8
    str x28, [x26], #8  // ⚠️ Guardar PUNTERO (8 bytes) y avanzar 8
    
    sub w27, w27, #1
    b copy_loop_string
    
copy_done_string:
    
    // Paso 3: Incrementar el tamaño
    add w20, w20, #1
    
    // Paso 4: Guardar el nuevo tamaño en la variable indicada
    str w20, [x22]
    
    // Paso 5: Agregar el nuevo PUNTERO al final del array destino
    // Calcular posición: array_destino + ((tamaño-1) * 8)
    sub w25, w20, #1     // w25 = índice del nuevo elemento (tamaño - 1)
    lsl w25, w25, #3     // ⚠️ w25 = índice * 8 (offset en bytes para punteros)
    add x26, x21, x25    // x26 = dirección base destino + offset
    str x23, [x26]       // Guardar el nuevo PUNTERO
    
    // Retorno exitoso: devolver el nuevo tamaño
    mov w0, w20
    b append_string_done
    
array_full_string:
    // Retorno de error: devolver -1
    mov w0, #-1
    
append_string_done:
    // Restaurar registros
    ldp x25, x26, [sp], #16
    ldp x23, x24, [sp], #16
    ldp x21, x22, [sp], #16
    ldp x19, x20, [sp], #16
    ldp x29, x30, [sp], #16
    ret