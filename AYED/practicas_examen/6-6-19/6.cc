#include <iostream>
using namespace std;

int mcd(int x, int y) {
  if (y == 0) return x;
  return mcd(y, x % y);
}

int main() {
  //system("clear");
  int a = 1071;
  int b = 462;
  std::cout << mcd(a,b) << endl;
  return 0;
}