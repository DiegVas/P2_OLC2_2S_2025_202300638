.global booltoa

.data
true_str:  .asciz "Verdadero"
false_str: .asciz "Falso"

.text
// Entrada: w0 = 1 o 0
// Salida: x1 = puntero a cadena ("Verdadero" o "Falso")
booltoa:
    CMP W0, #1
    BEQ is_true

    // Si no es 1 → devolver "Falso"
    ADR X0, false_str
    mov X1, X0  
    RET

is_true:
    ADR X0, true_str
    mov X1, X0
    RET
