#include <iostream>
#include "PriorityQueue.h"
#include <algorithm>
#include <fstream>
using namespace std;


int resolverCaso(int t);

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int t;
	
	cin >> t;
	while (t != 0)
	{ 
		
		cout << resolverCaso(t) << endl;
		cin >> t;
	}




#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
#endif

	return 0;
}

//-----------------------------------------------------------------------------------------------
int resolverCaso(int t) {
	
	int val;

	int a, b;
	
	//cin >> numtotal;

	int coste=0;
	int suma=0;

	PriorityQueue <int, std::less<int>> cola;
	//PriorityQueue <int> cola;
		for (int i = 0; i < t; i++) 
		{
			cin >> val;
			cola.push(val);
		}
		
			while (cola.size() > 1)
			{
				a = cola.top();
				cola.pop();
				b = cola.top();
				cola.pop();
				suma =  a + b;

				coste = coste + suma;

				cola.push(suma);
			}

		return coste;
}

