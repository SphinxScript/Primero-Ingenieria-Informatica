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


/**
 * @brief Función encargada de validar si el dato ingresado es válido y si no lo
 *        es imprime un mensaje de error por pantalla.
 * @param valor_ingresado Es el valor a comprobar si es válido.
 * @return Si es un número válido o no.
 */

bool CheckParams (const int& valor_ingresado) {
  if (valor_ingresado > 0) {
    return true;
  } else {
    std::cout << "El valor ingresado es inválido. Por favor, ingrese un número "
              << "natural mayor que 0." << std::endl;
    return false;
  }
}


/**
 * @brief Función encargada de pedir el número natural que se utilizará para
 *        la suma de productos y producto de sumas de los primeros N números
 *        naturales (siendo N el número ingresado) y de llamar a la función
 *        CheckParams para ver si el número ingresado es válido.
 * @param void
 * @return Valor válido para hacer los fututos cálculos y comparativas.
 */

int PedirValor () {
  std::cout << "Este programa realiza la comparación entre la suma de los "
            << "cuadrados y el cuadrado de la suma \nde los primeros N números "
            << "naturales, siendo N el número que ingresará usted por pantalla "
            << "a continuación." << std::endl;
  int valor_a_ingresar{0};
  while (std::cin >> valor_a_ingresar) {
    if (CheckParams(valor_a_ingresar)) {
      return valor_a_ingresar;
    }
  }
  return valor_a_ingresar;
}


/**
 * @brief Función que eleva al cuadrado un número.
 * @param valor_a_elevar Valor que se elevará al cuadrado.
 * @return Valor elevado al cuadrado.
 */

int Cuadrado (const int& valor_a_elevar) {
  return valor_a_elevar * valor_a_elevar;
}


/**
 * @brief Función que suma los cuadrados de los primeros N números naturales,
 *        siendo N el número ingresado por el usuario.
 * @param cantidad_primeros_numeros_naturales Es la cantidad de los primeros 
 *                                            números naturales que se sumaran.
 * @return Resultado de la suma de los cuadrados.
 */

int SumaDeCuadrados (int cantidad_primeros_numeros_naturales) {
  int suma{0};
  while (cantidad_primeros_numeros_naturales > 0) {
    suma += Cuadrado(cantidad_primeros_numeros_naturales);
    cantidad_primeros_numeros_naturales--;
  }
  return suma;
}


/**
 * @brief Función encargada de hacer el cuadrado de la suma de los primeros N
 *        números naturales, siendo N el número ingresaod por el usuario.
 * @param cantidad_primeros_numeros_naturales Es la cantidad de los primeros 
 *                                            números naturales que se sumaran.
 * @return Resultado del cuadrado de la suma.
 */

int CuadradoDeLaSuma (int cantidad_primeros_numeros_naturales) {
  int suma{0};
  while (cantidad_primeros_numeros_naturales > 0) {
    suma += cantidad_primeros_numeros_naturales;
    cantidad_primeros_numeros_naturales--;
  }
  return Cuadrado(suma);
}


/**
 * @brief Función encargada de ver cual de las dos sumas realizadas
 *        anteriormente es la mayor y de imprimirlo por pantalla.
 * @param suma_de_cuadrados Es la suma de los cuadrados.
 * @param cuadrado_de_la_suma Es el cuadrado de la suma.
 * @return void
 */

void ComparativaSumas (const int& suma_de_cuadrados, 
                       const int& cuadrado_de_la_suma) {
  if (suma_de_cuadrados > cuadrado_de_la_suma) {
    std::cout << suma_de_cuadrados << std::endl;
  } else {
    std::cout << cuadrado_de_la_suma << std::endl;
  }
}