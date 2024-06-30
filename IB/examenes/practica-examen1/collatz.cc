#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
  system("clear");
  int numero = std::stoi(argv[1]);
  std::cout << numero << " ";
  while (numero != 1) {
    if (numero % 2 == 0) {
      numero = numero / 2;
    }
    else {
      numero = numero * 3;
      numero++;
    }
    std::cout << numero << " ";
  }
  std::cout << std::endl;
  return 0;
}