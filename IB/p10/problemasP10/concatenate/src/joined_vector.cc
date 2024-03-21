/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief this program concatenates the two vectors that are given by commands.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "joined_vector.h"
#include <vector>

std::vector<double> joined_vector(const std::vector<double>& vector1, const 
std::vector<double>& vector2) {
  std::vector<double> result_vector = vector1;
  for (int i = 0; i < vector2.size(); ++i) {
    result_vector.push_back(vector2[i]);
  }
  return result_vector;
}
