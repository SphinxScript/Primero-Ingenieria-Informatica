/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * 
 * @author Ricardo David Rodríguez Pane
 * @date  30/06/2024
 * @brief Este programa recibe un número por línea de comandos, comprueba si es válido y nos dice si es guay o no.
 *        Un número natural se dice que es guay si la suma de los dígitos que están en posiciones
 *        impares (empezando a contar por la derecha) es un número par.
 */

#include <iostream>
#include "guay.h"

int main(int argc, char* argv[]) {
  if (NoValido(argc)) {
    std::cout << "Número de parametros no válido. Ha de introducir un número entero" << std::endl;
    return 1;
  }
  if (EsGuay(argv[1])) {
    std::cout << argv[1] << " es guay" << std::endl;
  }
  else {
    std::cout << argv[1] << " no es guay" << std::endl;
  }
  return 0;
}