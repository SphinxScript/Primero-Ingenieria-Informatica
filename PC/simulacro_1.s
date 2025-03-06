# Nombre: David Rodríguez Pane
# Fecha: 06/03/2025

	.data
strTitulo:	.ascii	"\nEvaluacion polinomio f(x) = a x^3 + b x^2 + c x + d"
		.asciiz	" en un intervalo [r,s]\n"
strIntroA:	.asciiz	"\nIntroduzca coeficiente a: "
strIntroB:	.asciiz	"Introduzca coeficiente b: "
strIntroC:	.asciiz	"Introduzca coeficiente c: "
strIntroD:	.asciiz	"Introduzca coeficiente d: "

strIntroR:	.asciiz	"\nLímite inferior r: "
strIntroS:	.asciiz	"Límite superior s: "

strF:		.asciiz	"\nf("
strIgual:	.asciiz	") = "
strTermina:	.asciiz	"\n\nTermina el programa\n"


# Tabla de variables a registros
# a		$f20
# b		$f21
# c		$f22
# d		$f23
# f		$f24
# x(float)	$f25

# ENTEROS:
# r		$s0
# s		$s1
# x		$s2



.text
main:

# int main(void) {

#   float a,b,c,d;

#   std::cout << "\nEvaluacion polinomio f(x) = a x^3 + b x^2 + c x + d"
	li	$v0,4
	la	$a0,strTitulo
	syscall

#   std::cout << "\nIntroduzca coeficiente a: ";
	li	$v0,4
	la	$a0,strIntroA
	syscall

#   std::cin >> a;
	li	$v0,6
	syscall
	mov.s	$f20,$f0

#   std::cout << "Introduzca coeficiente b: ";
#   std::cin >> b;
	li	$v0,4
	la	$a0,strIntroB
	syscall
	li	$v0,6
	syscall
	mov.s	$f21,$f0

#   std::cout << "Introduzca coeficiente c: ";
#   std::cin >> c;
	li	$v0,4
	la	$a0,strIntroC
	syscall
	li	$v0,6
	syscall
	mov.s	$f22,$f0
#   std::cout << "Introduzca coeficiente d: ";
#   std::cin >> d;
	li	$v0,4
	la	$a0,strIntroD
	syscall
	li	$v0,6
	syscall

	mov.s	$f23,$f0

#   int r,s;
#   do {
do_while:

#     std::cout << "\nLímite inferior r: ";
#     std::cin >> r;
	li	$v0,4
	la	$a0,strIntroR
	syscall
	li	$v0,5
	syscall
	move	$s0,$v0

#     std::cout << "Límite superior s: ";
#     std::cin >> s;
	li	$v0,4
	la	$a0,strIntroS
	syscall
	li	$v0,5
	syscall
	move	$s1,$v0

#   } while (r > s);
	bgt	$s0,$s1,do_while

	move	$s2,$s0		# s0 = s2
for:
#   for (int x = r ; x <= s ; x++) {
	bgt	$s2,$s1,fin_for		# en caso de que x > s salta

#     // float f = x*x*x*a + x*x*b + x*c + d;

#     float f = d;
	mov.s	$f24,$f23

#     f += x*c;
	#movemos x a registros flotantes
	mtc1		$s2,$f25		# copia cruda f25 = s2
	cvt.s.w		$f25,$f25		# pasamos f25 a ieee754
	mul.s		$f4,$f25,$f22			# f4 = x * c
	add.s		$f24,$f24,$f4

#     f += x*x*b;
	mul.s	$f4,$f25,$f25		# f4 = x * x
	mul.s	$f4,$f4,$f21		# f4 = f4 * b
	add.s	$f24,$f24,$f4		# f24 = f24 + f4

#     f += x*x*x*a;
	mul.s	$f4,$f25,$f25		# f4 = x * x
	mul.s	$f4,$f4,$f25		# f4 = f4 * x
	mul.s	$f4,$f4,$f20		# f4 = f4 * a
	add.s	$f24,$f24,$f4		# f24 = f24 + f4

#     if (f >= 2.5) {
	li.s	$f5,2.5		# f4 = 2.5
	c.le.s	$f5,$f24	# $f5 <= $f25, luego saltaré si no se cumple
	bc1f	fin_if

#       std::cout << "\nf(" << x << ") = " << f;
	li	$v0,4
	la	$a0,strF
	syscall

	li	$v0,1
	move	$a0,$s2
	syscall

	li	$v0,4
	la	$a0,strIgual
	syscall

	li	$v0,2
	mov.s	$f12,$f24
	syscall

#     }
fin_if:
#   }

	addi	$s2,1
	j	for
fin_for:

#   std::cout << "\n\nTermina el programa\n";
# }
	li	$v0,4
	la	$a0,strTermina
	syscall

	li	$v0,10
	syscall
