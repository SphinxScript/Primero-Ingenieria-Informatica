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

	# $s1		-> direccion de la matriz con la que se trabaja

	.text

print_mat:

					# manejo de la pila:
	addi	$sp,$sp,-36
	sw	$s0,0($sp)
	sw	$s1,4($sp)
	sw	$s2,8($sp)
	sw	$s3,12($sp)
	sw	$s4,16($sp)
	sw	$s5,20($sp)
	sw	$s6,24($sp)
	sw	$s7,28($sp)
	sw	$ra,32($sp)

	move	$s0,$a0			# muevo a s0 la direccion de matriz

	lw	$s1,0($s0)		# $s1 guarda el nº de filas
	lw	$s2,4($s0)		# $s2 guarda el nº de columnas

	li	$v0,4
	la	$a0,str_matTiene
	syscall

	li	$v0,1
	move	$a0,$s1
	syscall				# imprimo n_filas

	li	$v0,11
	li	$a0,'x'
	syscall				# imprimo 'x'
	
	li	$v0,1
	move	$a0,$s2
	syscall				# imprimo n_col

	li	$v0,4
	la	$a0,endl
	syscall				# imprimo salto de linea
	
	beq	$s1,$zero,fin_print
	beq	$s2,$zero,fin_print	# si columnas o filas son 0, se acaba el bucle print_mat

	addiu	$s3,$s0,8		# en $s3 almaceno la direccion de inicio del primer dato de la matriz

	move	$s4,$zero		# cargo en s4 y s5 valores 0, para ir aumentando y asi usarlos de contador
	move	$s5,$zero		# para saber cuando acaba la columna, la fila y la matriz

print_bucle1:
	
	beq	$s4,$s2,print_bucle2	# comprobamos si n_col es igual al numero de columnas de la matriz, en tal caso saltamos al bucle 2 para seguir por la siguiente fila

	l.s	$f4,0($s3)		# almacenamos en $f4 el primer dato de la matriz
	addiu	$s3,$s3,4		# movemos al siguiente dato de la matriz
	li	$v0,2			# imprimimos por pantalla el dato de la matriz
	mov.s	$f12,$f4		# imprimimos por pantalla el dato de la matriz
	syscall

	li	$v0,11
	li	$a0,' '
	syscall				# imprimo un espacio para separar los numeros
	
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

	li	$v0,4
	la	$a0,endl		# imprime salto de linea
	syscall

	lw	$ra,32($sp)
	lw	$s7,28($sp)
	lw	$s6,24($sp)
	lw	$s5,20($sp)
	lw	$s4,16($sp)
	lw	$s3,12($sp)
	lw	$s2,8($sp)
	lw	$s1,4($sp)
	lw	$s0,0($sp)
	addi	$sp,$sp,32

print_mat_fin:

	jr	$ra			# volvemos a la funcion

change_elto:

	move	$t0,$a0			# muevo el indice de la fila al registro t0 (de a0 a t0)
	move	$t1,$a1			# muevo el nindice de la columna al registro t1 (de a1 a t1)

	# f20 almacena el nuevo valor a reemplazar

	addi	$t2,$s1,8		# almaceno en t2 la direccion de inicio de la matriz

	lw	$t4,4($s1)		# guardo en t4 el nº de columnas de la matriz
					# la matriz se encuentra indexada de 0 a n-1

	mul	$t3,$t4,$t0		# multiplicamos nº columnas * indice de fila y guardamos en t3
	add	$t3,$t3,$t1		# sumamos t3 y el indice de columna y almacenamos en t3
	mul	$t3,$t3,sizeF		# multiplicamos por 4, ya que cada elemento ocupa 4 bytes
	add	$t3,$t3,$t2		# se suma el desplazamiento obtenido a la direccion de inicio de la matriz

	s.s	$f20,0($t3)		# se reemplaza el elemento

change_elto_fin:

	jr	$ra			# se vuelve al punto donde se estaba

