/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F de Sande
 * @date Dec 16 2022
 * @brief Client program to work with the vector3D class
 */

#include <iostream>

#include "vector3D.h"

int main() {
  Vector3D vector1{};
  std::cout << "First vector: " << vector1;
  Vector3D vector2{1.0, 2, 3};
  std::cout << "Second vector: " << vector2;
  const double kEscalarFactor = 3.5;
  multiplied_vector = vector1.MultiplyVector(kEscalarFactor);  // Multiplica el vector por el escalar
  // 4.2 // std::cout << "Multiplied Vector: " << multiplied_vector;
  // double vector_module{vector1.Module()};
  // 4.3 // std::cout << "Module of the first vector: " << vector_module << std::endl;
  // Vector3D sum_vector;
  // sum_vector = vector1 + vector2;     
  // 4.4 // std::cout << "Sum of the two vectors: " << sum_vector;
  // double scalar_product = vector1 * vector2;     
  // 4.5 // std::cout << "Scalar product of both vectors: " << scalar_product << std::endl;
  return 0;
}

