#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class notAcceptable {
public:
	notAcceptable() { cout << "not Acceptable" << endl; }
};

class notMovable {
public:
	notMovable() { cout << "not Movable" << endl; }
};

class Puzzle{
private:
	char nums[3][3];
	void findZero(int& i, int& j);
public:
	Puzzle();
	void move(char c);
	friend ostream& operator <<(ostream& outputStream, const Puzzle& c);
};


Puzzle::Puzzle() : nums{ {'1', '2', '3'}, { '8', '0', '4' }, { '7','6','5'} } { };


void Puzzle::findZero(int& i, int& j) {
	i = -1;
	j = -1;
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			if (nums[m][n] == '0') {
				i = m;
				j = n;
				return; 

			}

		}
	}
}

void Puzzle :: move(char c) {

	int i, j;
	findZero(i, j);

	switch (c) {
	case'n':
		if (i == 0) throw notMovable();
		nums[i][j] = nums[i - 1][j];
		nums[i - 1][j] = '0';
		break;
	case's':
		if (i == 2) throw notMovable();
		nums[i][j] = nums[i + 1][j];
		nums[i + 1][j] = '0';
		break;
	case'e':
		if (j == 2) throw notMovable();
		nums[i][j] = nums[i][j + 1];
		nums[i][j + 1] = '0';
		break;
	case'w':
		if (j == 0) throw notMovable();
		nums[i][j] = nums[i][j - 1];
		nums[i][j - 1] = '0';
		break;
	case'x':
		break;
	default:
		throw notAcceptable();
	}
}



ostream& operator <<(ostream& outputStream, const Puzzle& c) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << c.nums[i][j] << " ";
		}
		cout << endl;
	}
	return outputStream;
}


void main()
{
	Puzzle mypuzzle;
	char c;
	try {
		do {
			cout << mypuzzle << endl;
			cin >> c;
			mypuzzle.move(c);
		} while (c != 'x');
	}
	catch (notAcceptable i) {
	}
	catch (notMovable i) {
	}

}
