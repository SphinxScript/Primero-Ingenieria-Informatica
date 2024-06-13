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

using namespace std;

template<class T>
class vector_t
{
public:
  // constructor y destructor
  vector_t(const int = 0);
  ~vector_t();
  
  void resize1(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // métodos de escritura y lectura
  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


// contructor
template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}


// destructor
template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}



template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}



template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



template<class T>
void
vector_t<T>::resize1(const int n)
{
  destroy();
  sz_ = n;
  build();
}


// getter de valor
template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


// getter de tamaño
template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}


// setter de valor
template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



// devuelve la posicion
template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


//¿?
template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}


//¿?
template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


//¿?
template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}



// metodo de escritura
template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



// metodo de lectura
template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize1(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  assert (v.get_size() == w.get_size());
  T scalar_product{0};
  for (int i = 0; i < v.get_size(); ++i) {
    scalar_product = scalar_product + v[i] * w[i];
  }
  return scalar_product;
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  assert(v.get_size() == w.get_size());
  double scalar_product{0};
  for (int i = 0; i < v.get_size(); ++i) {
    scalar_product = scalar_product + v[i].value() * w[i].value();
  }
  return scalar_product;
}