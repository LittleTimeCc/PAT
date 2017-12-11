/*

1040. 有几个PAT（25）
时间限制
120 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CAO, Peng
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2

*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int A = 0,P = 0,T = 0,Min=0;
	T = count(s.begin(), s.end(), 'T');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P')	P++;
		if (s[i] == 'T')	T--;
		if (s[i] == 'A')	Min=(Min+(P*T)% 1000000007) % 1000000007;
	}
	cout << Min;
	return 0;
}