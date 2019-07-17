#include <iostream>
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
using namespace std;


class Kruskal {
private:
	queue <Arista<int>> _Q; // Cola simple para recoger el camino.
	PriorityQueue<Arista<int>> _minQ; // Aristas ordenadas de menor a mayor.
	int _minPathCost; // Suma total del peso del camino m�nimo.

public:
	// Funci�n para a�adir las aristas a la cola de prioridad coste O(log N) en el n�mero de aristas.
	void addE(const Arista<int> &e) {
		_minQ.push(e);
	}


	int minPath(const GrafoValorado<int> &graph) {
		int v;
		int w;
		ConjuntosDisjuntos uf(graph.V() + 1); // Creo una partici�n del tama�o de los v�rtices del grafo.
		_minPathCost = 0;
		// Mientras no haya vaciado la cola de prioridad de aristas o
		// la cola del cam�no m�nimo actual no tenga m�s aristas que v�rtices posibles ( menos el inicial ).
		while (!_minQ.empty() && _Q.size() < graph.V() - 1) { 
			// Cojo la arista de coste m�nimo.
			Arista<int> e = _minQ.top();
			v = e.uno();
			w = e.otro(v);
			if (!(uf.buscar(v) == uf.buscar(w))) { // Si no est�n en el mismo grupo las uno. Coste amortizado constante.
				uf.unir(v, w); // Coste amortizado constante.
				_Q.push(e); // Introduzco la arista en la cola de m�nmo. O(1) al ser una cola simple.
				_minPathCost += e.valor(); // Sumo el coste de la arista introducida.
			}
			_minQ.pop(); // Paso a la siguiente arista de coste m�nimo.
		}
		if (_Q.size() < graph.V() -2) _minPathCost = -1; // Si no hay aristas suficientes para recorrer todo el grafo..
		return _minPathCost;
	}

};