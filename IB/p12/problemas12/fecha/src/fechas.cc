/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief Main file of the program fecha, it calls the other functions and methods.
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/


#include <iostream>
#include "fecha.h"

int main() {
  std::cout << "ESTE PROGRAMA PERMITE CREAR FECHAS. DEBE INTRODUCIR LAS FECHAS SEGUIDAS DE UN ESPACIO" << std::endl;
  int dia, mes, anio;
  std::cin >> dia >> mes >> anio;
  Fecha fecha1(dia, mes, anio);
  if (fecha1.esBisiesto()) {
    std::cout << "Es un año bisiesto" << std::endl;
  }
  else {
    std::cout << "No es un año bisiesto" << std::endl;
  }
  return 0;
}