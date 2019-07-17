// DA19 , David Ortiz - Andrés Ortiz.
#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

void solveCase(int size);
//El coste del algoritmo sera O(NLogN) donde N es el numero de elementos a tratar en cada caso
/**********************************************************************************************************/
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int size;
	cin >> size;
	while (!cin.fail()) {
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
	int var, count = 0, acum = 0;
	PriorityQueue <int, std::greater<int>> queue; //cola de mayores para odenar en orden decreciente

	for (int i = 0; i<size; i++) {
		cin >> var;
		queue.push(var);
	}

	while (!queue.empty()) {
		var = queue.top();
		queue.pop();
		count++;

		if (count == 3) {
			count = 0;
			acum = acum + var;
		}

	}
	cout << acum << endl;
}//solveCase