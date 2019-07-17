// DA19 , David Ortiz - Andrés Ortiz.
#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

void resolverCaso(int t);

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int t;	
	cin >> t;
	while (t != 0)
	{ 		
		resolverCaso(t);
		cout << "" <<endl;
		cin >> t;
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

//-----------------------------------------------------------------------------------------------
//Usando dos colas de prioridad , una de mayores y otra de menores, hacemos coincidir la posicion mediana del vector total que llevamos
//leido con el top de cada cola en caso de que llevemos pares números leidos, y con el top de  la de maximos en caso de que llevemos impares 
//entradas leidas.
//Complejidad NLog(N)
void resolverCaso(int t) {
	long val;
	long aux,aux1, aux2;
	long tam = 0;

	PriorityQueue <int,std::greater<long>> colaA;
	PriorityQueue <int, std::less<long>> colaB;

	
	for (int i = 0; i < t; i++) 
		{
		cin >> val;
		
		tam = tam+1;
			
			if ((tam % 2) != 0)//si hay impares números leidos
			{
				if (((colaA.size()) == (colaB.size()))&&(tam>1)&&(val > (colaB.top()))) {
				//si ambas colas tienen el mismo tamaño, no es el primer numero que se introduce y top de la cola B es 
				//menor que el valor leido
					aux = colaB.top();
					colaB.pop();
					colaA.push(aux);
					colaB.push(val);
				}
				else colaA.push(val); //en caso contrario insertamos en la cola A
				
				aux1= colaA.top();
				cout << 2*aux1;
				cout << " ";
				
			}
			else {//si hay impares posiciones

				colaB.push(val);
				if ((colaB.top())<(colaA.top())) { // en caso de que top de la cola A sea mayor que la de B, sacamos de una y metemos 
												  //en la otra asi mantenemos igual el tamaño de ambas y las ordenamos
					                               
					aux1 = colaB.top();
					aux2 = colaA.top();
					colaA.pop();
					colaB.pop();
					colaA.push(aux1);
					colaB.push(aux2);

				}
				aux1 = colaA.top();
				aux2 = colaB.top();
				cout << (aux1+aux2);
				cout << " ";	
				}
			}
}

