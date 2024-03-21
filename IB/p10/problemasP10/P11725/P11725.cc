#include <iostream>
#include <vector>


bool exists(int x, const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    int valor = v[i];
    if (valor == x) {
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<int> vector;
  for (int i = 1; i < argc; ++i) {
    vector.push_back(std::stod(argv[i]));
  }
  std::cout << exists(3, vector) << std::endl;
  return 0;
}
