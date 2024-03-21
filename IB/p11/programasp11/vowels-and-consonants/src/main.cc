/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code prints on screen the word with the highest number of vowels, and
  *        then the word with the highest number of consonants.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <iostream>
#include <fstream>
#include "vowels-and-consonants.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "ERROR: debe introducir UN fichero de texto al ejecutar el comando" << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[1]);
  if (!inputFile) {
    std::cerr << "Error al abrir el archivo: " << argv[1] << std::endl;
    return 1;
  }

  std::string word;
  std::string maxVowelWord;
  std::string maxConsonantWord;
  int maxVowelCount = 0;
  int maxConsonantCount = 0;

  while (inputFile >> word) {
    int vowelCount = countVowels(word);
    int consonantCount = countConsonants(word);

    if (vowelCount > maxVowelCount) {
      maxVowelCount = vowelCount;
      maxVowelWord = word;
    }

    if (consonantCount > maxConsonantCount) {
      maxConsonantCount = consonantCount;
      maxConsonantWord = word;
    }
  }

  std::cout << "Palabra con mayor número de vocales: " << maxVowelWord << " (" << maxVowelCount << " vocales)" << std::endl;
  std::cout << "Palabra con mayor número de consonantes: " << maxConsonantWord << " (" << maxConsonantCount << " consonantes)" << std::endl;

  return 0;
}