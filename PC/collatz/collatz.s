# Práctica 2. Principios de Computadoras
# Completar código y comentarios
#
#

##include <iostream>

#int main() {
#    long numero; // Usamos long en caso de que la secuencia sea grande.

#    while (true) {
#        std::cout << "Introduzca un número para comprobar la Conjetura de Collatz o 0 para salir: ";
#        std::cin >> numero;

#        if (numero == 0) break; // Salir del bucle si el usuario introduce 0.

#        while (numero > 1) {
#            std::cout << numero << " ";
#            if (numero % 2 == 0) {
#                numero = numero / 2;
#            } else {
#                numero = 3 * numero + 1;
#            }
#        }
#        std::cout << numero << std::endl; // Imprimir el valor final (1).
#    }

#    return 0;
#}

#asigno variables a registros:
# numero		$s0
# numero1		$s1
# numero2		$s2

.data
msg: .asciiz "Introduzca un número para comprobar la Conjetura de Collatz o 0 para salir: "
space: .asciiz " "
newline: .asciiz "\n"
final: .asciiz "fin"

.text

main:


#int main() {
#    long numero; // Usamos long en caso de que la secuencia sea grande.

#    while (true) {
while_true:

#        std::cout << "Introduzca un número para comprobar la Conjetura de Collatz o 0 para salir: ";
	li	$v0,4
	la	$a0,msg
	syscall

#        std::cin >> numero;
	li	$v0,5
	syscall
	move	$s0,$v0

#        if (numero == 0) break; // Salir del bucle si el usuario introduce 0.
	beqz	$s0,while_true_fin

#        while (numero > 1) {	// if(numero <= 1) salto a while_numero_fin
while_numero:

	li	$t0,1
	ble	$s0,$t0,while_numero_fin

#            std::cout << numero << " ";
	li	$v0,1
	move	$a0,$s0
	syscall

	li	$v0,4
	la	$a0,space
	syscall

#            if (numero % 2 == 0) {
# primero numero % 2
	li	$s2,2
	div	$s0,$s2
	mfhi	$t0

# numero % 2 == 0
	bnez	$t0,else

#                numero = numero / 2;
	div	$s0,$s2
	mflo	$s0
	j	while_numero

#            } else {
else:

#                numero = 3 * numero + 1;
	li	$t0,3
	mul	$s0,$s0,$t0
	addi	$s0,$s0,1

#            }
	j	while_numero
#        }
while_numero_fin:

#        std::cout << numero << std::endl; // Imprimir el valor final (1).
	li	$v0,1
	move	$a0,$s0
	syscall
	
	li	$v0,4
	la	$a0,newline
	syscall

#    }
	j	while_true
while_true_fin:
	li	$v0,4
	la	$a0,final
	syscall

#    return 0;
#}
	li	$v0,10
	syscall