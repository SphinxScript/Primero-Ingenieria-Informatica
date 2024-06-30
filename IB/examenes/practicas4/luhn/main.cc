/**
 * Universidad de La Laguna
 * ESIT
 * Ingenieria informatcia
 * IB
 *
 * @author David Rodríguez Pane
 * @date 30/06/2024
 * @brief Este programa comprueba si una cadena de caracteres dada es válida segun el algoritmo de luhn.
 *        La cadena se recibe por parámetros, y se eliminan espacios y caracteres que no sean números; luego se comprueba.
 * @see
 * @bug there are no known bugs
 * @file luhn.h
 */

#include <iostream>
#include <string>
#include "luhn.h"


int main(int argc, char* argv[]) {
  if(!Usage(argc)) {
    std::cout << "Entrada no valida." << std::endl;
    return 1;
  }
  std::string numero = ToDigit(argv[1]);
  if (!IsValid(numero)) {
    std::cout << "Cadena de longitud no válida" << std::endl;
    return 1;
  }
  if (Luhn(numero)) {
    std::cout << numero << " Es válido." << std::endl;
  }
  else {
    std::cout << numero << " No es válido" << std::endl;
  }
  return 0;
}