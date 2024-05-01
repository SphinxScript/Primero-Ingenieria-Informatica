# Principio de Computadores. Preparación para el Microexamen
# Operaciones con funciones y direccionamiento indirecto
# Autor: 
# Fecha última modificación: 
#include <iostream>

# const int n1 = 10;
# double v1[n1] = {10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0};
# const int n2 = 5;
# double v2[n2] = {5.5, 4.5, 4.25, 2.5, 2.5 };
# const int n3 = 4;
# double v3[n3] = {7.0, 5.0, 2.0, 1.0};

sizeD = 8
LF = 10
SPACE = 32

    .data
n1:     .word 10
v1:     .double 10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0
n2:     .word 5
v2:     .double 5.5, 4.5, 4.25, 2.5, 2.5
n3:     .word 4
v3:     .double 7.0, 5.0, 2.0, 1.0
cad1:   .asciiz "\nVector con dimension "
cad2:   .asciiz "\nIntentando mezcla con dos vectores ...\n"
cad3:   .asciiz "\nFIN DEL PROGRAMA\n"
endl:	.asciiz	"\n"

    .text

printvec:

	move	$s0,$a0		# guardo en s0 la direccion del primer elemento del vector
	move	$s1,$a1		# guardo en s1 la direccion del nº de elementos del vector
	lw	$s1,0($s1)	# guardo en s1 el nº de elementos del vector
	move	$s2,$zero	# i = 0;

for_inicio:

	mul	$s3,$s2,sizeD	# i * sizeD
	add	$s3,$s3,$s0	# sumo a la direccion de inicio del vector
	l.d	$f20,0($s3)	# cargo en f20 el numero
	li	$v0,3
	mov.d	$f12,$f20	# imprimo f20
	syscall

	li	$v0,11
	li	$a0,' '
	syscall
	
for_fin:

	addi	$s2,$s2,1	#++i
	blt	$s2,$s1,for_inicio
	
printvec_fin:

	li	$v0,4
	la	$a0,endl
	syscall

	jr	$ra


ordenado_inicio:

ordenado_fin:

# void printvec(double *v, const int n) {
#     for (int i = 0; i < n; i++)
#         std::cout << v[i] << " ";
    
#     std::cout << "\n";
#     return;
# }


# int ordenado(double *v, const int n) {

ordenado:

	addi	$sp,$sp,-20
	sw	$s0,0($sp)
	sw	$s1,4($sp)
	sw	$s2,8($sp)
	sw	$s3,12($sp)
	sw	$ra,16($sp)

	move	$s0,$a0		# double *v lo guardo en s0
	move	$s1,$a1		# guardo en s1 el entero n

	lw	$s1,0($s1)

#     int resultado = 1;

	li	$s2,1		# resultado = 1

#     int i = 0;

	li	$s3,0		# i = 0

#     while (i < n-1) {

while_inicio:

	addi	$t0,$s1,-1
	bge	$s3,$t0,while_fin

#         if (v[i+1] >= v[i]) {

	addi	$t1,$s3,1
	mul	$t1,$t1,sizeD
	add	$t1,$t1,$s0
	l.d	$f4,0($t1)

	mul	$t1,$s3,sizeD
	add	$t1,$t1,$s0
	l.d	$f6,0($t1)

	c.lt.d	$f4,$f6
	bc1t	if_fin
	
if_inicio:

#             resultado = 0;

	li	$s2,0

#             break;

	j	while_fin

#         }

if_fin:

#         i++;

	addi	$s3,$s3,1
	j	while_inicio

#     }

while_fin:
#     return(resultado);

	move	$a0,$s2

	lw	$s0,0($sp)
	lw	$s1,4($sp)
	lw	$s2,8($sp)
	lw	$s3,12($sp)
	lw	$ra,16($sp)

	addi	$sp,$sp,20

	jal	$ra
# }

# void merge(double *v1, const int n1,double *v2, const int n2) {

merge:

	move	$s0,$a0		# direccion de v1
	move	$s1,$a1		# direccion de n1
	move	$s2,$a2		# direccion de v2
	move	$s3,$a3		# direccion de n2

#     int  o1 = ordenado(v1,n1);
	move	$a0,$s0
	move	$a1,$s1
	jal	ordenado
	move	$t0,$a0
	
#     if (o1 == 0) return;

	move	$t1,$zero
	beq	$t0,$t1,merge_fin

#     int o2 = ordenado(v2,n2);

	move	$a0,$s2
	move	$a1,$s3
	jal	ordenado
	move	$t0,$a0

#     if (o2 == 0) return;

	move	$t1,$zero
	beq	$t0,$t1,merge_fin

#     int i = 0; // índice para recorrer el v1

	move	$s4,$zero		# índice para recorrer el v1		i = 0

#     int j = 0; // índice para recorrer el v2

	move	$s5,$zero		# indice para recorrer v2		# j = 0

merge_while1:
#     while ( ( i < n1) && (j < n2) ) {

	lw	$t0,0($s1)
	bge	$s4,$t0,merge_while1_fin

	lw	$t0,0($s3)
	bge	$s5,$t0,merge_while1_fin

#         if (v1[i] >= v2[j]) {
#             std::cout << v1[i] << " ";
#             i++;
#         }
#         else {
#             std::cout << v2[j] << " ";
#             j++;
#         }
#     }
merge_while1_fin:

#     while ( i < n1) {
#         std::cout << v1[i] << " ";
#         i++;
#     }
#     while ( j < n2) {
#         std::cout << v2[j] << " ";
#         j++;
#     }
#     std::cout << "\n";
#     return;
# }

merge_fin:
	jr	$ra



main:

# int main(void) {
	#     std::cout << "\nVector con dimension " << n1 << std::endl;

	li	$v0,4
	la	$a0,cad1
	syscall
	
	la	$a0,n1
	lw	$t0,0($a0)
	
	li	$v0,1
	move	$a0,$t0
	syscall

	li	$v0,4
	la	$a0,endl
	syscall

#     printvec(v1,n1);
	
	la	$a0,v1
	la	$a1,n1
	jal	printvec
	
#     std::cout << "\nVector con dimension " << n2 << std::endl;
	li	$v0,4
	la	$a0,cad1
	syscall

	la	$a0,n2
	lw	$t0,0($a0)

	li	$v0,1
	move	$a0,$t0
	syscall

	li	$v0,4
	la	$a0,endl
	syscall

#     printvec(v2,n2);

	la	$a0,v2
	la	$a1,n2
	jal	printvec

  
#     std::cout << "\nVector con dimension " << n3 << std::endl;

	li	$v0,4
	la	$a0,cad1
	syscall

	la	$a0,n3
	lw	$t0,0($a0)

	li	$v0,1
	move	$a0,$t0
	syscall

	li	$v0,4
	la	$a0,endl
	syscall

#     printvec(v3,n3);

	la	$a0,v3
	la	$a1,n3
	jal	printvec
  
#     std::cout << "\nIntentando mezcla con dos vectores ...\n";

	li	$v0,4
	la	$a0,cad2
	syscall

#     merge(v1,n1,v2,n2);

	la	$a0,v1
	la	$a1,n1
	la	$a2,v2
	la	$a3,n2
	jal	merge
#     std::cout << "\nIntentando mezcla con dos vectores ...\n";
#     merge(v1,n1,v3,n3);

#     std::cout << "\nFIN DEL PROGRAMA\n";
#     return(0);
# }

	li	$v0,10
	syscall

