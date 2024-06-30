/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática básica
 * 
 * @author Liam Barrera Arteaga
 * @date 30/06/2024
 * @brief Este programa recibe un número por la línea de comandos y si es válido
 *        realiza la suma de los cuadrados y el cuadrado de la suma de los
 *        primeros N números naturales (siendo N el número ingresado),
 *        comparándo cual es mayor y retornando el resultado por pantalla.
 */


#include <iostream>
#include "Comparación_de_suma_de_cuadrados_y_cuadrado_de_la_suma.h"


int main() {
  int valor_ingresado = PedirValor();
  int suma_de_cuadrados = SumaDeCuadrados(valor_ingresado);
  int cuadrado_de_la_suma = CuadradoDeLaSuma(valor_ingresado);
  ComparativaSumas(suma_de_cuadrados, cuadrado_de_la_suma);
  return 0;
}