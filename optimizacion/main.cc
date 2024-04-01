 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"


void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{
    cout << "Optimiza!cion en Grafos, 2021-2022 NOMBRE DEL ESTUDIANTE" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    if (dirigido == 0) //Grafo no dirigido
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            //cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
            //cout << "y. Mostrar la matriz de adyacencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
            cout << "r. Realizar un [r]ecorrido en profundidad de un grafo desde un nodo" << endl;
	    //Aquí se añaden más opciones al menú del grafo no dirigido
            }
    else
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
            cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
            //cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo" << endl;
            cout << "r. Realizar un [r]ecorrido en profundidad del grafo" << endl;
            //cout << "d. caminos mínimos [d]ijkstra" << endl;
            //cout << "d. caminos mínimos" << endl;

	    //Aquí se añaden más opciones al menú del grafo dirigido
            };
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


void clear() {
  system("clear");
}

void pressanykey() {
  getchar();
}


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un menú inicial si no hay un grafo cargado
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;
    clear();
    //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
    if (argc > 1)
    {
	cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
    };
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
        pressanykey();
        clear();
    }
    else
    {
        cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
        pressanykey();
        clear();
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {
                case 'c' :
                    clear();
         	    cout << "Introduce el nombre completo del fichero de datos" << endl;
                    cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1)
                    {
                        cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
                    }
                    else
                    {
                        cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
                    };
                    pressanykey();
                    clear();
                    break;

                case 'i' :
                    clear();
		            cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    pressanykey();
                    //clear();
                    break;

                case 's' :
                    clear();
                    cout << "Lista de sucesores.\nGrafo cargado desde: " << nombrefichero << endl;
                    G.Mostrar_Listas(1);
                    pressanykey();
                    break;
                case 'p' :
                    clear();
                    cout << "Lista de predecesores.\nGrafo cargado desde " << nombrefichero << endl;
                    G.Mostrar_Listas(-1);
                    pressanykey;
                    break;
                
                case 'r' :
                    clear();
                    cout << "Haciendo recorrido en profundidad:" << endl;
                    G.RecorridoProfundidad();
                    pressanykey();
                    break;

                case 'm' :
                    clear();
                    cout << "Haciendo recorrido en amplitud:\n";
                    G.RecorridoAmplitud();
                    pressanykey();
                    break;
            }
    }
    while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};