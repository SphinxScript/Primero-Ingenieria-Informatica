#// Solución PR3 curso 23-24
#// Manejo de matrices con funciones
#
#
#typedef struct {
#  int nFil;
nFil = 0	# El desplazamiento al campo dentro de la estructura
#  int nCol;
nCol = 4	# El desplazamiento al campo dentro de la estructura
#  float elementos[];
elementos = 8	# El desplazamiento al campo dentro de la estructura
#} structMat;
#

sizeF = 4	# Numero de bytes de un float
LF = 10		# Caracter salto de línea
	.data
#structMat mat1 {
#  6,
#  6,
#  {
#    11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
#    21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
#    31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
#    41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
#    51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
#    61.61, 62.62, 63.63, 64.64, 65.65, 66.66
#  }
#};
mat1:	.word	6
	.word	6
	.float	11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
	.float	21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
	.float	31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
	.float	41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
	.float	51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
	.float	61.61, 62.62, 63.63, 64.64, 65.65, 66.66

#structMat mat2 {
#  7,
#  10,
#  {
#    -36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
#    -86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
#     4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
#    67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
#    30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
#    84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
#    -41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181
#  }
#};
mat2:	.word	7
	.word	10
	.float	-36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
	.float	-86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
	.float	4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
	.float	67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
	.float	30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
	.float	84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
	.float	-41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181

# structMat mat3 {
#   1,
#   8,
#   {
#     -36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61
#   }
# };
mat3:	.word	1
	.word	8
	.float	-36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61

# structMat mat4 {
#   16,
#   1,
#   { -90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3 ,
#     -96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83 }
# };
mat4:	.word	16
	.word	1
	.float	-90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3
	.float	-96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83

# structMat mat5 {
#   1,
#   1,
#   { 78.98 }
# };
mat5:	.word	1
	.word	1
	.float	78.98

# structMat mat6 {
#   0,
#   0,
#   { 0 }
# };
mat6:	.word	0
	.word	0
	.float	0.0

#float infinito = INFINITY;
infinito:	.word	0x7F800000

# Cadenas de caracteres
str_titulo:	.asciiz	"\nComienza programa manejo matrices con funciones\n"
str_menu:	.ascii	"(0) Terminar el programa\n"
		.ascii	"(1) Cambiar la matriz de trabajo\n"
		.ascii	"(3) Cambiar el valor de un elemento\n"
		.ascii	"(4) Intercambiar un elemento con su opuesto\n"
		.ascii	"(7) Encontrar el minimo\n"
		.asciiz	"\nIntroduce opción elegida: "
str_errorOpc:	.asciiz	"Error: opcion incorrecta\n"
str_termina:	.asciiz	"\nTermina el programa\n"
str_elijeMat:	.asciiz	"\nElije la matriz de trabajo (1..6): "
str_numMatMal:	.asciiz	"Numero de matriz de trabajo incorrecto\n"
str_errorFil:	.asciiz	"Error: dimension incorrecta.  Numero de fila incorrecto\n"
str_errorCol:	.asciiz	"Error: dimension incorrecta.  Numero de columna incorrecto\n"
str_indFila:	.asciiz	"\nIndice de fila: "
str_indCol:	.asciiz	"Indice de columna: "
str_nuevoValor:	.asciiz	"Nuevo valor para el elemento: "
str_valMin:	.asciiz	"\nEl valor minimo esta en ("
str_conValor:	.asciiz	") con valor "

str_matTiene:	.asciiz	"\n\nLa matriz tiene dimension "

endl:		.asciiz "\n"


#variables a registros:


	.text

