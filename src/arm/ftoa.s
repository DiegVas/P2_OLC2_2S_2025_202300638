// ftoa.s - Convierte un double a cadena ASCII
// Entradas:
//   D0 = número (double)
//   X1 = puntero a buffer destino  
//   W2 = número de decimales
// Salida:
//   X1 = puntero a buffer (misma dirección)

.global ftoa
.extern itao

.text
ftoa:
    STP X29, X30, [SP, #-16]!
    MOV X29, SP
    STP X19, X20, [SP, #-16]!    // Preservar registros adicionales
    STP X21, X22, [SP, #-16]!

    MOV X19, X1         // buffer destino (preservado)
    MOV W20, W2         // número de decimales (preservado)
    MOV X21, X1         // guardar dirección original del buffer

    // --- Manejo del signo ---
    FMOV D1, D0
    ADR X10, const_zero
    LDR D31, [X10]
    FCMPE D1, D31
    B.GE .positive
    MOV W4, #1          // negativo
    FNEG D1, D1
    B .cont
.positive:
    MOV W4, #0          // positivo
.cont:

    // --- Agregar signo primero si negativo ---
    CBZ W4, .no_sign
    MOV W7, #'-'
    STRB W7, [X19], #1
.no_sign:

    // --- Parte entera ---
    FCVTZS X5, D1                 // parte entera
    // Asegurarse que X5 sea positivo (evita doble signo)
    CMP X5, #0
    B.GE .call_itao
    NEG X5, X5
.call_itao:
    SCVTF D2, X5                  // parte entera como float
    FSUB D3, D1, D2               // parte fraccional

    MOV X0, X5
    MOV X1, X19                   // buffer actual
    BL itao
    
    // Encontrar el final de la cadena de enteros
.find_end:
    LDRB W6, [X19]
    CBZ W6, .found_end
    ADD X19, X19, #1
    B .find_end
.found_end:

    // --- Punto decimal ---
    CBZ W20, .done_frac          // usar W20 preservado
    MOV W7, #'.'
    STRB W7, [X19], #1

    // --- Parte fraccional ---
    ADR X9, const_ten
    LDR D4, [X9]

    MOV W8, #0
.frac_loop:
    CMP W8, W20                   // usar W20 preservado
    B.GE .done_frac
    FMUL D3, D3, D4
    FCVTZS X9, D3
    SCVTF D10, X9
    FSUB D3, D3, D10
    ADD W9, W9, #'0'
    STRB W9, [X19], #1
    ADD W8, W8, #1
    B .frac_loop

.done_frac:
    MOV W9, #0
    STRB W9, [X19]

    MOV X1, X21                   // retornar dirección original del buffer
    LDP X21, X22, [SP], #16
    LDP X19, X20, [SP], #16
    LDP X29, X30, [SP], #16
    RET

.data
.align 3
const_zero: .double 0.0
const_ten: .double 10.0
