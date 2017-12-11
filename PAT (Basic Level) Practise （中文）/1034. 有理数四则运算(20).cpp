/*

1034. ��������������(20)
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����Ҫ���д���򣬼���2���������ĺ͡�������̡�

�����ʽ��

������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��

�����ʽ��

�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�ע�������ÿ�������������Ǹ��������������ʽ��k a/b��������k���������֣�a/b�����������֣���Ϊ��������������ţ���������ĸΪ0���������Inf������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������

��������1��
2/3 -4/2
�������1��
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
��������2��
5/3 0/6
�������2��
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long BigInt;


inline BigInt Gcd(BigInt a, BigInt b) {
	a = abs(a);
	b = abs(b);
	return b == 0 ? a : Gcd(b, a%b);
}

class Fraction {
public:
	Fraction(BigInt a, BigInt b, bool f = true) {
		flag = f;
		if (flag) {
			if (a%b == 0) {
				numerator = a / b;
				denominator = 1;
			}
			else {
				BigInt c = Gcd(a, b);
				numerator = a / c;
				denominator = b / c;
			}
		}
	}


	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
		BigInt a = lhs.numerator*rhs.denominator + rhs.numerator*lhs.denominator;
		BigInt b = lhs.denominator*rhs.denominator;
		BigInt c = Gcd(a, b);
		return Fraction(a / c, b / c);
	}
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
		BigInt a = lhs.numerator*rhs.denominator - rhs.numerator*lhs.denominator;
		BigInt b = lhs.denominator*rhs.denominator;
		BigInt c = Gcd(a, b);
		return Fraction(a / c, b / c);
	}

	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
		BigInt a = lhs.numerator*rhs.numerator;
		BigInt b = lhs.denominator*rhs.denominator;
		BigInt c = Gcd(a, b);
		return Fraction(a / c, b / c);
	}

	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
		BigInt a = lhs.numerator*rhs.denominator;
		BigInt b = lhs.denominator*rhs.numerator;
		if (b < 0) {
			a *= -1;
			b *= -1;
		}
		BigInt c = Gcd(a, b);
		if (b == 0)	return Fraction(a / c, b / c, false);
		else return Fraction(a / c, b / c);
	}

	friend ostream& operator<<(ostream& os, const Fraction& F) {
		if (F.flag) {
			bool bracket = false;
			if (F.numerator < 0) 
				bracket = true;
			if (F.denominator == 1) {
				if (bracket) os << "(" << F.numerator << ")";
				else os << F.numerator;
			}
			else {
				if (bracket) os << "(";
				if (F.numerator / F.denominator != 0)	os << F.numerator / F.denominator << " ";
				else if (F.numerator < 0) os << "-";
				os << abs(F.numerator) % F.denominator << "/" << F.denominator;
				if (bracket) os << ")";
			}
		}
		else {
			os << "Inf";
		}
		return os;
	}
private:
	BigInt numerator, denominator;
	bool flag;
};

int main() {
	BigInt a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	Fraction num1(a, b), num2(c, d);
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
	cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

	return 0;
}