print_mat:

	move	$s0,$a0		# muevo a s0 la direccion de matriz

	lw	$s1,0($s0)	# $s1 guarda el nº de filas
	lw	$s2,4($s0)	# $s2 guarda el nº de columnas

	li	$v0,1
	move	$a0,$s1
	syscall			# imprimo n_filas

	li	$v0,11
	li	$a0,'x'
	syscall			# imprimo 'x'
	
	li	$v0,1
	move	$a0,$s2
	syscall			# imprimo n_col

	li	$v0,4
	la	$a0,endl
	syscall			# imprimo salto de linea
	
	beq	$s1,$zero,fin_print
	beq	$s2,$zero,fin_print	# si columnas o filas son 0, se acaba el bucle print_mat

	addiu	$s3,$s0,8		# en $s3 almaceno la direccion de inicio del primer dato de la matriz

	move	$s4,$zero		# cargo en s4 y s5 valores 0, para ir aumentando y asi usarlos de contador
	move	$s5,$zero		# para saber cuando acaba la columna, la fila y la matriz

print_bucle1:
	
	beq	$s4,$s2,print_bucle2	# comprobamos si n_col es igual al numero de columnas de la matriz, en tal caso saltamos al bucle 2 para seguir por la siguiente fila

	l.s	$f4,0($s3)	# almacenamos en $f4 el primer dato de la matriz
	addiu	$s3,$s3,4	# movemos al siguiente dato de la matriz
	li	$v0,2		# imprimimos por pantalla el dato de la matriz
	mov.s	$f12,$f4	# imprimimos por pantalla el dato de la matriz
	syscall

	li	$v0,11
	li	$a0,' '
	syscall			# imprimo un espacio para separar los numeros
	
	addiu	$s4,$s4,1		# sumo 1 al contador de columnas
	blt	$s4,$s2,print_bucle1	# si el contador es menor que el numero de columnas, sigue imprimiendo datos

	j	print_bucle2		# en otro caso salta a print_bucle2 para continuar con las siguientes filas

	
	
	j fin_print

print_bucle2:

	li	$v0,4			
	la	$a0,endl
	syscall				# se imprime un salto de linea
	
	move	$s4,$zero		# se recarga el contador de columnas a 0 (estamos en nueva fila)

	addiu	$s5,$s5,1		# se aumenta el contador de filas
	blt	$s5,$s1,print_bucle1	# si el contador de filas es menor que el total de filas de la matriz, se salta a bucle 1. en otro caso se finaliza la impresion de la misma
	
fin_print:

	jr	$ra			# volvemos a la funcion

main:
	
	li	$v0,4
	la	$a0,str_titulo
	syscall				# imprimimos el titulo

while_inicio:
	
	li	$v0,4
	la	$a0,str_menu
	syscall				# imprimimos el menu de opciones

	li	$v0,5
	syscall
	move	$s0,$v0			# leemos el entero introducido y lo movemos a $s0

	beq	$v0,$zero,while_fin	# si v0 es igual a 0 salta a fin del bucle

	beq	$s0,1,cambia_matr
	
cambia_matr:
	
	li	$v0,4
	la	$a0,str_elijeMat	# imprimimos eligemat
	syscall

	li	$v0,5
	syscall
	move	$t0,$v0			# leemos el entero

	blt	$t0,1,error_numero
	bgt	$t0,6,error_numero	# si es mayor que 6 o menor que 1 salta a erorr_numero

	move	$s0,$t0
	beq	$s0,1,menu_mat1		# movemos el dato de t0 a s0

menu_mat1:
	la	$a0,mat1	# almaceno en a0 la direccion de mat1
	jal	print_mat	# salto a print_mat
	j	while_inicio	# salto al inicio del while

menu_mat2:
	la	$a0,mat2
	jal	print_mat
	j	while_inicio

menu_mat3:
	la	$a0,mat3
	jal	print_mat
	j	while_inicio
	
menu_mat4:
	la	$a0,mat4
	jal	print_mat
	j	while_inicio

menu_mat5:
	la	$a0,mat5
	jal	print_mat
	j	while_inicio

menu_mat6:
	la	$a0,mat6
	jal	print_mat
	j	while_inicio

error_numero:

	li	$v0,4
	la	$a0,str_errorOpc
	syscall

while_fin:


	li	$v0,10
	syscall

