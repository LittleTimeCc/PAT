/*

1062. 最简分数(20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。

输入格式：

输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。

输出格式：

在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。

输入样例：
7/18 13/20 12
输出样例：
5/12 7/12

*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int Gcd(int a, int b) {
	return b == 0 ? a : Gcd(b, a%b);
}

int main() {
	int n1, m1, n2, m2, k;
	scanf("%d/%d%d/%d%d", &n1, &m1, &n2, &m2, &k);
	if (n1*m2 > n2*m1) {
		swap(n1, n2);
		swap(m1, m2);
	}
	bool flag = true;
	for (int i = n1*k / m1 + 1; i*m2 < n2*k; i++) {
		if (Gcd(i, k) == 1) {
			if (flag) {
				cout << i << "/" << k;
				flag = false;
			}
			else {
				cout << " " << i << "/" << k;
			}
		}
	}

	return 0;
}