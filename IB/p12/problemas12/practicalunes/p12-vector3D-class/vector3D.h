/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F de Sande
 * @date Dec 16 2022
 * @brief Vector3D class Definition
 */

#ifndef VECTOR3D_H
#define VECTOR3D_H

/** @brief Class Vector3D */
class Vector3D {
 public:
  Vector3D() : x{0.0}, y{0.0}, z{0.0} { }
  // 3 Getters:
  double x_position() const { return x; } 
  double y_position() const { return y; }
  double z_position() const { return z; }
  double multiplicar();
 
 private:
  double x{};
  double y{};
  double z{};
};

std::ostream& operator<<(std::ostream& kOutput, const Vector3D& vector1);

#endif