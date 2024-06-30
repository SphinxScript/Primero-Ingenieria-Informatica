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


/**
 * @brief esta funcion comprueba si el número de parametros pasados al main es correcto, retorna true si es correcto, false si no es asi
 * @param argc
 * @return
 */

bool Usage(const int& argc) {
  if (argc != 2) {
    return false;
  }
  return true;
}

/**
 * @brief esta funcion elimina los caracteres que no sean digitos de la cadena inicial
 * @param cadena_numeros
 * @return numero
 */

std::string ToDigit(const std::string& cadena_numeros) {
  std::string numero;
  for (int i{0}; i < cadena_numeros.size(); ++i) {
    if(isdigit(cadena_numeros[i])) {
      numero += cadena_numeros[i];
    }
  }
  return numero;
}

/**
 * @brief esta funcion comprueba si la longitud de la cadena válida (solo de números) es correcta.
 * @param numero
 * @return true/false
 */

bool IsValid(const std::string& numero) {
  if (numero.size() <= 1) return false;
  return true;
}

/**
 * @brief esta funcion realiza el algoritmo de luhn
 * @param numero
 * @return true/false
 */

bool Luhn(const std::string& numero) {
  bool duplicar = false;
  int sumatorio{0};
  for (int i{numero.size() - 1}; i >= 0; --i) {
    int digito = numero[i] - '0';
    if (duplicar) {
      digito *= 2;
      if (digito > 9) {
        int cociente = digito / 10;
        int resto = digito % 10;
        digito = cociente + resto;
      }
    }
    sumatorio += digito;
    duplicar = !duplicar;
  }
  return ((sumatorio % 10) == 0);
}