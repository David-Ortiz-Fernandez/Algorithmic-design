// DA19 - David Ortiz - Andrés Ortiz

#include <fstream>
#include <iostream>

#include <vector>
#include "UnionFind2D.h"
using namespace std;

// Verifica posiciones adyacentes buscando posibles # para unirlas.
void verify(const vector<vector<bool>> &a, int F, int C, int x, int y, UnionFind2D &ag);

// Hemos usado una matriz booleana para recoger los datos.
// Cuando pasámos los datos a la partición para unir dos conjuntos usamos una fórmula de desplazamiento para convertir las posiciones de la matriz
// a su correspondiente posición en un vector unidimensional.

// Recorremos la matriz uniendo las # añadidas de inicio. 
// Si no hay ninguna el tamaño máximo es 0.
// Volvemos a recorrer posiciones adyacentes para las nuevas # y mostramos su tamaño máximo actualizado.

// Coste:
// Inicializar el vector de booleanos de dos dimensiones a false ( entiendo que es un coste de preprocesado y no lo voy a contar en la solución final).
// Para cada # del vector comprobar sus posiciones adyacentes ( como máximo 8 ) y unir los conjuntos pertinentes.
// Unir = O(find) + O(unir) = O(find) que es en el peor caso Log N en el número de elementos totales.
// Coste de inicializar F*C posiciones en el vector unidimensional de la partición a -1. O(F*C) ( entiendo que es un coste que solo se hace 1 vez y no lo voy a contar).
//  O((F*C posiciones)*8(posibles posiciones adyacentes)*(unir)).
// O(F*C*8*Log(F*C)). = O(N*8 log(N))= O (N LOG(N)).
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	int F;
	int C;
	char aux;
	
	cin >> F;
	while (!cin.fail()) { // Mientras que haya casos..
		cin >> C;
		vector < vector<bool>> matrix(F, vector<bool>(C, false)); // Inicializamos vector de 2 dimensiones.
		UnionFind2D algorithm(F, C); // Inicializamos la partición .


		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
				if (j == 0) cin.ignore();
				cin.get(aux);
				if (aux == '#'){
					matrix[i][j] = true;
					if (algorithm.maxTam == 0) algorithm.maxTam = -1; // si hemos añadido un # cambiamos el tamaño máximo del conjunto a 1.
				}
			}
		}

		// Para cada posición del vector con # verificamos sus posiciones adyacentes buscando más # y unificándolas en un solo conjunto.
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
				if (matrix[i][j]) verify(matrix, F, C, i, j, algorithm);
			}
		}

		cout << -algorithm.maxTam << " "; // Mostramos el tamaño del mayor conjunto antes de añadir nuevas #.
		int numCel;
		int a;
		int b;
		cin >> numCel;
		for (int i = 0; i < numCel; i++) {
			cin >> a;
			cin >> b;
			matrix[a - 1][b - 1] = true;
			verify(matrix, F, C, a - 1, b - 1, algorithm); // Verificamos para la nueva posición.
			if (algorithm.maxTam == 0) cout << 1; // Si el tamaño máximo era vacío lo cambiamos a 1.
			else {
				cout << -algorithm.maxTam; // Mostramos el  tamaño del conjunto más grande.
			}
			if (i != numCel - 1) cout << " ";
		}
		cout << endl;
		cin >> F;
	}
	
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif

	return 0;
}

void verify(const vector<vector<bool>> &a, int F, int C, int x, int y, UnionFind2D &ag) {
		// Para las 8 posiciones adyacentes válidas verificamos si podemos unirlas.
		for (int i = x - 1; i < x + 2; i++) {
			for (int j = y - 1; j < y + 2; j++) {
				if ((i >= 0 && i < F) && (j >= 0 && j < C) && (a[i][j])) {

					// Fórmula de desplazamiento para convertir posiciones X e Y de una matriz en su correspondiente
					// posición en un vector unidimensional (única).
					int a = ((x )*C + y );
					int b = ((i )*C + j );
					ag.unir(a, b);
				}
			}
		}
	}