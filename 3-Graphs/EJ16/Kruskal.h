#include <iostream>
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
using namespace std;


class Kruskal {
private:
	queue <Arista<int>> _Q; // Cola simple para recoger el camino.
	PriorityQueue<Arista<int>> _minQ; // Aristas ordenadas de menor a mayor.
	int _minPathCost; // Suma total del peso del camino mínimo.

public:
	// Función para añadir las aristas a la cola de prioridad coste O(log N) en el número de aristas.
	void addE(const Arista<int> &e) {
		_minQ.push(e);
	}


	int minPath(const GrafoValorado<int> &graph) {
		int v;
		int w;
		ConjuntosDisjuntos uf(graph.V() + 1); // Creo una partición del tamaño de los vértices del grafo.
		_minPathCost = 0;
		// Mientras no haya vaciado la cola de prioridad de aristas o
		// la cola del camíno mínimo actual no tenga más aristas que vértices posibles ( menos el inicial ).
		while (!_minQ.empty() && _Q.size() < graph.V() - 1) { 
			// Cojo la arista de coste mínimo.
			Arista<int> e = _minQ.top();
			v = e.uno();
			w = e.otro(v);
			if (!(uf.buscar(v) == uf.buscar(w))) { // Si no están en el mismo grupo las uno. Coste amortizado constante.
				uf.unir(v, w); // Coste amortizado constante.
				_Q.push(e); // Introduzco la arista en la cola de mínmo. O(1) al ser una cola simple.
				_minPathCost += e.valor(); // Sumo el coste de la arista introducida.
			}
			_minQ.pop(); // Paso a la siguiente arista de coste mínimo.
		}
		if (_Q.size() < graph.V() -2) _minPathCost = -1; // Si no hay aristas suficientes para recorrer todo el grafo..
		return _minPathCost;
	}

};