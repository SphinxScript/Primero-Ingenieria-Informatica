#include <iostream>
#include <string>

int main() {
  system("clear");
  std::string numero;
  std::cin >> numero;
  int contador{0};
  int posicion{1};
  for (int i{numero.size() - 1}; i >= 0; --i) {
    if (posicion % 2 != 0) {
      contador += numero[i] - '0';
    }
    ++posicion;
  }
  if (contador % 2 == 0) {
    std::cout << "N es guay" << std::endl;
  }
  else std::cout << "N no es guay" << std::endl;
  return 0;
}