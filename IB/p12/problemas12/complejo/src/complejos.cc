/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief This is the main file of the program Complejo. It allows you doing additions and subtractions of complex numbers.
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/


#include <iostream>
#include "complejo.h"

int main() {
  Complejo complejo1(4, 9), complejo2(7, -8);
  Complejo resultado = complejo1.sumar(complejo2);
  std::cout << "suma: " << std::endl;
  resultado.result();

  Complejo resta = complejo1.restar(complejo2);
  std::cout << "resta: " << std::endl;
  resta.result();
  return 0;
}