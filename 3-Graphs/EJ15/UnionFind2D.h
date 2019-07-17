// DA19  David Ortiz - Andr�s Ortiz

#include <vector>
#include <iostream>
using namespace std;
class UnionFind2D {
public:

	// crea una estructura de partici�n con los elementos 0..N-1, cada uno en un conjunto
	// En este caso con el tama�o completo que tendr� el vector unidimensional , de tama�o ( F*C).
	UnionFind2D(size_t F, size_t C) : size(F*C), _count(size), id(size, -1), maxTam(0) {

	}

	// devuelve el n�mero de conjuntos disjuntos
	size_t count() const { return _count; }

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const {
		if (id.at(p) < 0) // es una ra�z
			return p;
		else
			return id[p] = int(buscar(id[p]));
	}

	// unir los conjuntos que contengan a p y q
	// Dentro actualizamos el tama�o del conjunto m�s grande.
	void unir(size_t p, size_t q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la ra�z del mayor �rbol
			id[i] += id[j]; id[j] = int(i);
			if (id[i] < maxTam) maxTam = id[i];
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			if (id[j] < maxTam) maxTam = id[j];
		}
		_count--;

	}

	size_t size;             // los elementos son 0 .. size-1
	size_t _count;           // n�mero de conjuntos disjuntos
	mutable vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tama�o del conjunto de i
	signed int maxTam; // Tama�o del mayor conjunto.

};







