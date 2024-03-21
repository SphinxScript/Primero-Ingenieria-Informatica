/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code returns the word with the highest number
  *        of vowels and the word with the highest number of consonants.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "vowels-and-consonants.h"
#include <cctype>

int countVowels(const std::string& word) {
  int count = 0;
  for (char c : word) {
    if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u') {
      count++;
    }
  }
  return count;
}

int countConsonants(const std::string& word) {
  int count = 0;
  for (char c : word) {
    if (std::isalpha(c) && std::tolower(c) != 'a' && std::tolower(c) != 'e' && std::tolower(c) != 'i' && std::tolower(c) != 'o' && std::tolower(c) != 'u') {
      count++;
    }
  }
  return count;
}