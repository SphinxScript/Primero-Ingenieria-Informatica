#include "computeint.h"

void usage(int argc) {
  if (argc != 3) {
    std::cerr << "ERROR: DEBE INTRODUCIR 2 NÚMEROS" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char* argv[]) {
  usage(argc);
  int numero1 = std::stoi(argv[1]);
  int numero2 = std::stoi(argv[2]);
  ComputeInt prueba{numero1, numero2};
  prueba.SumSerie();
  prueba.Factorial();
  prueba.IsPrime();
  prueba.AreRelativesPrimes();
  prueba.IsPerfecPrime();
  prueba.EsEspecial();
  return 0;
}