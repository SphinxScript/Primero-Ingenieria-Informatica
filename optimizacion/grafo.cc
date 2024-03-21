 /*
 *  GRAFO.CPP - Plantilla para la implementación de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

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
        // leemos los m arcos
		for (k=0;k<m;k++)
        	{
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
			//damos los valores a dummy.j y dummy.c
			//situamos en la posición del nodo i a dummy mediante push_back
			//pendiente de hacer un segundo push_back si es no dirigido. O no.
			//pendiente la construcción de LP, si es dirigido
			//pendiente del valor a devolver en errorapertura
			//...
        }
    }

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

}

void GRAFO::Info_Grafo()
{

}

void Mostrar_Lista(vector<LA_nodo> L)
{

}

void GRAFO :: Mostrar_Listas (int l)
{

}

void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
{

}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
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
    vector<bool> visitado;      // inicializar vector de visita de nodos
    visitado.resize(n,false);

    vector<unsigned> prenum;    // inicializamos prenum y postnum
    prenum.resize(n,0); 
    unsigned prenum_ind{0};     // inicializamos os indices de prenum y postnum

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
    {   unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0;j<L[k].size();j++)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no está visitado
            {
            if((L[k].[j].j) == false) {
                visitado(L[k].[j].j) = true;
                pred[j] = k;
                cola.push(L[k][j].j);
                d(L[k][j].j) = d[k] + 1;
                //Lo visitamos
                //Lo metemos en la cola
                //le asignamos el predecesor
                //le calculamos su etiqueta distancia
            }

            };
        //Hemos terminado pues la cola está vacía
    };



}

void RecorridoAmplitud(); //Construye un recorrido en amplitud desde un nodo inicial
{
    unsigned i{0};
    std::cout << "nodo inicial introduzca: " << std::endl;
    std::cin >> (unsigned&)i;
    bfs_num(i-1,LS,pred,d); // recorrido amplitud realiza el recorrido en amplitud papu
    std::cout << "informacion almacenada en pred y d: " << std::endl;        // imprimir por pantalla la informacion almacenada en pred y d

    // IMPORTANTE: RECORDAR QUE HE RESTADO UNA UNIDAD EN CADA NODO
}