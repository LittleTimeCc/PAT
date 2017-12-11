/*

1059. C语言竞赛(20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2. 其他人将得到巧克力。

给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。

输入格式：

输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。

输出格式：

对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。

输入样例：
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

*/

#include<iostream>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;

bool isPrime(int x) {
	for (int i = 2; i < static_cast<int>((x)); i++) {
		if (x%i == 0)	return false;
	}
	return true;
}


bool check[10000] = { 0 };
int main() {
	unordered_map<string, int> Map;
	string s;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		Map[s] = i;
	}
	int M;
	cin >> M;
	string ss;
	for (int j = 0; j < M; j++) {
		cin >> ss;
		if (Map.count(ss) > 0) {
			if (Map[ss] == 1) {
				if (check[Map[ss]] == 0){
					cout << ss << ": Mystery Award" << endl;
					check[Map[ss]] = 1;
			}
				else
					cout << ss << ": Checked" << endl;
			}
			else if (isPrime(Map[ss])) {
				if (check[Map[ss]] == 0) {
					cout << ss << ": Minion" << endl;
					check[Map[ss]] = 1;
				}
				else
					cout << ss << ": Checked" << endl;
			}
			else
			{
				if (check[Map[ss]] == 0) {
					cout << ss << ": Chocolate" << endl;
					check[Map[ss]] = 1;
				}
				else
					cout << ss << ": Checked" << endl;
			}
		}
		else{
			cout << ss << ": Are you kidding?" << endl;
		}		
	}

	return 0;
}