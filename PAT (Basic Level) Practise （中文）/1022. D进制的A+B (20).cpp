/*

1022. D进制的A+B (20)

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
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103

*/

#include<iostream>
#include<stack>
using namespace std;

stack<int> Dnum(int num,int D)
{
	stack<int> result;
	while (num) {
		result.push(num%D);
		num /= D;
	}
	return result;
}

int main()
{
	int A, B, D;
	cin >> A >> B >> D;
	int temp = A + B;
	if (!temp) {
		cout << 0 << endl;
		return 0;
	}
	stack<int> result = Dnum(temp,D);
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	cout << endl;
	return 0;
}