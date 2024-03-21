#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include "racional.h"
#include "comparacion.h"

void usage(int argc) {
  if (argc != 3) {
    std::cerr << "ERROR: debe introducir 2 números racionales separados por un espacio, en lugar de una '/'" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char* argv[]) {
  usage(argc);
  int numerador1, denominador1, numerador2, denominador2;
  std::string primer_racional = argv[1];
  std::vector<char> num1;
  for (char c : primer_racional) {
    num1.push_back(c);
  }
  numerador1 = static_cast<int>(num1[0]) - 48;
  denominador1 = static_cast<int>(num1[2]) - 48; /// aqui ya consigo los elementos del primer número racional
  std::string segundo_racional = argv[2];
  std::vector<char> num2;
  for (char c : segundo_racional) {
    num2.push_back(c);
  }
  numerador2 = static_cast<int>(num2[0]) - 48;
  denominador2 = static_cast<int>(num2[2]) - 48; /// aqui ya consigo los elementos del segundo número racional
  Racional racional{numerador1, denominador1}, racional2{numerador2, denominador2};
  std::cout << "suma: " << racional + racional2 << std::endl;
  std::cout << "resta: " <<racional - racional2 << std::endl;
  std::cout << "multiplicación: " << racional * racional2 << std::endl;
  std::cout << "división: " << racional / racional2 << std::endl;
  Comparacion resultado = racional.comparar(racional2);
  switch (resultado) {
    case Comparacion::Menor:
      std::cout << racional << " es menor que: " << racional2 << std::endl;
      break;
    case Comparacion::Igual:
    std::cout << racional << " y " << racional2 << " son iguales" << std::endl;
      break;
    case Comparacion::Mayor:
      std::cout << racional << " es mayor que: " << racional2 << std::endl;
      break;
  }
  return 0;
}