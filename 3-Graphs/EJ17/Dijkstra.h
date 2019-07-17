// DA19 . David Ortiz , Andrés Ortiz.

#include <iostream>
#include "GrafoDirigidoValorado.h"
#include "PriorityQueue.h"
#include <queue>
#include <climits>
using namespace std;


// First es el vértice adyacente y second el peso de la arista.
#define Node pair<int,int>

class Dijkstra {
private:

	// Comparador que devuelve la arista de menos peso.
	struct cmp {
		bool operator() (const Node &a, const Node &b) {
			return a.second < b.second;
		}
	};

	int _v; // Número de vértices de la arista.
	int *_distTo; // Distancia a cada vértice desde el vértice inicial.
	bool *_visited; // Array de booleanos para los vértices visitados.
	PriorityQueue<Node, cmp> Q; // Cola de mínimos adyacentes.
	int finalWeight; // Peso a retornar desde el vértice adyacente al N-1.
	

	// Actualiza la distancia desde el vértice el vértice actual hasta el adyacente
	// si este mejora el coste anterior.
	void relax(int current, int ady, int weight) {

		// Si la distancia actual + el peso de la arista es menor a la adyacente actualizamos.
		if (_distTo[current] + weight < _distTo[ady]) {
			_distTo[ady] = _distTo[current] + weight; 
			//cout << current << " - " << ady << " Value:" << _distTo[ady] << endl;
			Node a; a.first = ady; a.second = _distTo[ady];
			Q.push(a);
		}
	}
public:

	Dijkstra(const GrafoDirigidoValorado<int> &graph,int plusWeight) {
		_v = graph.V(); // Número de vértices del grafo.
		_distTo = new int[_v]; // Distancia desde el vértice inicial al resto.
		_visited = new bool[_v]; // Array booleano de visitados.

		// No cuento este tiempo en la complejidad al entender que es un preprocesado de datos
		// y no afecta a la complejidad del algoritmo.
		for (int i = 0; i < _v; i++) {
			_distTo[i] = INT_MAX; // Al actualizar bastará con que la distancia sea menor que INT_MAX.
			_visited[i] = false; // Visitados todos a false inicialmente.

		}

		_distTo[1] = 0; // Distancia del vértice 1 al 1 = 0.
		Q.push(Node(1, 0)); // Metemos en la cola el vértice 1 con su peso.

		int current; // vértice actual.
		int ady; // vértice adyacente.
		int weight; // Peso de la arista del vértice actual al adyacente.


		// Mientras que la cola no esté vacía..
		while (!Q.empty()) {
			
			current = Q.top().first; // Pillamos el primer vértice con su peso.
			Q.pop(); // Lo sacamos.
			if (!_visited[current]) { // si no está visitado entramos para mirar los adyacentes.
				_visited[current] = true;  // Lo marcamos como visitado.
				for (int i = 0; i < graph.adj(current).size(); i++) { // Recorremos toda su lista de adyacentes.
					ady = graph.adj(current)[i].to(); // Cogemos el primer adyacente.
					weight = graph.adj(current)[i].valor(); // Cogemos su peso.
					if (!_visited[ady]) { // Si el adyacente no ha sido visitado.
						relax(current, ady, weight); // actualizamos el camino.
					}
				 }
			 }	
		 }

		finalWeight = _distTo[_v - 1]+plusWeight; // Añadimos el peso del primer vértice ( cargar la primera página ).

		// Liberamos memoria.
		delete[] _distTo; 
		delete[] _visited;
	}

	int weight() {
		return finalWeight;
	}
};
