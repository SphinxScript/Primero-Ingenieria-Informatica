/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief Este código lee el primer caracter de una linea de un fichero y luego el segundo, separados por un espacio,
   *        despues cambia todas las apariciones del primer caracter por el segundo caracter en una secuencia sin espacios
   *        introducida justo despues del segndo caracter. Finalmente imprime el resultado en pantalla.
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string change_chars(const std::string& input) {
  std::string result = input;
  char first = result[1];
  char second = result[2];
  for (int i = 0; i < result.length(); ++i){
    if (result[i + 3] == first) {
      result[i + 3] = second;
    }
  }
  return result;
}

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

  /// Leer el contenido del fichero
  std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
    std::istreambuf_iterator<char>());

  /// cambiar los caracteres
  std::string changed_char = change_chars(fileContent);

  /// Imprimir el contenido resultante
  std::cout << changed_char << std::endl;

  return 0;
}