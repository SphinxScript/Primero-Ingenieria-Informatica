##include <iostream>
#using namespace std;
.data
elige_opcion:	.asciiz		"Elige una opcion (1, 2 o 3):"
opcion_1:	.asciiz		"Opcion 1\n"
opcion_2:	.asciiz		"opcion 2\n"
opcion_3:	.asciiz		"opcion 3\n"
no_valido:	.asciiz		"opcion no valida\n"

.text
#int main() {
main:

#    int opcion;

#    cout << "Elige una opcion (1, 2 o 3): ";
	li	$v0, 4
	la	$a0, elige_opcion
	syscall

#    cin >> opcion;
	li	$v0, 5
	syscall
	move	$s0, $v0	# ponemos en s0 el valor leido

#    switch(opcion) {
switch:
	beq	$s0,1,case_1
	beq	$s0,2,case_2
	beq	$s0,3,case_3
	j default
#        case 1:
case_1:
#            cout << "Seleccionaste la opcion 1" << endl;
	li	$v0,4
	la	$a0,opcion_1
	syscall
#            break;
	j fin_switch
#        case 2:
case_2:
#            cout << "Seleccionaste la opcion 2" << endl;
	li	$v0,4
	la	$a0,opcion_2
	syscall
	j fin_switch
#            break;
#        case 3:
case_3:
#            cout << "Seleccionaste la opcion 3" << endl;
	li	$v0,4
	la	$a0,opcion_3
	syscall
	j fin_switch
#            break;
#        default:
default:
	li	$v0,4
	la	$a0,no_valido
	syscall
#            cout << "Opcion no valida" << endl;
#            break;
#    }
fin_switch:
#    
#    return 0;
	li	$v0, 10
	syscall
#}

