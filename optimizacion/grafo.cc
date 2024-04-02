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
	if (textfile.is_open()) {
        errorapertura = 0;
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);
        A.resize(n);
        LP.resize(n);
        /*if (dirigido == 1) {
            LP.resize(n); // si hay n nodos, la primera dimension de LS y LP tiene n espacios
        }*/
        // leemos los m arcos
		for (k = 0; k < m; k++)
        	{
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
			//damos los valores a dummy.j y dummy.c
			//situamos en la posición del nodo i a dummy mediante push_back
			//pendiente de hacer un segundo push_back si es no dirigido. O no.
			//pendiente la construcción de LP, si es dirigido
			//pendiente del valor a devolver en errorapertura
            dummy.j = j - 1;    // se resta 1 unidad ya que el nodo 1 esta en posicion 0, nodo 2 en posicion 1...
            if (dirigido == 1) {
                LS[i - 1].emplace_back(dummy); //colocamos en la lista (en posicion 0) el nodo sucesor y el coste
                dummy.j = i - 1;    // se cambia al nodo predecesor y se ajusta (i - 1)
                LP[j - 1].emplace_back(dummy);  // colocamos en la lista el nodo predecesor y el coste
            }
            else {
                LS[i - 1].emplace_back(dummy); //colocamos en la lista el nodo sucesor y el coste
                dummy.j = i - 1; // cambiamos al nodo predecesor y ajustamos
                LP[i - 1].emplace_back(dummy);
                //if (i != j) { // no se añade dos veces el mismo arco en caso de un bucle
                //    dummy.j = i - 1; // ajusta el indice del nodo origen para la dirección inversa
                //    LS[j - 1].emplace_back(dummy);
                //}
            }
        }
        textfile.close();
    }
    else {
        errorapertura = 1;
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
    return dirigido;
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
        //cout << "Tamaño fila: " << L[k].size() << endl; // prueba para el programador
        if (L[k].size() == 0) {
            cout << " : NULL";
        }
        for (int i{0}; i < L[k].size(); ++i) {
            cout << " : " << L[k][i].j << "(" << L[k][i].c << ") ";
        }
        cout << endl;
    }
}

void GRAFO::Mostrar_Listas (int l) {
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
void GRAFO::dfs_num(unsigned& i, vector<LA_nodo>& L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) {
    visitado[i] = true;
    prenum[prenum_ind] = i;
    prenum_ind++;
 // Asignar el orden de visita prenum al nodo i
    for (unsigned j{0}; j < L[i].size(); j++) {
        if (visitado[L[i][j].j] == false) {
            dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
        }
    }
    postnum[postnum_ind] = i;    // Asignar el orden de visita postnum al nodo i
    postnum_ind++;
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
    unsigned i;

    // solicitamos el nodo inicial al usuario por pantalla
    std::cout << " elige nodo de partida: " << "[1 - " << n << "]" << endl;

    // leer el nodo inicial introducido

    std::cin >> (unsigned&)i;
    --i;    // ajustamos el valor i

    //cout << i << "valor prueba "; test programador

    dfs_num(i,LS,visitado,prenum,prenum_ind,postnum,postnum_ind);

    // imprimimos por pantalla prenum y postnum
    cout << "Orden de visita en preorden: ";
    for (int k{0}; k < prenum_ind; ++k) {
        std::cout << "[" << prenum[k] + 1 << "]";
        if ((k + 1 != prenum_ind)) {
            cout << " -> ";
        }
    }
    std::cout << endl;
    cout << "Orden de visita en postorden: ";
    for (int k{0}; k < postnum_ind; ++k) {
        std::cout << "[" << postnum[k] + 1 << "]";
        if ((k + 1 != postnum_ind)) {
            cout << " -> ";
        }
    }
    std::cout << endl << endl;
    //cout << prenum << postnum << endl;

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
        
        if(pred[k] == i){ // Asignamos la distancia de los nodos respecto a la i, utilizando la lista de sucesores
            d[k] = 1;
            d[i] = -1; // El nodo inicial le ponemos distancia -1 para diferenciar de los que no tienen conexión que poseerían distancia 0

        } else {
            d[k] = d[(pred[k])] + 1; 
        }

        for (unsigned j=0;j<L[k].size();j++){
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no está visitado

            int vida = L[k][j].j;

            pred[vida] = k; // Asignamos su predecesor

            if(visitado[vida] != true){ // Si no está visitado lo añadimos a la cola
                cola.push(vida);
            }

            //Lo visitamos
            //Lo metemos en la cola
            //le asignamos el predecesor
            //le calculamos su etiqueta distancia

        }
        visitado[k] = true; // Lo ponemos como visitado

        //Hemos terminado pues la cola está vacía

    }

}

