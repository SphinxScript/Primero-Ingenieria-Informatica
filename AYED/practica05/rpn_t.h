// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl << "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  int resultado = stack_.top();
  stack_.pop();
  return resultado;
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == 'r' || c == '^' || c == 'l' || c == 'c');

  if ((c != 'r') && (c != 'l') && (c != 'c')) {
    // poner código
    int numA = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << numA << std::endl;
    int numB = stack_.top();
    stack_.pop();
    // poner código
    std::cout << "   Sacamos de la pila otro operando: " << numB << std::endl;
    
    switch (c) {
      case '+': {
        int suma = numA + numB;
        stack_.push(suma);
        break;
      }
      case '-': {
        int resta = numB - numA;
        stack_.push(resta);
        break;
      }
      case '*': {
        int mul = numA * numB;
        stack_.push(mul);
        break;
      }
      case '/': {
        int div = numB / numA;
        stack_.push(div);
        break;
      }
      case '^': {
        int pow = std::pow(numB,numA);
        stack_.push(pow);
      }
      default: {
        std::cout << "Operación no válida." << std::endl;
        break;
      }
      // poner código resto de operadores
    }
  }
  else if (c == 'r') {
    int numC = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << numC << std::endl;
    double root = std::sqrt(numC);
    stack_.push(root);
  }
  else if (c == 'l') {
    int numL = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << numL << std::endl;
    double log = std::log2(numL);
    stack_.push(log);
  }
  else if (c == 'c') {
    int numS = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << numS << std::endl;
    int square = numS * numS;
    stack_.push(square);
  }
  // poner código
  std::cout << "   Metemos en la pila el resultado: " << stack_.top() << std::endl;
}

 
#endif  // RPNT_H_
