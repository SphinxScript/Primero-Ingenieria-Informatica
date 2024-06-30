#include <iostream>


class Box {
 public:
  Box();
  Box(double largo, double ancho, double alto);
  double length() { return length_; }
  double breadth() { return breadth_; }
  double height() { return height_; }
  friend std::istream& operator>>(std::istream& is, Box& box);
  bool operator==(Box& box);
 private:
  double length_;
  double breadth_;
  double height_;
};
// constructores:
Box::Box() : length_{0}, breadth_{0}, height_{0} {}
Box::Box(double largo, double ancho, double alto) : length_{largo}, breadth_{ancho}, height_{alto} {}

std::ostream& operator<<(std::ostream& os, Box& box) {
  os << "Largo: " << box.length() << ". Ancho: " << box.breadth() << ". Alto: " << box.height();
  return os;
}

std::istream& operator>>(std::istream& is, Box& box) {
  is >> box.length_;
  is >> box.breadth_;
  is >> box.height_;
  return is;
}

bool Box::operator==(Box& box) {
  bool iguales = true;
  if (length() != box.length()) iguales = false;
  if (breadth() != box.breadth()) iguales = false;
  if (height() != box.height()) iguales = false;
  return iguales;
}

int main() {
  system("clear");
  Box caja(20, 20, 20);
  Box caja2(20, 20, 20);
  std::cout << caja << " -> " << caja2 << std::endl;
  if (caja == caja2) {
    std::cout << "Son iguales" << std::endl;
  }
  else std::cout << "son diferentes" << std::endl;
  return 0;
}