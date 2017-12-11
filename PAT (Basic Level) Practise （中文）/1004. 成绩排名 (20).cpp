/*
1004. 成绩排名 (20)

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


读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：每个测试输入包含1个测试用例，格式为

第1行：正整数n
第2行：第1个学生的姓名 学号 成绩
第3行：第2个学生的姓名 学号 成绩
... ... ...
第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Stu {
	string name;
	string num;
	int score;

	friend istream& operator >> (istream& is, Stu& obj) {
		is >> obj.name >> obj.num >> obj.score;
		return is;
	}
};

int main()
{
	vector<Stu> inputs;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Stu temp;
		cin >> temp;
		inputs.push_back(temp);
	}

	sort(inputs.begin(), inputs.end(), [](const Stu& lhs, const Stu& rhs) {return lhs.score > rhs.score; });
	cout << inputs.front().name << " " << inputs.front().num << endl;
	cout << inputs.back().name << " " << inputs.back().num << endl;

	return 0;
}