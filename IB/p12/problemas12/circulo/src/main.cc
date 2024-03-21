#include <iostream>

class Circulo {
 public:
  enum Color {
   negro,
   rojo,
   azul,
   verde,
   violeta,
  };
  Circulo(double, double, double, Color); // constructor
  Color color;
  double Area();
  double Perimetro();
  void Print();
 
 private:
  double centrox;
  double centroy;
  double radio;
};

// constructor
Circulo::Circulo(double _centrox, double _centroy, double _radio, Color _color) {
  centrox = _centrox;
  centroy = _centroy;
  radio = _radio;
  color = _color;
}

const double pi = 3.141592;

// metodo que calcula el área del círculo
double Circulo::Area() {
  return pi * radio * radio;
}

// metodo para calcular el perímetro del círculo
double Circulo::Perimetro() {
  return 2 * pi * radio;
}

// metodo imprimir la información del círculo
void Circulo::Print() {
  std::cout << "Centro: (" << centrox << ", " << centroy << "), Radio: " << radio << ", Color: ";
  switch (color) {
    case negro:
      std::cout << "Negro";
      break;
    case rojo:
      std::cout << "Rojo";
      break;
    case azul:
      std::cout << "Azul";
      break;
    case verde:
      std::cout << "verde";
      break;
    case violeta:
      std::cout << "violeta";
        break;
    default:
      std::cout << "Desconocido";
  }

  std::cout << std::endl;
}

int main() {

  Circulo circulo1(0.5, 0.0, 5.0, Circulo::violeta);
  circulo1.Print();
  std::cout << "Área: " << circulo1.Area() << std::endl;
  std::cout << "Perímetro: " << circulo1.Perimetro() << std::endl;

  return 0;
}