// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);
  // implementacion propia:
  void suma(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

  // metodo serpiente
  void serpiente(const matrix_t<T>& A);

  // metodos practica
  double superior() const;
  double sin_diagonal() const;
  double triangular_inferior() const;
  double triangular_inferior_sin() const;
  bool product(const matrix_t<T>&, const matrix_t<T>&) const;

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize1(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize1(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}


// m filas
// n columnas
// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  for (int i{1}; i <= A.get_m(); ++i) {
    for (int j{1}; j <= B.get_n(); ++j) {
      at(i,j) = 0;
      for (int k{1}; k <= B.get_m(); ++k) {
      at(i,j) = at(i,j) + A(i,k) * B(k,j);
      }
    }
  }
}

// metodo propio: suma

template<class T>
void matrix_t<T>::suma(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert((A.get_m() == B.get_m()) && (A.get_n() == B.get_n()));
  resize(A.get_m(), B.get_m());
  for (int i{1}; i <= A.get_m(); ++i) {
    for (int j{1}; j <= A.get_n(); ++j) {
      at(i,j) = A(i,j) + B(i,j);
    }
  }
}

template<class T>
void matrix_t<T>::serpiente(const matrix_t<T>& A) {
  for (int i{1}; i <= A.get_m(); ++i) {
    if (i % 2 == 0) {
      for (int j = A.get_n(); j >= 1; --j) {
        std::cout << at(i,j) << " ";
      }
    }
    else {
      for (int j{1}; j <= A.get_n(); ++j) {
        std::cout << at(i,j) << " ";
      }
    }
  }
  std::cout << std::endl;
}



// ejercicios practica examen:
template <class T>
double matrix_t<T>::superior() const {
  double suma{0};
  for (int i{1}; i <= get_m(); ++i) {  // m filas
    for (int j{i}; j <= get_n(); ++j) {  // n columnas
      suma += at(i,j);
    }
  }
  return suma;
}


template <class T>
double matrix_t<T>::sin_diagonal() const {
  double suma{0};
  for (int i{1}; i <= get_m(); ++i) {  // m filas
    for (int j{i + 1}; j <= get_n(); ++j) {  // n columnas
      suma += at(i,j);
    }
  }
  return suma;
}

template <class T>
double matrix_t<T>::triangular_inferior() const {
  double suma{0};
  for (int i{get_m()}; i > 0; --i) {
    for (int j{i}; j > 0; --j) {
      suma += at(i,j);
    }
  }
  return suma;
}


template <class T>
double matrix_t<T>::triangular_inferior_sin() const {
  double suma{0};
  for (int i{get_m()}; i > 0; --i) {
    for (int j{i - 1}; j > 0; --j) {
      suma += at(i,j);
    }
  }
  return suma;
}

template <class T>
bool matrix_t<T>::product(const matrix_t<T>& A, const matrix_t<T>& B) const {
  if (A.get_n(); != B.get_m()) {
    std::cout << "No son multiplicables" << std::endl;
    return false;
  }
  resize(A.get_m(), B.get_n());
  for (int i{1}; i <= get_m(); ++i) {
    for (int j{1}; j <= get_n(); ++j) {
      T aux = 0;
      for (int k{1}; k <= A.get_n(); ++k) {
        aux += A.at(i,k) * B.at(k,j);
      }
      at(i,j) = aux;
    }
  }
  return true;
}