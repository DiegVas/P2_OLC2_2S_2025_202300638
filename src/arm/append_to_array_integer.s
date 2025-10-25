.global append_to_array_integer

/*
=====================================
FUNCIÓN: append_to_array_generic
=====================================
Parámetros:
  x0 = dirección del array base
  w1 = tamaño del array base
  x2 = dirección donde guardar nueva lista
  x3 = dirección donde guardar nuevo tamaño
  w4 = nuevo valor a agregar

Retorno:
  w0 = nuevo tamaño (o -1 si error)
*/

.text

append_to_array_integer:
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
    mov w23, w4  // nuevo valor
    
    // Paso 1: Verificar si hay espacio (capacidad máxima = 100)
    mov w24, #100
    cmp w20, w24
    bge array_full_generic
    
    // Paso 2: Copiar todos los valores del array base al array destino
    mov x25, x19        // x25 = fuente (array base)
    mov x26, x21        // x26 = destino (nuevo array)
    mov w27, w20        // w27 = contador (tamaño actual)
    
copy_loop_generic:
    cbz w27, copy_done_generic
    
    ldr w28, [x25], #4  // Cargar word (4 bytes) de fuente y avanzar
    str w28, [x26], #4  // Guardar en destino y avanzar
    
    sub w27, w27, #1
    b copy_loop_generic
    
copy_done_generic:
    
    // Paso 3: Incrementar el tamaño
    add w20, w20, #1
    
    // Paso 4: Guardar el nuevo tamaño en la variable indicada
    str w20, [x22]
    
    // Paso 5: Agregar el nuevo valor al final del array destino
    // Calcular posición: array_destino + ((tamaño-1) * 4)
    sub w25, w20, #1     // w25 = índice del nuevo elemento (tamaño - 1)
    lsl w25, w25, #2     // w25 = índice * 4 (offset en bytes)
    add x26, x21, x25    // x26 = dirección base destino + offset
    str w23, [x26]       // Guardar el nuevo valor
    
    // Retorno exitoso: devolver el nuevo tamaño
    mov w0, w20
    b append_generic_done
    
array_full_generic:
    // Retorno de error: devolver -1
    mov w0, #-1
    
append_generic_done:
    // Restaurar registros
    ldp x25, x26, [sp], #16
    ldp x23, x24, [sp], #16
    ldp x21, x22, [sp], #16
    ldp x19, x20, [sp], #16
    ldp x29, x30, [sp], #16
    ret