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


int main() {
  Car coche1("hola", "123", 40);
  Car coche2("adios", "234", 50);
  //coche2 = coche1;
  std::cout << coche1 << coche2 << std::endl;
  if (coche1 > coche2) std::cout << "si";
  else std::cout << "no";
  return 0;
}