// concat.s - Concatenación de dos cadenas en ARM64
// Entrada: x1 = puntero a cadena1, x2 = puntero a cadena2
// Salida: x0 = puntero al nuevo string concatenado

.global string_concat

.text
string_concat:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    stp x19, x20, [sp, #-16]!
    stp x21, x22, [sp, #-16]!

    mov x19, x1
    mov x20, x2

    // longitud 1
    mov x21, #0
.Lstrlen1:
    ldrb w9, [x19, x21]
    cbz w9, .Lstrlen1_done
    add x21, x21, #1
    b .Lstrlen1
.Lstrlen1_done:

    // longitud 2
    mov x22, #0
.Lstrlen2:
    ldrb w9, [x20, x22]
    cbz w9, .Lstrlen2_done
    add x22, x22, #1
    b .Lstrlen2
.Lstrlen2_done:

    // tamaño total
    add x0, x21, x22
    add x0, x0, #1
    add x0, x0, #15
    and x0, x0, #-16
    mov x23, x0

    // mmap
    mov x0, #0 // addr
    mov x1, x23 // length
    mov x2, #3 // PROT_READ | PROT_WRITE
    mov x3, #0x22 // MAP_PRIVATE | MAP_ANONYMOUS
    mov x4, #-1 // fd
    mov x5, #0 // offset
    mov x8, #222 // syscall: mmap
    svc #0

    cbz x0, .Lconcat_error
    mov x9, x0 // buffer destino

    // copiar cadena 1
    mov x10, #0
.Lcopy1:
    ldrb w11, [x19, x10]
    strb w11, [x9, x10]
    cbz w11, .Lcopy1_done
    add x10, x10, #1
    b .Lcopy1
.Lcopy1_done:

    // copiar cadena 2
    mov x12, #0
.Lcopy2:
    ldrb w11, [x20, x12]
    strb w11, [x9, x10]
    cbz w11, .Lcopy2_done
    add x10, x10, #1
    add x12, x12, #1
    b .Lcopy2
.Lcopy2_done:

    mov x0, x9
    b .Lconcat_end

.Lconcat_error:
    mov x0, #0

.Lconcat_end:
    ldp x21, x22, [sp], #16
    ldp x19, x20, [sp], #16
    ldp x29, x30, [sp], #16
    ret
