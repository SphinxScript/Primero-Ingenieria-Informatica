#include <iostream>
#include <string>

bool Luhn(const std::string& cadena) {
  if(cadena.size() <= 1) return false;

  bool digito = false;
  int numero;
  int acumulador{0};
  for (int i{(cadena.size()) - 1}; i >= 0; --i) {
    numero = cadena[i] - '0';
    if (digito) {
      numero *= 2;
      if (numero > 9) {
        numero = (numero % 10) + (numero / 10);
      }
    }
    acumulador += numero;
    digito = !digito;
  }
  return ((acumulador % 10) == 0);
}
int main() {
  std::string cadena = "4539319503436467";
  if (Luhn(cadena)) {
    std::cout << "valido" << std::endl;
  } else {
    std::cout << "no valido" << std::endl;
  }
  return 0;
}
