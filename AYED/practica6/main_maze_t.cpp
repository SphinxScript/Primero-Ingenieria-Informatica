// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// Se compila con:
// g++ main_maze_t.cpp maze_t.cpp -o main_maze_t

#include <iostream>
#include "maze_t.hpp"

using namespace std;

int main()
{
  system("clear");
  maze_t M;
  // uso de una pila de pares para guardar las parejas i y j y almacenar el camino de salida (FASE III)
  stack_l_t<pair_t<int>> pila_sol;
  
  cin >> M;
  
  cout << M << endl;
  
  if (M.solve(pila_sol))
  { 
    cout << "¡¡ Se ha encontrado una salida al laberinto !!" << endl;
    cout << M << endl << "La solución, por parejas de (fila, columna) es: " << endl << endl;
    pila_sol.write();
  }
  else
    cout << "No se ha podido encontrar la salida del laberinto..." << endl;
  
  return 1;
}