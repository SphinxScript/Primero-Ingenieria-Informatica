// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol) : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  void Show(void) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

// metodo escritura
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  //std::cout << "prueba" << pow(2,3) << std::endl;
  for (int i{0}; i < get_size(); ++i) {
    result += at(i) * pow(x,i);
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  int no_cero1{0}, no_cero2{0};
  for (int i = get_size() - 1; i >= 0; --i) {
    if (fabs(at(i)) > eps) {
      no_cero1 = i;
      break;
    }
  }
  for (int i = pol.get_size() - 1; i >= 0; --i) {
    if (fabs(pol.at(i)) > eps) {
      no_cero2 = i;
      break;
    }
  }
  if (no_cero1 != no_cero2) return false;
  for (int i{0}; i <= no_cero1; ++i) {
    if (fabs(at(i) - pol.at(i)) > eps) {
      return false;
    }
  }
  return true;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}
// metodo escritura sobrecargado
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i{0}; i < get_nz(); ++i) {
    //std::cout << "valor: " << at(i).get_val() << " indice: " << at(i).get_inx() << std::endl;
    //std::cout << " " << at(i) << " " << std::endl;
    result += at(i).get_val() * pow(x,at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  if ((spol.get_nz())!=(get_nz())) return false;
  for (int i{0}; i < get_nz(); ++i) {
    if (fabs((at(i).get_val()) - (spol.at(i).get_val())) > EPS) {
      return false;
    }
  }
  return true;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  return IsEqual(SparsePolynomial(pol));
}

// modificacion:

void SparsePolynomial::Show(void) const {
  for (int i = 0; i < get_nz() - 1; ++i) {
    if (at(i).get_inx() + 1 == at(i + 1).get_inx()) {
      std::cout << at(i).get_val() << ", " << at(i + 1).get_val() << ", ";
    }
  }
  std::cout << std::endl;
}


#endif  // POLYNOMIAL_H_