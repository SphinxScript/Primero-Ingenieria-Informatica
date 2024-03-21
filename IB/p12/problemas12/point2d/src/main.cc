#include <iostream>
#include <cmath>

class Point2d {
 private: ///Atributos
  int coordx;
  int coordy;
 public: ///Métodos
 Point2d(int, int); ///constructor
  void Show();
  void Move();
  void Distance();
  void Middle();
};

/// constructor; nos sirve para inicializar los atributos
Point2d::Point2d(const int _coordx, const int _coordy) {
  coordx = _coordx;
  coordy = _coordy;
}

void Point2d::Show() {
  std::cout << "el punto original es: " << std::endl;
  std::cout << "(" << coordx << "," << coordy << ")" << std::endl;
}

void Point2d::Move() {
  int newcoordx;
  int newcoordy;
  std::cout << "introduzca otra coordenada 'x', y otra coordenada 'y'" << std::endl; 
  std::cin >> newcoordx;
  std::cin >> newcoordy;
  newcoordx = coordx + newcoordx;
  newcoordy = coordy + newcoordy;
  std::cout << "el nuevo punto es:" << std::endl;
  std::cout << "(" << newcoordx << "," << newcoordy << ")" << std::endl; 
}

void Point2d::Distance() {
  double restax = pow((3.0 - coordx), 2);
  double restay = pow((4.0 - coordy), 2);
  double numero = restax + restay;
  double distancia = sqrt(numero);
  std::cout << "distancia (con respecto al punto original) = " << distancia << std::endl;
}

void Point2d::Middle() {
  double newcoordx = (3.0 + coordx) / 2.0;
  double newcoordy = (4.0 + coordy) / 2.0;
  std::cout << "el punto medio (con respecto al original) es: " << "(" << newcoordx << "," << newcoordy << ")" << std::endl;
}

int main() {
  int coordx, coordy;
  std::cout << "introduzca una coordenada 'x', y una coordenada 'y'" << std::endl; 
  std::cin >> coordx;
  std::cin >> coordy;
  Point2d punto2(coordx, coordy);
  punto2.Show();
  punto2.Move();
  punto2.Show();
  punto2.Middle();
  punto2.Distance();
  return 0;
}