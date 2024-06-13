#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  system("clear");
  std::string palabra{argv[1]};
  for (int i{0}; i < palabra.size(); ++i) {
    if (isalpha(palabra[i])) {
      if (islower(palabra[i])) {
        palabra[i] = toupper(palabra[i]);
      }
      else {
        palabra[i] = tolower(palabra[i]);
      }
    }
  }
  std::cout << palabra << std::endl;
  return 0;
}