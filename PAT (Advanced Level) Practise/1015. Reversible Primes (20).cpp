
/*

1015. Reversible Primes (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.
Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.
Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No

*/

#include<iostream>
#include<cassert>
#include<cmath>
#include<vector>

using namespace std;

inline static bool isPrime(int x) {
	assert(x > 0);
	if (x < 2)	return false;
	for (int i = 2; i <= static_cast<int>(floor(sqrt(x)+0.05)); i++) {
		if (x%i == 0) return false;
	}
	return true;
}

inline static int D_Reverse(int x, int d) {
	vector<int> v;
	while (x) {
		v.push_back(x%d);
		x /= d;
	}
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res = (res*d + v[i]);
	}
	
	return res;
}

int main() {
	int n, d;
	while (cin >> n,  n >= 0) {
		cin >> d;
		if (isPrime(n)) {
			int rn = D_Reverse(n, d);
			if (isPrime(rn)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}