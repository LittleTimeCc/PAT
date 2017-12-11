/*

1061. 判断题(15)
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
判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。

输入格式：

输入在第一行给出两个不超过100的正整数N和M，分别是学生人数和判断题数量。第二行给出M个不超过5的正整数，是每道题的满分值。第三行给出每道题对应的正确答案，0代表“非”，1代表“是”。随后N行，每行给出一个学生的解答。数字间均以空格分隔。

输出格式：

按照输入的顺序输出每个学生的得分，每个分数占一行。

输入样例：
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
输出样例：
13
11
12

*/

#include<iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int *a = new int[M];
	int *b = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
		
		for (int i = 0; i < N; i++) {
			int ans, sum = 0;
			for (int j = 0; j < M; j++) {
				cin >> ans;
				if (ans == b[j])
				{
					sum += a[j];
				}

			}
			cout << sum << endl;
		}
	return 0;
}