/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code calls the function joined_vector and then prints on screen
  *        the concatenated vector. The first number given by commands, is the
  *        size of the first vector, and the rest numbers are the numbers of
  *        vector2.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <iostream>
#include <vector>
#include "joined_vector.h"

void Usage(int argc) {
  if (argc < 3) {
    std::cerr << "ERROR: debe introducir al menos 2 números" << std::endl;
    exit(0);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc);
  std::vector<double> vector_total;
  for(int i = 1; i < argc; ++i) {
    vector_total.push_back(std::stod(argv[i]));
  }
  std::vector<double> vector1;
  std::vector<double> vector2;
  for (int i = 1; i < vector_total[0] + 1; ++i) {
    vector1.push_back(vector_total[i]);
  }
  for (int i = vector_total[0] + 1; i < vector_total.size(); ++i) {
    vector2.push_back(vector_total[i]);
  }

  std::vector<double> result_vector = joined_vector(vector1, vector2);
  for (int i = 0; i < result_vector.size(); ++i) {
    std::cout << result_vector[i] << " ";
  }
  std::cout << std::endl; 
/* //esta parte puede ser de utilidad para comprobar que el primer número indica
 //el tamaño del vector1, y el vector2 es el resto de los números.

  for (int i = 0; i < vector1.size(); ++i) {
    std::cout << vector1[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < vector2.size(); ++i) {
    std::cout << vector2[i] << " ";
  }
  std::cout << std::endl;
*/
}
