#include <iostream>
#include <fstream>
#include "Interval.h"
#include "PriorityQueue.h"
#include "Grafo.h"

using namespace std;

typedef struct {
	int pos;
	int num;

} tData;

int solveCase(int L,int N);

int main() {
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int L=0;
	int N=0;
	cin >> L;
	cin >> N;
	while (!cin.fail()) {
		auto x = solveCase(L, N);
	
		cout << x << endl; 
		cin >> L;
		cin >> N;
	}


	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif


}

// Se convierten todos los restaurantes y su área de influencia en un intervalo.
// Se ordenan todos los restaurantes priorizando su punto de influencia de inicio ,
// de menor a mayor,si éste coincide con algún otro intervalo se prima el que cubra el mayor número de puntos de la calle,
// de mayor a menor.

// El coste de ordenar todos los restaurantes en la cola de prioridad 
// Para cada restaurante , ordenarlo : O( N log N) siendo N el número de restaurantes.

// Después se fija el inicio en 1 y el máximo rango alcanzado hasta el momento en -1.
// Empieza el bucle , se coge el primero y dentro de todos los que interseccionan con este intervalo
// se busca el máximo rango alcanzado , se fija el punto de inicio como el máximo alcanzado y se vuelve a iterar.

// Antes de salir se comprueba si el punto máximo alcanzado coincide con la longitud de la calle.

// Tiempo total O ( N log N ) + O( N ) = O ( N log N) siendo N el número de restaurantes.
int solveCase(int L,int N) {
	if (N == 0) return -1;
	int a;
	int b;
	int s;
	int e;
	bool found = false;

	PriorityQueue<Interval, Interval> Q;

	for (int i = 0; i < N; i++) {
		cin >> a;
		cin >> b;
		s = a - b;
		e = a + b;
		if (s <= 0) s = 1;
		if (e > L) e = L;
		Interval var;
		var.start = s;
		var.end = e;
		Q.push(var);
	}

	//////////////////
	
	int start = 1;
	int max = -1;
	int num = 0;
	while (!Q.empty() && max < L) {

		if (Q.top().end <= start) { // La solución anterior era mejor.
		
		Q.pop();
		}
		else {
			if (Q.top().start > start) // Falta un punto de la calle por cubrir.
				break;
			while (!Q.empty() && max < L && Q.top().start <= start) {
				if (Q.top().end > max) {
					max = Q.top().end;
				}
				
				Q.pop();
			}
			if (start != max) {
				start = max;
				num++;
			}

		}
	}
	if (max < L)
		return -1;
	return N-num;
}
	

	
	
	


