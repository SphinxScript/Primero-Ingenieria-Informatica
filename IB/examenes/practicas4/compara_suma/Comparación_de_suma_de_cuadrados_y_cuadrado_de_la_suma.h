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


/**
 * @brief Función encargada de validar si el dato ingresado es válido y si no lo
 *        es imprime un mensaje de error por pantalla.
 * @param valor_ingresado Es el valor a comprobar si es válido.
 * @return Si es un número válido o no.
 */

bool CheckParams (const int& valor_ingresado);


/**
 * @brief Función encargada de pedir el número natural que se utilizará para
 *        la suma de productos y producto de sumas de los primeros N números
 *        naturales (siendo N el número ingresado) y de llamar a la función
 *        CheckParams para ver si el número ingresado es válido.
 * @param void
 * @return Valor válido para hacer los fututos cálculos y comparativas.
 */

int PedirValor ();


/**
 * @brief Función que eleva al cuadrado un número.
 * @param valor_a_elevar Valor que se elevará al cuadrado.
 * @return Valor elevado al cuadrado.
 */

int Cuadrado (const int& valor_a_elevar);


/**
 * @brief Función que suma los cuadrados de los primeros N números naturales,
 *        siendo N el número ingresado por el usuario.
 * @param cantidad_primeros_numeros_naturales Es la cantidad de los primeros 
 *                                            números naturales que se sumaran.
 * @return Resultado de la suma de los cuadrados.
 */

int SumaDeCuadrados (int cantidad_primeros_numeros_naturales);


/**
 * @brief Función encargada de hacer el cuadrado de la suma de los primeros N
 *        números naturales, siendo N el número ingresaod por el usuario.
 * @param cantidad_primeros_numeros_naturales Es la cantidad de los primeros 
 *                                            números naturales que se sumaran.
 * @return Resultado del cuadrado de la suma.
 */

int CuadradoDeLaSuma (int cantidad_primeros_numeros_naturales);


/**
 * @brief Función encargada de ver cual de las dos sumas realizadas
 *        anteriormente es la mayor y de imprimirlo por pantalla.
 * @param suma_de_cuadrados Es la suma de los cuadrados.
 * @param cuadrado_de_la_suma Es el cuadrado de la suma.
 * @return void
 */

void ComparativaSumas (const int& primer_numero_a_comparar,
                       const int& segundo_numero_a_comparar);