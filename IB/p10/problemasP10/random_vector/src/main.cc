/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief main file of random vector program. The code calls two void functios
  *        to check the correct parameters and then calls the function
  *        GenerateVector to create the vector.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "random_vector.h"

void Usage(int argc) {
  if (argc != 4) {
    std::cout << "debe introducir los datos correctos" << std::endl;
    exit(0);
  }
}
void Usage2(double lower, double upper) {
  if (lower > upper) {
    std::cout << "el rango inferior no puede ser superior al rango superior" <<
    std::endl;
    exit(0);
  }
}

int main(int argc, char* argv []) {
  Usage(argc);
  int size = std::stoi(argv[1]);
  int lower = std::stod(argv[2]);
  int upper = std::stod(argv[3]);
  Usage2(lower, upper);
  std::vector<double> my_vector = GenerateVector(size, lower, upper);
  for (const auto& value: my_vector) {
    std::cout << "Component: " << value << std::endl;
  }
  return 0;
}
