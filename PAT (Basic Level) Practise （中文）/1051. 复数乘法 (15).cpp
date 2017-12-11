/*

1051. 复数乘法 (15)

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
复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i2 = -1；也可以写成极坐标下的指数形式(R*e(Pi))，其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式 R(cos(P) + isin(P))。

现给定两个复数的R和P，要求输出两数乘积的常规形式。

输入格式：

输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。

输出格式：

在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。

输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i

*/

// ###ps：当两个结果介于0到0.01的时候记得向下取0;

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main() {
	double R1, P1, R2, P2,result1,result2;
	cin >> R1 >> P1 >> R2 >> P2;

	result1 = (R1*R2)*cos(P1 + P2);
	result2 = (R1*R2)*sin(P1 + P2);

	if (fabs(result1) < 0.01) {
		result1 = 0;
	}
	if (fabs(result2) < 0.01) {
		result2 = 0;
	}

	if (result2 < 0) {
		printf("%.2lf-%.2lfi", result1, fabs(result2));
	}
	else
	{
		printf("%.2lf+%.2lfi", result1, result2);
	}



	return 0;
}