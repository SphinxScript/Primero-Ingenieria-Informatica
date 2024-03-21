#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <string>
#include "racional.h"
#include "comparacion.h"

int main(int argc, char* argv[]) {
  std::ifstream inputFile(argv[1]);
  if (!inputFile) {
    std::cerr << "ERROR: tiene que pasar un fichero de entrada" << std::endl;
    return 1;
  }
  std::ofstream outputFile(argv[2]);
  if (!outputFile) {
    std::cerr << "ERROR: proporcione un fichero de salida" << std::endl;
    return 1;
  }
  std::string primer_racional;
  std::getline(inputFile, primer_racional);
  std::vector<char> racional_1;
  for (char c : primer_racional) {
    racional_1.push_back(c);
  }
  std::string segundo_racional;
  std::getline(inputFile, segundo_racional);
  std::vector<char> racional_2;
  for (char c : segundo_racional) {
    racional_2.push_back(c);
  }

  for (char c : racional_1){
    std::cout << c;
  }

  int numerador1{}, denominador1{}, numerador2{}, denominador2{};
  for (char c : racional_1) {
    if (c != '/') {
      break;
    }
    numerador1 += c - '0';
  }

  std::cout << std::endl;
  std::cout << numerador1;

  for (char c : primer_racional) {
    if (c == '/') {
      denominador1 += c - '0';
    }
  }
  for (char c : segundo_racional) {
    if (c != '/') {
      numerador2 += c - '0';
    }
  }
  for (char c : segundo_racional) {
    if (c != '/') {
      denominador2 += c - '0';
    }
  }
  Racional racional1{numerador1, denominador1}, racional2{numerador2, denominador2};
  outputFile << "suma: " << racional1 + racional2 << std::endl;
  outputFile << "resta: " << racional1 - racional2 << std::endl;
  outputFile << "multiplicación: " << racional1 * racional2 << std::endl;
  outputFile << "división: " << racional1 / racional2 << std::endl;
  Comparacion resultado = racional1.comparar(racional2);
  switch (resultado) {
    case Comparacion::Menor:
      outputFile << racional1 << " es menor que " << racional2;
      break;
    case Comparacion::Igual:
      outputFile << racional1 << " es igual a " << racional2;
      break;
    case Comparacion::Mayor:
      outputFile << racional1 << " es mayor que " << racional2;
      break;
  }
  std::cout << "resultados escritos en " << argv[2] << std::endl;
  return 0;
}