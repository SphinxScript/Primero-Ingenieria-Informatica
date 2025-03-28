/*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"

void menu(unsigned dirigido, char &opcion) {  // Expresión del menú de opciones según sea un grafo dirigido o no dirigido
  std::cout << "Optimiza!cion en Grafos, 2021-2022 Ricardo David Rodríguez Pane" << std::endl;
  std::cout << "c. [c]argar grafo desde fichero" << std::endl;
  if (dirigido == 0) {  // Grafo no dirigido
    std::cout << "i. Mostrar [i]nformacion basica del grafo" << std::endl;
    std::cout << "a. Mostrar la lista de [a]dyacencia del grafo" << std::endl;
    std::cout << "o. Mostrar c[o]mponentes conexas del grafo" << std::endl;
    // cout << "y. Mostrar la matriz de adyacencia del grafo" << endl;
    // cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
    // cout << "r. Realizar un [r]ecorrido en profundidad de un grafo desde un nodo" << endl;
    // cout << "k. Mostrar árbol generador de mínimo coste, [k]ruskal" << endl;
    // Aquí se añaden más opciones al menú del grafo no dirigido
  } else {  // Grafo dirigido
    std::cout << "i. Mostrar [i]nformacion basica del grafo" << std::endl;
    std::cout << "s. Mostrar la lista de [s]ucesores del grafo" << std::endl;
    std::cout << "p. Mostrar la lista de [p]redecesores del grafo" << std::endl;
    std::cout << "o. Mostrar componentes fuertemente c[o]nexas del grafo" << std::endl;
    // cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
    // cout << "m. Realizar un recorrido en a[m]plitud del grafo" << endl;
    // cout << "r. Realizar un [r]ecorrido en profundidad del grafo" << endl;
    // cout << "d. Realizar el algoritmo PDM" << endl;
    // cout << "d. caminos mínimos [d]ijkstra" << endl;
    // cout << "d. caminos mínimos" << endl;
    // Aquí se añaden más opciones al menú del grafo dirigido
  }
  std::cout << "q. Finalizar el programa" << std::endl;
  std::cout << "Introduce la letra de la accion a ejecutar  > ";
  std::cin >> opcion;
}

void clear() {
  system("clear");
}

void pressanykey() {
  getchar();
}

// El principal es simplemente un gestor de menú, diferenciando acciones para dirigido y para no dirigido,
// y un menú inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {
  int error_apertura;
  std::string nombrefichero;
  char opcion;
  clear();
  // Si tenemos el nombre del primer fichero por argumento, es una excepción, y lo intentamos cargar; si no, lo pedimos desde teclado
  if (argc > 1) {
    std::cout << "Cargando datos desde el fichero dado como argumento" << std::endl;
    nombrefichero = argv[1];
  }
  else {
    std::cout << "Introduce el nombre completo del fichero de datos" << std::endl;
    std::cin >> nombrefichero;
  }
  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
    std::cout << nombrefichero << std::endl;
    std::cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << std::endl;
    return EXIT_FAILURE;
  }
  else {
    std::cout << "Grafo cargado desde el fichero " << nombrefichero << std::endl;
    pressanykey();
    clear();
    do {
      menu(G.Es_dirigido(), opcion);
      switch (opcion) {
        case 'c':
          clear();
          std::cout << "Introduce el nombre completo del fichero de datos" << std::endl;
          std::cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura);
          if (error_apertura == 1) {
            std::cout << "Error en la apertura del fichero: revisa nombre y formato" << std::endl;
            EXIT_FAILURE;
          }
          else {
            std::cout << "Fichero cargado correctamente desde " << nombrefichero << std::endl;
          }
          pressanykey();
          clear();
          break;
        case 'a':
          clear();
          std::cout << "Lista de adyacencia: " << std::endl;
          G.Mostrar_Listas(0);
          break;
        case 'i':
          clear();
          std::cout << "Grafo cargado desde " << nombrefichero << std::endl;
          G.Info_Grafo();
          // G.mostrar_nodos();
          pressanykey();
          // clear();
          break;
        case 's':
          clear();
          std::cout << "Lista de sucesores.\nGrafo cargado desde: " << nombrefichero << std::endl;
          G.Mostrar_Listas(1);
          pressanykey();
          break;
        case 'o':
          clear();
          if (G.Es_dirigido() == 0) {
            std::cout << "Componentes conexas del grafo: " << std::endl << std::endl;
            G.ComponentesConexas();
          }
          else {
            std::cout << "Componentes fuertemente conexas del grafo: " << std::endl << std::endl;
            G.ComponentesFuertementeConexas();
          }
          break;
        case 'p':
          clear();
          std::cout << "Lista de predecesores.\nGrafo cargado desde " << nombrefichero << std::endl;
          G.Mostrar_Listas(-1);
          pressanykey();
          break;
        case 'r':
          clear();
          std::cout << "Haciendo recorrido en profundidad:" << std::endl;
          G.RecorridoProfundidad();
          pressanykey();
          break;
        case 'm':
          clear();
          std::cout << "Haciendo recorrido en amplitud:" << std::endl;
          G.RecorridoAmplitud();
          pressanykey();
          break;
        case 'k':
          clear();
          std::cout << "Algoritmo de kruskal: " << std::endl << std::endl;
          G.kruskal();
          break;
        case 'd':
          clear();
          std::cout << "Algoritmo de caminos mínimos PDM" << std::endl << std::endl;
          G.PDM();
          break;
      }
    }
    while (opcion != 'q');
  }
  std::cout << "Fin del programa" << std::endl;
  return 0;
}
