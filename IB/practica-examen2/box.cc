#include <iostream>

class Box {
 public:
  // constructores
  Box();
  Box(int lenght, int breadth, int height);
  // operadores
  bool operator==(Box& caja);
  friend std::istream& operator>>(std::istream&, Box& caja);
  int length() { return length_; }
  int breadth() { return breadth_; }
  int height() { return height_; }
 private:
  int length_;
  int breadth_;
  int height_;
};

//std::ostream& operator<<(std::ostream& os, const Box& caja);

// constructores:
Box::Box() : length_{0}, breadth_{0}, height_{0} {}

Box::Box(int lenght, int breadth, int height) : length_{lenght}, breadth_{breadth}, height_{height} {}

bool Box::operator==(Box& caja) {
  bool iguales = true;
  if (length() != caja.length()) iguales = false;
  if (breadth() != caja.breadth()) iguales = false;
  if (height() != caja.height()) iguales = false;
  return iguales;
}

// operador insercion y extraccion

std::ostream& operator<<(std::ostream& os, Box& caja) {
  os << "Largo: " << caja.length() << std::endl;
  os << "Ancho: " << caja.breadth() << std::endl;
  os << "Alto: " << caja.height() << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Box& caja) {
  is >> caja.length_ >> caja.breadth_ >> caja.height_;
  return is;
}

int main() {
  system("clear");
  Box caja1, caja2(10,20,30);
  std::cout << "Introduzca valores de caja 1: " << std::endl;
  std::cin >> caja1;
  std::cout << "caja1: " << caja1 << " Caja2: " << caja2;
  if (caja1 == caja2) std::cout << "\nIguales" << std::endl;
  else std::cout << "\ndiferentes" << std::endl;

  return 0;
}