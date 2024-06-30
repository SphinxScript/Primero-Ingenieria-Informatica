/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * 
 * @author Ricardo David Rodríguez Pane
 * @date 30/06/2024
 * @brief Este programa toma una cadena de caracteres dada por parametros al main, y cambia las
 *        minúsculas por mayúsculas y viceversa. Los caracteres que no son letras no se ven alterados.
 * @see
 * @file switch.h
 * @bug There are no known bugs.
 */

#include "switch.h"

int main(int argc, char* argv[]) {
  Usage(argc);
  std::string cadena_caracteres = argv[1];
  SwitchCase(cadena_caracteres);
  std::cout << cadena_caracteres << std::endl;
  return 0;
}