void GRAFO::RecorridoAmplitud(){ //Construye un recorrido en amplitud desde un nodo inicial
    int NodoInicial = 0;
    std::cout << "¿Elija nodo de partida? [1-" << n << "] ";
    std::cin >> NodoInicial;
    vector<unsigned> pred;
	vector<unsigned> d;
    NodoInicial = NodoInicial - 1;
    
    if(dirigido == 1){
        bfs_num(NodoInicial, LS, pred, d);
    } else {

        bfs_num(NodoInicial, A, pred, d);
    }
    

    // Nodos según distancia al nodo inicial en número de aristas

    int tam1 = d.size();
    int contador = 0;  // = d[tam1-1];
    for(int i = 0; i < tam1; i++){
        if(d[i] != 0 ){
            contador = d[i];
        }
    }
    std::cout << std::endl;


    std::cout << "Nodos según distancia al nodo inicial en número de aristas" << std::endl;
    for(int w = -1; w < contador+1; w++){ // Imprimimos las distancias
        //std::cout << " w vale " << w << std::endl;
        if(w == -1){ // El nodo inicial i
            std::cout << "Distancia " << 0 << " aristas";
        } else if(w == 0){ // Nodos que no conectan al nodo i
            std::cout;
        } else {
            std::cout << "Distancia " << w << " aristas";
        }

        for(int j = 0; j < tam1; j++){
            if(d[j] == w){
                if (w == 0){
                    std::cout;
                } else{
                    std::cout << " : " << j+1;
                }

            }
        }
        if (w == 0){
            std::cout;
        } else{
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl;
    std::cout << "Ramas de conexión en el recorrido" << std::endl;
    int b = 0, j;

    for(int i = 0; i < n; i++){
        j = i;
        if(d[i] == 0 || d[i] == -1){
            std::cout;
        } else {
            b = 0;
            vector<unsigned> predAlReves(pred.size());
            predAlReves[b] = pred[j];
            while(j != NodoInicial){ // Recorremos toda la lista de predecesores y lo metemos en el vector predAlReves

                j = pred[j];
                b++;
                predAlReves[b] = pred[j];
            }
        

            b = b -1;            
            for(int u = b; u >= 0; u = u - 1){
                std::cout << predAlReves[u]+1 << " - ";
            }
            
            std::cout << i+1 << std::endl; 

        }
    }



}
/*
void GRAFO::mostrar_nodospriv(vector<LA_nodo>& LS, vector<LA_nodo>& LP) {
    cout << "Información de nodos (LS): " << endl;
    for (int i{0}; i < n; ++i) {
        for (int k{0}; k < LS[i].size(); ++k) {
            cout << LS[i][k].j << " - ";
        }
    }
    cout << endl << "Información de nodos (LP): " << endl;
    for (int i{0}; i < n; ++i) {
        for (int k{0}; k < LP[i].size(); ++k) {
            cout << LP[i][k].j << " - ";
        }
    }
    cout << endl << endl;
}

void GRAFO::mostrar_nodos() {
    mostrar_nodospriv(LS, LP);
}

*/