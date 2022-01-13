#include<iostream>
#include<new>


using namespace std;


class mother {
public:
	mother()	//default constructor
	{
		cout << "mother: no parameter\n";
	}
	mother(int a) //파라미터 하나를 받는 constructor 
	{
		cout << "mother: int parameter\n";
	}

};

class daughter : public mother {
public:
	daughter(int a)
	{
		cout << "daughter: int parameter\n\n";
	}
};

class son : public mother {
public:
	son(int a):mother(a) // 명시적으로 파라미터 하나를 받는 constructor를 지목해서 실행함!
	{
		cout << "son: int parameter\n\n";
	}
};

int main() {
	daughter cynthia(0); // 보기에는 daughter와 son만 호출된듯 하지만 부모 클래스의 constructor가 먼저 실행됨.
	son daiel(0);
	return 0;
}
