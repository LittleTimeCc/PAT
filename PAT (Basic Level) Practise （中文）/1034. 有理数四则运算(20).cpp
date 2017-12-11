/*

1034. 有理数四则运算(20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
本题要求编写程序，计算2个有理数的和、差、积、商。

输入格式：

输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。

输出格式：

分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。

输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
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