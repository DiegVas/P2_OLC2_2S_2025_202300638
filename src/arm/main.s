.global main 
.extern printf 
.extern itao 
.extern ftoa 
.extern booltoa 
.extern string_compare 
.extern string_concat 
.extern chartoa 
.extern buscar_entero 
.extern buscar_string 
.extern append_to_array_integer 
 .extern append_to_string_array 
.extern string_to_double 
.extern string_to_int 
.extern string_join 

.data 
print: .asciz "%s\n" 
int_0: .word 0
int_1: .word 2
buffer1: .space 32
int_2: .word 1
buffer2: .space 32
int_3: .word 1

.bss 
i_Global: .space 4

.text 
main: 
STP X29, X30, [SP, #-16]! 
MOV X29, SP 
	
	// Declaración de variable i_Global
	
	// Carga de entero 0
	adr    x0, int_0
	ldr    w0, [x0]
	ldr x1, =i_Global
	str x0, [x1]
	
	
	// Instrucción WHILE 0
	while_0:
	
	// Carga de variable i_Global de tipo INTEGER
	adr   x1, i_Global
	ldr    w1, [x1]
	
	// Carga de entero 2
	adr    x2, int_1
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, le
	mov w3, w0
	cbz w3, end_while_0
	
	// Instrucción de impresión
	
	// Carga de variable i_Global de tipo INTEGER
	adr   x0, i_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer1
	bl itao
	adr x0, print
	bl printf
	
	
	// Carga de variable i_Global de tipo INTEGER
	adr   x1, i_Global
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_2
	ldr    w2, [x2]
	add    w0, w1, w2
	mov    w3, w0
	
	// Asignación de variable i_Global
	mov    w0, w3
	ldr x1, =i_Global
	str w0, [x1]
	
	b while_0
	end_while_0:
	
	// Instrucción de impresión
	
	// Carga de variable i_Global de tipo INTEGER
	adr   x0, i_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer2
	bl itao
	adr x0, print
	bl printf
	
	
	// Carga de variable i_Global de tipo INTEGER
	adr   x1, i_Global
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_3
	ldr    w2, [x2]
	add    w0, w1, w2
	mov    w3, w0
	
	// Asignación de variable i_Global
	mov    w0, w3
	ldr x1, =i_Global
	str w0, [x1]
	


MOV W0, #0 
LDP X29, X30, [SP], #16 
mov x8, 93 
svc 0 