intercambia:

	lw	$t0,4($s1)		# almacenamos en t0 el nº de columnas
	lw	$t1,0($s1)		# almaceno en t1 el nº de filas

	move	$t3,$a0			# muevo a t3 el indice de fila del usuario
	move	$t4,$a1			# muevo a t4 el indice de columna del usuario

	addi	$t2,$s1,8		# almaceno en t2 la direccion de inicio de la matriz

	mul	$t5,$t3,$t0		# multiplico la fila dada del usuario por el nº de columnas de la matriz
	add	$t5,$t5,$t4		# sumo la multiplicacion anterior con el indice de columna dada por el usuario	(desplazamiento de e1)
	mul	$t5,$t5,sizeF		# multiplico por 4 para saber la posicion dentro de la matriz del elemento	(direccion relativa en la memoria de e1)
	add	$t5,$t5,$t2		# hallo la direccion en memoria de ese dato
	l.s	$f21,0($t5)		# muevo el dato al registro f21

	sub	$t6,$t1,$t3		# resto nº filas - indFila dada por el usuario (t4 = nº filas - infFila)
	addi	$t6,-1			# resto al nº anterior 1 unidad ($t4 = $t4 - 1)
	mul	$t6,$t6,$t0		# multiplico por el nº de columnas

	# uso t5 como variable para realizar operaciones intermedias:

	sub	$t7,$t0,$t4		# numCol - indC
	addi	$t7,-1			# numCol - indC - 1

	add	$t6,$t6,$t7		# (numFil - indF - 1) * numCol + (numCol - indC - 1)
	mul	$t6,$t6,sizeF		# se multiplica por 4 por los desplazamientos en la memoria
	add	$t6,$t6,$t2		# se halla la direccion de memoria del dato
	l.s	$f22,0($t6)		# se almacena en $f22

	# como se llama a otra funcion desde esta, se maneja el puntero de pila para el registro ra
	addi	$sp,$sp,-4
	sw	$ra,0($sp)

	move	$a0,$t5			# a0 = t3
	move	$a1,$t6			# a1 = t4
	
	jal	swap

	# se reajusta el registro sp y ra
	lw	$ra,0($sp)
	addi	$sp,$sp,4

intercambia_fin:

	jr	$ra

swap:

	move	$t0,$a0			# t0 = a0
	move	$t1,$a1			# t1 = a1

	l.s	$f4,0($t0)		# f4 = [0(t0)]
	l.s	$f5,0($t1)		# f5 = [0(t1)]

	mov.s	$f7,$f4
	mov.s	$f4,$f5			# f5 = f4
	mov.s	$f5,$f7			# f4 = f6
	

	s.s	$f4,0($t0)		# [0(t0)] = f5
	s.s	$f7,0($t1)		# [0(t1)] = f4

swap_fin:

	jr	$ra

find_min:
	lw	$t0,0($s1)		# cargo en t0 el nº de filas
	lw	$t1,4($s1)		# cargo en t1 el nº de columnas

	addi	$t2,$s1,8		# float* datos = mat-> elementos // cargo en $t2 la direccion de inicio de los elementos

	li	$t3,-1			# fmin = -1
	li	$t4,-1			# cmin = -1

	la	$a0,infinito
	l.s	$f5,0($a0)		# cargo en f5 el nº infinito

	beq	$t0,$zero,fin_primer_for
	beq	$t1,$zero,fin_primer_for	# si tiene 0 filas o columnas salta a no_fila o no_col

	move	$t5,$zero		# f = 0

	primer_for:
	
		move	$t6,$zero			# c = 0

		segundo_for:

			mul	$t7,$t5,$t1	# f * numCol	
			add	$t7,$t7,$t6	# f * numCol + c
			mul	$t7,$t7,sizeF	# se multiplica por 4 por el tamaño de los elementos
			add	$t7,$t7,$t2	# se suma a t7 la direccion del primer dato de la matriz
			l.s	$f4,0($t7)	# float valor = datos[f * numCol + c]

			c.lt.s	$f4,$f5
			bc1f	if_fin

			if:
			mov.s	$f5,$f4		# min = valor
			move	$t3,$t5		# fmin = f
			move	$t4,$t6		# cmin = c

			if_fin:

			addi	$t6,$t6,1			# ++c
			blt	$t6,$t1,segundo_for		# si t6 es mayor o igual al nº de columnas salta al final del segundo bucle

	fin_primer_for:
	addi	$t5,$t5,1			# aumenta 1 unidad
	blt	$t5,$t0,primer_for		# si t5 es mayor o igual al nº de filas acaba el bucle

min_return:


	mov.s	$f0,$f5				# valor minimo
	move	$a0,$t3				# fila minima
	move	$a1,$t4				# columna minima

find_min_fin:

	jr	$ra

main:
	
	li	$v0,4
	la	$a0,str_titulo
	syscall				# imprimimos el titulo

	la	$s1,mat1		# almaceno en a0 la direccion de la matriz 1

antes_inicio:

	move	$a0,$s1			# muevo a s1 la direccion de mat1
	jal	print_mat		# salto a print_mat

while_inicio:
	
	li	$v0,4
	la	$a0,str_menu
	syscall				# imprimimos el menu de opciones

	li	$v0,5
	syscall
	move	$s5,$v0			# leemos el entero introducido y lo movemos a $s5

	blt	$s5,$zero,error_opc
	beq	$s5,2,error_opc
	beq	$s5,5,error_opc
	beq	$s5,6,error_opc
	bgt	$s5,7,error_opc

	beq	$s5,$zero,while_fin	# si s5 es igual a 0 salta a fin del bucle

	beq	$s5,1,cambia_matr	# si s5 es igual a 1 salta a cambia_matr
	beq	$s5,3,menu_elto		# si s5 es igual a 3 salta a menu_elto
	beq	$s5,4,menu_elto		# si s5 es igual a 4 salta a menu_elto, alli se llama luego a la funcion swap
	beq	$s5,7,min_menu		# si s5 es igual a 7 salta a min_menu, alli se llamará a funcion find_min

