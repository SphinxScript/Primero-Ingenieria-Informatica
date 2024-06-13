/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief This file contains the declaration of the class "Fecha"
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   */


#ifndef FECHA_H
#define FECHA_H

class Fecha {
 public:
  Fecha (int, int, int); // constructor
  bool esBisiesto();
  bool esFechaValida();
 
 private:
  int dia;
  int mes;
  int anio;
};

#endif