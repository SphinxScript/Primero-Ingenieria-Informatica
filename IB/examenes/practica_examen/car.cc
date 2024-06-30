#include <iostream>
#include <string>



class Car {
 public:
  Car();
  Car(const std::string& model, const std::string& plate, int kilometers);
  friend std::istream& operator>>(std::istream& is, Car& coche);
  bool operator>(const Car& car);
  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }
 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};

// constructores
Car::Car() : model_{}, plate_{}, kilometers_{} {}
Car::Car(const std::string& model, const std::string& plate, int kilometers) : model_{model}, plate_{plate}, kilometers_{kilometers} {}

// extraccion e insercion

std::ostream& operator<<(std::ostream& os, const Car& coche) {
  os << "Modelo: " << coche.model() << std::endl;
  os << "Placa: " << coche.plate() << std::endl;
  os << "Km: " << coche.kilometers() << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Car& car) {
  is >> car.model_ >> car.plate_ >> car.kilometers_;
  return is;
}

// operador comparar
bool Car::operator>(const Car& car) {
  return (kilometers() > car.kilometers());
}

int main() {
  Car coche1, coche2;
  std::cin >> coche1 >> coche2;
  std::cout << coche1 << coche2;
  if (coche1 > coche2) std::cout << coche1.model() << " esta antes " << std::endl;
  else std::cout << coche2.model() << " esta antes " << std::endl;
  return 0;
}