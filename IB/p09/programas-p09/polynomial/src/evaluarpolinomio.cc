#include <vector>
#include "evaluarpolinomio.h"

double evaluarPolinomio(const std::vector<double> &coeficientes, double valor) {
  double resultado = 0.0;
  double potencia = 1.0;

  for (int i = coeficientes.size() - 1; i >= 0; --i) {
    resultado = resultado + coeficientes[i] * potencia;
    potencia = potencia * valor;
  }

  return resultado;
}
