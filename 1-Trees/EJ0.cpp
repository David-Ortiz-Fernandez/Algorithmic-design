// DA19, David Ortiz - Andr�s Ortiz
// Leemos el �rbol.
// Tenemos en cuenta que si el �rbol es vac�o su altura es 0
// Se lee recursivamente el �rbol pasando por cada nodo llegando a las hojas y 
// determinando la altura final del �rbol binario, siendo esta 1 + el m�ximo de la altura de sus hijos ( si no es vac�o ).


#include <iostream>
#include "BinTree.h"
#include <algorithm>
using namespace std;

				

// Lee un �rbol recursivamente.BinTree<char> leerArbol() {
	char raiz;
	cin >> raiz;
	if (raiz == '.') { // es un �rbol vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}
/////////////////////////////////////////////////////

// dado un �rbol binario, calcula su altura
// lineal en el n�mero N de nodos del �rbol, O(N)
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