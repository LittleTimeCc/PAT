/*

1052. 卖个萌 (20)

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

萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。

之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。

输入样例：
[╮][╭][o][~\][/~]  [<][>]
[╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	vector<vector<string>> Map;
	for (int i = 0; i < 3; i++){
		string str;
		getline(cin,str);
		vector<string> looks;
		int j = 0,k = 0;
		while (j < str.size()) {
			if (str[j] == '[') {
				while (k++ < str.size()) {
					if (str[k] == ']') {
						looks.push_back(str.substr(j + 1, k - j - 1));
						break;
					}
				}
			}
			j++;
		}
		Map.push_back(looks);
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (a > Map[0].size() || b > Map[1].size() || c > Map[2].size() || d > Map[1].size() || e > Map[0].size() || a < 1 || b < 1 || c < 1 || d < 1 || e < 1) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		cout << Map[0][a-1] << "(" << Map[1][b - 1] << Map[2][c - 1] << Map[1][d - 1] << ")" << Map[0][e - 1] << endl;
	}


	return 0;
}



