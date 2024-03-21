#include "complex_numbers.h"
#include <cmath>
namespace complex_numbers {
Complex::Complex(double real_, double imag_) : real_(real_), imag_(imag_) {}
double Complex::real() const { return real_; }
double Complex::imag() const { return imag_; }
double Complex::abs() const { return sqrt(real_ * real_ + imag_ * imag_); }
Complex Complex::operator+(Complex const &obj) const {
  return Complex(real_ + obj.real(), imag_ + obj.imag());
}
Complex Complex::operator-(Complex const &obj) const {
  return Complex(real_ - obj.real(), imag_ - obj.imag());
}
Complex Complex::operator*(Complex const &obj) const {
  return Complex(real_ * obj.real() - imag_ * obj.imag(),
                 imag_ * obj.real() + real_ * obj.imag());
}
Complex Complex::operator/(Complex const &obj) const {
  double denominator = obj.real() * obj.real() + obj.imag() * obj.imag();
  return Complex((real_ * obj.real() + imag_ * obj.imag()) / denominator,
                 (imag_ * obj.real() - real_ * obj.imag()) / denominator);
}
Complex Complex::conj() const { return Complex(real_, -imag_); }
Complex Complex::exp() const {
  double common_factor = std::exp(real_);
  return Complex(common_factor * cos(imag_), common_factor * sin(imag_));
}
}