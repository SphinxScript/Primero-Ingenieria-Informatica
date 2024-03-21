/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief Main file. It calls the functions and then prints on screen the
  *        maximum value, minimum value, and average of the vector.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <iostream>
#include <vector>
#include "calcular_datos.h"

void Usage(int argc) {
  if (argc < 2) {
    std::cerr << "ERROR: debe introducir al menos un número" << std::endl;
    exit(0);
  }
}
int main(int argc, char* argv[]) {
  Usage(argc);
  std::vector<double> vector;
  for(int i = 1; i < argc; ++i) {
    vector.push_back(std::stod(argv[i]));
  }
  double maximo, minimo, media;
  calcularDatos(vector, maximo, minimo, media);
  std::cout << "máximo: " << maximo << std::endl;
  std::cout << "mínimo: " << minimo << std::endl;
  std::cout << "media: " << media << std::endl;
  return 0;
}
