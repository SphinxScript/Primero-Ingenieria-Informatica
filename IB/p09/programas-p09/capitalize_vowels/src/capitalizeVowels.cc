#include <iostream>
#include <string>
#include "capitalizeVowels.h"

bool esVocal(char letra) {
  letra = tolower(letra);
  return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}
std::string capitalizeVowels(std::string palabra) {
  for (int i = 0; i < palabra.length(); ++i) {
    char &caracter = palabra[i];

    if (std::isalpha(caracter)) {
      if (esVocal(caracter)) {
        caracter = std::toupper(caracter);
      }
      else {
        caracter = std::tolower(caracter);
      }
    }
  }
  return palabra;
}
