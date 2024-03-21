#include <iostream>
#include <string>
#include "capitalizeVowels.h"

void Usage(int argc) {
  if (argc == 1) {
    std::cerr << "Este programa cambia a mayúsculas las vocales de una cadena de"
                 " caracteres, por favor, introduzca una" << std::endl;
    exit(0);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc);
  std::string palabra;
  for (int i = 1; i < argc; i++) {
    palabra = palabra + argv[i];
  }
  std::string resultado = capitalizeVowels(palabra);
  std::cout << resultado << std::endl;
}
