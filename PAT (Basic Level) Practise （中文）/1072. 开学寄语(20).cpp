/*

1072. 开学寄语(20)
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

本题要求你写个程序帮助这所学校的老师检查所有学生的物品，以助其成大器。

输入格式：

输入第一行给出两个正整数N（<= 1000）和M（<= 6），分别是学生人数和需要被查缴的物品种类数。第二行给出M个需要被查缴的物品编号，其中编号为4位数字。随后N行，每行给出一位学生的姓名缩写（由1-4个大写英文字母组成）、个人物品数量K（0 <= K <= 10）、以及K个物品的编号。

输出格式：

顺次检查每个学生携带的物品，如果有需要被查缴的物品存在，则按以下格式输出该生的信息和其需要被查缴的物品的信息（注意行末不得有多余空格）：

姓名缩写: 物品编号1 物品编号2 ……
最后一行输出存在问题的学生的总人数和被查缴物品的总数。

输入样例：
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
输出样例：
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	int m, n, a,count1=0,count2=0;
	cin >> m >> n;
	vector<bool> exist(10000, false);
	for (int i = 0; i < n; i++) {
		cin >> a;
		exist[a] = true;
	}
	string s;
	int b, c;
	for (int j = 0; j < m; j++) {
		bool flag = true;
		cin >> s >> b;
		for (int i = 0; i < b; i++) {
			cin >> c;
			if (exist[c]) {
				if (flag)
				{
					cout << s << ":";
					count1++;
					flag = false;
				}
				printf(" %04d", c);
				count2++;
			}
		}
		if(!flag)
			cout << endl;
	}
	cout << count1 <<" "<< count2 << endl;

	return 0;
}