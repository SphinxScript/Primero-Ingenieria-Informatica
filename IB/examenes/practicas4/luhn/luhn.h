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

#include <string>

bool Usage(const int& argc);

std::string ToDigit(const std::string& cadena_numeros);

bool IsValid(const std::string& numero);

bool Luhn(const std::string& numero);