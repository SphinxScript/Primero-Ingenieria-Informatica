#include <iostream>
#include <string>

class Car {
 public:
  Car();
  Car (std::string model, std::string plate, int kilometers);
  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }
  friend std::istream& operator>>(std::istream& is, Car& car);
  bool operator>(const Car&);
 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};

// constructores:
Car::Car () {}
Car::Car(std::string model, std::string plate, int kilometers) : model_{model}, plate_{plate}, kilometers_{kilometers} {}

std::ostream& operator<<(std::ostream& os, const Car& car) {
  os << "Modelo: " << car.model() << ". Matrícula: " << car.plate() << ". Kilómetros: " << car.kilometers();
  return os;
}
std::istream& operator>>(std::istream& is, Car& car) {
  std::string model, plate;
  int kilometers;
  is >> model;
  is >> plate;
  is >> kilometers;
  car.model_ = model;
  car.plate_ = plate;
  car.kilometers_ = kilometers;
  return is;
}

bool Car::operator>(const Car& coche) {
  if (kilometers_ > coche.kilometers()) {
    return true;
  }
  return false;
}

int main() {
  system("clear");
  Car coche1("caballo", "122L", 45);
  Car coche2("roberta", "589J", 46);
  std::cout << coche1 << "  ->  " << coche2 << std::endl;
  if (coche1 >  coche2) {
    std::cout << coche1.model() << " Está antes" << std::endl;
  }
  std::cout << coche2.model() << " Está antes" << std::endl;
  return 0;
}