/*
1013. 数素数 (20)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/

#include<iostream>
#include<cmath>
using namespace std;

int a[10000];
bool isPrime(int x) {
	bool flag = true;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			flag = false;
			return flag;
		}
	}
	return flag;
}

int main()
{
	int j=0,k = 2,t=0;
	int M, N;
	cin >> M >> N;
	while (t<N){
		if (isPrime(k)) {
			t++;
			if (t >= M) {
				a[++j] = k;
			}
		}
		k++;
	}
	int row = j/10;
	if (j % 10 == 0) {
		row--;
	}
	for (int i = 0; i < row; i++) {
		for (int k = 1; k < 10; k++) {
			cout << a[10 * i + k] << " ";
		}
		cout  << a[(i+1)*10] << endl;
	}
	for (int i = row * 10 + 1; i < j; i++) {
		cout <<a[i]<<" ";
	}
	cout << a[j];
	return 0;
}