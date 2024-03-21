#include <iostream>
#include <vector>
#include "evaluarpolinomio.h"

void Usage(int argc) {
  if (argc <= 1) {
    std::cout << "ERROR: debe ingresar al menos un número" << std::endl;
    exit (0);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc);
  std::vector<double> coeficientes;

  for (int i = 1; i < argc - 1; ++i) {
    double coeficiente = std::stod(argv[i]);
    coeficientes.push_back(coeficiente);
  }
  // Último argumento es el valor a evaluar
  double valorEvaluar = std::stod(argv[argc - 1]);

  double resultado = evaluarPolinomio(coeficientes, valorEvaluar);

  std::cout << resultado << std::endl;

  return 0;
}
