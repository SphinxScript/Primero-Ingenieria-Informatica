#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  system("clear");
  std::string cadena = argv[1];
  for (int i{0}; i < cadena.size(); ++i) {
    if (isalpha(cadena[i])) {
      if (islower(cadena[i])) {
        cadena[i] = toupper(cadena[i]);
      }
      else cadena[i] = tolower(cadena[i]);
    }
  }
  std::cout << cadena << std::endl;
  return 0;
}