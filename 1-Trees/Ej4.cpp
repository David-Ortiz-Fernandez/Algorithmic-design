// DA19 - Andrés Ortiz - David Ortiz.


#include <iostream>
#include "TreeMap_AVL.h"
#include <algorithm>
#include <fstream>
using namespace std;



int resolverCaso();

int main() {
    /*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif*/

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cout << resolverCaso() << endl;
		
	}

    /*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
    #endif*/
	return 0;
}


// Coste N Log(N) siendo N el número de elementos del vector.
// Para cada elemento se realiza una búsqueda en los elementos ya introducidos anteriormente
// esta búsqueda se hace en un árbol binario de búsqueda en el que la clave es el entero y el valor es la posición que ocupaba en el array.
int resolverCaso() {
	int num;
	int cont = 1;  // Longitud
	int max_len = 1;  // resultado final
	int i_prev;  
	int var;
	cin >> num;

	TreeMap<int, int> a; // Árbol para guardar elementos y hacer una búsqueda eficiente.

	// Array sin elementos.
	if (num == 0) { max_len = 0; return max_len; }

	// Inserto el primer elemento.
	cin >> var;
	a[var] = 0;

	for (int i = 1; i < num; i++)
	{
		cin >> var;
		// found determina si se ha encontrado el elemento.
		bool found = a.contains(var);
		// Índice del último elemento insertado.
		i_prev = a[var];

		// Si el elemento no está o si no forma parte del actual sub-segmento.
		if (!found || i - cont > i_prev)
			cont++;
		else
		{
			// Actualizar contador si es mayor que el máximo actual.
			if (cont > max_len)
				max_len = cont;

			// Como el elemento actual ya estaba anteriormente se corta el vector desde su posición para actualizar cont.
			// Es decir , restan los elementos anteriores al elemento repetido.
			cont = i - i_prev;
		}
		// Se inserta el nuevo elemento.
		a[var] = i;
		
	}

	if (cont > max_len)
		max_len = cont;

	return max_len;
}
