#include <iostream>
#include "hypotenuse.h"

void Usage(int argc) {
  if (argc < 3 || argc > 3) {
    std::cerr << "ERROR: introduzca dos lados de un triangulo" << std::endl;
    exit (0);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc);
  double cateto1, cateto2;
  cateto1 = std::stod(argv[1]);
  cateto2 = std::stod(argv[2]);
  std::cout << calcularHipotenusa(cateto1, cateto2) << std::endl;
  return 0;
}
