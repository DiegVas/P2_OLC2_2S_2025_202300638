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
string_0: .asciz "\n--- UNIR CADENAS CON Strings.join ---"
string_1: .asciz ", "
buffer1: .space 32
string_2: .asciz "Ana"
string_3: .asciz "Luis"
string_4: .asciz "Maria"
string_5: .asciz "Carlos"
joined_string_0: .quad string_2, string_3, string_4, string_5
joined_string_0_length: .word 4
string_6: .asciz "Lista de estudiantes: "
string_7: .asciz " | "
buffer2: .space 32
string_8: .asciz "Matematicas"
string_9: .asciz "Fisica"
string_10: .asciz "Quimica"
joined_string_1: .quad string_8, string_9, string_10
joined_string_1_length: .word 3
string_11: .asciz "Materias disponibles: "
string_12: .asciz " - "
buffer3: .space 32
string_13: .asciz "85"
string_14: .asciz "92"
string_15: .asciz "78"
string_16: .asciz "95"
joined_string_2: .quad string_13, string_14, string_15, string_16
joined_string_2_length: .word 4
string_17: .asciz "Reporte de calificaciones: "

.bss 
listaEstudiantes_Global: .space 8
listaMaterias_Global: .space 8
reporteCalificaciones_Global: .space 8

.text 
main: 
STP X29, X30, [SP, #-16]! 
MOV X29, SP 
	
	// Instrucción de impresión
	
	// Carga de string \n--- UNIR CADENAS CON Strings.join ---
	adr     x1, string_0
	adr x0, print
	bl printf
	
	
	// Declaración de variable listaEstudiantes_Global
	
	// JOIN de elementos con separador , 
	
	// Carga de string , 
	adr     x0, string_1
	adr     x3, buffer1
	adrp      x1, joined_string_0
	add       x1, x1, :lo12:joined_string_0
	adr       x2, joined_string_0_length
	ldr       w2, [x2]
	bl string_join
	ldr x1, =listaEstudiantes_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Lista de estudiantes: 
	adr     x1, string_6
	str     x1, [sp, #-16]!
	
	// Carga de variable listaEstudiantes_Global de tipo STRING
	adr   x2, listaEstudiantes_Global
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Declaración de variable listaMaterias_Global
	
	// JOIN de elementos con separador  | 
	
	// Carga de string  | 
	adr     x0, string_7
	adr     x3, buffer2
	adrp      x1, joined_string_1
	add       x1, x1, :lo12:joined_string_1
	adr       x2, joined_string_1_length
	ldr       w2, [x2]
	bl string_join
	ldr x1, =listaMaterias_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Materias disponibles: 
	adr     x1, string_11
	str     x1, [sp, #-16]!
	
	// Carga de variable listaMaterias_Global de tipo STRING
	adr   x2, listaMaterias_Global
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Declaración de variable reporteCalificaciones_Global
	
	// JOIN de elementos con separador  - 
	
	// Carga de string  - 
	adr     x0, string_12
	adr     x3, buffer3
	adrp      x1, joined_string_2
	add       x1, x1, :lo12:joined_string_2
	adr       x2, joined_string_2_length
	ldr       w2, [x2]
	bl string_join
	ldr x1, =reporteCalificaciones_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Reporte de calificaciones: 
	adr     x1, string_17
	str     x1, [sp, #-16]!
	
	// Carga de variable reporteCalificaciones_Global de tipo STRING
	adr   x2, reporteCalificaciones_Global
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	


MOV W0, #0 
LDP X29, X30, [SP], #16 
mov x8, 93 
svc 0 

