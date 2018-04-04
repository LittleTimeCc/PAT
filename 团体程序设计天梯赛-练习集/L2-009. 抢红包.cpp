
/*

L2-009. 抢红包

时间限制
300 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
没有人没抢过红包吧…… 这里给出N个人之间互相发红包、抢红包的记录，请你统计一下他们抢红包的收获。

输入格式：

输入第一行给出一个正整数N（<= 104），即参与发红包和抢红包的总人数，则这些人从1到N编号。随后N行，第i行给出编号为i的人发红包的记录，格式如下：

K N1 P1 ... NK PK

其中K（0 <= K <= 20）是发出去的红包个数，Ni是抢到红包的人的编号，Pi（> 0）是其抢到的红包金额（以分为单位）。注意：对于同一个人发出的红包，每人最多只能抢1次，不能重复抢。

输出格式：

按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出。

输入样例：
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10
输出样例：
1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32

*/

#include<algorithm>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

struct Info {
	int id,cnt,balance;
};

int main() {
	int n, k, a, b;
	cin >> n;
	vector<Info> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i].id = i;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			v[i].balance -= b;
			v[a].balance += b;
			v[a].cnt++;
		}
	}
	sort(v.begin() + 1, v.end(), [](const Info& lhs,const Info& rhs) {
		if (lhs.balance == rhs.balance) {
			if (lhs.cnt == rhs.cnt)	return lhs.id < rhs.id;
			else  return lhs.cnt > rhs.cnt;
		}
		else  return lhs.balance > rhs.balance;
	});

	for (auto it = v.begin() + 1; it != v.end(); it++) {
		double t = static_cast<double>(it->balance*1.0 / 100);
		printf("%d %.2lf\n", it->id, t);
	}

	return 0;
}