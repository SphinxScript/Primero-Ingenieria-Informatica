/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code creates files: A.txt, B.txt, ..., Z.txt, and each of those files contain, on separate
  *        lines, all the words from the file passed as a parameter that begin with the corresponding letter of the file.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "create-files.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void processFile(const std::string &inputFileName) {
  std::ifstream inputFile(inputFileName);

  if (!inputFile.is_open()) {
    std::cerr << "No se pudo abrir el archivo de entrada: " << inputFileName << std::endl;
    return;
  }

  // Vector de vectores de strings para almacenar palabras por letra
  std::vector<std::vector<std::string>> wordsByLetter(26);

  std::string word;
  while (inputFile >> word) {
    if (!word.empty()) {
      char firstLetter = std::toupper(word[0]); // Convertir a mayúsculas
      if (std::isalpha(firstLetter)) {
        int index = firstLetter - 'A';
        wordsByLetter[index].push_back(word);
      }
    }
  }

  inputFile.close();

  // Escribir los resultados en archivos A.txt, B.txt, ..., Z.txt
  for (int i = 0; i < 26; ++i) {
    char letter = static_cast<char>('A' + i);
    std::string outputFileName = std::string(1, letter) + ".txt";

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
      std::cerr << "No se pudo abrir el archivo de salida: " << outputFileName << std::endl;
      continue;
    }

    // Ordenar las palabras antes de escribirlas en el archivo
    std::sort(wordsByLetter[i].begin(), wordsByLetter[i].end());

    // Escribir las palabras en el archivo
    for (const auto &w : wordsByLetter[i]) {
      outputFile << w << "\n";
    }

    outputFile.close();
  }
}