

class infoId {
public:
	long int id; // Identificador
	long int idTime; // Tiempo actual de transmisión.
	long int firstTime; // Primer tiempo de transmisión.

	bool operator()(infoId a,infoId b) {
		if (a.idTime != b.idTime) {
			return a.idTime <= b.idTime;
		}
		else  {
			return a.id < b.id;
		}
	}

};
