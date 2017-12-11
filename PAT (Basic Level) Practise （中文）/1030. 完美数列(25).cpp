/*

1030. 完美数列(25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CAO, Peng
给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long BigInt;
int main()
{
	int N;
	BigInt p;
	cin >> N >> p;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	int result = 0;
	for (int i = 0; i < N; i++) {
		int pos = upper_bound(num.begin(), num.end(), num[i] * p) - num.begin();
		if (pos - 1 >= 0)	pos--;
		result = max(result, pos - i + 1);
	}
	cout << result << endl;

	return 0;
}
