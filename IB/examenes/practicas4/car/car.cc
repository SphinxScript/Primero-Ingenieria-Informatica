/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Ricardo David Rodríguez Pane
 * @date 30/06/2024
 * @brief este programa implementa una clase que maneja objetos "coche". Tiene como atributos la placa,
 *        el kilometraje y el modelo. Implementaremos constructores, sobrecarga de operador de insercion y extraccion,
 *        una sobrecarga para comprobar que coche tiene mas kilometros que otro y una sobrecarga del operador =
 */

#include "car.h"
#include <iostream>

/**
 * @brief constructores, uno por defecto y otro con parametros
 * @param model, plate, kilometers el que emplea parametros lleva sus parametros correspondientes para crear el objeto coche.
 * @return no retornan nada, ya que son constructores.
 */
 
Car::Car() : model_{}, plate_{}, kilometers_{} {}

Car::Car(const std::string& model, const std::string& plate, const int& kilometers) : model_{model}, plate_{plate}, kilometers_{kilometers} {}

/**
 * @brief sobrecarga del operador de extraccion >>
 * @param std::istream
 * @param Car
 * @return is 
 */

std::istream& operator>>(std::istream& is, Car& coche) {
  is >> coche.model_ >> coche.plate_ >> coche.kilometers_;
  return is;
}

/**
 * @brief sobrecarga del operador de inserción <<
 * @param std::ostream
 * @param Car
 * @return os
 */

std::ostream& operator<<(std::ostream& os, const Car& coche) {
  os << "Model: " << coche.model() << std::endl;
  os << "Plate: " << coche.plate() << std::endl;
  os << "Km: " << coche.kilometers() << std::endl;
  return os;
}

/**
 * @brief metodo que comprueba si el coche invocante tiene mayor kilometraje que el coche que se pasa como parametro
 * @param Car
 * @return true/false
 */

bool Car::operator>(const Car& coche) {
  if (kilometers() >= coche.kilometers()) return true;
  return false;
}

/**
 * @brief sobrecarga del operador =
 * @param Car
 * @return Car
 */

Car& Car::operator=(const Car& coche) {
  if (this == &coche) {
    return *this;
  }

  model_ = coche.model();
  plate_ = coche.plate();
  kilometers_ = coche.kilometers();

  return *this;
}