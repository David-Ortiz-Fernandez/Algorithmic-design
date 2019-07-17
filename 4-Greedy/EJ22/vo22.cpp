// DA19 , David Ortiz - Andrés Ortiz.
#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

void solveCase(int size);
// El coste del algoritmo sera O(NLogN) donde N es el numero de partidos en cada caso
/**********************************************************************************************************/
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int size;
	cin >> size;
	while (size != 0) {
		solveCase(size);
		cin >> size;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

/**********************************************************************************************************/
void solveCase(int size) {
	bool aux;
	int var1, var2, count = 0, acum = 0;
	PriorityQueue <int, std::greater<int>> broncos; //cola de mayores para odenar en orden decreciente
	PriorityQueue <int> rival; //cola de minimos para odenar en orden decreciente

	for (int i = 0; i<size; i++) {
		cin >> var2;
		rival.push(var2);
	}

	for (int i = 0; i<size; i++) {
		cin >> var1;
		broncos.push(var1);
	}

	while (!broncos.empty()) {
		var1 = broncos.top();
		var2 = rival.top();
		broncos.pop();
		rival.pop();


		if (var1>var2) {
			acum = acum + (var1 - var2);
		}

	}
	cout << acum << endl;
}//solveCase