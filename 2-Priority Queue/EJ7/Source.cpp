// DA19 Andrés Ortiz - David Ortiz


#include <iostream>
#include "PriorityQueue.h"
#include "infoId.h"
#include <fstream>

using namespace std;

// La idea principal es introducir todos los elementos al principio de forma ordenada
// y en el momento de mostrarlos por pantalla ir actualizando sus valores de manera 
// que su prioridad irá cambiando cada vez que se muestre un id por pantalla.
void solveCase(int users);

int main() {
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int users;
		
	cin >> users;
	while (users != 0) {
		solveCase(users);
		cout << "----" << endl;
		cin >> users;
	}
		
	
	/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/


	//system("Pause");
	return 0;
}

// Tiempo en ejecución ( users log(users) + k(log(users) )   = ( N log(N) ).
void solveCase(int users) {
	PriorityQueue<infoId,infoId> queue;
	infoId a;
	int k;

	// Para cada elemento ( id , periodo ) Lo introduzco en la cola
	// De modo que la primera prioridad es el tiempo y la segunda el id en caso de que el tiempo sea igual.
	// Tiempo en ejecución ( users Log(users) ).
	for (int i = 0; i < users; i++) {
		cin >> a.id;
		cin >> a.idTime;
		a.firstTime = a.idTime;
		queue.push(a);

	}
	cin >> k;

	// Para k veces muestro por pantalla el elemento más prioritario y actualizo el mismo
	// al nuevo periodo al que será retransmitido
	// Tiempo en ejecución ( k Log(users) ).
	for (int j = 0; j < k; j++) {
		cout << queue.top().id << endl;
		a = queue.top();
		queue.pop();
		a.idTime  += a.firstTime;
		queue.push(a);
	}
}