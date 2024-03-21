#ifndef COMPUTEINT_H
#define COMPUTEINT_H

#include <iostream>
#include <cmath>
#include <vector>

class ComputeInt {
 public:
  ComputeInt(int, int); ///constructor
  void Factorial();
  void SumSerie();
  void IsPrime();
  void AreRelativesPrimes();
  void IsPerfecPrime();
  void EsEspecial();

 private:
  int numA_;
  int numB_;
};

#endif