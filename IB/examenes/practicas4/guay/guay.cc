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


#include "guay.h"
#include <iostream>

/**
 * @brief función que comprueba si se han introducido los parametros correspondientes en el main
 * @param argc el número de parametros pasados al main
 * @return retorna true o false, en caso de ser true, mostraria por pantalla el error;
 */

bool NoValido(const int& argc) {
  bool NoValido = true;
  if (argc == 2) NoValido = false;
  return NoValido;
}


/**
 * @brief función que recibe un número en forma de string, y realiza la comprobación de si es guay.
 * @param numero Es el número que se quiere comprobar si es guay
 * @return retorna true si es guay, o false si no lo es
 */

bool EsGuay(const std::string& numero) {
  int suma_valores = 0;
  bool posicion = true;
  for (int i{numero.size() - 1}; i >= 0; --i) {
    if (posicion) {
      suma_valores += numero[i] - '0';
    }
    posicion = !posicion;
  }
  return ((suma_valores % 2) == 0);
}