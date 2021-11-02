// c++ 메모리 Dinamic allocation

int main() {
	int i, n;
	int* p;

	cout << "How many numbers would you like to type? ";
	cin >> i;
	p = new (nothrow) int[i];                         // nothrow의미: 메모리 할당을 못 받을 경우 예외처를 넣어준다
	if (p == 0) 
		cout << "Error: memory could not be allocated"; // 10억이상의 값이 i로 들어가게 되면, 에러 발생! (이유: dynamic allocation은 연속된 메모리 공간을 요구하는데
                                                    // 10억의 값은 heap공간에 빈공간은 있을 수 있지만 10억만큼의 연속된 공간이 없기 때문에 에러 발생함. )

	else
	{
		for (n = 0; n < i; n++) {
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++) 
			cout << p[n] << ", ";
		delete [] p;                                   // 모두에 대해서 반환함 if) 'delete p;' 는 맨 앞 한칸만을 반환함을 의미함.
		
		
	}
	return 0;
}
