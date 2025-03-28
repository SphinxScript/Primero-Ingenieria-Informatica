/*
*  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
*
*
*  Autores : Antonio Sedeno Noda, Sergio Alonso
*  Cursos   : 2012-2021
*/

#include "grafo.h"
#include <stack>

void GRAFO::destroy() {
  for (unsigned i = 0; i < n; i++) {
    LS[i].clear();
    A[i].clear();
    if (dirigido == 1) {
      LP[i].clear();
    }
  }
  LS.clear();
  LP.clear();
  A.clear();
}

void GRAFO::build(char nombrefichero[85], int &errorapertura) {
  if (errorapertura == 1) {
    cout << "Error de apertura. Fin de programa" << endl;
    EXIT_FAILURE;
  }
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if (textfile.is_open()) {
    unsigned i, j, k;
    // Leemos por conversión implícita el número de nodos, arcos y el atributo dirigido
    textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;
    // Los nodos internamente se numeran desde 0 a n-1
    // Creamos las n listas de sucesores
    LS.resize(n);
    A.resize(n);
    if (dirigido == 1)
      LP.resize(n);  // Si tenemos n nodos, la primera dimensión de LS y LP debe tener n espacios
    // Leemos los m arcos
    for (k = 0; k < m; k++) {
      textfile >> (unsigned &)i >> (unsigned &)j >> (int &)dummy.c;
      // Damos los valores a dummy.j y dummy.c
      // Situamos en la posición del nodo i a dummy mediante push_back
      // Pendiente de hacer un segundo push_back si es no dirigido. O no.
      // Pendiente la construcción de LP, si es dirigido
      // Pendiente del valor a devolver en errorapertura
      dummy.j = j - 1;  // Resto a j una unidad, para tener el nodo 1 en la posición cero, el 2 en la 1, etc...
      if (dirigido == 0) {  // Si es no dirigido, solo trabajamos con LS
        LS[i - 1].emplace_back(dummy);  // Colocamos en la fila del nodo correspondiente en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1;  // Asignamos el valor del nodo predecesor
        if ((i - 1) != (j - 1)) {
          LS[j - 1].emplace_back(dummy);  // Colocamos en la fila del nodo correspondiente en LS, el nodo que le precede, y el coste del camino
          // Como es un grafo no dirigido, se ponen todos los datos en LS pero reflejados en la diagonal principal
        }
      }
      if (dirigido == 1) {  // No pongo un else, por si acaso dirigido != 0 y dirigido != 1
        LS[i - 1].emplace_back(dummy);  // Colocamos en la fila del nodo correspondiente en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1;  // Asignamos el valor del nodo predecesor
        LP[j - 1].emplace_back(dummy);  // Colocamos en la fila del nodo correspondiente en LP, el nodo que le precede, y el coste del camino
        // Como es un grafo dirigido, usamos LP para colocar este dato
      }
    }
  }
  textfile.close();
}

// void GRAFO::ListaPredecesores(){}

