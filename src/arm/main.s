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

.data 
print: .asciz "%s\n" 
string_0: .asciz "=== SISTEMA DE GESTION DE INVENTARIO ==="
string_1: .asciz "\n--- DECLARACION DE ARREGLOS ---"
productos_Global: .quad productos_Global_elem_0, productos_Global_elem_1, productos_Global_elem_2, productos_Global_elem_3, productos_Global_elem_4
productos_Global_elem_0: .asciz "Laptop"
productos_Global_elem_1: .asciz "Mouse"
productos_Global_elem_2: .asciz "Teclado"
productos_Global_elem_3: .asciz "Monitor"
productos_Global_elem_4: .asciz "Impresora"
productos_Global_length: .word 5
precios_Global: .word 15000, 250, 800, 3500, 2200
precios_Global_length: .word 5
cantidades_Global: .word 10, 50, 30, 15, 8
cantidades_Global_length: .word 5
disponibles_Global: .word 1, 1, 1, 1, 0
disponibles_Global_length: .word 5
codigosProducto_Global: .word 0, 0, 0, 0, 0
codigosProducto_Global_length: .word 5
proveedores_Global: .quad proveedores_Global_elem_0, proveedores_Global_elem_1, proveedores_Global_elem_2, proveedores_Global_elem_3, proveedores_Global_elem_4
proveedores_Global_elem_0: .asciz ""
proveedores_Global_elem_1: .asciz ""
proveedores_Global_elem_2: .asciz ""
proveedores_Global_elem_3: .asciz ""
proveedores_Global_elem_4: .asciz ""
proveedores_Global_length: .word 5
string_12: .asciz "Arreglos declarados exitosamente:"
string_13: .asciz "- productos: arreglo de String con "
buffer1: .space 32
string_14: .asciz " elementos"
string_15: .asciz "- precios: arreglo de int con "
buffer2: .space 32
string_16: .asciz " elementos"
string_17: .asciz "- cantidades: arreglo de int con "
buffer3: .space 32
string_18: .asciz " elementos"
string_19: .asciz "- disponibles: arreglo de boolean con "
buffer4: .space 32
string_20: .asciz " elementos"
string_21: .asciz "- codigosProducto: arreglo vacío de "
buffer5: .space 32
string_22: .asciz " elementos"
string_23: .asciz "- proveedores: arreglo vacío de "
buffer6: .space 32
string_24: .asciz " elementos"
string_25: .asciz "\n--- MODIFICACION DE ELEMENTOS ---"
string_26: .asciz "Estado inicial del Mouse:"
string_27: .asciz "- Precio: "
int_15: .word 1
buffer7: .space 32
string_28: .asciz "- Cantidad: "
int_16: .word 1
buffer8: .space 32
string_29: .asciz "- Disponible: "
int_17: .word 1
buffer9: .space 32
int_19: .word 1
int_18: .word 280
int_21: .word 1
int_20: .word 45
int_22: .word 4
string_30: .asciz "\nDespués de modificaciones:"
string_31: .asciz "- Nuevo precio Mouse: "
int_23: .word 1
buffer10: .space 32
string_32: .asciz "- Nueva cantidad Mouse: "
int_24: .word 1
buffer11: .space 32
string_33: .asciz "- Impresora ahora disponible: "
int_25: .word 4
buffer12: .space 32
int_27: .word 0
int_26: .word 1001
int_29: .word 1
int_28: .word 1002
int_31: .word 2
int_30: .word 1003
int_33: .word 3
int_32: .word 1004
int_35: .word 4
int_34: .word 1005
int_36: .word 0
string_34: .asciz "TechCorp"
int_37: .word 1
string_35: .asciz "DeviceMax"
int_38: .word 2
string_36: .asciz "KeyboardPro"
int_39: .word 3
string_37: .asciz "ScreenTech"
int_40: .word 4
string_38: .asciz "PrintSolutions"
string_39: .asciz "Códigos y proveedores asignados correctamente"
string_40: .asciz "\n--- ACCESO A ELEMENTOS ---"
string_41: .asciz "Inventario completo:"
int_41: .word 0
string_42: .asciz ""
string_43: .asciz "DISPONIBLE"
string_44: .asciz "AGOTADO"
string_45: .asciz "Posición "
buffer13: .space 32
string_46: .asciz ":"
string_47: .asciz "  Código: "
buffer14: .space 32
string_48: .asciz "  Producto: "
string_49: .asciz "  Proveedor: "
string_50: .asciz "  Precio: Q"
buffer15: .space 32
string_51: .asciz "  Cantidad: "
buffer16: .space 32
string_52: .asciz "  Estado: "
string_53: .asciz ""
int_42: .word 1
string_54: .asciz "Acceso directo a elementos específicos:"
string_55: .asciz "Primer producto: "
int_43: .word 0
string_56: .asciz "Último producto: "
int_44: .word 1
string_57: .asciz "Producto del medio: "
int_45: .word 2
string_58: .asciz "\n--- BUSQUEDA CON Arrays.indexOf ---"
string_59: .asciz "Monitor"
string_60: .asciz "Producto '"
string_61: .asciz "' encontrado en posición: "
buffer17: .space 32
string_62: .asciz "Detalles:"
string_63: .asciz "  Código: "
buffer18: .space 32
string_64: .asciz "  Precio: Q"
buffer19: .space 32
string_65: .asciz "  Cantidad: "
buffer20: .space 32
string_66: .asciz "  Proveedor: "
string_67: .asciz "Producto '"
string_68: .asciz "' no encontrado"
int_47: .word 1003
string_69: .asciz "Código "
buffer21: .space 32
string_70: .asciz " encontrado en posición: "
buffer22: .space 32
string_71: .asciz "Corresponde al producto: "
string_72: .asciz "Tablet"
string_73: .asciz "Búsqueda de '"
string_74: .asciz "': "
buffer23: .space 32
string_75: .asciz " (no encontrado)"
string_76: .asciz "\n--- TAMAÑO DE ARREGLOS (length) ---"
string_77: .asciz "Información de tamaños:"
string_78: .asciz "- Productos: "
buffer24: .space 32
string_79: .asciz " elementos"
string_80: .asciz "- Precios: "
buffer25: .space 32
string_81: .asciz " elementos"
string_82: .asciz "- Cantidades: "
buffer26: .space 32
string_83: .asciz " elementos"
string_84: .asciz "- Disponibilidad: "
buffer27: .space 32
string_85: .asciz " elementos"
string_86: .asciz "Todos los arreglos tienen el mismo tamaño: "
buffer28: .space 32
string_87: .asciz "\nUso de length en iteraciones:"
int_49: .word 0
int_50: .word 0
int_51: .word 1
int_52: .word 1
string_88: .asciz "Productos disponibles: "
buffer29: .space 32
string_89: .asciz " de "
buffer30: .space 32
string_90: .asciz "\n--- AGREGAR ELEMENTOS CON add() ---"
string_91: .asciz "Estado inicial: "
buffer31: .space 32
string_92: .asciz " productos"
productosAmpliados_Global: .space 400
productosAmpliados_Global_length: .word 0
string_93: .asciz "Webcam"
string_94: .asciz "Audífonos"
string_95: .asciz "Micrófono"
preciosAmpliados_Global: .space 400
preciosAmpliados_Global_length: .word 0
int_53: .word 450
int_54: .word 320
int_55: .word 180
cantidadesAmpliadas_Global: .space 400
cantidadesAmpliadas_Global_length: .word 0
int_56: .word 25
int_57: .word 40
int_58: .word 15
string_96: .asciz "Después de agregar: "
buffer32: .space 32
string_97: .asciz " productos"
string_98: .asciz "Nuevos productos agregados:"
string_99: .asciz "- "
string_100: .asciz " | Precio: Q"
buffer33: .space 32
string_101: .asciz " | Cantidad: "
buffer34: .space 32
int_59: .word 1
string_102: .asciz "\n--- ALGORITMOS DE ORDENAMIENTO ---"
preciosParaOrdenar_Global: .word 15000, 280, 800, 3500, 2200, 450, 320, 180
preciosParaOrdenar_Global_length: .word 8
productosParaOrdenar_Global: .quad productosParaOrdenar_Global_elem_0, productosParaOrdenar_Global_elem_1, productosParaOrdenar_Global_elem_2, productosParaOrdenar_Global_elem_3, productosParaOrdenar_Global_elem_4, productosParaOrdenar_Global_elem_5, productosParaOrdenar_Global_elem_6, productosParaOrdenar_Global_elem_7
productosParaOrdenar_Global_elem_0: .asciz "Laptop"
productosParaOrdenar_Global_elem_1: .asciz "Mouse"
productosParaOrdenar_Global_elem_2: .asciz "Teclado"
productosParaOrdenar_Global_elem_3: .asciz "Monitor"
productosParaOrdenar_Global_elem_4: .asciz "Impresora"
productosParaOrdenar_Global_elem_5: .asciz "Webcam"
productosParaOrdenar_Global_elem_6: .asciz "Audífonos"
productosParaOrdenar_Global_elem_7: .asciz "Micrófono"
productosParaOrdenar_Global_length: .word 8

