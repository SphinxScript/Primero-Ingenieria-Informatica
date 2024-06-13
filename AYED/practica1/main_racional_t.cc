/**
 * AUTOR: Ricardo David Rodríguez Pane
 * FECHA: 14/02/2024
 * EMAIL: alu0101643137@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA:
 * PRÁCTICA Nº: 1
*/

#include <iostream>
#include <cmath>
#include "rational_t.h"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  cout << "x: ";
  x.write();
  cout << "y: ";
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  cout << "a + b: ";
  a.add(b).write();
  
  cout << "b - a: ";
  b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();
  
  cout << "a / b: ";
  a.divide(b).write();
  // PRACTICA
  cout << "ingrese un número racional, luego se imprimirá en pantalla dicho número - 1 (a/b - 1)" << endl;
  rational_t h{0};
  h.read();
  cout << "el número que ingresó - 1 es ";
  h.substractone().write();
  return 0;
}