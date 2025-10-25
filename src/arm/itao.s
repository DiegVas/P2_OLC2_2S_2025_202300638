// itao.s - Convierte un entero a cadena ASCII
// Entradas:
//   X0 = número (signed int)
//   X1 = puntero a buffer destino
// Salida:
//   X1 = puntero a buffer (misma dirección)

.global itao
.text

itao:
    STP X29, X30, [SP, #-16]!    // guardar marco y LR
    MOV X29, SP

    MOV X2, X1          // copia del puntero destino
    MOV X3, X0          // copia del número

    // --- Manejo de signo ---
    MOV W4, W3
    CMP W4, #0
    B.LT .negative       // si < 0, manejar signo
    MOV W5, #0           // positivo, sin signo
    B .convert
.negative:
    NEG W3, W3          // convertir a positivo
    MOV W5, #1          // flag de signo
.convert:

    // --- Convertir número a cadena invertida ---
    MOV X6, X2          // puntero temporal
    MOV X7, #0          // contador de dígitos

.loop:
    MOV W8, #10
    UDIV W9, W3, W8     // W9 = W3 / 10
    MSUB W10, W9, W8, W3 // W10 = W3 - (W9 * 10)
    ADD W10, W10, #'0'  // convertir a ASCII
    STRB W10, [X6], #1  // guardar caracter y avanzar
    MOV W3, W9
    ADD X7, X7, #1
    CBNZ W3, .loop

    // --- Agregar signo si era negativo ---
    CBZ W5, .reverse
    MOV W10, #'-'
    STRB W10, [X6], #1
    ADD X7, X7, #1

.reverse:
    // --- Invertir cadena ---
    SUB X6, X6, #1      // retrocede al último caracter válido
    MOV X9, X1          // inicio
    MOV X10, X6         // fin
.revloop:
    CMP X9, X10
    B.GE .done
    LDRB W11, [X9]
    LDRB W12, [X10]
    STRB W12, [X9]
    STRB W11, [X10]
    ADD X9, X9, #1
    SUB X10, X10, #1
    B .revloop

.done:
    ADD X6, X6, #1
    MOV W0, #0
    STRB W0, [X6]       // null terminator

    MOV X1, X1          // devolver puntero al buffer
    LDP X29, X30, [SP], #16
    RET
