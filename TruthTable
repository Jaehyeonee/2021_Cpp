#include <iostream>
using namespace std;

//my code

class Gate {
public:

	bool x[4] = { true, true, false, false };
	bool y[4] = { true, false, true, false };
	
	virtual bool output(bool &a, bool &b) = 0;

};

class AND : public Gate {
public:
	bool output(bool &a, bool &b)
	{	
		if ((a == true) & (b == true))
			return true;
		else
			return false;
		
	
	}

};

class OR : public Gate {

public:

	bool output(bool &a, bool &b)
	{

		if ((a == true) || (b == true))
			return true;
		else
			return false; 
	}

};


class TruthTable {
public:
	static void printTable(Gate *pGate) {
		cout << "A" << "B" << "O"<< endl;

		for (int i = 0; i < 4; i++) {
			cout << pGate->x[i] << pGate->y[i];
			cout << pGate->output(pGate->x[i], pGate->y[i]) << endl;;
			
		}
	}


};


int main() {
	AND a;
	OR b;

	TruthTable::printTable(&a);

	TruthTable::printTable(&b);

}



// lecture code


class Gate {
public :
	virtual bool output(bool a, bool b) = 0;
};

class And : public Gate {
	bool output(bool a, bool b);
};

class Or : public Gate {
	bool output(bool a, bool b);
};

class Truthtable {
public :
	static void printTable(Gate* pGate);
};

bool And::output(bool a, bool b) {
	return a && b;
}

bool Or::output(bool a, bool b) {
	return a || b;
}

void Truthtable::printTable(Gate* pGate) {
	cout << "A B O" << endl;
	cout << "1 1 " << pGate->output(true, true) << endl;
	cout << "1 0 " << pGate->output(true, false) << endl;
	cout << "0 1 " << pGate->output(false, true) << endl;
	cout << "0 0 " << pGate->output(false, false) << endl;
}

int main() {
	And a;
	Or b;
	Truthtable::printTable(&a);
	Truthtable::printTable(&b);
}
