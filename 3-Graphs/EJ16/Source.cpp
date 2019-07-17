#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "Kruskal.h"
using namespace std;

int solveCase(int islands);

int main() {
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int aux;
	int islands;
	cin >> islands;
	while (!cin.fail()) {
		aux = solveCase(islands);
		if (aux == -1) cout << "No hay puentes suficientes" << endl; // -1 es el código que determina que no hay puentes suficientes.
		else {
			cout << aux << endl;
		}
		cin >> islands;
	}
	
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif

	return 0;
}


// Para esta solución nos ayudamos de la clase Kruskal , la cual implementa su algoritmo.
// Para empezar recogemos todas las aristas en una cola de prioridad ordenadas de menor a mayor peso ,
// esto supone un tiempo de ejecución O(log E) siendo E el número total de aristas del grafo.
// Después para cada arista de la cola de prioridad empezamos a construir el camino mínimo de recubrimiento del grafo ( en este caso cada vértice es una isla ).
// Coste e en el número de aristas.
// En cada iteración borramos el elemento mas prioritario o(log e). en el número de aristas.
// Si al final no se ha llegado al mínimo de puentes que hipotéticamente unirían todas las islas se devuelve el centinela -1.
// Coste total O ( log(e) + e log(e) ) = O(e log(e)).

int solveCase(int islands) {
	GrafoValorado<int> graph(islands + 1);
	Kruskal algorithm;
	int bridges;
	int iA;
	int iB;
	int cost;


	// Recogia de datos.
	cin >> bridges;
	for (int i = 0; i < bridges; i++) {
		cin >> iA;
		cin >> iB;
		cin >> cost;
		Arista<int> e(iA,iB,cost);
		graph.ponArista(e); // Añadir aristas al grafo O(1).
		algorithm.addE(e); // Añadir aristas a la cola de prioridad O(long N) en el número de aristas.
		
	}

	return algorithm.minPath(graph);
}