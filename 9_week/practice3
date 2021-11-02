#include<iostream>
using namespace std;

class CRectangle {
	int width, height;
public:
	void set_values(int, int);
	int area(void) { return(width * height); }
};

void CRectangle::set_values(int a, int b) {
	width = a;
	height = b;
}

int main() {
	CRectangle a, * b, * c;                       //a는 obj 메모리가 잡힘. *b, *c는 포인터변수(주소)가 메모리에 잡히게 되는데 현재 b,c갑이 없으니 현재는 garbage 주소임.
	CRectangle* d = new CRectangle[2];            //d는 array로 d[[0], d[1]에 각각 a,b값을 할당 받음 == 2개의 공간을 가짐
	b = new CRectangle;                           //새롭게 obj assign함

	c = &a;           //c는 a를 가리킴
	a.set_values(1, 2);
	b->set_values(3, 4);
	d->set_values(5, 6);                          // 'd->' = 'd[0].' 두개의 의미가 같음!
	d[1].set_values(7, 8);

	cout << "a area: " << a.area() << endl;
	cout << "*b area: " << b->area() << endl;
	cout << "*c area: " << c->area() << endl;     //앞서 'c=&a'라고 했기때문에 출력값이 a와 동일
	cout << "d[0] area: " << d[0].area() << endl;
	cout << "d[1] area" << d[1].area() << endl;

	delete[] d;
	delete b;
	return 0;


}
