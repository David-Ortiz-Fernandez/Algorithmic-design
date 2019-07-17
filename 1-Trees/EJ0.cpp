// DA19, David Ortiz - Andrés Ortiz
// Leemos el árbol.
// Tenemos en cuenta que si el árbol es vacío su altura es 0
// Se lee recursivamente el árbol pasando por cada nodo llegando a las hojas y 
// determinando la altura final del árbol binario, siendo esta 1 + el máximo de la altura de sus hijos ( si no es vacío ).


#include <iostream>
#include "BinTree.h"
#include <algorithm>
using namespace std;

				

// Lee un árbol recursivamente.BinTree<char> leerArbol() {
	char raiz;
	cin >> raiz;
	if (raiz == '.') { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}
/////////////////////////////////////////////////////

// dado un árbol binario, calcula su altura
// lineal en el número N de nodos del árbol, O(N)
int altura(BinTree<char> const& arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		return 1 + max(altura(arbol.left()), altura(arbol.right()));
	}
}

////////////////////////////////////////////////////

// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	int sol = altura(arbol);
	cout << sol << "\n";
}

////////////////////////////////////////////////////

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
		
	
	return 0;
}