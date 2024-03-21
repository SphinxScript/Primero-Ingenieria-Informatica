#include <numeric>
#include "racional.h"

std::ostream& operator<<(std::ostream& os, const Racional& racional) {
  os << racional.numerad_ << "/" << racional.denomin_;
  return os;
}

std::istream& operator>>(std::istream& is, Racional& racional) {
  is >> racional.numerad_ >> racional.denomin_;
  return is;
}

Racional Racional::operator+(const Racional& racional) const {
  Racional suma;
  int mcm = std::lcm(denomin_, racional.denomin_);
  suma.numerad_ = (mcm / denomin_) * numerad_ + (mcm / racional.denomin_ * racional.numerad_);
  suma.denomin_ = mcm;
  return suma;
}

Racional Racional::operator-(const Racional& racional) const {
  Racional resta;
  int mcm = std::lcm(denomin_, racional.denomin_);
  resta.numerad_ = (mcm / denomin_) * numerad_ - (mcm / racional.denomin_ * racional.numerad_);
  resta.denomin_ = mcm;
  return resta;
}

Racional Racional::operator*(const Racional& racional) const {
  Racional multipl;
  multipl.numerad_ = numerad_ * racional.numerad_;
  multipl.denomin_ = denomin_ * racional.denomin_;
  return multipl;
}

Racional Racional::operator/(const Racional& racional) const {
  Racional divid;
  divid.numerad_ = numerad_ * racional.denomin_;
  divid.denomin_ = denomin_ * racional.numerad_;
  return divid;
}