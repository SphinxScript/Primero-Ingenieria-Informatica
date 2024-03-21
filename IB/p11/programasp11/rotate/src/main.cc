/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 02 2023
  * @brief main file of the code that changes vowels in a text file
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "rotate.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "ERROR: debe introducir al menos un fichero de texto en línea de comandos" << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[1]);
  if (!inputFile.is_open()) {
    std::cerr << "ERROR: imposible abrir el archivo" << argv[1] << std::endl;
    return 1;
  }

  // Leer el contenido del fichero
  std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
    std::istreambuf_iterator<char>());

  // cambiar las vocales
  std::string rotatedContent = rotateVowels(fileContent);

  // Imprimir el contenido resultante
  std::cout << rotatedContent << std::endl;

  return 0;
}