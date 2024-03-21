#include <iostream>
#include <vector>
#include <string>

bool is_increasing(int numero) {
  if (numero < 10) {
    return true;
  }
  int ultimoDigito = numero % 10;
  numero = numero / 10;
  if (is_increasing(numero) && ultimoDigito >= numero % 10) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  int numero;
  std::cin >> numero;
  if (is_increasing(numero)) {
    std::cout << "si" << std::endl;
  }
  else {
    std::cout << "no" << std::endl;
  }
  return 0;
}
