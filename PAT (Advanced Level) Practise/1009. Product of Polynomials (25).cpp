/*

1009. Product of Polynomials (25)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6

*/

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

static double a[1001], b[1001], c[2002];

int main() {
	int n, k;
	double v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k >> v;
		a[k] = v;
	}
	cin >> n;
	for (int j = 1; j <= n; j++) {
		cin >> k >> v;
		b[k] = v;
	}
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	int cnt = count_if(begin(c), end(c), [](int a) {return a != 0.0; });
	cout << cnt;
	for (int i = 2000; i >= 0;i--) {
		if (c[i]) printf(" %d %.1lf", i, c[i]);
	}
	
	return 0;
}



