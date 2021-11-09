#include <iostream>
using namespace std;

class Gate{
public:
  bool x[4] = {true, true, false, false};
  bool y[4] = {true, false, true, false};
  virtual bool output(bool &a, bool &b) = 0; //pure virtual
  
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
  
