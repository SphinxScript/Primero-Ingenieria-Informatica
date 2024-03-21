/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief This file contains the definition of the methods of the class Fecha. It checks if it is a leap year and a valid date.
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/


#include <iostream>
#include "fecha.h"

/// constructor
Fecha::Fecha(int _dia, int _mes, int _anio) : dia(_dia), mes(_mes), anio(_anio) {
  if (!esFechaValida()) {
    std::cerr << "ERROR: fecha NO válida. Se establecerá la fecha por defecto: 01/01/2000" << std::endl;
    dia = 1;
    mes = 1;
    anio = 2000;
    exit(1);
  }
}

bool Fecha::esFechaValida() {
  if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
    return false;
  }
  if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
    return false;
  }
  if (mes == 2) {
    if ((anio % 4 == 0 && anio % 100 !=0) || anio % 400 == 0) {
      if (dia > 29) {
        return false;
      }
    }
    else {
      if (dia > 28) {
        return false;
      }
    }
  }
  return true;
}

bool Fecha::esBisiesto() {
    if ((anio % 4) == 0) {
      if ((anio % 100) == 0) {
        return ((anio % 400) == 0);
      }
      else {
        return true;
      }
    }
    else {
      return false;
    }
}