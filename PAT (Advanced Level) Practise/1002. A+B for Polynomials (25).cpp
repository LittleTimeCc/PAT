
/*

1002. A+B for Polynomials (25)
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
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2

*/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

double a[1001], b[1001];

int main()
{	
	memset(a, 0, 1001);
	memset(b, 0, 1001);

	int n, k;
	double v;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> k >> v;
		a[k] = v;
	}
	cin >> n;
	for(int j=0;j<n;j++)
	{
		cin >> k >> v;
		b[k] = v;
	}

	int ans = 0;
	for(int i=0;i<1001;i++)
	{
		a[i] += b[i];
		if (a[i])	ans++;
	}
	cout << ans;
	for(int i=1000;i>=0;i--)
	{
		if (a[i])	printf(" %d %.1lf", i, a[i]);
	}

	return 0;
}
