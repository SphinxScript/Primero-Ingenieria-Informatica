/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This code encrypts and decrypts text files.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "cripto.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string xorCipher(const std::string &input, const std::string &key) {
  std::string result = input;
  for (size_t i = 0; i < input.size(); ++i) {
    result[i] = input[i] ^ key[i % key.size()];
  }
  return result;
}

std::string caesarCipher(const std::string &input, int key) {
  std::string result = input;
  for (char &c : result) {
    if (std::isalpha(c)) {
      char base = std::isupper(c) ? 'A' : 'a';
      c = (c - base + key) % 26 + base;
    }
  }
  return result;
}

void processFile(const std::string &inputFile, const std::string &outputFile, int method, const std::string &password, char operation) {
  std::ifstream inFile(inputFile);
  if (!inFile) {
    std::cerr << "Error: No se pudo abrir el archivo de entrada." << std::endl;
    exit(EXIT_FAILURE);
  }

  std::stringstream buffer;
  buffer << inFile.rdbuf();
  std::string content = buffer.str();
  inFile.close();

  std::string result;

  switch (method) {
    case 1: // Cifrado XOR
      result = xorCipher(content, password);
      break;
    case 2: // Cifrado de César
      result = caesarCipher(content, std::stoi(password));
      break;
    default:
      std::cerr << "Error: Método de encriptación no válido." << std::endl;
      exit(EXIT_FAILURE);
  }

  std::ofstream outFile(outputFile);
  if (!outFile) {
    std::cerr << "Error: No se pudo abrir el archivo de salida." << std::endl;
    exit(EXIT_FAILURE);
  }

  if (operation == '+') {
    outFile << result;
    std::cout << "Operación completada: Fichero encriptado correctamente." << std::endl;
  } else if (operation == '-') {
    outFile << result;
    std::cout << "Operación completada: Fichero desencriptado correctamente." << std::endl;
  } else {
    std::cerr << "Error: Operación no válida." << std::endl;
    exit(EXIT_FAILURE);
  }

  outFile.close();
}