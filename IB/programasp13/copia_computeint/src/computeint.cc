#include "computeint.h"

ComputeInt::ComputeInt(int numA, int numB) { ///constructor
  numA_ = numA;
  numB_ = numB;
}
void ComputeInt::SumSerie() {
  int resultA{};
  int resultB{};
  for (int i = 0; i <= numA_; ++i) {
    resultA += i;
  }
  for (int i = 0; i <= numB_; ++i) {
    resultB += i;
  }
  std::cout << "la suma de los " << numA_ << " primeros términos es: " << resultA << std::endl;
  std::cout << "la suma de los " << numB_ << " primeros términos es: " << resultB << std::endl;
}

void ComputeInt::Factorial() {
  int resultA = 1;
  int resultB = 1;
  for (int i = 2; i <= numA_; ++i) {
    resultA = resultA * i;
  }
  for (int i = 2; i <= numB_; ++i) {
    resultB *= i;
  }
  std::cout << "el factorial de " << numA_ << " es: " << resultA << std::endl;
  std::cout << "el factorial de " << numB_ << " es: " << resultB << std::endl;
}
/// funcion que se implementará en el método IsPrime
/// calcula si el número es primo o no
bool esPrimo(int number) {
  if (number <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(number); ++i) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

void ComputeInt::IsPrime() {
  if (esPrimo(numA_)) {
    std::cout << numA_ << " es primo" << std::endl;
  }
  else {
    std::cout << numA_ << " no es primo" << std::endl;
  }
  if (esPrimo(numB_)) {
    std::cout << numB_ << " es primo" << std::endl;
  }
  else {
    std::cout << numB_ << " no es primo" << std::endl;
  }
}

void ComputeInt::AreRelativesPrimes() {
  if ((esPrimo(numA_) && esPrimo(numB_)) && (numA_ != numB_)) {
    std::cout << "son primos relativos" << std::endl;
  }
  else {
    std::cout << "no son primos relativos" << std::endl;
  }
}
/// funcion a implementar en el metodo isperfectprime
int sumarDigitos(int numero) {
  int suma = 0;
  while (numero > 0) {
    suma += numero % 10;
    numero = numero / 10;
  }
  return suma;
}

bool is_perfect_prime(int n) {
  if (!esPrimo(n)) {
    return false;
  }
  int suma = sumarDigitos(n);
  // Caso base: si la suma es un número de un solo dígito y es primo, retornar verdadero
  if (suma < 10 && esPrimo(suma)) {
    return true;
  }
  // Llamada recursiva con la suma como nuevo número
  return is_perfect_prime(suma);
}

void ComputeInt::IsPerfecPrime() {
  if (is_perfect_prime(numA_)) {
    std::cout << numA_ << " es primo perfecto" << std::endl;
  }
  else {
    std::cout << numA_ << " no es primo perfecto" << std::endl;
  }
  if (is_perfect_prime(numB_)) {
    std::cout << numB_ << " es primo perfecto" << std::endl;
  }
  else {
    std::cout << numB_ << " no es primo perfecto" << std::endl;
  }
}

/* esta función calculará si un número es perfecto o no, siguiendo la definición:
   un número es perfecto si es igual a la suma de todos sus divisores menos él mismo.
   luego imprime si es o no especial
*/
void ComputeInt::EsEspecial() {
  int suma{0};
  for (int i = 0; i < numA_; ++i) {
    suma += i;
    if (numA_ % i == 0) {
      suma += i;
    }
    else {
      std::cout << numA_ << " no es especial" << std::endl;
    }
  }
  suma = 0;
  for (int i = 0; i < numB_; ++i) {
    if (numB_ % i == 0) {
      std::cout << numB_ << " es especial" << std::endl;
    }
    else {
      std::cout << numB_ << " no es especial" << std::endl;
    }
  }
  std::cout << "hola" << std::endl;
}