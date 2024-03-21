/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code contains the function that calculates the sum of the
  *        components of the vector.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "reduce_sum.h"
#include <vector>

double reduce_sum(const std::vector<double> &vector) {
  double result{0};
  for (int i = 0; i < vector.size(); ++i) {
    result += vector[i];
  }
  return result;
}
