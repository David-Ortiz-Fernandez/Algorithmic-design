// DA19 Andrés Ortiz - David Ortiz 


#include <iostream>
#include "GrafoDirigidoValorado.h"
#include <fstream>
#include "Dijkstra.h"
#include <queue>
using namespace std;

int solveCase(int cases);

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int cases;
	int weight;
	cin >> cases;
	while (cases != 0) {

		weight = solveCase(cases);
		if (weight < 0) cout << "IMPOSIBLE" << endl;
		else {
			cout << weight << endl;
		}
		cin >> cases;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif


	return 0;
}


// Para cada vértice encontrar el camino de mayor peso , si recorro todos los vértices
// al almacenarlo en la cola de prioridad y quedarme con el menor consigo complejidad O( log V ) en el número de vértices.
// Sin embargo al actualizar la lista de distancias a cada vértice puede que tenga que pasar por todas las aristas para encontrar el
// mejor camino.  O ( E Log V ) siendo E el número total de aristas y V el de los vértices.
// Estructuras de datos usadas : GrafoDirigido , Cola de prioridades de mínimos para valorar el camino más corto desde el principio.
int solveCase(int cases) {
	GrafoDirigidoValorado<int> graph(cases + 1);
	int links;
	int  *loadTime = new int[cases];
	// Inicializamos los tiempos de carga de caga página.
	for (int i = 0; i < cases; i++) {
		cin >> loadTime[i];
	}
	int v1;
	int v2;
	int value;

	cin >> links;

	// Recogemos el grafo y sumamos los tiempos de carga de cada página.
	// Menos de la primera que la sumaremos al final.
	for (int i = 0; i < links; i++) {
		cin >> v1;
		cin >> v2;
		cin >> value;
		value += loadTime[v2 - 1];
		AristaDirigida<int> a(v1, v2, value); // Añadir aristas en una cola O ( 1 ) .
		graph.ponArista(a);
	}

	// Pásamos el grafo por argumento y el tiempo
	// de carga de la página 1 , que se sumará al final 
	Dijkstra algorithm(graph,loadTime[0]);
	


	delete[] loadTime;
	return algorithm.weight();
}