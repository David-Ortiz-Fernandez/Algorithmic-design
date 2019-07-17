#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <cmath>
#include <algorithm>

using namespace std;


typedef struct {
	int deep;
	int gold;

} tChest;

void solve(int secs,int chests);
void solveCase(const tChest *Q, const int chests,const int secs,bool *sol);

int main() {
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	int secs;
	int chests;

	cin >> secs;
	cin >> chests;
	while (!cin.fail()) {
		solve(secs, chests);
		cout << "----" << endl;
		cin >> secs;
		cin >> chests;
	}


	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	return 0;
}

void solve(int secs, int chests) {
	tChest *Q = new tChest[chests+1];
	bool *sol = new bool[chests + 1];

	int a;
	int b;
	tChest var;
	for (int i = 1; i <= chests; i++) {
		cin >> a;
		cin >> b;
		var.deep = a;
		var.gold = b;
		Q[i] = var;
		sol[i] = false;
	}
	solveCase(Q, chests, secs,sol);

	delete[] Q;
	delete[] sol;
 
}

void solveCase(const tChest *Q, const int chests, int secs,bool *sol) {

	Matriz<int> matrix(chests + 1, secs + 1, 0);

	int num;
	for (int i = 1; i <= chests; i++) {
		for (int j = 1; j <= secs; j++) {
			num = Q[i].deep + (Q[i].deep * 2);
			if (num > j){
				matrix[i][j] = matrix[i - 1][j];
			} 
			else {

				if (matrix.posCorrecta(i - 1, j - num )) {
					matrix[i][j] = max(matrix[i - 1][j],
										matrix[i - 1][j - num] + Q[i].gold);
				}
			}
		}
	}

	int remainder = secs;
	int cont = 0;
	for (int i = chests; i >= 1; --i) {
		if (matrix[i][remainder] == matrix[i - 1][remainder]) {
			sol[i] = false;
		}
		else {
			sol[i] = true;
			cont++;
			remainder-= Q[i].deep + (Q[i].deep * 2);
		}
	}
	cout << matrix[chests][secs] << endl;
	cout << cont << endl;
	for (int i = 1; i <= chests; i++) {
		if (sol[i]) {
			cout << Q[i].deep << " " << Q[i].gold << endl;
		} 
	}
}



