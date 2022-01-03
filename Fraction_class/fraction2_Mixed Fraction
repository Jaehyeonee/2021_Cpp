//분수 사칙연산 + 대분수 구현

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Fraction {
protected:

    int numerator, denominator; // 분자, 분모
    Fraction reduce(int num, int den);
    int gcd(int a, int b); // 최대공약수 찾기

public:
    Fraction(int n, int d);
    // 연산자 오버로딩
    Fraction operator+(const Fraction& f);
    Fraction operator-(const Fraction& f);
    Fraction operator*(const Fraction& f);
    Fraction operator/(const Fraction& f);
    //출력 overloading
    friend ostream& operator << (ostream& os, const Fraction& f); //나의 멤버가 아니여서 상속에 포함되지 않음
    //Mixed class 대분수 구현
    friend class Mixed;

};

Fraction::Fraction(int n, int d)
{
    this->numerator = n;
    this->denominator = d;
}

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

//Fraction 클래스를 상속받아 대분수 사칙연산하기
class Mixed : public Fraction {
private:
    int whole;
public:
    Mixed(int whole, int numerator, int denominator);
    friend ostream& operator <<(ostream& os, const Mixed& f);
    Mixed operator+(const Mixed& f);
    Mixed operator-(const Mixed& f);
    Mixed operator*(const Mixed& f);
    Mixed operator/(const Mixed& f);

};

Mixed::Mixed(int whole, int numerator, int denominator) : Fraction(numerator, denominator) {
    this->whole = whole;
};

ostream& operator<<(ostream& os, const Mixed& f) {
    os << f.whole << " ";
    os << f.numerator << "/" << f.denominator;
    return os;
}

Mixed Mixed::operator+(const Mixed& d) {
    int w = this->whole + d.whole;
    int num = (this->numerator * d.denominator) + (this->denominator * d.numerator);
    int den = (this->denominator * d.denominator);

    cout << this->numerator << " " << d.numerator << endl;
    Fraction result = reduce(num, den);

    if (result.numerator >= result.denominator) {
        w += result.numerator / result.denominator;
        result.numerator %= result.denominator;

    }

    this->whole = w;
    this->numerator = result.numerator;
    this->denominator = result.denominator;
    return *this;

}


Mixed Mixed::operator-(const Mixed& d) {
    int w = this->whole - d.whole;
    int num = (this->numerator * d.denominator) - (this->denominator * d.numerator);
    int den = (this->denominator * d.denominator);

    //cout << this->numerator << " " << d.numerator << endl;
    //cout << num << " " << den << endl;

    Fraction result = reduce(num, den);

    if (result.numerator >= result.denominator) {
        w += result.numerator / result.denominator;
        result.numerator %= result.denominator;

    }

    this->whole = w;
    this->numerator = result.numerator;
    this->denominator = result.denominator;
    return *this;
}

Mixed Mixed::operator*(const Mixed& d) {
    int w = this->whole * d.whole;
    int num = this->numerator * d.numerator;
    int den = this->denominator * d.denominator;

    Fraction result = reduce(num, den);

    if (result.numerator >= result.denominator) {
        w += result.numerator / result.denominator;
        result.numerator %= result.denominator;

    }

    this->whole = w;
    this->numerator = result.numerator;
    this->denominator = result.denominator;
    return *this;
}

Mixed Mixed::operator/(const Mixed& d) {
    int w = this->whole / d.whole;
    int num = this->numerator * d.denominator;
    int den = this->denominator * d.numerator;
    Fraction result = reduce(num, den);

    if (result.numerator >= result.denominator) {
        w += result.numerator / result.denominator;
        result.numerator %= result.denominator;

    }

    this->whole = w;
    this->numerator = result.numerator;
    this->denominator = result.denominator;
    return *this;

}



int main() {
    Fraction a(2, 3);
    Fraction b(3, 5);
    Mixed c(2, 2, 3);
    Mixed d(1, 3, 5);
    cout << (a + b) << ":" << (a - b) << endl;
    cout << (a * b) << ":" << (a / b) << endl;
    cout << "Mixed Cal" << endl;
    cout << (c + d) << ":" << (c - d) << endl;
    cout << (c * d) << ":" << (c / d) << endl;
}
