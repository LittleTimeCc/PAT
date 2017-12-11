/*

1043. 输出PATest(20)
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
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee

*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int P=0, A=0, T=0,e=0, s=0, t=0;
	for (auto ch : str) {
		if (ch == 'P')	P++;
		if (ch == 'A')	A++;
		if (ch == 'T')	T++;
		if (ch == 'e')	e++;
		if (ch == 's')	s++;
		if (ch == 't')	t++;
	}
	for (;;) {
		if (P != 0) { cout << "P"; P--; }
		if (A != 0) { cout << "A"; A--; }
		if (T != 0) { cout << "T"; T--; }
		if (e != 0) { cout << "e"; e--; }
		if (s != 0) { cout << "s"; s--; }
		if (t != 0) { cout << "t"; t--; }
		if (P == 0 && A == 0 && T == 0 && e == 0 && s == 0 && t == 0) break;

	}

	
	cout << endl;
	return 0;
}