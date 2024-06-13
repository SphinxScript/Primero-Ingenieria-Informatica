#include <iostream>
#include <string>

class Car {
 public:
  Car();
  Car(const std::string&, const std::string&, int);
  // Operadores:
  friend std::istream& operator>>(std::istream& is, Car&);
  bool operator>(const Car&);
  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }
 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};

// constructores:
Car::Car() : model_{}, plate_{}, kilometers_{} {}
Car::Car(const std::string& model, const std::string& plate, int kilometers) :
 model_{model}, plate_{plate}, kilometers_{kilometers} {}

std::ostream& operator<<(std::ostream& os, const Car& coche) {
  os << "Modelo: " << coche.model() << std::endl;
  os << "Plate: " << coche.plate() << std::endl;
  os << "Kilometers: " << coche.kilometers() << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Car& coche) {
  is >> coche.model_ >> coche.plate_ >> coche.kilometers_;
  return is;
}

bool Car::operator>(const Car& coche) {
  bool anterior = true;
  if (kilometers() <= coche.kilometers()) {
    anterior = false;
  }
  else anterior = false;
  return anterior;
}

int main() {
  Car coche1, coche2;
  std::cin >> coche1 >> coche2;
  std::cout << coche1 << std::endl << coche2;
  if (coche1 > coche2) std::cout << coche1.model() << "es mayor" << std::endl;
  else std::cout << coche2.model() << " es mayor" << std::endl;
  return 0;
}