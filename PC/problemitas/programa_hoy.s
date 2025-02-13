# nombre: David rodriguez pane
# fecha: 13/02/2025


.data
titulo:		.asciiz		"\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n"
cadena1:	.asciiz		"\nIntroduzca un numero entero positivo (negativo para finalizar el programa): "
cadena2:	.asciiz		"Introduzca un digito (0-9): "
cadena3:	.asciiz		"El numero de veces que aparece el digito en el numero es: "
cadena4:	.asciiz		"\nFin del programa.\n"


.text

#	TABLA DE REGISTROS
#	numero --- $s0
#	digito --- $s1
#	cuenta --- $s2
#	resto  --- $t1

main:
	#int main() {
	#  std::cout << "\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n";
	li	$v0,4
	la	$a0,titulo
	syscall

#  while (true) {
inicio_while:

	#    int numero;
	#    std::cout << "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): ";
	li	$v0,4
	la	$a0, cadena1
	syscall

	#    std::cin >> numero;
	li	$v0, 5
	syscall
	move	$s0,$v0

	#    if (numero < 0)
	#      break;
	bltz	$s0,fin_bucle

	#    int digito;
	#    do {
do_digito:

	#      std::cout << "Introduzca un digito (0-9): ";
	li	$v0,4
	la	$a0,cadena2
	syscall

	#      std::cin >> digito;
	li	$v0,5
	syscall
	move	$s1,$v0

	#    } while ((digito < 0) || (digito > 9));
	bltz	$s1,do_digito
	bgt	$s1,9,do_digito

	#    int cuenta = 0;
	#    do {
do_cuenta:

	#      int resto = numero % 10;
	li	$t0,10
	div 	$s0,$t0
	mfhi	$t1		#resto
	mflo	$s0

	#      numero /= 10;
	#      if ( resto == digito )
	bne	$t1,$s1,no_sumo

	#        cuenta++;
	addi	$t1,$t1,1
	
	#    } while ( numero != 0 );
	
no_sumo:
	bne	$s0,$zero,do_cuenta
	#    std::cout << "El numero de veces que aparece el digito en el numero es: "
	li	$v0,4
	la	$a0,cadena3
	syscall

	li	$v0,1
	move	$a0,$s2
	syscall
	#        << cuenta << '\n';
	li	$v0,11
	li	$a0,'\n'

	#  }
	j inicio_while

fin_bucle:
	#  std::cout << "\nFin del programa.\n";
	li	$v0,4
	la	$a0,cadena4
	syscall
#}
	li	$v0,10
	syscall
