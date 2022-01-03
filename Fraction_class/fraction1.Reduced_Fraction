#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Fraction {
    //int whole;
    int numerator, denominator; // 분자, 분모
    Fraction reduce(int num, int den);
    int gcd(int a, int b); // 최대공약수 찾기

public:
    Fraction(int n, int d) { this->numerator = n; this->denominator = d; } //: numerator(n), denominator(d) {}
    void reduction(void);
    //기약분수
    double toMeasure() {
        return (double)numerator / denominator;
    }
    // 연산자 오버로딩
    Fraction operator+(const Fraction& f);
    Fraction operator-(const Fraction& f);
    Fraction operator*(const Fraction& f);
    Fraction operator/(const Fraction& f);
    //출력 overloading
    friend ostream& operator << (ostream& os, const Fraction& f); //나의 멤버가 아니여서 상속에 포함되지 않음

};

Fraction Fraction::reduce(int n, int d) {
    int common = this->gcd(n, d);
    Fraction a(n / common, d / common);
    return a;
}

int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a < b) swap(a, b);
    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


Fraction Fraction::operator+(const Fraction& f) {
    //Fraction temp(0, 0);
    int num = (this->numerator * f.denominator) + (this->denominator * f.numerator);
    int den = (this->denominator * f.denominator);
    return this->reduce(num, den);

}

Fraction Fraction::operator-(const Fraction& f) {
    int num = (this->numerator * f.denominator) + (this->denominator * f.numerator);
    int den = (this->denominator * f.denominator);
    return this->reduce(num, den);

}

Fraction Fraction::operator*(const Fraction& f) {
    int num = (this->numerator * f.numerator);
    int den = (this->denominator * f.denominator);
    return this->reduce(num, den);

}
Fraction Fraction::operator/(const Fraction& f) {
    int num = (this->numerator * f.denominator);
    int den = (this->denominator * f.numerator);
    return this->reduce(num, den);
}

ostream& operator << (ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
   
    return os;
} 

int main() {
    Fraction a(2, 3);
    Fraction b(3, 5);
    cout << (a + b) << ":" << (a - b) << endl;
    cout << (a * b) << ":" << (a / b) << endl;
}
