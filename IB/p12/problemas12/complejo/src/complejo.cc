/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief This file contains the definition of the class "Complejo", the methods and the builder. The methods are for additions and subtractions.
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/


#include "complejo.h"

/// constructor
Complejo::Complejo(double _partereal, double _parteimaginaria) {
  partereal = _partereal;
  parteimaginaria = _parteimaginaria;
}

Complejo Complejo::sumar(const Complejo& otroComplejo) {
  Complejo resultado (0.0, 0.0);
  resultado.partereal = partereal + otroComplejo.partereal;
  resultado.parteimaginaria = parteimaginaria + otroComplejo.parteimaginaria;
  return resultado;
}

Complejo Complejo::restar(const Complejo& otroComplejo) {
  Complejo resultado(0.0, 0.0);
  resultado.partereal = partereal - otroComplejo.partereal;
  resultado.parteimaginaria = parteimaginaria - otroComplejo.parteimaginaria;
  return resultado;
}

void Complejo::result() {
  std::cout << "el resultado es: " << partereal;
  if (parteimaginaria < 0) {
    std::cout << parteimaginaria << "i";
  }
  if (parteimaginaria > 0) {
    std::cout << " + " << parteimaginaria << "i";
  }
  else {
    exit;
  }
  std::cout << std::endl;
}