#include "comparacion.h"
#include "racional.h"

Comparacion Racional::comparar(const Racional& racional) const {
  double valorActual = static_cast<double>(numerad_) / denomin_;
  double valorOtro = static_cast<double>(racional.numerad_) / racional.denomin_;

  if (valorActual < valorOtro) {
    return Comparacion::Menor;
  } else if (valorActual > valorOtro) {
    return Comparacion::Mayor;
  } else {
    return Comparacion::Igual;
  }
}