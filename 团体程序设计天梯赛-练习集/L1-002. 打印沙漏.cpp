
/*

L1-002. 打印沙漏
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2

*/

#include<iostream>
using namespace std;

int main() {
	int N,rows=0;
	char ch;
	cin >> N >> ch;
	for (int j = 1; j < N; j++) {
		if ((2*j*(j + 2) + 1)>N){	
			rows = j-1;
			break;
		}
	}
	for (int i = rows; i > 0; i--) {
		for (int j = rows - i; j > 0; j--) {
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << ch;
		}
		cout << endl;
	}

	for (int i = 0; i < rows;i++) {
		cout << " ";
	}
	cout << ch << endl;
	for (int i = 1; i <= rows; i++) {
		for (int j = rows - i; j >= 1 ; j--) {
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << ch;
		}
		cout << endl;
	}
	cout << N - (2 * rows*(rows + 2) + 1)<<endl;
	return 0;
}