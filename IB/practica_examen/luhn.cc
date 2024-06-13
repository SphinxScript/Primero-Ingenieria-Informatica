#include <iostream>
#include <string>

bool luhn(const std::string& numero) {
  //std::cout << numero << std::endl;
  if (numero.size() <= 1) return false;
  int contador{0};
  bool doblar = false;
  for (int i{numero.size() - 1}; i >= 0; --i) {
    int valor = numero[i] - '0';
    if (doblar) {
      valor *= 2;
      if (valor > 9) {
        int cifra1 = valor % 10;
        int cifra2 = valor / 10;
        valor = cifra1 + cifra2;
      }
    }
    doblar = !doblar;
    contador += valor;
  }
  std::cout << contador << std::endl;
  return ((contador % 10) == 0);
}


int main(int argc, char* argv[]) {
  //system ("clear");
  std::string cadena = argv[1];
  std::string numero;
  for (char c : cadena) {
    if (isdigit(c)) {
      numero += c;
    }
  }
  if (luhn(numero)) std::cout << " Es válido " << std::endl;
  else std::cout << " No es válido" << std::endl;
  return 0;
}