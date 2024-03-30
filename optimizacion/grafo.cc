 /*
 *  GRAFO.CPP - Plantilla para la implementación de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"
using namespace std;

void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		A[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
	A.clear();

}

void GRAFO :: build (char nombrefichero[85], int &errorapertura)
{
    ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open())
    {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);
        A.resize(n);
        if (dirigido == 1) {
            LP.resize(n); // si hay n nodos, la primera dimension de LS y LP tiene n espacios
        }
        // leemos los m arcos
		for (k=0;k<m;k++)
        	{
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
			//damos los valores a dummy.j y dummy.c
			//situamos en la posición del nodo i a dummy mediante push_back
			//pendiente de hacer un segundo push_back si es no dirigido. O no.
			//pendiente la construcción de LP, si es dirigido
			//pendiente del valor a devolver en errorapertura
            dummy.j = j - 1;    // se resta 1 unidad ya que el nodo 1 esta en posicion 0, nodo 2 en posicion 1...
            if (dirigido == 0) {    // en caso de ser no dirigido, solo trabajamos con LS
                LS[i - 1].emplace_back(dummy);  // colocamos en la lista el elemento dummy (nodo sucesor y coste)
                dummy.j = i -1;     // movemos el nodo sucesor
                if ((i - 1) != (j - 1)) {
                    LS[j - 1].emplace_back(dummy); // colocamos en la lista el nodo sucesor y el coste.
                }
            }
            if (dirigido == 1) {
                LS[i - 1].push_back(dummy); //colocamos en la lista el nodo sucesor y el coste
                dummy.j = i - 1;    // se cambia el nodo predecesor
                LP[j - 1].emplace_back(dummy);  // colocamos en la lista el nodo predecesor y el coste
            }
        }
    }
    textfile.close();
}

GRAFO::~GRAFO()
{
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido()
{
    if (dirigido == 0) {
        return 0;
    }
    else return 1;
}

void GRAFO::Info_Grafo()
{
    cout << "El grafo tiene esta información: " << endl;
    cout << "Número de nodos: " << n << endl;
    cout << "Número de arcos: " << m << endl;
    cout << "¿Es dirigido?" << (dirigido == 1 ? " Si" : " No") << endl;
    cout << endl;
}

void Mostrar_Lista(vector<LA_nodo> L, unsigned& nodos)
{
    for (int k{0}; k < nodos; ++k) {
        cout << "[" << k + 1 << "]";
        if (L[k].size() == 0) {
            cout << " : NULL";
        }
        for (int i{0}; i < L[k].size(); ++i) {
            cout << " : " << L[k][i].j << "(" << L[k][i].c << ") ";
        }
        cout << endl;
    }
    //cout << endl;
    cout << L[0][0].j << endl << endl;
}

void GRAFO :: Mostrar_Listas (int l)
{
    if (l == 1 || l == 0) {
        Mostrar_Lista(LS, n); // lista adyacencia para grafos dirigidos y no dirigidos
    }
    if (l == -1) {
        Mostrar_Lista(LP, n); // lista de predecesores para grafos dirigidos
    }
}
/*
void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes NO HACER
{

}
*/
void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++] = i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j{0}; j<L[i].size(); ++j)
        if (!visitado[L[i][j].j]) {
            dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
        };
    postnum[postnum_ind++] = i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad()
{
    vector<bool> visitado;      // inicializar vector de visita de nodos
    visitado.resize(n,false);

    vector<unsigned> prenum;    // inicializamos prenum y postnum
    prenum.resize(n,0); 
    unsigned prenum_ind{0};     // inicializamos los indices de prenum y postnum
    vector<unsigned> postnum;
    postnum.resize(n,0);
    unsigned postnum_ind{0};

    // definimos la variable que almacena el nodo inicial a i
    unsigned i{0};

    // solicitamos el nodo inicial al usuario por pantalla
    std::cout << " elige nodo de partida: " << endl;

    // leer el nodo inicial introducido

    std::cin >> (unsigned&)i;

    dfs_num(i,LS,visitado,prenum,prenum_ind,postnum,postnum_ind);

    // imprimimos por pantalla prenum y postnum

}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construcción de pred y d: usamos la cola
{
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);
    visitado[i] = true;

    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1

    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y continúa hasta que la cola se vacíe
    {
        unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        if (pred[k] == i) {
            d[k] = 1;
            d[i] = -1;
        }
        else {
            d[k] = d[(pred[k])] + 1;
        }

        for (unsigned j{0}; j < L[k].size(); j++)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no está visitado
            {
            
            int vida = L[k][j].j;
            pred[vida] = k;

            if(visitado[vida] != true) {
                cola.push(vida);
                //Lo visitamos
                //Lo metemos en la cola
                //le asignamos el predecesor
                //le calculamos su etiqueta distancia
            }
            };
        visitado[k] = true;
        //Hemos terminado pues la cola está vacía
    };



}

void GRAFO::RecorridoAmplitud() //Construye un recorrido en amplitud desde un nodo inicial
{
    unsigned nodoinicial{0};
    std::cout << "nodo inicial introduzca: " << std::endl;
    std::cin >> (unsigned&)nodoinicial;
    vector<unsigned> pred;
        vector<unsigned> d;
    nodoinicial = nodoinicial - 1;

    if (dirigido == 1) {
        bfs_num(nodoinicial, LS, pred, d);
    }
    else {
        bfs_num(nodoinicial, A, pred, d);
    }

    int tam1 = d.size();
    int contador = 0;
    for (int i{0}; i < tam1; ++i) {
        if (d[i] != 0) {
            contador = d[i];
        }
    }
    cout << endl;

    std::cout << "Nodos según distancia al nodo inicial en número de aristas" << std::endl;
    for (int w{-1}; w < contador + 1; ++w) {
        if (w == -1) {
            cout << "Distancia " << 0 << " aristas";
        }
        else if (w == 0) {
            cout;
        }
        else {
            cout << "Distancia " << w << " aristas";
        }
        for (int j{0}; j < tam1; ++j) {
            if (d[j] == w) {
                cout;
            }
            else {
                cout << " : " <<j + 1;
            }
        }
        if (w == 0) {
            cout;
        }
        else {
            cout << endl;
        }
    }
    cout << endl;
    cout << "Ramas de conexión en el recorrido: " << endl;

    bfs_num(nodoinicial-1,LS,pred,d); // recorrido amplitud realiza el recorrido en amplitud papu
    cout << "informacion almacenada en pred y d: " << std::endl;        // imprimir por pantalla la informacion almacenada en pred y d

    // IMPORTANTE: RECORDAR QUE HE RESTADO UNA UNIDAD EN CADA NODO
}