#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Matriz.h"
using namespace std;

void solveCase(int people, int rel);





void imp_camino_int(size_t i, size_t j, Matriz<size_t> const& camino) {
	size_t k = camino[i][j];
	if (k > 0) {
		imp_camino_int(i, k, camino);
		cout << " " << k;
		imp_camino_int(k, j, camino);
	}
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int people;
	int rel;
	cin >> people;
	cin >> rel;
	while (!cin.fail()) {

		solveCase(people, rel);
		cin >> people;
		cin >> rel;
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

void solveCase(int people, int rel) {
	if (people > 1 && rel == 0) {
		cout << "DESCONECTADA" << endl;
		return;
	}
	if (people == 1 && rel == 0) {
		cout << "0" << endl;
		return;
	}
	Matriz<int> C(people + 1, people + 1, 999999);

	for (int i = 1; i <= people; i++) {
		C[i][i] = 0;
	}

	unordered_map<string, int> hm;

	string nom1;
	string nom2;
	int i1;
	int i2;

	int a = 0;
	for (int i = 0; i < rel; i++) {
		cin >> nom1;
		cin >> nom2;

		if (hm.find(nom1) == hm.end()) {
			hm[nom1] = a + 1;
			a++;
		}
		if (hm.find(nom2) == hm.end()) {
			hm[nom2] = a + 1;
			a++;
		}

		C[hm[nom1]][hm[nom2]] = 1;
		C[hm[nom2]][hm[nom1]] = 1;
	}

	//	Matriz<int> C(0, 0); 
	Matriz<size_t> camino(0, 0);
	bool error = false;
	int max = -1;


	size_t n = C.numfils() - 1;
	// inicialización
	//C = Q;
	camino = Matriz<size_t>(n + 1, n + 1, 0);
	// actualizaciones de la matriz
	for (size_t k = 1; k <= n; ++k)
		for (size_t i = 1; i <= n; ++i)
			for (size_t j = 1; j <= n; ++j) {
				int temp = C[i][k] + C[k][j];

				if (temp < C[i][j]) { // es mejor pasar por k
					C[i][j] = temp;
					camino[i][j] = k;

				}
				
			}


	n = C.numfils() - 1;
	for (size_t i = 1; i <= n; ++i)
		for (size_t j = 1; j <= n; ++j) {
			if (i != j && C[i][j] == 999999) {

				if (C[i][j] == 999999) {
					max = -1;
					break;
				}

			}
			if (C[i][j] > max && C[i][j] != 999999) {
				max = C[i][j];
			}

		}


	if (max == -1) cout << "DESCONECTADA" << endl;
	else {
		cout << max << endl;
	}

}