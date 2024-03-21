#// Programa para evaluar polinomio tercer grado

# #include <iostream>
#int main(void) {
#  float a,b,c,d;
#  std::cout << "\nEvaluacion polinomio f(x) = a x^3  + b x^2 + c x + d  en un intervalo [r,s]\n";
#  std::cout << "\nIntroduzca los valores de a,b,c y d (separados por retorno de carro):\n";
#  std::cin >> a;
#  std::cin >> b;
#  std::cin >> c;
#  std::cin >> d;
#  int r,s;
#  do {
#    std::cout << "Introduzca [r,s] (r y s enteros, r <= s)  (separados por retorno de carro):\n";
#    std::cin >> r;
#    std::cin >> s;
#  } while (r > s);
#  for (int x = r ; x <= s ; x++) {
#    float f = a*x*x*x + b*x*x + c*x + d;
#    if (f >= 2.1) {
#      std::cout << "\nf(" << x << ") = " << f;
#    }
#  }
#  std::cout << "\n\nTermina el programa\n";
#}


# asignacion de variables a registros
# a		$f20
# b		$f21
# c		$f22
# d		$f23
# r		$s0
# s		$s1
# x		$s2
# 2.1		$f4
# f		$f24


.data
eval: .asciiz "\nEvaluacion polinomio f(x) = a x^3  + b x^2 + c x + d  en un intervalo [r,s]\n"
valores: .asciiz "\nIntroduzca los valores de a,b,c y d (separados por retorno de carro):\n"
introduzca: .asciiz "Introduzca [r,s] (r y s enteros, r <= s)  (separados por retorno de carro):\n"
fx1: .asciiz "\nf("
fx2: .asciiz ") = "
final: .asciiz "\n\nTermina el programa\n"

.text

main:

#int main(void) {
#  float a,b,c,d;
#  std::cout << "\nEvaluacion polinomio f(x) = a x^3  + b x^2 + c x + d  en un intervalo [r,s]\n";
	li	$v0,4
	la	$a0,eval
	syscall

#  std::cout << "\nIntroduzca los valores de a,b,c y d (separados por retorno de carro):\n";
	li	$v0,4
	la	$a0,valores
	syscall

#  std::cin >> a;
	li	$v0,6
	syscall
	mov.s	$f20,$f0

#  std::cin >> b;
	li	$v0,6
	syscall
	mov.s	$f21,$f0

#  std::cin >> c;
	li	$v0,6
	syscall
	mov.s	$f22,$f0

#  std::cin >> d;
	li	$v0,6
	syscall
	mov.s	$f23,$f0

#  int r,s;
#  do {
do_while:

#    std::cout << "Introduzca [r,s] (r y s enteros, r <= s)  (separados por retorno de carro):\n";
	li	$v0,4
	la	$a0,introduzca
	syscall

#    std::cin >> r;
	li	$v0,5
	syscall
	move	$s0,$v0

#    std::cin >> s;
	li	$v0,5
	syscall
	move	$s1,$v0

#  } while (r > s);	// si r <= s entonces finaliza el do_while.
	ble	$s0,$s1,do_while_fin
	j	do_while

do_while_fin:

#  for (int x = r ; x <= s ; x++) {
	move	$s2,$s0
for:
	bgt	$s2,$s1,for_fin       # si x > s se salta a for_fin.

#    float f = a*x*x*x + b*x*x + c*x + d;
	mtc1	$s2,$f5
	cvt.s.w	$f5,$f5

#  ax^3:
	mul.s	$f6,$f5,$f5
	mul.s	$f7,$f6,$f5
	mul.s	$f7,$f7,$f20

#  bx^2
	mul.s	$f6,$f6,$f21

#  cx
	mul.s	$f8,$f5,$f22

#  suma
	add.s	$f7,$f7,$f6
	add.s	$f7,$f7,$f8
	add.s	$f7,$f7,$f23

	mov.s	$f24,$f7

#    if (f >= 2.1) {		// si f < 2.1 salta fuera del if
	li.s	$f4,2.1
	c.lt.s	$f24,$f4
	bc1t	if_fin
	
#      std::cout << "\nf(" << x << ") = " << f;
	li	$v0,4
	la	$a0,fx1
	syscall

	li	$v0,1
	move	$a0,$s2
	syscall

	li	$v0,4
	la	$a0,fx2
	syscall

	li	$v0,2
	mov.s	$f12,$f24
	syscall

#    }
if_fin:
#  }
	addi	$s2,1
	j	for
for_fin:

#  std::cout << "\n\nTermina el programa\n";
	li	$v0,4
	la	$a0,final
	syscall
#}
	li	$v0,10
	syscall