/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This file contains the theclarations of the functions
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#ifndef CRIPTO_H
#define CRIPTO_H

#include <string>

std::string xorCipher(const std::string &input, const std::string &key);
std::string caesarCipher(const std::string &input, int key);
void processFile(const std::string &inputFile, const std::string &outputFile, int method, const std::string &password, char operation);

#endif  // CRIPTO_H