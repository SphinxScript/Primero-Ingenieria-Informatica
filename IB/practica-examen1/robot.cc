#include “point2D.h”
#include <iostream>
#include <string>

namespace robot {
  enum class Direccion {
    Norte,
    Sur,
    Este,
    Oeste
  };
  class Robot {
   public:
    Robot();
    Robot(std::string nombre, Point2D posicion, Direccion direccion, int cansancio);
    //getters
    std::string get_nombre() const { return nombre_; }
    Point2D get_posicion() const { return posicion_; }
    Direccion get_direccion() const { return direccion_; }
    int get_cansancio() const { return cansancio_; }
    void EjecutaSecuencia(std::string secuencia);
    void GiroDerecha();
    void GiroIzquierda();
    void Avanzar();
   private:
    std::string nombre_;
    Point2D posicion_;
    Direccion direccion_;
    int cansancio_;
  };
}
//constructores
robot::Robot::Robot() : nombre_{}, posicion_{}, direccion_{}, cansancio_{} {}

robot::Robot::Robot(std::string nombre, Point2D posicion, Direccion direccion, int cansancio) :
nombre_{nombre}, posicion_{posicion}, direccion_{direccion}, cansancio_{cansancio} {}

// operador insercion:
std::ostream& operator<<(std::ostream& os, const robot::Robot& robot) {
  os << "Nombre: " << robot.get_nombre() << ". Posicion: " << robot.get_posicion() << ". Cansancio: " << robot.get_cansancio() << std::endl;
  return os;
}

void robot::Robot::GiroDerecha() {
  if (direccion_ == Direccion::Norte) {
    direccion_ = Direccion::Este;
  }
  else if (direccion_ == Direccion::Este) {
    direccion_ = Direccion::Sur;
  }
  else if (direccion_ == Direccion::Sur) {
    direccion_ = Direccion::Oeste;
  }
  else {
    direccion_ = Direccion::Norte;
  }
}

void robot::Robot::GiroIzquierda() {
  if (direccion_ == Direccion::Norte) {
    direccion_ = Direccion::Oeste;
  }
  else if (direccion_ == Direccion::Este) {
    direccion_ = Direccion::Norte;
  }
  else if (direccion_ == Direccion::Sur) {
    direccion_ = Direccion::Este;
  }
  else {
    direccion_ = Direccion::Sur;
  }
}
void robot::Robot::Avanzar() {
  if (direccion_ == Direccion::Norte) {
    ++posicion_.y;
  }
  else if (direccion_ == Direccion::Este) {
    ++posicion_.x;
  }
  else if (direccion_ == Direccion::Sur) {
    --posicion_.y;
  }
  else {
    --posicion_.x;
  }
}

void robot::Robot::EjecutaSecuencia(std::string secuencia) {
  for (int i{0}; i < secuencia.size(); ++i) {
    if (secuencia[i] == 'A') {
      robot::Robot::Avanzar();
    }
    else if (secuencia[i] == 'D') {
      robot::Robot::GiroDerecha();
    }
    else robot::Robot::GiroIzquierda;
  }
}