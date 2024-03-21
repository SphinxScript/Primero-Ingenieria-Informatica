#include <iostream>
#using namespace std;

#int main() {
#  cout << "Programa que indica si un número es primo o no.\n"
#       << "Si no es primo, imprime el primer divisor del mismo.\n"
#       << "Si el número introducido es 0, el programa se detiene.\n";
#  int n;
#  do {
#    cin >> n;
#    for (int i{2}; i < n; ++i) {
#      if (n % i == 0) {
#        cout << "Divisor encontrado: " << i << '\n';
#        break;
#      }
#      if (i == n-1) {
#        cout << "Es un número primo.\n";
#      }
#    }
#  } while (n != 0);
#  cout << "Fin del programa.\n";
#  return 0;
#}

# Asignación de variables a registros
# n		$s0
# i		$s1 

.data
inicio:	.asciiz "Programa que indica si un número es primo o no.
Si no es primo, imprime el primer divisor del mismo.
Si el número introducido es 0, el programa se detiene.\n"

divisor: .asciiz "Divisor encontrado: "
primo: .asciiz "Es un número primo.\n"
final:	.asciiz "fin del programa"
newline: .asciiz "\n"

.text

main:

#int main() {
#  cout << "Programa que indica si un número es primo o no.\n"
#       << "Si no es primo, imprime el primer divisor del mismo.\n"
#       << "Si el número introducido es 0, el programa se detiene.\n";
	li	$v0,4
	la	$a0,inicio
	syscall

#  int n;
#  do {
do_while:

#    cin >> n;
	li	$v0,5
	syscall
	move	$s0,$v0

#    for (int i{2}; i < n; ++i) {	// si i >= n ==> salta a fin bucle for

	li	$s1,2
for:
	bge	$s1,$s0,for_fin

#      if (n % i == 0) {
if_cero:
	div	$s0,$s1
	mfhi	$t0
	bnez	$t0,if_cerofin

#        cout << "Divisor encontrado: " << i << '\n';
	li	$v0,4
	la	$a0,divisor
	syscall

	li	$v0,1
	move	$a0,$s1
	syscall

	li	$v0,4
	la	$a0,newline
	syscall

#        break;
	j	for_fin
#      }
if_cerofin:

#      if (i == n-1) {
if_n:
	li	$t0,1
	sub	$t1,$s0,$t0
	bne	$t1,$s1,if_nfin

#        cout << "Es un número primo.\n";
	li	$v0,4
	la	$a0,primo
	syscall

#      }
if_nfin:

#    }
	addi	$s1,1
	j	for
for_fin:

#  } while (n != 0);
	beqz	$s0,do_while_fin
	j	do_while

do_while_fin:
#  cout << "Fin del programa.\n";
	li	$v0,4
	la	$a0,final
	syscall

#  return 0;
#}
	li	$v0,10
	syscall