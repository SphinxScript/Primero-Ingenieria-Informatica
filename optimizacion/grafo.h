#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <deque>

// using namespace std;

const unsigned UERROR = 65000;  // Para ciertos algoritmos es necesario codificar este valor de error
const int maxint = 1000000;       // Para ciertos algoritmos es necesario codificar este valor de máximo

// Definición de un elemento de la lista de adyacencia
typedef struct {
  unsigned j;  // nodo
  int c;       // atributo para expresar los costes, pesos, longitudes, inversiones, etc.
} ElementoLista;

typedef struct {
  unsigned extremo1, extremo2;
  int peso;
} AristaPesada;

// Definición del tipo de una lista de adyacencia de un nodo
typedef std::vector<ElementoLista> LA_nodo;

class GRAFO {
 public:
  GRAFO(const std::string &nombrefichero, int &errorapertura);
  void actualizar(const std::string &nombrefichero, int &errorapertura);
  unsigned Es_dirigido();
  void Info_Grafo();
  void Mostrar_Listas(int l);
  void Mostrar_Matriz();
  void RecorridoProfundidad();
  void RecorridoAmplitud();
  ~GRAFO();
  void mostrar_nodos();
  void kruskal();
  void mostrarcamino(unsigned s, int i, const std::vector<unsigned>& pred);
  void PDM();
  void ComponentesConexas();
  void ComponentesFuertementeConexas();

 private:
  unsigned dirigido;           // 0 si el grafo es no dirigido y 1 si es dirigido
  unsigned n;                  // número de nodos
  unsigned m;                  // número de arcos
  std::vector<LA_nodo> LS;          // Lista de adyacencia de los sucesores: cada fila puede tener distinto tamaño
  std::vector<LA_nodo> LP;          // Lista de adyacencia de los predecesores: cada fila puede tener distinto tamaño
  std::vector<LA_nodo> A;           // Matriz de adyacencia, tanto de adyacencia como de costes

  void destroy();  // Destructor de LS, A y LP, en su caso
  void build(const std::string &nombrefichero, int &errorapertura);  // Crea LS, A y LP, desde la lectura del fichero

  // Recorrido en profundidad recursivo con asignación de números de pre y postorden
  void dfs_num(unsigned &i, std::vector<LA_nodo>& L, std::vector<bool> &visitado, std::vector<unsigned> &prenum, unsigned &prenum_ind, std::vector<unsigned> &postnum, unsigned &postnum_ind);

  // Recorrido en amplitud con cálculo de predecesores y distancias
  void bfs_num(unsigned &i, std::vector<LA_nodo>& L, std::vector<unsigned> &pred, std::vector<int> &d);

  void mostrar_nodospriv(std::vector<LA_nodo>&, std::vector<LA_nodo>&);

  void dfs_cc(unsigned i, std::vector<bool> &visitado);    // Metodo que realiza el recorrido en profundidad para calcular las componentes conexas

  void dfs_postnum(unsigned i, std::vector<bool> &visitado, std::vector<unsigned> &postnum, unsigned &postnum_ind);
  void dfs_cfc(unsigned i, std::vector<bool> &visitado);
};

#endif