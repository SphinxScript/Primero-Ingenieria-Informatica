#ifndef RACIONAL_H
#define RACIONAL_H

#include "comparacion.h"
#include <iostream>

class Racional {
 public:
  Racional() = default;
  Racional(const int numerador, const int denominador) : numerad_{numerador}, denomin_{denominador} {} /// constructor
  friend std::ostream& operator<<(std::ostream& os, const Racional& racional);
  friend std::istream& operator>>(std::istream& is, Racional& racional);
  Racional operator+(const Racional& racional) const;
  Racional operator-(const Racional& racional) const;
  Racional operator*(const Racional& racional) const;
  Racional operator/(const Racional& racional) const;
  Comparacion comparar(const Racional& racional) const;
 private:
  int numerad_;
  int denomin_;
};

#endif