// chartoa.s - Convierte un carácter a cadena ASCII (string de 2 bytes)
// Entradas:
//   W0 = carácter (unsigned/signed char)
//   X1 = puntero a buffer destino
// Salida:
//   X1 = puntero a buffer (misma dirección)

.global chartoa
.text

chartoa:
    STP X29, X30, [SP, #-16]!
    MOV X29, SP

    STRB W0, [X1]        // Guarda el carácter en el buffer
    MOV W2, #0
    STRB W2, [X1, #1]    // Terminador nulo

    MOV X1, X1           // Devuelve el puntero al buffer

    LDP X29, X30, [SP], #16
    RET