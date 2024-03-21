#include <cmath>
#include "calcular_raiz.h"

double calcularRaiz(double number) {
  double epsilon = 0.0001;
  double root{1.0};
  double delta{1.0};
  while (std::abs((root * root) - number) > epsilon) {
    if (delta > 0) {
      while ((root * root) < number) {
        root = delta + root;
      }
    }
    else {
      while ((root * root) > number) {
        root = delta * root;
      }
    }
    delta = delta * -0.5;
  }
  return root;
}
