/**
 * AUTOR: Ricardo David Rodríguez Pane
 * FECHA: 14/02/2024
 * EMAIL: alu0101643137@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA:
 * PRÁCTICA Nº: 1
*/

#include "rational_t.h"

//método constructor de la clase rational_t;
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}
// método getter de la clase rational_t para recibir el valor del numerador;
int rational_t::get_num() const
{
  return num_;
}
// método getter de la clase rational_t para recibir el valor del denominador;
int rational_t::get_den() const
{
  return den_;
}
// método setter para cambiar el valor del numerador;
void rational_t::set_num(const int n)
{
  num_ = n;
}
// método setter para cambiar el valor del denominador;
void rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}
// método value para obtener el valor del numero racional;
double rational_t::value() const
{ 
  return double(get_num()) / get_den();
}

// COMPARACIONES
// metodo para saber si son iguales, mediante un valor referencia de error;
bool rational_t::is_equal(const rational_t& r, const double precision) const
{
  return((fabs(value() - r.value()) < precision));
}
// método para saber si el valor primero es mas grande que el valor segundo mediante una precision;
bool rational_t::is_greater(const rational_t& r, const double precision) const
{
  return(value() - r.value() > precision);
}
// metodo para saber si el primer numero es menor que el segundo mediante una precision;
bool rational_t::is_less(const rational_t& r, const double precision) const
{
  return (value() - r.value() < precision);
}
// operaciones
// operación suma;
rational_t rational_t::add(const rational_t& r)
{
  int numerador{}, denominador{};
  denominador = den_ * r.den_;
  numerador = num_ * r.den_ + den_ * r.num_;
  return rational_t(numerador, denominador);
}
// operación resta;
rational_t rational_t::substract(const rational_t& r)
{
  int numerador{}, denominador{};
  denominador = den_ * r.den_;
  numerador = num_ * r.den_ - den_ * r.num_;
  return rational_t(numerador, denominador);
}
// operación multiplicación;
rational_t rational_t::multiply(const rational_t& r)
{
  int numerador{}, denominador{};
  numerador = num_ * r.num_;
  denominador = den_ * r.den_;
  return rational_t(numerador, denominador);
}
// operación división;
rational_t rational_t::divide(const rational_t& r)
{
  int numerador{}, denominador{};
  numerador = num_ * r.den_;
  denominador = den_ * r.num_;
  return rational_t(numerador, denominador);
}
// método para esbribir en pantalla un número racional;
void rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << " = " << value() << endl;
}
// método para leer por teclado y establecer un número racional;
void rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

// PRÁCTICA, MÉTODO RESTAR 1;
rational_t rational_t::substractone() {
  int numerador, denominador;
  numerador = num_ - den_;
  denominador = den_;
  return rational_t(numerador, denominador);
}