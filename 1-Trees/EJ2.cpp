// DA19 , David Ortiz - Andr�s Ortiz.


#include <iostream>
#include "BinTree.h"
#include <algorithm>
#include <fstream>
using namespace std;


// Lee un �rbol recursivamente.
BinTree<int> leerArbol() {
	int raiz;
	cin >> raiz;
	if (raiz == -1) { // es un �rbol vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}


// Complejidad O(N) siendo N el n�mero de nodos a recorrer los cuales s�lo se recorren una vez.
int equilibrado(BinTree<int> const  &nodo,int mini,int maxi) {
	if (nodo.empty()) { // Si el nodo es vac�o..
		return 0;
	}
	// Si el nodo no cumple la condici�n recursvia de "ser balanceado"..
	// Los valores maxi y mini se actualizan seg�n la rama que estemos visitando.
 	if (nodo.root() >= maxi || nodo.root() <= mini) {
		return -1;
	}
		

	// En el hijo izquiero dejamos tal cual el M�nimo y actualizamos el m�ximo para ver�ficar que todos cumplen que son menores que la ra�z.	
	int left = equilibrado(nodo.left(),mini,nodo.root());
	if (left == -1)return -1; // si se devolv�o -1 ( Hay m�s de 1 en diferencia de altura ) devuelvo -1 a las llamadas anteriores.

	// En el hijo derecho dejamos el m�ximo igual y actualizamos el m�nimo sabiendo que todos tienen que ser mayor que la ra�z.
	int right = equilibrado(nodo.right(),nodo.root(),maxi);
	if (right == -1) return -1; // si se devolv�o -1 ( Hay m�s de 1 en diferencia de altura ) devuelvo -1 a las llamadas anteriores.

	if (abs(left - right) > 1) { // hay m�s de 1 en diferencia de altura entre hijos.
		return -1;
	}
	else {
		return max(left, right) + 1; // Si el nodo no es vac�o (por eso se suma 1). y no hay m�s de 1 en diferencia de altura devuelvo la m�xima altura de los hijos.
	}
}


void resuelveCaso() {
	auto arbol = leerArbol();
	int a = 0;

	int b = 0;
	int c = 2147483647;

	a = equilibrado(arbol,b,c);
	if (a != -1) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}


}

int main() {

  
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
		
	}
	return 0;
}