.bss 
i_For0: .space 4
estado_For0: .space 8
productoBuscado_Global: .space 8
posicionProducto_Global: .space 4
codigoBuscado_Global: .space 4
posicionCodigo_Global: .space 4
productoInexistente_Global: .space 8
posicionInexistente_Global: .space 4
totalProductos_Global: .space 4
totalPrecios_Global: .space 4
totalCantidades_Global: .space 4
totalDisponibles_Global: .space 4
datosConsistentes_Global: .space 4
productosDisponibles_Global: .space 4
i_For1: .space 4
i_For2: .space 4

.text 
main: 
STP X29, X30, [SP, #-16]! 
MOV X29, SP 
	
	// Instrucción de impresión
	
	// Carga de string === SISTEMA DE GESTION DE INVENTARIO ===
	adr     x1, string_0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \n--- DECLARACION DE ARREGLOS ---
	adr     x1, string_1
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Arreglos declarados exitosamente:
	adr     x1, string_12
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - productos: arreglo de String con 
	adr     x1, string_13
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector productos_Global
	adr    x0, productos_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer1
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_14
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - precios: arreglo de int con 
	adr     x1, string_15
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector precios_Global
	adr    x0, precios_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer2
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_16
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - cantidades: arreglo de int con 
	adr     x1, string_17
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector cantidades_Global
	adr    x0, cantidades_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer3
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_18
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - disponibles: arreglo de boolean con 
	adr     x1, string_19
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector disponibles_Global
	adr    x0, disponibles_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer4
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_20
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - codigosProducto: arreglo vacío de 
	adr     x1, string_21
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector codigosProducto_Global
	adr    x0, codigosProducto_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer5
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_22
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - proveedores: arreglo vacío de 
	adr     x1, string_23
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector proveedores_Global
	adr    x0, proveedores_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer6
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_24
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \n--- MODIFICACION DE ELEMENTOS ---
	adr     x1, string_25
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Estado inicial del Mouse:
	adr     x1, string_26
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Precio: 
	adr     x1, string_27
	str     x1, [sp, #-16]!
	
	// Carga de entero 1
	adr    x0, int_15
	ldr    w0, [x0]
	
	// Carga de variable precios_Global de tipo INTEGER
	adrp   x1, precios_Global
	add    x1, x1, :lo12:precios_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer7
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Cantidad: 
	adr     x1, string_28
	str     x1, [sp, #-16]!
	
	// Carga de entero 1
	adr    x0, int_16
	ldr    w0, [x0]
	
	// Carga de variable cantidades_Global de tipo INTEGER
	adrp   x1, cantidades_Global
	add    x1, x1, :lo12:cantidades_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer8
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Disponible: 
	adr     x1, string_29
	str     x1, [sp, #-16]!
	
	// Carga de entero 1
	adr    x0, int_17
	ldr    w0, [x0]
	
	// Carga de variable disponibles_Global de tipo BOOLEAN
	adrp   x1, disponibles_Global
	add    x1, x1, :lo12:disponibles_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de BOOLEAN a STRING
	adr     x1, buffer9
	bl booltoa
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Carga de entero 1
	adr    x2, int_19
	ldr    w2, [x2]
	
	// Carga de entero 280
	adr    x0, int_18
	ldr    w0, [x0]
	
	// Asignación de vector precios_Global[1]
	
	// Carga de variable precios_Global de tipo INTEGER
	adrp   x1, precios_Global
	add    x1, x1, :lo12:precios_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 1
	adr    x2, int_21
	ldr    w2, [x2]
	
	// Carga de entero 45
	adr    x0, int_20
	ldr    w0, [x0]
	
	// Asignación de vector cantidades_Global[1]
	
	// Carga de variable cantidades_Global de tipo INTEGER
	adrp   x1, cantidades_Global
	add    x1, x1, :lo12:cantidades_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 4
	adr    x2, int_22
	ldr    w2, [x2]
	
	// Carga de boolean true
	mov     w0, #1
	
	// Asignación de vector disponibles_Global[4]
	
	// Carga de variable disponibles_Global de tipo BOOLEAN
	adrp   x1, disponibles_Global
	add    x1, x1, :lo12:disponibles_Global
	str    w0, [x1, x2, lsl #2]
	
	// Instrucción de impresión
	
	// Carga de string \nDespués de modificaciones:
	adr     x1, string_30
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Nuevo precio Mouse: 
	adr     x1, string_31
	str     x1, [sp, #-16]!
	
	// Carga de entero 1
	adr    x0, int_23
	ldr    w0, [x0]
	
	// Carga de variable precios_Global de tipo INTEGER
	adrp   x1, precios_Global
	add    x1, x1, :lo12:precios_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer10
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Nueva cantidad Mouse: 
	adr     x1, string_32
	str     x1, [sp, #-16]!
	
	// Carga de entero 1
	adr    x0, int_24
	ldr    w0, [x0]
	
	// Carga de variable cantidades_Global de tipo INTEGER
	adrp   x1, cantidades_Global
	add    x1, x1, :lo12:cantidades_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer11
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Impresora ahora disponible: 
	adr     x1, string_33
	str     x1, [sp, #-16]!
	
	// Carga de entero 4
	adr    x0, int_25
	ldr    w0, [x0]
	
	// Carga de variable disponibles_Global de tipo BOOLEAN
	adrp   x1, disponibles_Global
	add    x1, x1, :lo12:disponibles_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de BOOLEAN a STRING
	adr     x1, buffer12
	bl booltoa
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Carga de entero 0
	adr    x2, int_27
	ldr    w2, [x2]
	
	// Carga de entero 1001
	adr    x0, int_26
	ldr    w0, [x0]
	
	// Asignación de vector codigosProducto_Global[0]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 1
	adr    x2, int_29
	ldr    w2, [x2]
	
	// Carga de entero 1002
	adr    x0, int_28
	ldr    w0, [x0]
	
	// Asignación de vector codigosProducto_Global[1]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 2
	adr    x2, int_31
	ldr    w2, [x2]
	
	// Carga de entero 1003
	adr    x0, int_30
	ldr    w0, [x0]
	
	// Asignación de vector codigosProducto_Global[2]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 3
	adr    x2, int_33
	ldr    w2, [x2]
	
	// Carga de entero 1004
	adr    x0, int_32
	ldr    w0, [x0]
	
	// Asignación de vector codigosProducto_Global[3]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 4
	adr    x2, int_35
	ldr    w2, [x2]
	
	// Carga de entero 1005
	adr    x0, int_34
	ldr    w0, [x0]
	
	// Asignación de vector codigosProducto_Global[4]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	str    w0, [x1, x2, lsl #2]
	
	// Carga de entero 0
	adr    x2, int_36
	ldr    w2, [x2]
	
	// Carga de string TechCorp
	adr     x0, string_34
	
	// Asignación de vector proveedores_Global[0]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	str    x0, [x1, x2, lsl #3]
	
	// Carga de entero 1
	adr    x2, int_37
	ldr    w2, [x2]
	
	// Carga de string DeviceMax
	adr     x0, string_35
	
	// Asignación de vector proveedores_Global[1]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	str    x0, [x1, x2, lsl #3]
	
	// Carga de entero 2
	adr    x2, int_38
	ldr    w2, [x2]
	
	// Carga de string KeyboardPro
	adr     x0, string_36
	
	// Asignación de vector proveedores_Global[2]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	str    x0, [x1, x2, lsl #3]
	
	// Carga de entero 3
	adr    x2, int_39
	ldr    w2, [x2]
	
	// Carga de string ScreenTech
	adr     x0, string_37
	
	// Asignación de vector proveedores_Global[3]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	str    x0, [x1, x2, lsl #3]
	
	// Carga de entero 4
	adr    x2, int_40
	ldr    w2, [x2]
	
	// Carga de string PrintSolutions
	adr     x0, string_38
	
	// Asignación de vector proveedores_Global[4]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	str    x0, [x1, x2, lsl #3]
	
	// Instrucción de impresión
	
	// Carga de string Códigos y proveedores asignados correctamente
	adr     x1, string_39
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \n--- ACCESO A ELEMENTOS ---
	adr     x1, string_40
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Inventario completo:
	adr     x1, string_41
	adr x0, print
	bl printf
	
	
	// Declaración de variable i_For0
	
	// Carga de entero 0
	adr    x0, int_41
	ldr    w0, [x0]
	ldr x1, =i_For0
	str x0, [x1]
	
	
	// Instrucción FOR 0
	for_0:
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x1, i_For0
	ldr    w1, [x1]
	
	// Obtener longitud del vector productos_Global
	adr    x2, productos_Global_length
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, lt
	mov w3, w0
	cbz w3, end_for_0
	
	// Declaración de variable estado_For0
	
	// Carga de string 
	adr     x0, string_42
	ldr x1, =estado_For0
	str x0, [x1]
	
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Carga de variable disponibles_Global de tipo BOOLEAN
	adrp   x1, disponibles_Global
	add    x1, x1, :lo12:disponibles_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Instrucción IF 1
	cbz w0, else_0
	
	// Carga de string DISPONIBLE
	adr     x0, string_43
	ldr x1, =estado_For0
	str x0, [x1]
	
	b end_if_1
	
	// ELSE0
	else_0:
	
	// Carga de string AGOTADO
	adr     x0, string_44
	ldr x1, =estado_For0
	str x0, [x1]
	
	b end_if_1
	end_if_1:
	
	// Instrucción de impresión
	
	// Carga de string Posición 
	adr     x1, string_45
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer13
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string :
	adr     x2, string_46
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Código: 
	adr     x1, string_47
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer14
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Producto: 
	adr     x1, string_48
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Carga de variable productos_Global de tipo STRING
	adrp   x1, productos_Global
	add    x1, x1, :lo12:productos_Global
	ldr    x2, [x1, x0, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Proveedor: 
	adr     x1, string_49
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	ldr    x2, [x1, x0, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Precio: Q
	adr     x1, string_50
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Carga de variable precios_Global de tipo INTEGER
	adrp   x1, precios_Global
	add    x1, x1, :lo12:precios_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer15
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Cantidad: 
	adr     x1, string_51
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x0, i_For0
	ldr    w0, [x0]
	
	// Carga de variable cantidades_Global de tipo INTEGER
	adrp   x1, cantidades_Global
	add    x1, x1, :lo12:cantidades_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer16
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Estado: 
	adr     x1, string_52
	str     x1, [sp, #-16]!
	
	// Carga de variable estado_For0 de tipo STRING
	adr   x2, estado_For0
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string 
	adr     x1, string_53
	adr x0, print
	bl printf
	
	update_for_0:
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x1, i_For0
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_42
	ldr    w2, [x2]
	add    w0, w1, w2
	mov    w3, w0
	
	// Asignación de variable i_For0
	mov    w0, w3
	ldr x1, =i_For0
	str w0, [x1]
	
	
	// Carga de variable i_For0 de tipo INTEGER
	adr   x1, i_For0
	ldr    w1, [x1]
	
	// Obtener longitud del vector productos_Global
	adr    x2, productos_Global_length
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, lt
	mov w4, w0
	b for_0
	end_for_0:
	
	// Instrucción de impresión
	
	// Carga de string Acceso directo a elementos específicos:
	adr     x1, string_54
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Primer producto: 
	adr     x1, string_55
	str     x1, [sp, #-16]!
	
	// Carga de entero 0
	adr    x0, int_43
	ldr    w0, [x0]
	
	// Carga de variable productos_Global de tipo STRING
	adrp   x1, productos_Global
	add    x1, x1, :lo12:productos_Global
	ldr    x2, [x1, x0, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Último producto: 
	adr     x1, string_56
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector productos_Global
	adr    x1, productos_Global_length
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_44
	ldr    w2, [x2]
	sub    w0, w1, w2
	mov    w3, w0
	
	// Carga de variable productos_Global de tipo STRING
	adrp   x1, productos_Global
	add    x1, x1, :lo12:productos_Global
	ldr    x2, [x1, x3, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Producto del medio: 
	adr     x1, string_57
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector productos_Global
	adr    x1, productos_Global_length
	ldr    w1, [x1]
	
	// Carga de entero 2
	adr    x2, int_45
	ldr    w2, [x2]
	sdiv    w0, w1, w2
	mov    w3, w0
	fcvtzs w3, d3
	
	// Carga de variable productos_Global de tipo STRING
	adrp   x1, productos_Global
	add    x1, x1, :lo12:productos_Global
	ldr    x2, [x1, x3, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \n--- BUSQUEDA CON Arrays.indexOf ---
	adr     x1, string_58
	adr x0, print
	bl printf
	
	
	// Declaración de variable productoBuscado_Global
	
	// Carga de string Monitor
	adr     x0, string_59
	ldr x1, =productoBuscado_Global
	str x0, [x1]
	
	
	// Declaración de variable posicionProducto_Global
	
	// Obtener indexOf del valor en el vector productos_Global
	
	// Carga de variable productoBuscado_Global de tipo STRING
	adr   x0, productoBuscado_Global
	ldr    x0, [x0]
	mov  x2, x0
	adrp x0, productos_Global
	add  x0, x0, :lo12:productos_Global
	adr  x1, productos_Global_length
	ldr  w1, [x1]
	bl   buscar_string
	ldr x1, =posicionProducto_Global
	str x0, [x1]
	
	
	// Carga de variable posicionProducto_Global de tipo INTEGER
	adr   x1, posicionProducto_Global
	ldr    w1, [x1]
	cmp w1, w2
	cset w0, ne
	mov w3, w0
	
	// Instrucción IF 2
	cbz w3, else_1
	
	// Instrucción de impresión
	
	// Carga de string Producto '
	adr     x1, string_60
	str     x1, [sp, #-16]!
	
	// Carga de variable productoBuscado_Global de tipo STRING
	adr   x2, productoBuscado_Global
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string ' encontrado en posición: 
	adr     x2, string_61
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionProducto_Global de tipo INTEGER
	adr   x0, posicionProducto_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer17
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Detalles:
	adr     x1, string_62
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Código: 
	adr     x1, string_63
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionProducto_Global de tipo INTEGER
	adr   x0, posicionProducto_Global
	ldr    w0, [x0]
	
	// Carga de variable codigosProducto_Global de tipo INTEGER
	adrp   x1, codigosProducto_Global
	add    x1, x1, :lo12:codigosProducto_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer18
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Precio: Q
	adr     x1, string_64
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionProducto_Global de tipo INTEGER
	adr   x0, posicionProducto_Global
	ldr    w0, [x0]
	
	// Carga de variable precios_Global de tipo INTEGER
	adrp   x1, precios_Global
	add    x1, x1, :lo12:precios_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer19
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Cantidad: 
	adr     x1, string_65
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionProducto_Global de tipo INTEGER
	adr   x0, posicionProducto_Global
	ldr    w0, [x0]
	
	// Carga de variable cantidades_Global de tipo INTEGER
	adrp   x1, cantidades_Global
	add    x1, x1, :lo12:cantidades_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer20
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string   Proveedor: 
	adr     x1, string_66
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionProducto_Global de tipo INTEGER
	adr   x0, posicionProducto_Global
	ldr    w0, [x0]
	
	// Carga de variable proveedores_Global de tipo STRING
	adrp   x1, proveedores_Global
	add    x1, x1, :lo12:proveedores_Global
	ldr    x2, [x1, x0, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	b end_if_2
	
	// ELSE0
	else_1:
	
	// Instrucción de impresión
	
	// Carga de string Producto '
	adr     x1, string_67
	str     x1, [sp, #-16]!
	
	// Carga de variable productoBuscado_Global de tipo STRING
	adr   x2, productoBuscado_Global
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string ' no encontrado
	adr     x2, string_68
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	b end_if_2
	end_if_2:
	
	// Declaración de variable codigoBuscado_Global
	
	// Carga de entero 1003
	adr    x0, int_47
	ldr    w0, [x0]
	ldr x1, =codigoBuscado_Global
	str x0, [x1]
	
	
	// Declaración de variable posicionCodigo_Global
	
	// Obtener indexOf del valor en el vector codigosProducto_Global
	
	// Carga de variable codigoBuscado_Global de tipo INTEGER
	adr   x0, codigoBuscado_Global
	ldr    w0, [x0]
	mov  x2, x0
	adrp x0, codigosProducto_Global
	add  x0, x0, :lo12:codigosProducto_Global
	adr  x1, codigosProducto_Global_length
	ldr  w1, [x1]
	bl   buscar_entero
	ldr x1, =posicionCodigo_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Código 
	adr     x1, string_69
	str     x1, [sp, #-16]!
	
	// Carga de variable codigoBuscado_Global de tipo INTEGER
	adr   x0, codigoBuscado_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer21
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  encontrado en posición: 
	adr     x2, string_70
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionCodigo_Global de tipo INTEGER
	adr   x0, posicionCodigo_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer22
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Carga de variable posicionCodigo_Global de tipo INTEGER
	adr   x1, posicionCodigo_Global
	ldr    w1, [x1]
	cmp w1, w2
	cset w0, ne
	mov w3, w0
	
	// Instrucción IF 3
	cbz w3, end_if_3
	
	// Instrucción de impresión
	
	// Carga de string Corresponde al producto: 
	adr     x1, string_71
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionCodigo_Global de tipo INTEGER
	adr   x0, posicionCodigo_Global
	ldr    w0, [x0]
	
	// Carga de variable productos_Global de tipo STRING
	adrp   x1, productos_Global
	add    x1, x1, :lo12:productos_Global
	ldr    x2, [x1, x0, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	b end_if_3
	end_if_3:
	
	// Declaración de variable productoInexistente_Global
	
	// Carga de string Tablet
	adr     x0, string_72
	ldr x1, =productoInexistente_Global
	str x0, [x1]
	
	
	// Declaración de variable posicionInexistente_Global
		ldr x1, =posicionInexistente_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Búsqueda de '
	adr     x1, string_73
	str     x1, [sp, #-16]!
	
	// Carga de variable productoInexistente_Global de tipo STRING
	adr   x2, productoInexistente_Global
	ldr    x2, [x2]
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string ': 
	adr     x2, string_74
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de variable posicionInexistente_Global de tipo INTEGER
	adr   x0, posicionInexistente_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer23
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  (no encontrado)
	adr     x2, string_75
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \n--- TAMAÑO DE ARREGLOS (length) ---
	adr     x1, string_76
	adr x0, print
	bl printf
	
	
	// Declaración de variable totalProductos_Global
	
	// Obtener longitud del vector productos_Global
	adr    x0, productos_Global_length
	ldr    w0, [x0]
	ldr x1, =totalProductos_Global
	str x0, [x1]
	
	
	// Declaración de variable totalPrecios_Global
	
	// Obtener longitud del vector precios_Global
	adr    x0, precios_Global_length
	ldr    w0, [x0]
	ldr x1, =totalPrecios_Global
	str x0, [x1]
	
	
	// Declaración de variable totalCantidades_Global
	
	// Obtener longitud del vector cantidades_Global
	adr    x0, cantidades_Global_length
	ldr    w0, [x0]
	ldr x1, =totalCantidades_Global
	str x0, [x1]
	
	
	// Declaración de variable totalDisponibles_Global
	
	// Obtener longitud del vector disponibles_Global
	adr    x0, disponibles_Global_length
	ldr    w0, [x0]
	ldr x1, =totalDisponibles_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Información de tamaños:
	adr     x1, string_77
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Productos: 
	adr     x1, string_78
	str     x1, [sp, #-16]!
	
	// Carga de variable totalProductos_Global de tipo INTEGER
	adr   x0, totalProductos_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer24
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_79
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Precios: 
	adr     x1, string_80
	str     x1, [sp, #-16]!
	
	// Carga de variable totalPrecios_Global de tipo INTEGER
	adr   x0, totalPrecios_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer25
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_81
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Cantidades: 
	adr     x1, string_82
	str     x1, [sp, #-16]!
	
	// Carga de variable totalCantidades_Global de tipo INTEGER
	adr   x0, totalCantidades_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer26
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_83
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string - Disponibilidad: 
	adr     x1, string_84
	str     x1, [sp, #-16]!
	
	// Carga de variable totalDisponibles_Global de tipo INTEGER
	adr   x0, totalDisponibles_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer27
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  elementos
	adr     x2, string_85
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Declaración de variable datosConsistentes_Global
	
	// Carga de variable totalProductos_Global de tipo INTEGER
	adr   x1, totalProductos_Global
	ldr    w1, [x1]
	
	// Carga de variable totalPrecios_Global de tipo INTEGER
	adr   x2, totalPrecios_Global
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, eq
	mov w3, w0
	
	// Carga de variable totalPrecios_Global de tipo INTEGER
	adr   x1, totalPrecios_Global
	ldr    w1, [x1]
	
	// Carga de variable totalCantidades_Global de tipo INTEGER
	adr   x2, totalCantidades_Global
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, eq
	mov w4, w0
	and w0, w3, w4
	mov w3, w0
	
	// Carga de variable totalCantidades_Global de tipo INTEGER
	adr   x1, totalCantidades_Global
	ldr    w1, [x1]
	
	// Carga de variable totalDisponibles_Global de tipo INTEGER
	adr   x2, totalDisponibles_Global
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, eq
	mov w5, w0
	and w0, w0, w5
	mov w0, w0
	ldr x1, =datosConsistentes_Global
	str x0, [x1]
	
	
	// Instrucción de impresión
	
	// Carga de string Todos los arreglos tienen el mismo tamaño: 
	adr     x1, string_86
	str     x1, [sp, #-16]!
	
	// Carga de variable datosConsistentes_Global de tipo BOOLEAN
	adr   x0, datosConsistentes_Global
	ldr    w0, [x0]
	
	// Conversion de BOOLEAN a STRING
	adr     x1, buffer28
	bl booltoa
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \nUso de length en iteraciones:
	adr     x1, string_87
	adr x0, print
	bl printf
	
	
	// Declaración de variable productosDisponibles_Global
	
	// Carga de entero 0
	adr    x0, int_49
	ldr    w0, [x0]
	ldr x1, =productosDisponibles_Global
	str x0, [x1]
	
	
	// Declaración de variable i_For1
	
	// Carga de entero 0
	adr    x0, int_50
	ldr    w0, [x0]
	ldr x1, =i_For1
	str x0, [x1]
	
	
	// Instrucción FOR 1
	for_1:
	
	// Carga de variable i_For1 de tipo INTEGER
	adr   x1, i_For1
	ldr    w1, [x1]
	
	// Obtener longitud del vector disponibles_Global
	adr    x2, disponibles_Global_length
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, lt
	mov w3, w0
	cbz w3, end_for_1
	
	// Carga de variable i_For1 de tipo INTEGER
	adr   x0, i_For1
	ldr    w0, [x0]
	
	// Carga de variable disponibles_Global de tipo BOOLEAN
	adrp   x1, disponibles_Global
	add    x1, x1, :lo12:disponibles_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Instrucción IF 4
	cbz w0, end_if_4
	
	// Carga de variable productosDisponibles_Global de tipo INTEGER
	adr   x1, productosDisponibles_Global
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_51
	ldr    w2, [x2]
	add    w0, w1, w2
	mov    w3, w0
	
	// Asignación de variable productosDisponibles_Global
	mov    w0, w3
	ldr x1, =productosDisponibles_Global
	str w0, [x1]
	
	b end_if_4
	end_if_4:
	update_for_1:
	
	// Carga de variable i_For1 de tipo INTEGER
	adr   x1, i_For1
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_52
	ldr    w2, [x2]
	add    w0, w1, w2
	mov    w3, w0
	
	// Asignación de variable i_For1
	mov    w0, w3
	ldr x1, =i_For1
	str w0, [x1]
	
	
	// Carga de variable i_For1 de tipo INTEGER
	adr   x1, i_For1
	ldr    w1, [x1]
	
	// Obtener longitud del vector disponibles_Global
	adr    x2, disponibles_Global_length
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, lt
	mov w4, w0
	b for_1
	end_for_1:
	
	// Instrucción de impresión
	
	// Carga de string Productos disponibles: 
	adr     x1, string_88
	str     x1, [sp, #-16]!
	
	// Carga de variable productosDisponibles_Global de tipo INTEGER
	adr   x0, productosDisponibles_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer29
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  de 
	adr     x2, string_89
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de variable totalProductos_Global de tipo INTEGER
	adr   x0, totalProductos_Global
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer30
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string \n--- AGREGAR ELEMENTOS CON add() ---
	adr     x1, string_90
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Estado inicial: 
	adr     x1, string_91
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector productos_Global
	adr    x0, productos_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer31
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  productos
	adr     x2, string_92
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Declaración de vector con add productosAmpliados
	adrp x2, productosAmpliados_Global
	add x2, x2, :lo12:productosAmpliados_Global
	adr x3, productosAmpliados_Global_length
	
	// Carga de string Webcam
	adr     x0, string_93
	mov   x4, x0
	
	// Agregar elemento al vector productos_Global
	adr   x0, productos_Global
	adr   x1, productos_Global_length
	ldr   w1, [x1]
	bl append_to_string_array	
	// reasignacion de vector con add productosAmpliados
	adrp x2, productosAmpliados_Global
	add x2, x2, :lo12:productosAmpliados_Global
	adr x3, productosAmpliados_Global_length
	
	// Carga de string Audífonos
	adr     x0, string_94
	mov   x4, x0
	
	// Agregar elemento al vector productosAmpliados_Global
	adr   x0, productosAmpliados_Global
	adr   x1, productosAmpliados_Global_length
	ldr   w1, [x1]
	bl append_to_string_array	
	// reasignacion de vector con add productosAmpliados
	adrp x2, productosAmpliados_Global
	add x2, x2, :lo12:productosAmpliados_Global
	adr x3, productosAmpliados_Global_length
	
	// Carga de string Micrófono
	adr     x0, string_95
	mov   x4, x0
	
	// Agregar elemento al vector productosAmpliados_Global
	adr   x0, productosAmpliados_Global
	adr   x1, productosAmpliados_Global_length
	ldr   w1, [x1]
	bl append_to_string_array	
	// Declaración de vector con add preciosAmpliados
	adrp x2, preciosAmpliados_Global
	add x2, x2, :lo12:preciosAmpliados_Global
	adr x3, preciosAmpliados_Global_length
	
	// Carga de entero 450
	adr    x0, int_53
	ldr    w0, [x0]
	mov   x4, x0
	
	// Agregar elemento al vector precios_Global
	adr   x0, precios_Global
	adr   x1, precios_Global_length
	ldr   w1, [x1]
	bl append_to_array_integer	
	// reasignacion de vector con add preciosAmpliados
	adrp x2, preciosAmpliados_Global
	add x2, x2, :lo12:preciosAmpliados_Global
	adr x3, preciosAmpliados_Global_length
	
	// Carga de entero 320
	adr    x0, int_54
	ldr    w0, [x0]
	mov   x4, x0
	
	// Agregar elemento al vector preciosAmpliados_Global
	adr   x0, preciosAmpliados_Global
	adr   x1, preciosAmpliados_Global_length
	ldr   w1, [x1]
	bl append_to_array_integer	
	// reasignacion de vector con add preciosAmpliados
	adrp x2, preciosAmpliados_Global
	add x2, x2, :lo12:preciosAmpliados_Global
	adr x3, preciosAmpliados_Global_length
	
	// Carga de entero 180
	adr    x0, int_55
	ldr    w0, [x0]
	mov   x4, x0
	
	// Agregar elemento al vector preciosAmpliados_Global
	adr   x0, preciosAmpliados_Global
	adr   x1, preciosAmpliados_Global_length
	ldr   w1, [x1]
	bl append_to_array_integer	
	// Declaración de vector con add cantidadesAmpliadas
	adrp x2, cantidadesAmpliadas_Global
	add x2, x2, :lo12:cantidadesAmpliadas_Global
	adr x3, cantidadesAmpliadas_Global_length
	
	// Carga de entero 25
	adr    x0, int_56
	ldr    w0, [x0]
	mov   x4, x0
	
	// Agregar elemento al vector cantidades_Global
	adr   x0, cantidades_Global
	adr   x1, cantidades_Global_length
	ldr   w1, [x1]
	bl append_to_array_integer	
	// reasignacion de vector con add cantidadesAmpliadas
	adrp x2, cantidadesAmpliadas_Global
	add x2, x2, :lo12:cantidadesAmpliadas_Global
	adr x3, cantidadesAmpliadas_Global_length
	
	// Carga de entero 40
	adr    x0, int_57
	ldr    w0, [x0]
	mov   x4, x0
	
	// Agregar elemento al vector cantidadesAmpliadas_Global
	adr   x0, cantidadesAmpliadas_Global
	adr   x1, cantidadesAmpliadas_Global_length
	ldr   w1, [x1]
	bl append_to_array_integer	
	// reasignacion de vector con add cantidadesAmpliadas
	adrp x2, cantidadesAmpliadas_Global
	add x2, x2, :lo12:cantidadesAmpliadas_Global
	adr x3, cantidadesAmpliadas_Global_length
	
	// Carga de entero 15
	adr    x0, int_58
	ldr    w0, [x0]
	mov   x4, x0
	
	// Agregar elemento al vector cantidadesAmpliadas_Global
	adr   x0, cantidadesAmpliadas_Global
	adr   x1, cantidadesAmpliadas_Global_length
	ldr   w1, [x1]
	bl append_to_array_integer	
	// Instrucción de impresión
	
	// Carga de string Después de agregar: 
	adr     x1, string_96
	str     x1, [sp, #-16]!
	
	// Obtener longitud del vector productosAmpliados_Global
	adr    x0, productosAmpliados_Global_length
	ldr    w0, [x0]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer32
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  productos
	adr     x2, string_97
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	
	// Instrucción de impresión
	
	// Carga de string Nuevos productos agregados:
	adr     x1, string_98
	adr x0, print
	bl printf
	
	
	// Declaración de variable i_For2
	
	// Obtener longitud del vector productos_Global
	adr    x0, productos_Global_length
	ldr    w0, [x0]
	ldr x1, =i_For2
	str x0, [x1]
	
	
	// Instrucción FOR 2
	for_2:
	
	// Carga de variable i_For2 de tipo INTEGER
	adr   x1, i_For2
	ldr    w1, [x1]
	
	// Obtener longitud del vector productosAmpliados_Global
	adr    x2, productosAmpliados_Global_length
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, lt
	mov w3, w0
	cbz w3, end_for_2
	
	// Instrucción de impresión
	
	// Carga de string - 
	adr     x1, string_99
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For2 de tipo INTEGER
	adr   x0, i_For2
	ldr    w0, [x0]
	
	// Carga de variable productosAmpliados_Global de tipo STRING
	adrp   x1, productosAmpliados_Global
	add    x1, x1, :lo12:productosAmpliados_Global
	ldr    x2, [x1, x0, lsl #3]
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  | Precio: Q
	adr     x2, string_100
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For2 de tipo INTEGER
	adr   x0, i_For2
	ldr    w0, [x0]
	
	// Carga de variable preciosAmpliados_Global de tipo INTEGER
	adrp   x1, preciosAmpliados_Global
	add    x1, x1, :lo12:preciosAmpliados_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer33
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de string  | Cantidad: 
	adr     x2, string_101
	ldr     x1, [sp], #16
	bl string_concat
	mov     x1, x0
	str     x1, [sp, #-16]!
	
	// Carga de variable i_For2 de tipo INTEGER
	adr   x0, i_For2
	ldr    w0, [x0]
	
	// Carga de variable cantidadesAmpliadas_Global de tipo INTEGER
	adrp   x1, cantidadesAmpliadas_Global
	add    x1, x1, :lo12:cantidadesAmpliadas_Global
	ldr    w0, [x1, x0, lsl #2]
	
	// Conversion de INTEGER a STRING
	adr     x1, buffer34
	bl itao
	mov    x2, x1
	ldr     x1, [sp], #16
	bl string_concat
	mov x1, x0
	adr x0, print
	bl printf
	
	update_for_2:
	
	// Carga de variable i_For2 de tipo INTEGER
	adr   x1, i_For2
	ldr    w1, [x1]
	
	// Carga de entero 1
	adr    x2, int_59
	ldr    w2, [x2]
	add    w0, w1, w2
	mov    w3, w0
	
	// Asignación de variable i_For2
	mov    w0, w3
	ldr x1, =i_For2
	str w0, [x1]
	
	
	// Carga de variable i_For2 de tipo INTEGER
	adr   x1, i_For2
	ldr    w1, [x1]
	
	// Obtener longitud del vector productosAmpliados_Global
	adr    x2, productosAmpliados_Global_length
	ldr    w2, [x2]
	cmp w1, w2
	cset w0, lt
	mov w4, w0
	b for_2
	end_for_2:
	
	// Instrucción de impresión
	
	// Carga de string \n--- ALGORITMOS DE ORDENAMIENTO ---
	adr     x1, string_102
	adr x0, print
	bl printf
	


MOV W0, #0 
LDP X29, X30, [SP], #16 
mov x8, 93 
svc 0 

