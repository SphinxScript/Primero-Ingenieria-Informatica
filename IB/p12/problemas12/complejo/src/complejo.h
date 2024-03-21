/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief This file contains the definition of the class "Complejo", the attributes and the methods.
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/


#ifndef COMPLEJOS_H
#define COMPLEJOS_H

#include <iostream>

class Complejo {
 public:
  Complejo(double, double); // constructor
  Complejo sumar(const Complejo&);
  Complejo restar(const Complejo&);
  void result();

 private:
  double partereal;
  double parteimaginaria;
};

#endif