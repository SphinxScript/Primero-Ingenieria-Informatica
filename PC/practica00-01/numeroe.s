//#include <iostream>
//#include <iomanip>

//int main(int argc, char *argv[]) {
//  double error = 0;
//  double e = 1; //1/0!
//  double fact = 1; //0!
//  double numterminos = 1;
//  double ultimo_termino = 1; ; //1/0!

//    std::cout << "\nPR1: Principio de computadores.\n";
//    do {
//        std::cout << "\nIntroduzca maximo error permitido: ";
//        std::cin >> error;
//        if (!(error >= 0.00001 && error < 1))
//            std::cout << "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n";
//        else break;
//    } while (true);

//    while (ultimo_termino >= error) {
//        fact *= numterminos;
//        ultimo_termino = 1/fact;
//        e += ultimo_termino;
//        numterminos++;
//    }
//    std::cout <<  "\nNumero e: ";
//    std::cout << std::fixed << std::setprecision(17) << e;
//    std::cout << "\nNumero de terminos: " << int(numterminos);
//    std::cout << "\nPR1: Fin del programa.\n";
//    return 0;
//}