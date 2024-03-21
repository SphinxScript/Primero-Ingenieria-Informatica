/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code changes the lowercase vowels that finds in a text file, following the next structure:
  *        'a' by 'e', 'e' by 'i', 'i' by 'o', 'o' by 'u' and 'u' by 'a'.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "rotate.h"

std::string rotateVowels(const std::string& input) {
  std::string result = input;

  for (char& c : result) {
    switch (c) {
      case 'a':
        c = 'e';
        break;
      case 'e':
        c = 'i';
        break;
      case 'i':
        c = 'o';
        break;
      case 'o':
        c = 'u';
        break;
      case 'u':
        c = 'a';
        break;
    }
  }

  return result;
}