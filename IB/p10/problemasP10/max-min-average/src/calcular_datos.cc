/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code calculates the maximun and minimun value of a vector, and
  *        also the average.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <vector>
#include "calcular_datos.h"

void calcularDatos(const std::vector<double>& vector, double& maximo, double&
minimo, double& promedio) {
  /// Inicializar variables con el primer elemento del vector
  maximo = minimo = promedio = vector[0];
  /// Recorrer el vector desde el segundo elemento
  for (size_t i = 1; i < vector.size(); ++i) {
    /// Calcular máximo
    if (vector[i] > maximo) {
      maximo = vector[i];
    }
    /// Calcular mínimo
    if (vector[i] < minimo) {
      minimo = vector[i];
    }
    /// Acumular para calcular la media
    promedio += vector[i];
  }
  /// Calcular la media dividiendo por el número de elementos del vector
  promedio = promedio / vector.size();
}
