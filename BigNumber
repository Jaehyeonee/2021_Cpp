#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

class BigNumber
{
private:
    char num[32];

public:
    BigNumber(const char* n);
    friend BigNumber& operator +(BigNumber& a, BigNumber& b);
    friend ostream& operator <<(ostream& outputStream, const BigNumber& c);


};


BigNumber:: BigNumber(const char* n)
{
    //strcpy(this->num, n);
    int len = strlen(n);
    for (int i = 0; i < 32; i++) {
        if (i < len)
            num[i] = n[len -1 - i];
        else // 앞부분 0으로 채우기
            num[i] = '0';
    }

}


BigNumber& operator +(BigNumber& a,BigNumber& b) {
    BigNumber c("0");
    int carryout = 0;
    for (int i = 0; i < 32; i++) {
        c.num[i] = (((a.num[i] -'0') + (b.num[i] - '0') + carryout) % 10) + '0';
        carryout = (((a.num[i] - '0') + (b.num[i] - '0') + carryout) / 10);
    }
    return c;
}

ostream& operator <<(ostream& output, const BigNumber& c) {
    bool start = false;
    for (int i = 31; i >= 0; i--) {
        if (!start && c.num[i] > '0'){
            start = true;
            output << c.num[i];
        }
        else if (start) {
            output << c.num[i]; //시작됐으면 계속 찍으면 된다.
        }
    }
    return output;
}

int main() {
    BigNumber a("1234567890");
    BigNumber b("123456");
    cout << (a + b) << endl;

}
