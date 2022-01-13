#include<iostream>
using namespace std;

class CDummy {
public:
	static int n;	                            //variable에 대한 초기화는 class내에서 불가능. 
					                                  // 보통 그래서 constructor에 하는데 static은 시점이 안맞음
	CDummy() { n++; };                        //초기화가 아니라 사용
	~CDummy() { n--; };
	static void printN(CDummy& k);
//	void reset() { n = 0; };
	int i;
	void reset() { n = 0; i == 100; };
};

void CDummy::printN(CDummy& k) {
	cout << n << ',' << k.i /*i는 모든 obj마다 서로다른i가 생김 근데 static안에서 쓰면 어느 obj인지 모르니까 모호성이 생겨서 쓸 수 없음 - 에러발생*/<<endl;
}

int CDummy::n = 0;//static member variable 초기화

int main() {


	
	CDummy::printN;                       // static 이므로 obj소속이 아니라 class소속
	//CDummy::reset(); reset에 대해선 static이 아니므로 obj에 속해서 obj 필요.


	CDummy a;
	CDummy b[5];
	CDummy* c = new CDummy; 
	cout << a.n << endl;                  // n access시, 멤버변수에 access하듯 쓰기
	delete c;
	cout << CDummy::n << endl;            // 클래스를 네임스페이스를 줘서 n에 바로 access하기
	return 0;

}
