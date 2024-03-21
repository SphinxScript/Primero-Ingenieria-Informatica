#include <iostream>
#include <vector>
#include "scalar_product.h"

int producto_escalar(const std::vector<double> &vector1, const std::vector<double> &vector2) {
  // bucle para calcular el producto escalar
  double escalar_product; // defino el dato producto escalar
  for (int i = 0; i < vector1.size(); ++i) {
    escalar_product += (vector1[i] * vector2[i]);
  }
  return escalar_product;
}
