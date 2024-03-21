/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief Main code. It calls the rest of the functions and then prints the sum
  *        of the components of the vector.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <vector>
#include <iostream>
#include <iomanip>
#include "reduce_sum.h"

void Usage(int argc) {
  if (argc < 2) {
    std::cout << "error, debe introducir al menos un número" << std::endl;
    exit(0);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc);
  std::vector<double> vector;
  for (int i = 1; i < argc; ++i) {
    vector.push_back(std::stod(argv[i]));
  }
  std::cout << std::fixed << std::setprecision(1) << reduce_sum(vector) << std::endl;
  return 0;
}
