// DA19 , Andrés Ortiz , David Ortiz.
// Recogemos el árbol , y empezamos a comprobar la opción de si el árbol es vacío en cuyo caso está equilibrado.
// Luego comprobamos si los nodos internos están equilibrados llevando un conteo de la altura del hijo izq y der ;
// Y también a su vez comprobando recursivamente si los hijos cumplen el equilibrio.




#include <iostream>
#include "BinTree.h"
#include <algorithm>
using namespace std;



// Lee un árbol recursivamente.
BinTree<char> leerArbol() {
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


// Complejidad O(N) siendo N el número de nodos a recorrer los cuales sólo se recorren una vez.
int equilibrado(BinTree<char> const  &nodo) {
	if (nodo.empty()) { // Si el nodo es vacío..
		return 0;
	}
	
	int left = equilibrado(nodo.left());
	if (left == -1)return -1; // si se devolvío -1 ( Hay más de 1 en diferencia de altura ) devuelvo -1 a las llamadas anteriores.

	int right = equilibrado(nodo.right());
	 
	if (right == -1) return -1; // si se devolvío -1 ( Hay más de 1 en diferencia de altura ) devuelvo -1 a las llamadas anteriores.

	if (abs(left - right) > 1) { // hay más de 1 en diferencia de altura entre hijos.
		return -1;
	}
	else {
		return max(left, right) + 1; // Si el nodo no es vacío (por eso se suma 1). y no hay más de 1 en diferencia de altura devuelvo la máxima altura de los hijos.
	}
}


// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	int a = 0;

	a = equilibrado(arbol);
	if (a !=-1) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	
	return 0;
}