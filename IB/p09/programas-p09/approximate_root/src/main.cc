#include <iostream>
#include "calcular_raiz.h"
void Usage(int argc) {
  if (argc < 2) {
    std::cerr << "ERROR: debe introducir al menos un numero real." << std::endl;
    exit (0);
  }
}
int main(int argc, char* argv[]) {
  Usage(argc);
  double number;
  number = std::stod(argv[argc - 1]);
  std::cout << calcularRaiz(number) << std::endl;
  return 0;
}
