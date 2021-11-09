class Notation {
private:
	int n, base;
public:
	void setN(int b, int v);
	void setBase(int b);
	friend ostream& operator<<(ostream& output, const Notation& d);
};

void Notation:: setN(int b, int v){
	n = 0;
	//v--> v^0 * v0 +b^1 * v1 + b^2*v2...
	for (int tb = 1; v > 0; tb *= b) {
		v = v / b;
		n += (v % b) * tb;
	}

}
void Notation::setBase(int b) {
	base = b;
}
ostream& operator<<(ostream& output, const Notation& d) 
{
	
	string result = "";
	//진법 계산법 ... 맨 마지막 뒤부터 읽음 따라서 숫자를 거꾸로 읽어야 해서 밑에  순서 바꾸기 for문을 하나 더 만듬
	for (int n = d.n; n > 0; ) {
		n = n / d.base;
		result += to_string(n % d.base);
		
	}
	//순서 뒤집기
	for (int i = 0; i < result.size(); i++)
		output << result[result.size() - 1 - i]; // 맨 뒷자리부터 찍기
	return output;


}

int main() {
	Notation mynotaion;
	mynotaion.setN(4, 32);

}
