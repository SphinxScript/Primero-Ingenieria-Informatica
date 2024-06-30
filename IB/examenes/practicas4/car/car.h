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


#include <string>

class Car {
 public:
  Car();
  Car(const std::string& model, const std::string& plate, const int& kilometers);
  friend std::istream& operator>>(std::istream& is, Car& coche);
  bool operator>(const Car& coche);
  Car& operator=(const Car& coche);
  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }
 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};

std::ostream& operator<<(std::ostream& os, const Car& coche);