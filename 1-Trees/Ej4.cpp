// DA19 - Andr�s Ortiz - David Ortiz.


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


// Coste N Log(N) siendo N el n�mero de elementos del vector.
// Para cada elemento se realiza una b�squeda en los elementos ya introducidos anteriormente
// esta b�squeda se hace en un �rbol binario de b�squeda en el que la clave es el entero y el valor es la posici�n que ocupaba en el array.
int resolverCaso() {
	int num;
	int cont = 1;  // Longitud
	int max_len = 1;  // resultado final
	int i_prev;  
	int var;
	cin >> num;

	TreeMap<int, int> a; // �rbol para guardar elementos y hacer una b�squeda eficiente.

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
		// �ndice del �ltimo elemento insertado.
		i_prev = a[var];

		// Si el elemento no est� o si no forma parte del actual sub-segmento.
		if (!found || i - cont > i_prev)
			cont++;
		else
		{
			// Actualizar contador si es mayor que el m�ximo actual.
			if (cont > max_len)
				max_len = cont;

			// Como el elemento actual ya estaba anteriormente se corta el vector desde su posici�n para actualizar cont.
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
