#include <iostream>
#include <string>


bool guay(const std::string& numero) {
  int acumulador{0};
  int posicion{1};
  for (int i{numero.size() - 1}; i >= 0; --i){
    if (posicion % 2 != 0) {
      acumulador += numero[i] - '0';
    }
    ++posicion;
  }
  return ((acumulador % 2) == 0);
}

int main(int argc, char* argv[]) {
  std::string numero;
  numero = argv[1];
  if (guay(numero)) std::cout << numero << " Es guay" << std::endl;
  else std::cout << numero << " No es guay " << std::endl;

  return 0;
}