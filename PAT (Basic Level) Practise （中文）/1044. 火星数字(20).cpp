/*

1044. 火星数字(20)
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
火星人是以13进制计数的：

 地球人的0被火星人称为tret。
 地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
 火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
 例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13

*/

#include<iostream>
#include<string>
using namespace std;

typedef void(*FuncStr)(const string&);
const string a[] = { "","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const string b[] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void Fun1_Str(const string& s) {
	unsigned int Len = s.size();
	int index;
	if (Len == 1)	index = s[0] - '0';
	else if (Len == 2)	index = (s[0] - '0') * 10 + (s[1] - '0');
	else index = (s[0] - '0') * 100 + (s[1] - '0')*10+(s[2]-'0');

	if (index <= 12)	cout << a[index] << endl;
	else if (index % 13 == 0) cout << b[index / 13] << endl;
	else cout << b[index / 13] << " " << a[index % 13] << endl;
}

void Fun2_Str(const string& s) {
	unsigned int Len = s.size();
	if (Len == 3) {
		for (int i = 1; i <= 12; i++) {
			if (s[0] == a[i][0] && s[1] == a[i][1] && s[2] == a[i][2]) {
				cout << i << endl;
			}
			else if (s[0] == b[i][0] && s[1] == b[i][1] && s[2] == b[i][2]) {
				cout << 13 * i << endl;
			}
		}
	}
	else {
		int high = 0, low = 0;
		for (int j = 1; j <= 12; j++) {
			if (s[0] == b[j][0] && s[1] == b[j][1] && s[2] == b[j][2]) {
				high = j;
			}
			if (s[4] == a[j][0] && s[5] == a[j][1] && s[6] == a[j][2]) {
				low = j;
			}
		}
		cout << high * 13 + low << endl;
	}
}

int main(){
	int N;
	cin >> N;
	getchar();
	FuncStr NumToChar = Fun1_Str, CharToNum = Fun2_Str;
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		if (s.size() == 1 && s[0] == '0')
			cout << "tret" << endl;
		else {
			if (s[0]  >= '0'&&s[0] <= '9') {
				NumToChar(s);
			}
			else {
				CharToNum(s);
			}
		}

	}
	return 0;
}