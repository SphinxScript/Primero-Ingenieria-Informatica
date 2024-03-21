/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief this file creates the vector with the parameters given by the main
  *        function.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "random_vector.h"
#include <cstdlib>
#include <vector>

std::vector<double> GenerateVector(const int size, const double lower, const double upper){
  std::vector<double> result;
  for (int i = 0; i < size; ++i) {
    double random_number = ((double)rand() / RAND_MAX) * (upper - lower) + lower;
    result.push_back(random_number);
  }
  return result;
}
