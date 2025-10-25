// string_compare.s - Comparar dos cadenas en ARM64
// Entrada: x1 = puntero a cadena1, x2 = puntero a cadena2
// Salida: x1 = 1 si son iguales, 0 si son diferentes

.global string_compare
.text

string_compare:
    stp x29, x30, [sp, #-16]!
    mov x29, sp

.Lcompare_loop:
    ldrb w3, [x1], #1      // leer byte cadena1
    ldrb w4, [x2], #1      // leer byte cadena2
    cmp  w3, w4            // comparar
    b.ne .Lnot_equal       // si distintos → falso
    cbz  w3, .Lequal       // si fin de cadena → iguales
    b    .Lcompare_loop

.Lequal:
    mov x1, #1             // verdadero
    b    .Lend

.Lnot_equal:
    mov x1, #0             // falso

.Lend:
    ldp x29, x30, [sp], #16
    ret
