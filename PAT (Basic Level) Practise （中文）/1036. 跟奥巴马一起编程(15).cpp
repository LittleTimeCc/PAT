/*

1036. 跟奥巴马一起编程(15)
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
美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

输入格式：

输入在一行中给出正方形边长N（3<=N<=20）和组成正方形边的某种字符C，间隔一个空格。

输出格式：

输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的50%（四舍五入取整）。

输入样例：
10 a
输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa

*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int N;
	char ch;
	cin >> N >> ch;
	int m = N / 2 + N % 2;
	for (int i = 0; i < N; i++) {
		cout << ch;
	}
	cout << endl;
	for (int j = 0; j < m - 2; j++) {
		cout << ch;
		for (int k = 0; k < N - 2; k++) {
			cout << " ";
		}
		cout << ch << endl;
	}
	for (int i = 0; i < N; i++) {
		cout << ch;
	}
	cout << endl;
	return 0;
}