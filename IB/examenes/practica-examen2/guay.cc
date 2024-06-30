#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  std::string numero{argv[1]};
  int contador{0};
  int posicion{1};
  for (int i{numero.size() - 1}; i >= 0; --i) {
    if(posicion % 2 != 0) {
      contador += numero[i] - '0';
    }
    ++posicion;
  }
  if (contador % 2 == 0) std::cout << numero << " Es guay" << std::endl;
  else std::cout << numero << " No es guay" << std::endl;
  return 0;
}