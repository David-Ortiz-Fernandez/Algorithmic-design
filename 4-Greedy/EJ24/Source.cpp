#include "Interval.h"
#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int solveCase(int N);


int main() {
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int n;
	cin >> n;
	while (n!=0) {
		cout << solveCase(n) << endl;
		cin >> n;
	}
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	return 0;
}

// Se ordenan todos los edificios priorizando su punto de finalización del más pequeño al más grande ,
// En caso de que algunos intervalos compartan el mismo punto de finalización se prioriza el punto de inicio ,
// del más pequeño al más grande.

// Coste de ordenar los edificios en la cola de prioridad O ( N log N ) siendo N el número de edificios.
// Por cada edificio debe de cruzar al menos un túnel.
// Fijo el mínimo como el final del primer intervalo , mientras que el inicio de los siguientes intervalos
// sea menor que el mínimo ( su intersección no es vacía ) podrán cruzar por el mismo tunel.
// se vuelve a fijar un nuevo mínimo y a iterar hasta vaciar la cola por completo.

// Coste total O ( N log N ) + O ( N ) en el número de edificios.
int solveCase(int N) {
	PriorityQueue<Interval, Interval> Q;
	Interval aux;
	int s;
	int e;
	
	for (int i = 0; i < N; i++) {
		cin >> s;
		cin >> e;
		aux.start = s;
		aux.end = e;
		Q.push(aux);
	}

	int num = 0;
	int min = -1;
	while (!Q.empty()) {
		if (Q.top().end > min) {
			min = Q.top().end;
			Q.pop();
		} 

		while (!Q.empty() && Q.top().start < min) {
			Q.pop();		
		}
		num++;

	}

	return num;
	
}