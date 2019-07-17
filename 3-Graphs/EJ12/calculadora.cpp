// DA19 , David Ortiz - Andrés Ortiz.
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"

using namespace std;
// El coste del algoritmo solveCase sería O(V+E), donde V es el numero de elementos a tratar segun la entrada, es decir la
//diferencia entre el maximo y el minimo, y E es el número de aristas que saldrian del posible grafo que en este caso es 3 por 
//cada vertice
void solveCase(int origin, int final);
/***********************************************************************************************************/
class calculatorPath {
public:
	calculatorPath()
		: marked(10000, false), distTo(10000) {
		
	}

	// Hay camino del origen a v?----------------------------------------------------------------------------
	bool hasPathTo(size_t v) const {
		return marked.at(v); //como hacer marked[v]
	}

	// Devuelve el camino más corto desde el origen a v (vacío si no están conectados).----------------------
	/*Path pathTo(size_t v) const {

		Path path;
		if (!hasPathTo(v)) return path;
		for (auto x = v; x != s; x = edgeTo[x])
			path.push_front(x);
		path.push_front(s);
		return path;
	}*/

	// Devuelve el número de aristas en el camino más corto a v-----------------------------------------------
	size_t distance(size_t v) const {
		return distTo.at(v); //como hacer distTo[v]
	}

	//-------------------------------------------------------------------------------------------------------
	void bfs(size_t origin, size_t final) {
		std::queue<size_t> q;// cola

		size_t w;
		size_t v;
		bool aux=false;

		distTo[origin%10000] = 0; ////ultimo desde el origen pongo un 0
		marked[origin%10000] = true; //marco el origen en el vector de marcados
		q.push(origin%10000); //tamañado el origen a la cola

		v = origin;
		while ((!q.empty()) && (!aux)) { //mientras queden elementos que tratar en la cola y no sea el elemento final..
			v = q.front(); q.pop();

			for (int i = 0; i<3; i++) {

				if (i == 0) w = (v + 1) % 10000;
				if (i == 1) w = (v * 2) % 10000;
				if (i == 2) w = (v / 3)%10000;

				if ((w == final) || (v==final)) aux = true;

				if (!marked[w]) {
					//edgeTo[w] = v;
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}//if
			}//for
		}//while
		cout << distTo[final] << endl;
	}//bfs

private:
	std::vector<bool> marked;     // marked[v] = hay camino s-v?
	//std::vector<size_t> edgeTo;   // edgeTo[v] = último vértice antes de llegar a v
	std::vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto
//	size_t s;                     // vértice origen
								  //------------------------------------------------------------------------------------------------------------


};//class calculator
  /**********************************************************************************************************/
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int o, f;
	cin >> o;
	cin >> f;

	while (!cin.fail())
	{
		solveCase(o, f);
		cin >> o;
		cin >> f;


	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

//-----------------------------------------------------------------------------------------------
void solveCase(int origin, int final) {

	calculatorPath cal;
	cal.bfs(origin,final);


}
