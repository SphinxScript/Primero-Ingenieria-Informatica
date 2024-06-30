#include <string>
#include <iostream>


bool correct(int num) {
  if (num < 1) {
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  int numero{std::stoi(argv[1])};
  if (!correct(numero)) {
    std::cout << "Número no válido" << std::endl;
  }
  else {
    //std::cout << numero;
    int cuadrado_suma;
    int acumulador{0};
    for (int i{1}; i <= numero; ++i) {
      acumulador += i;
    }
    cuadrado_suma = acumulador;
    cuadrado_suma = cuadrado_suma * cuadrado_suma;
    int suma_cuadrados;
    acumulador = 0;
    for (int i{1}; i <= numero; ++i) {
      acumulador += i * i;
      //std::cout << i;
    }
    suma_cuadrados = acumulador;
    std::cout << "La suma de cuadrados es: " << suma_cuadrados << " y el cuadrado de la suma es: " << cuadrado_suma << std::endl;
  }
  return 0;
}