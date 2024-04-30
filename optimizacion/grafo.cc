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
  for (unsigned i=0; i< n; i++)
    {
    LS[i].clear();
    A[i].clear();
    if (dirigido == 1) {
      LP[i].clear();
    };
  }
  LS.clear();
  LP.clear();
  A.clear();

}

void GRAFO::build(char nombrefichero[85], int &errorapertura){
  if (errorapertura == 1) {
    cout << "Error de apertura. Fin de programa" << endl;
    EXIT_FAILURE;
  }
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if(textfile.is_open()) {
    unsigned i, j, k;
    // leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
    textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
    // los nodos internamente se numeran desde 0 a n-1
    // creamos las n listas de sucesores
    LS.resize(n);
    A.resize(n);
    if(dirigido == 1)
      LP.resize(n); // Si tenemos n nodos, la primera dimensión de LS y LP debe tener n espacios
          // leemos los m arcos
    for (k=0;k<m;k++) {
      textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
      //damos los valores a dummy.j y dummy.c
      //situamos en la posicion del nodo i a dummy mediante push_backM
      //pendiente de hacer un segundo push_back si es no dirigido. O no.
      //pendiente la construccion de LP, si es dirigido
      //pendiente del valor a devolver en errorapertura
      dummy.j = j - 1; // resto a j una unidad, para tener el nodo 1, en la posición cero, el 2 en la 1, etc...
      if(dirigido == 0) // Si es no dirigido, solo tenemos que trabajar con LS
      {
        LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1; // Asignamos el valor del nodo predecesor
        if((i-1) != (j-1)) {
          LS[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo que le precede, y el coste del camino
          // Como es un grafo no dirigido, se ponen todos los datos en LS pero reflejados con la diagonal principal
        }
      }
      if(dirigido == 1) // No pongo un else, por si hay acaso, dirigido != 0 y dirigido !=1
      {
        LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1; // Asignamos el valor del nodo predecesor
        LP[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LP, el nodo que le precede, y el coste del camino
        // Como es un grafo dirigido, usamos LP para colocar este dato
        
      }
    }
  }
  textfile.close();
}

//void GRAFO::ListaPredecesores(){}

GRAFO::~GRAFO() { destroy();}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) { build (nombrefichero, errorapertura); }

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {
  //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
  destroy();
  //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() { return dirigido; }

void GRAFO::Info_Grafo() {
  cout << endl << "El Grafo cargado actualmente tiene las siguiente características:" << endl;
  cout << "Nº de Nodos: " << n << endl;
  cout << "Nº de Arcos: " << m << endl;
  cout << "¿Grafo Dirigido? " << (dirigido == 1 ? " Si" : " No");
  cout << endl << endl;
}

void Mostrar_Lista(const vector<LA_nodo>& L, unsigned& nodos) {
  for(int i{0}; i < nodos; ++i) {
    cout << "[" << i + 1 << "]";
    if(L[i].size() == 0) 
      cout << " : NULL";
    for(int k{0}; k < L[i].size(); ++k) {
      cout << " :  " << L[i][k].j + 1 << "(" << L[i][k].c << ") ";
    }
    cout << endl;
  }
  //cout << L[0][0].j << endl;
  cout << endl;
}

void GRAFO::Mostrar_Listas(int l) {
  if(l == 1 || l == 0)
    Mostrar_Lista(LS, n); // Para Grafos Dirigidos y No Dirigidos   
  if(l == -1)
    Mostrar_Lista(LP, n); // Para Grafos Dirigidos
}






void GRAFO::dfs_num(unsigned& i, vector<LA_nodo>&  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j=0;j<L[i].size();j++)
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}


void GRAFO::RecorridoProfundidad()
{
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
    cin >> (unsigned&) i;
    cout << endl;
    
    --i;
    dfs_num(i, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);

    //Mostrar prenum
    cout << "Orden de visita de los nodos en preorden\n";
    for(int i{0}; i < prenum_ind; ++i) {
        cout << '[' << prenum[i] + 1 << ']';
        if (!(i + 1 == prenum_ind)) {
            cout << " -> ";
        }
    }
    cout << endl << endl;
    //Mostrar postnum
    cout << "Orden de visita de los nodos en postorden\n";
    for(int i{0}; i < postnum_ind; ++i) {
        cout << '[' << postnum[i] + 1 << ']';
        if (!(i + 1 == postnum_ind)) {
            cout << " -> ";
        }
    }
    cout << endl << endl;
}





void GRAFO::bfs_num(unsigned& i, vector<LA_nodo>& L, vector<unsigned> &pred, vector<int> &d) {
  vector<bool> visitado; // Vector de visitados
  visitado.resize(n, false);
  visitado[i] = true;

  pred.resize(n, 0); // Vector de predecesores y distancia
  d.resize(n, 0);
  pred[i] = i;
  d[i] = 0;

  queue<unsigned> cola; // Cola de nodos
  cola.push(i); // Inicializamos la cola con el nodo inicial

  while (!cola.empty()) { // Mientras la cola no esté vacía
    unsigned k = cola.front(); // Tomamos el primer elemento de la cola
    cola.pop(); // Lo sacamos de la cola
    for (unsigned j{0}; j < L[k].size(); ++j) { // Recorremos los nodos adyacentes a k+1
      if(visitado[L[k][j].j] == false) { // Si no ha sido visitado
        visitado[L[k][j].j] = true;   // Lo visitamos
        cola.push(L[k][j].j);         // Lo metemos en la cola
        pred[L[k][j].j] = k;          // Le asignamos predecesores
        d[L[k][j].j] = d[k] + 1;      // Le calculamos la distancia
      }
    }
  }
}

void GRAFO::RecorridoAmplitud() {
  vector<unsigned> pred;    // Declaramos el vector de nodos predecesores, la posición es el vector actual, y el número que contiene es su predecesor
  vector<int> d;       // Declaramos el vector de etiquetas distancia, la posición es el nodo, y el número que contenga, es la distancia del nodo elegido por el usuario
  unsigned nodo_inicial{0};

  cout << endl << "Elige el nodo inicial en el rango [1 - " << n << "]: ";
  cin >> nodo_inicial;

  while (nodo_inicial < 1 || nodo_inicial > n){
    cout << "El nodo elegido no está en el rango [1 - " << n << "], elige otro: ";
    cin >> nodo_inicial;
  }
  
  cout << "Nodo inicial elegido: [" << nodo_inicial << "]" << endl << endl;

  --nodo_inicial;
  bfs_num(nodo_inicial, LS, pred, d);
  cout << "Distancia entre el nodo inicial y el resto, expresado en el número de arcos:" << endl << endl;

  for(int i{0}; i < d.size(); ++i) { // Recorremos el vector de distancias para mostrar los nodos a distancia i
    cout << "[" << i + 1 << "] : " << d[i];
    cout << endl;
  }

  // Mostramos los predecesores
  cout << endl << "Predecesores de cada nodo" << endl << endl;
  for(int i{0}; i < pred.size(); ++i) {
    cout << "Predecesor de " << i + 1 << " : ";
      cout << pred[i] + 1 << endl;
  }
  cout << endl;
}

void GRAFO::kruskal() {
  unsigned q = 0;
  int pesoMST = 0;
  //Cargamos todas las aristas de la lista de adyacencia
  std::vector<AristaPesada> Aristas;
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

  // ordenamos el vector aristas
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

  //Inicializamos el registro de componentes conexas: cada nodo está en
  //su componente conexa
  std::vector<unsigned> Raiz;
  Raiz.resize(n);
  for (unsigned q = 0; q < n; q++) {
    Raiz[q] = q;
  }

  // a partir de aqui el codigo no esta en el guion
  vector<AristaPesada> T;     // declaro un vector de AristaPesada T
  int primer_elemento{0};            // inicio un contador primer_elemento a 0
  int contador{0};                   // inicio un contador a 0
  AristaPesada arista;        // declaro un elemento arista de tipo AristaPesada
  while(contador < (n - 1) && primer_elemento < m) {
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

  // en caso de siempre aplicar kruskal a pesar de ser no conexo, se comentan las lineas del else

  ///*
  if (contador != (n - 1)) {
    cout << "Grafo no conexo. No tiene árbol generador." << endl << endl;
  }
  //*/

  else {
    for (int i{0}; i < T.size(); ++i) {
      cout << "Arista numero " << i + 1 << " incorporada: (" << T[i].extremo1 + 1 << "," << T[i].extremo2 + 1 << "), con peso " << T[i].peso << endl;
    }
    cout << endl << "El peso del árbol generador de mínimo coste es: " << pesoMST << endl << endl;
  }
}


void GRAFO::mostrarcamino(unsigned s, int i, const vector<unsigned>& pred) {
  if (pred[i] == UERROR) {
    std::cout << "No hay camino desde el nodo " << s + 1 << " hasta el nodo " << i + 1;
    return;
  }
  if (i != s) {
    mostrarcamino(s,pred[i],pred);
    std::cout << " -> " << i + 1;
  }
  else {
    std::cout << i + 1;
    return;
  }
}


void GRAFO::PDM() {
  deque<unsigned> dcola;
  vector<int> d;
  vector<unsigned> pred;
  vector<bool> Encola;
  unsigned s;

  Encola.resize (n, false);
  d.resize (n, maxint);
  pred.resize (n, UERROR);

  std::cout << "Escoja nodo de partida: (1 - " << n << ") " << endl;
  std::cin >> s;
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
  std::cout << "soluciones: \n\n";
  for (unsigned i{0}; i < n; ++i) {
    cout << "Nodo" << i + 1 << ": ";
    mostrarcamino(s, i, pred);
    cout << ".   Distancia: " << d[i];
    std::cout << std::endl << endl;
  }
  //std::cout << endl;
}
