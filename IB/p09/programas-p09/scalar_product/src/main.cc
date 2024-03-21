#include <iostream>
#include <vector>
#include "scalar_product.h"

void Usage(int argumentos) {
  if ((argumentos % 2) != 0 || argumentos == 0) {
    std::cerr << "número incorrecto de parámetros, este programa imprime la"
                 " multiplicación vectorial de dos vectores" << std::endl;
    exit(0);
  }
}

int main(int argc, char* argv[]) {
  // cantidad de argumentos sin contar el nombre del programa
  int CantidadArgumentos = argc - 1;
  Usage(CantidadArgumentos);
  // declaramos los 2 vectores que usaremos para el producto escalar
  std::vector<double> PrimerVector;
  std::vector<double> SegundoVector;
  // bucle para establecer los datos de los dos vectores
  for (int i = 1; i <  CantidadArgumentos / 2 + 1; ++i) {
    double numero1 = std::stod(argv[i]);
    double numero2 = std::stod(argv[i + CantidadArgumentos / 2]);
    PrimerVector.push_back(numero1);
    SegundoVector.push_back(numero2);
  }
  std::cout << producto_escalar(PrimerVector, SegundoVector) << std::endl;
  return 0;
}
