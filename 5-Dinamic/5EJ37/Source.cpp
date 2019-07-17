// DA19 , David Ortiz - Andrés Ortiz.
//El algoritmo rellena inicialmente una matriz y un vector que resuelve la siguiente funcion de recurrencia
//caracoles(i)=Sumatorio de j=1 hasta j=i(combinaciones de i elementos tomados de j en j)*caracoles(i-j))
//En cuanto a memoria adicional el coste del algoritmo es O(n*n) para la matriz y O(n) para el vector 
//En cuanto a tiempo  el coste del algoritmo es O(n*n) donde n es el numero de caracoles

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Matriz.h"
#include <vector>
using namespace std;

void solveCase(int caracoles, vector<int>c);
/**********************************************************************************************************/
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int car;
	cin >> car;
	int c = 1000;
	Matriz<int> C(c+1, c+1, 0);
	vector<int> caracoles(c+1, 0);

	C[0][0] = 1;
	caracoles[0] = 1;
	caracoles[1] = 1;


	for (int i = 1; i <= c; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= c; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 46337;
			if ((i>1) && (j <= i)) {
				caracoles[i] = (caracoles[i] + (C[i][j] * caracoles[i - j])) % 46337;
			}

		}

	}

	while (!cin.fail()) {
		if (car == 0) cout << "0";
		solveCase(car,caracoles);
		cin >> car;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

/**********************************************************************************************************/
void solveCase(int c,vector<int>caracoles) {

	cout << (caracoles[c])%46337 << endl;
}//solveCase