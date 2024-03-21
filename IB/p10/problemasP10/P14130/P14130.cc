#include <iostream>
#include <vector>

int equal(std::vector<int>& vector) {
  int cantidad{0};
  int last_element = vector[vector.size() - 1];
  for (int i = 0; i < vector.size(); ++i) {
    if (vector[i] == last_element) {
      cantidad += 1;
    }
  }
  return cantidad;
}


int main() {
  int num_n;
  std::cin >> num_n;
  std::vector<int> vector;
  for (int i = 0; i < num_n; ++i) {
    int cadena;
    std::cin >> cadena;
    vector.push_back(cadena);
  }
  std::cout << equal(vector) << std::endl;
  return 0;
}

