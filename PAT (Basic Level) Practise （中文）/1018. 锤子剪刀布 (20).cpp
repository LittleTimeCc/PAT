/*

1018. 锤子剪刀布 (20)
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
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B

*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N,p1=0,p2=0;
	char ch1, ch2;
	char Map[4] = { "BCJ" };
	cin >> N;
	vector<int> play1(3), play2(3);
	for (int i = 0; i < N; i++) {
		cin >> ch1 >> ch2;
		if (ch1 == 'B'&&ch2 == 'C') {
			p1++;
			play1[0]++;
		}else if (ch1=='B'&&ch2=='J'){
			p2++;
			play2[2]++;
		}
		else if (ch1 == 'C'&&ch2 == 'B') {
			p2++;
			play2[0]++;
		}
		else if (ch1 == 'C'&&ch2 == 'J') {
			p1++;
			play1[1]++;
		}
		else if (ch1 == 'J'&&ch2 == 'B') {
			p1++;
			play1[2]++;
		}
		else if (ch1 == 'J'&&ch2 == 'C') {
			p2++;
			play2[1]++;
		}
	}
	cout << p1 << " " << N - p1 - p2 << " " << p2 << endl << p2 << " " << N - p1 - p2 << " " << p1 << endl;
	int M1 = play1[0] >= play1[1] ? 0 : 1;
	M1 = play1[M1] >= play1[2] ? M1 : 2;
	int M2 = play2[0] >= play2[1] ? 0 : 1;
	M2 = play2[M2] >= play2[2] ? M2 : 2;
	cout << Map[M1] << " " << Map[M2];

	return 0;
}