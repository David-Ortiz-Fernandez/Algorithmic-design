#include <iostream>
using namespace std;
class Interval {
public:
	int start;
	int end;

	bool operator() (const Interval &a, const Interval&b) {
		if (a.start < b.start) return a.start < b.start;
		if (a.start == b.start) return a.end > b.end;
		return false;
	}

	

	void print(){
		cout << "[" << start << " , " << end << "]" << endl;
	}

};


