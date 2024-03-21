/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief This file is the main file to encrypt and decrypt files
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "cripto.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 6 || std::string(argv[1]) == "--help") {
    std::cout << "./cripto -- Cifrado de ficheros\n"
              << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación\n"
              << "Pruebe ./cripto --help para más información" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputFile = argv[1];
  std::string outputFile = argv[2];
  int method = std::stoi(argv[3]);
  std::string password = argv[4];
  char operation = argv[5][0];

  processFile(inputFile, outputFile, method, password, operation);

  return EXIT_SUCCESS;
}