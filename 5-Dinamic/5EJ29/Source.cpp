#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


void solveCase(int objetive, int nums);
vector<int> calcular_monedas2(vector<int> const& M, int C,
	vector<int> const& monedas);

vector<int> calcular_monedas1(vector<int> const& M, int C,
	vector<int> const& monedas);

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int objetive;
	int nums;
	cin >> objetive;
	cin >> nums;
	while (!cin.fail()) {
		solveCase(objetive, nums);
		cin >> objetive;
		cin >> nums;

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

void solveCase(int objetive, int nums) {



	vector<int> M(nums+1);
	for (int i = 1; i <= nums; i++) {
		int a;
		cin >> a;
		M[i] = a;
	}
	int abc = 150000;

	size_t n = M.size() - 1;

	vector<int> monedas(objetive + 1, abc);
	monedas[0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {

		for (int j = M[i]; j <= objetive; ++j) {
			monedas[j] = min(monedas[j], monedas[j - M[i]] + 1);
		}
	}
	


		
	
	bool ok = false;
	if (n == 0) {
		if (objetive%M[0] == 0) {
			monedas[objetive] = objetive / M[0];
			ok = true;
		}
	}

	if (monedas[objetive] == abc) {
		cout << "Imposible ";
	}
	else {
		cout << monedas[objetive] << ": ";
		if (ok) {
			for (int i = 0; i < objetive / M[0]; i++) {
				cout << M[0] << " ";
			}
		}
		else {
			calcular_monedas2(M, objetive, monedas);
		}
	}

	cout << endl;
}

vector<int> calcular_monedas2(vector<int> const& M, int C,
	vector<int> const& monedas) {


	size_t n = M.size() - 1;
	vector<int> cuantas(n + 1, 0);
	int i = n; int j = C;
	int a = 0;
	while (j > 0) { // no se ha pagado todo
		if ((M[i] <= j) && (monedas[j] == monedas[j - M[i]] + 1)) {
			// tomamos una moneda de tipo i
			++cuantas[i];

			j = j - M[i];
			cout << M[i] << " ";
		}
		else // no tomamos más monedas de tipo i
			--i;
	}

	return cuantas;
}