GRAFO::~GRAFO() { destroy(); }

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
  build(nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {
  // Limpiamos la memoria dinámica asumida en la carga previa, como en el destructor
  destroy();
  // Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() { return dirigido; }

void GRAFO::Info_Grafo() {
  cout << endl << "El Grafo cargado actualmente tiene las siguientes características:" << endl;
  cout << "Nº de Nodos: " << n << endl;
  cout << "Nº de Arcos: " << m << endl;
  cout << "¿Grafo Dirigido? " << (dirigido == 1 ? " Si" : " No");
  cout << endl << endl;
}

void Mostrar_Lista(const vector<LA_nodo>& L, unsigned &nodos) {
  for (int i{0}; i < nodos; ++i) {
    cout << "[" << i + 1 << "]";
    if (L[i].size() == 0)
      cout << " : NULL";
    for (int k{0}; k < L[i].size(); ++k) {
      cout << " :  " << L[i][k].j + 1 << "(" << L[i][k].c << ") ";
    }
    cout << endl;
  }
  // cout << L[0][0].j << endl;
  cout << endl;
}

void GRAFO::Mostrar_Listas(int l) {
  if (l == 1 || l == 0)
    Mostrar_Lista(LS, n);  // Para Grafos Dirigidos y No Dirigidos
  if (l == -1)
    Mostrar_Lista(LP, n);  // Para Grafos Dirigidos
}

void GRAFO::dfs_num(unsigned &i, vector<LA_nodo>& L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) {
  visitado[i] = true;
  prenum[prenum_ind++] = i;  // Asignamos el orden de visita prenum que corresponde al nodo i
  for (unsigned j = 0; j < L[i].size(); j++) {
    if (!visitado[L[i][j].j]) {
      dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
    }
  }
  postnum[postnum_ind++] = i;  // Asignamos el orden de visita postnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad() {
  vector<bool> visitado;
  visitado.resize(n, false);

  vector<unsigned> prenum;
  prenum.resize(n, 0);
  vector<unsigned> postnum;
  postnum.resize(n, 0);

  unsigned prenum_ind = 0;
  unsigned postnum_ind = 0;

  unsigned i;
  cout << "Elige un nodo de partida [1-" << n << "]: ";
  cin >> (unsigned &)i;
  cout << endl;

  --i;
  dfs_num(i, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);

  // Mostrar prenum
  cout << "Orden de visita de los nodos en preorden\n";
  for (int i{0}; i < prenum_ind; ++i) {
    cout << '[' << prenum[i] + 1 << ']';
    if (!(i + 1 == prenum_ind)) {
      cout << " -> ";
    }
  }
  cout << endl << endl;
  // Mostrar postnum
  cout << "Orden de visita de los nodos en postorden\n";
  for (int i{0}; i < postnum_ind; ++i) {
    cout << '[' << postnum[i] + 1 << ']';
    if (!(i + 1 == postnum_ind)) {
      cout << " -> ";
    }
  }
  cout << endl << endl;
}

void GRAFO::bfs_num(unsigned &i, vector<LA_nodo>& L, vector<unsigned> &pred,
                    vector<int> &d) {
  vector<bool> visitado;  // Vector de visitados
  visitado.resize(n, false);
  visitado[i] = true;

  pred.resize(n, 0);  // Vector de predecesores y distancias
  d.resize(n, 0);
  pred[i] = i;
  d[i] = 0;

  queue<unsigned> cola;  // Cola de nodos
  cola.push(i);  // Inicializamos la cola con el nodo inicial

  while (!cola.empty()) {
    // Mientras la cola no esté vacía
    unsigned k = cola.front();  // Tomamos el primer elemento de la cola
    cola.pop();  // Lo sacamos de la cola
    for (unsigned j{0}; j < L[k].size(); ++j) {
      if (visitado[L[k][j].j] == false) {  // Si no ha sido visitado
        visitado[L[k][j].j] = true;   // Lo visitamos
        cola.push(L[k][j].j);         // Lo metemos en la cola
        pred[L[k][j].j] = k;          // Asignamos su predecesor
        d[L[k][j].j] = d[k] + 1;      // Calculamos su distancia
      }
    }
  }
}

void GRAFO::RecorridoAmplitud() {
  vector<unsigned> pred;  // Vector de nodos predecesores
  vector<int> d;          // Vector de distancias
  unsigned nodo_inicial{0};

  cout << endl << "Elige el nodo inicial en el rango [1 - " << n << "]: ";
  cin >> nodo_inicial;
  while (nodo_inicial < 1 || nodo_inicial > n) {
    cout << "El nodo elegido no está en el rango [1 - " << n << "], elige otro: ";
    cin >> nodo_inicial;
  }
  cout << "Nodo inicial elegido: [" << nodo_inicial << "]" << endl << endl;
  --nodo_inicial;
  bfs_num(nodo_inicial, LS, pred, d);
  cout << "Distancia entre el nodo inicial y el resto, expresada en número de arcos:" << endl << endl;
  for (int i{0}; i < d.size(); ++i) {
    cout << "[" << i + 1 << "] : " << d[i] << endl;
  }
  // Mostrar los predecesores
  cout << endl << "Predecesores de cada nodo" << endl << endl;
  for (int i{0}; i < pred.size(); ++i) {
    cout << "Predecesor de " << i + 1 << " : " << pred[i] + 1 << endl;
  }
  cout << endl;
}

void GRAFO::kruskal() {
  unsigned q = 0;
  int pesoMST = 0;
  // Cargamos todas las aristas de la lista de adyacencia
  vector<AristaPesada> Aristas;
  Aristas.resize(m);
  unsigned k = 0;
  for (unsigned i = 0; i < n; i++) {
    for (unsigned j = 0; j < LS[i].size(); j++) {
      if (i < LS[i][j].j) {
        Aristas[k].extremo1 = i;
        Aristas[k].extremo2 = LS[i][j].j;
        Aristas[k++].peso = LS[i][j].c;
      }
    }
  }

  // Ordenamos el vector de aristas
  AristaPesada aux;
  for (int k{0}; k < Aristas.size(); ++k) {
    for (int i{0}; i < Aristas.size(); ++i) {
      if (Aristas[i].peso > Aristas[k].peso) {
        aux = Aristas[k];
        Aristas[k] = Aristas[i];
        Aristas[i] = aux;
      }
    }
  }

  // Inicializamos el registro de componentes conexas: cada nodo está en su propia componente
  vector<unsigned> Raiz;
  Raiz.resize(n);
  for (unsigned q = 0; q < n; q++) {
    Raiz[q] = q;
  }

  // A partir de aquí el código no está en el guion
  vector<AristaPesada> T;  // Declaro un vector de AristaPesada T
  int primer_elemento{0};  // Contador para el primer elemento
  int contador{0};         // Contador de aristas añadidas
  AristaPesada arista;     // Declaramos un elemento arista de tipo AristaPesada
  while (contador < (n - 1) && primer_elemento < m) {
    if (Raiz[Aristas[primer_elemento].extremo1] != Raiz[Aristas[primer_elemento].extremo2]) {
      int kill = Raiz[Aristas[primer_elemento].extremo1];
      for (int k{0}; k < n; ++k) {
        if (Raiz[k] == kill) {
          Raiz[k] = Raiz[Aristas[primer_elemento].extremo2];
        }
      }
      ++contador;
      arista.extremo1 = Aristas[primer_elemento].extremo1;
      arista.extremo2 = Aristas[primer_elemento].extremo2;
      arista.peso = Aristas[primer_elemento].peso;
      T.push_back(arista);
      pesoMST += Aristas[primer_elemento].peso;
    }
    primer_elemento++;
  }

  if (contador != (n - 1)) {
    cout << "Grafo no conexo. No tiene árbol generador." << endl << endl;
  }
  else {
    for (int i{0}; i < T.size(); ++i) {
      cout << "Arista número " << i + 1 << " incorporada: (" << T[i].extremo1 + 1 << "," << T[i].extremo2 + 1 << "), con peso " << T[i].peso << endl;
    }
    cout << endl << "El peso del árbol generador de mínimo coste es: " << pesoMST << endl << endl;
  }
}

void GRAFO::mostrarcamino(unsigned s, int i, const vector<unsigned>& pred) {
  if (pred[i] == UERROR) {
    cout << "No hay camino desde el nodo " << s + 1 << " hasta el nodo " << i + 1;
    return;
  }
  if (i != s) {
    mostrarcamino(s, pred[i], pred);
    cout << " -> " << i + 1;
  }
  else {
    cout << i + 1;
    return;
  }
}

void GRAFO::PDM() {
  deque<unsigned> dcola;
  vector<int> d;
  vector<unsigned> pred;
  vector<bool> Encola;
  unsigned s;

  Encola.resize(n, false);
  d.resize(n, maxint);
  pred.resize(n, UERROR);

  cout << "Escoja nodo de partida: (1 - " << n << ") " << endl;
  cin >> s;
  cout << endl;
  s--;
  d[s] = 0;
  pred[s] = s;

  dcola.push_back(s);
  Encola[s] = true;

  while (!dcola.empty()) {
    int k = dcola.front();
    dcola.pop_front();
    Encola[k] = false;
    for (int j{0}; j < LS[k].size(); ++j) {
      if (d[LS[k][j].j] > d[k] + LS[k][j].c) {
        if (pred[LS[k][j].j] == 0) {
          dcola.push_back(LS[k][j].j);
        }
        else {
          if (Encola[LS[k][j].j] == false) {
            dcola.push_front(LS[k][j].j);
          }
        }
        d[LS[k][j].j] = d[k] + LS[k][j].c;
        pred[LS[k][j].j] = k;
        Encola[LS[k][j].j] = true;
      }
    }
  }
  cout << "soluciones: \n\n";
  for (unsigned i{0}; i < n; ++i) {
    cout << "Nodo" << i + 1 << ": ";
    mostrarcamino(s, i, pred);
    cout << ". Distancia: " << d[i];
    cout << endl << endl;
  }
}

void GRAFO::dfs_cc(unsigned i, vector<bool> &visitado) {     // Recorrido en profundidad para calcular componentes conexas
  visitado[i] = true;
  cout << i + 1;
  for (unsigned j{0}; j < LS[i].size(); ++j) {
    if (!visitado[LS[i][j].j]) {
      cout << ", ";
      dfs_cc(LS[i][j].j, visitado);
    }
  }
}

void GRAFO::ComponentesConexas() {        // metodo para imprimir las componentes conexas y llamar a dfs_cc
  unsigned componentesconexas{0};
  vector<bool> visitado;
  visitado.resize(n,false);
  for (int i{0}; i < n; ++i) {
    if (!visitado[i]) {
      componentesconexas++;
      std::cout << "componente Conexa" << componentesconexas << " : { ";
      dfs_cc(i, visitado);
      std::cout << " }" << std::endl;
    }
  }  
}