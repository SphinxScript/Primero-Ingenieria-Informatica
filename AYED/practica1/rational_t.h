/**
 * AUTOR: Ricardo David Rodríguez Pane
 * FECHA: 14/02/2024
 * EMAIL: alu0101643137@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA:
 * PRÁCTICA Nº: 1
*/

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

#define EPSILON 1e-6

using namespace std;

class rational_t
{
 public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  // getters
  int get_num() const;
  int get_den() const;  
  // setters
  void set_num(const int);
  void set_den(const int);
  // método para obtener el valor aproximado (o exacto) del número racional;
  double value(void) const;

  // FASE II
  // métodos para comprobar y realizar comparaciones;
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  // métodos de operaciones aritméticas;
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);

  // PRÁCTICA
  //método que resta 1 unidad al racional. sigue la forma a/b - 1 = (a-b)/b 
  rational_t substractone();
  // método para escribir en pantalla (write) y leer desde teclado (read);
  void write(ostream& = cout) const;
  void read(istream& = cin);
  
 private:
  // atributos de la clase (numerador y denominador);
  int num_;
  int den_;
};