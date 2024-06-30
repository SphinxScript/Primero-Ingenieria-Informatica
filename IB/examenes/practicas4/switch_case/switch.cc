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

/**
 * @brief Esta función comprueba si el nº de parametros pasados por comandos es correcto
 * @param argc
 * @return true/false
 */

void Usage(const int& argc) {
  if (argc != 2) {
    std::cout << "Número de parámetros incorrecto" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Esta función cambia los caracteres que sean letras de minúscula a mayúscula y viceversa.
 * @param cadena_caracteres
 * @return void
 */

void SwitchCase(std::string& cadena_caracteres) {
  for (int i{0}; i < cadena_caracteres.size(); ++i) {
    if (isalpha(cadena_caracteres[i])) {
      if (isupper(cadena_caracteres[i])) {
        cadena_caracteres[i] = tolower(cadena_caracteres[i]);
      }
      else if (islower(cadena_caracteres[i])) {
        cadena_caracteres[i] = toupper(cadena_caracteres[i]);
      }
    }
  }
}