
// DA19 David Ortiz - Andr�s Ortiz.

#include <iostream>
#include "Grafo.h"
#include <vector>
using namespace std;


int solveCase();

 int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) cout << solveCase() << endl;


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


//  el coste m�ximo es  ( V + E ) , que se da de recorrer en profundidad cada componente conexa que forman el grafo.
int solveCase() {
	int people;
	int pair;
	int a;
	int b;
	int maxPair = 0;
	vector<int> initialPos; // Vector para guardar las posibles posiciones iniciales.
	int aux=0;
	cin >> people;
	cin >> pair;
	if (pair == 0) return 1; // Si hay personas , pero ninguno se relaciona , se devuelve 1.

	Grafo partners(people + 1);
	for (int i = 0; i < pair; i++) {
		cin >> a;
		cin >> b;
		if (i == 0) initialPos.push_back(a); // Inserto la primera posici�n inicial.
		else {
			// Si ning�n v�rtice de la pareja tiene adyacentes lo a�ado como posible posici�n inicial.
			if (partners.adj(a).size() == 0 && partners.adj(b).size() == 0) initialPos.push_back(a);
		}
		// Inserto la arista.
		partners.ponArista(a, b);
	}


	// Para cada posible posici�n inicial hago la b�squeda en profundidad.
	int i = 0;
	DepthFirstSearch search(partners, initialPos[i]);
	aux = search.count();
	for (int i = 1; i < initialPos.size(); i++) {
		// Me quedo con el mayor n�mero de v�rtices en la componente conexa m�s grande.
		if (aux > maxPair) maxPair = aux;
		// Si en el primer recorrido no se ha marcado este posible v�rtice de inicio en concreto es que est� en otra componente.
		if (!search.marked(initialPos[i])) {
			DepthFirstSearch searchAux(partners, initialPos[i]);
			aux = searchAux.count();
		}
	}
	if (aux > maxPair) maxPair = aux;
	return maxPair;

}
