# PR1. PRINCIPIO DE COMPUTADORES.
# Autor: Ricardo David Rodríguez Pane
# Fecha ultima modificacion: 24/02/2024

# Programa en c++:

#include <iostream>
#include <iomanip>

# int main(int argc, char *argv[]) {
#    double error = 0;
#    double e = 1; // 1/0!
#    double fact = 1; // 0!
#    double numterminos = 1;
#    double ultimo_termino = 1; ; // 1/0!

#    std::cout << "\nPR1: Principio de computadores.\n";
#    do {
#        std::cout << "\nIntroduzca maximo error permitido: ";
#        std::cin >> error;
#        if (error < 0.00001 || error > 1)
#            std::cout << "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n";
#        else break;
#    } while (true);

#    while (ultimo_termino >= error) {
#        fact *= numterminos;
#        ultimo_termino = 1/fact;
#        e += ultimo_termino;
#        numterminos++;
#    }
#    std::cout <<  "\nNumero e: ";
#    std::cout << std::fixed << std::setprecision(17) << e;
#    std::cout << "\nNumero de terminos: " << int(numterminos);
#    std::cout << "\nPR1: Fin del programa.\n";
#    return 0;
#}


# Asignación de variables a registros
# error			-> $f20
# e 			-> $f22
# fact 			-> $f24
# numterminos 		-> $f26
# ultimo_termino	-> $f28

# Cargo un valor 1.0 para realizar divisiones y sumas (sumar 1, dividir 1)
# num1			-> $f30


	.data

titulo:		.asciiz "\nPR1: Principio de computadores.\n"
pet:		.asciiz "\nIntroduzca maximo error permitido: "
caderr:		.asciiz "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n"
cade:		.asciiz "\nNumero e: "
cadnt:		.asciiz "\nNumero de terminos: "
cadfin:		.asciiz "\nPR1: Fin del programa.\n"

	.text

#int main(int argc, char *argv[]) {
main:

#    num1 = 1.0
	li.d	$f30,1.0

#    double error = 0;
	li.d	$f20,0.0

#    double e = 1; // 1/0!
	li.d	$f22,1.0

#    double fact = 1; // 0!
	li.d	$f24,1.0

#    double numterminos = 1;
	li.d	$f26,1.0

#    double ultimo_termino = 1; ; // 1/0!
	li.d	$f28,1.0

#    std::cout << "\nPR1: Principio de computadores.\n";
	li	$v0,4
	la	$a0,titulo
	syscall
	
#    do {
do_while:

#       std::cout << "\nIntroduzca maximo error permitido: ";
	li	$v0,4
	la	$a0,pet
	syscall

#        std::cin >> error;
	li	$v0,7
	syscall
	mov.d	$f20,$f0

#        if (error < 0.00001 || error > 1)
if_error:
#     Cargo los límites del error en registros de punto flotante tipo double
	li.d	$f0, 0.00001		# Cargo 0.00001 en $f0
	li.d	$f2, 1.0		# Cargo 1.0 en $f2

#     Comparo error < 0.00001
	c.lt.d $f20, $f0		# Comparo si $f20 es menor que 0.00001 (en $f0)
	bc1t error_lower		# Salto a error_lower si la comparación es verdadera

#     Comparo error >= 1.0
	c.le.d $f2, $f20		# Comparar si 1.0 (en $f2) es menor que $f20
	bc1t error_greater_equal	# Saltar a error_greater_equal si la comparación es verdadera

#     Si ninguna condición se cumple, salto al final del do_while. Salto a do_while_fin
	j do_while_fin

error_lower:
	li	$v0,4
	la	$a0,caderr
	syscall
	j do_while			# salta al inicio del bucle do_while

error_greater_equal:
	li 	$v0,4
	la 	$a0,caderr
	syscall
	j do_while			# salta al inicio del bucle do_while

#    } while (true);			# No lo traduzco a ninguna instrucción ensamblador

do_while_fin:


while:					# etiqueta del bucle while (no confundir con el bucle do_while)
#    while (ultimo_termino >= error) {
	c.le.d	$f20,$f28		# comparo si error < ultimo_termino
	bc1f	while_fin

#        fact *= numterminos;
	mul.d	$f24,$f24,$f26

#        ultimo_termino = 1/fact;
	div.d	$f28,$f30,$f24

#        e += ultimo_termino;
	add.d	$f22,$f22,$f28

#        numterminos++;
	add.d	$f26,$f30,$f26

# Salto al inicio del bucle while
	j while

#    }

while_fin:				# no lo traduzco por ninguna instruccion en ensablador

#    std::cout <<  "\nNumero e: ";
	li	$v0,4
	la	$a0,cade
	syscall

#    std::cout << std::fixed << std::setprecision(17) << e;
	mov.d	$f12,$f22
	li	$v0,3
	syscall

#    std::cout << "\nNumero de terminos: " << int(numterminos);
	li	$v0,4
	la	$a0,cadnt
	syscall
	
	mov.d	$f12,$f26
	li	$v0,3
	syscall

#    std::cout << "\nPR1: Fin del programa.\n";
	li	$v0,4
	la	$a0,cadfin
	syscall

#    return 0;
#}
	li	$v0,10
	syscall