error_opc:
	li	$v0,4
	la	$a0,str_errorOpc
	syscall
	j	antes_inicio
	
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

	beq	$s0,1,menu_mat1
	beq	$s0,2,menu_mat2
	beq	$s0,3,menu_mat3
	beq	$s0,4,menu_mat4
	beq	$s0,5,menu_mat5
	beq	$s0,6,menu_mat6

menu_mat1:
	la	$a0,mat1		# almaceno en a0 la direccion de mat1
	move	$s1,$a0			# muevo a s1 la direccion
	jal	print_mat		# salto a print_mat
	j	while_inicio		# salto al inicio del while

menu_mat2:
	la	$a0,mat2
	move	$s1,$a0
	jal	print_mat
	j	while_inicio

menu_mat3:
	la	$a0,mat3
	move	$s1,$a0
	jal	print_mat
	j	while_inicio
	
menu_mat4:
	la	$a0,mat4
	move	$s1,$a0
	jal	print_mat
	j	while_inicio

menu_mat5:
	la	$a0,mat5
	move	$s1,$a0
	jal	print_mat
	j	while_inicio

menu_mat6:
	la	$a0,mat6
	move	$s1,$a0
	jal	print_mat
	j	while_inicio

error_numero:

	li	$v0,4
	la	$a0,endl		# imprimimos un salto de linea
	syscall

	li	$v0,4
	la	$a0,str_numMatMal	# imprimimos error de opcion
	syscall

	j	antes_inicio		# volvemos a elegir matriz

menu_elto:

	li	$v0,4
	la	$a0,str_indFila		# imprimimos leer indice fila
	syscall

	li	$v0,5
	syscall
	move	$s0,$v0			# muevo a s0 el indice de la fila

	blt	$s0,$zero,error_fila	# si es menor que 0 salta a error_fila

	lw	$s3,0($s1)		# cargo en s3 el nº de filas
	bge	$s0,$s3,error_fila	# si el nº introducido es mayor que el nº de filas, salta a error_fila

	li	$v0,4
	la	$a0,str_indCol		# imprimimos leer indice columna
	syscall

	li	$v0,5
	syscall
	move	$s2,$v0			# cambio a s2 el indice de la columna

	blt	$s2,$zero,error_colum	# si es menor que 0 el indice de columna salta a error colum

	lw	$s4,4($s1)		# guardamos el valor del nº de columnas en s4
	bge	$s2,$s4,error_colum	# si es mayor que el número de columnas salta a error_colum

	# aqui se comprueba si el valor introducido en el menu es 4, y si es asi se llama a la funcion swap
	li	$t0,4
	beq	$t0,$s5,llama_swap

	li	$v0,4
	la	$a0,str_nuevoValor	# imprimimos leer nuevo valor
	syscall

	li	$v0,6
	syscall
	mov.s	$f20,$f0		#leemos nuevo valor y lo almacenamos en f20
	
	move	$a0,$s0			# muevo a a0 el inidice de la fila
	move	$a1,$s2			# muevo a a1 el indice de la columna

	jal	change_elto		# saltamos a change_elto
	j	antes_inicio
	

error_fila:

	li	$v0,4
	la	$a0,str_errorFil
	syscall

	j	antes_inicio

error_colum:

	li	$v0,4
	la	$a0,str_errorCol
	syscall

	j	antes_inicio

llama_swap:

	move	$a0,$s0			# muevo a a0 el indice de la fila
	move	$a1,$s2			# muevo a a1 el inidice de la columna
	jal	intercambia
	j	antes_inicio

min_menu:
	jal	find_min

	mov.s	$f20,$f0
	move	$s2,$a0
	move	$s3,$a1

	li	$v0,4
	la	$a0,str_valMin			# imprimo str_valMin
	syscall

	li	$v0,1
	move	$a0,$s2				# imprimo el indice de fila
	syscall

	li	$v0,11
	li	$a0,','				# imprimo una ','
	syscall

	li	$v0,1
	move	$a0,$s3				# imprimo el indice de columna
	syscall

	li	$v0,4
	la	$a0,str_conValor		# imprimo str_conValor
	syscall

	li	$v0,2
	mov.s	$f12,$f20			# imprimo el valor minimo
	syscall
	
	j	antes_inicio

while_fin:

	li	$v0,4
	la	$a0,str_termina
	syscall


	li	$v0,10
	syscall
