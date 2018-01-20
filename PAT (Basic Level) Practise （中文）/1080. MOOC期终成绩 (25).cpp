
/*

1080. MOOC期终成绩 (25)
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
对于在中国大学MOOC（http://www.icourse163.org/）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G = (G期中x 40% + G期末x 60%)，如果 G期中 > G期末；否则总评 G 就是 G期末。这里 G期中 和 G期末 分别为学生的期中和期末成绩。

现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

输入格式：

输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。

接下来有三块输入。第一块包含 P 个在线编程成绩 G编程；第二块包含 M 个期中考试成绩 G期中；第三块包含 N 个期末考试成绩 G期末。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

输出格式：

打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 G编程 G期中 G期末 G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“-1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84

*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Info
{
	string name;
	int gb,g1, g2, g;
	Info(const string n="",int a=-1,int b=-1,int c=-1,int d=0):name(n),gb(a),g1(b),g2(c),g(d){}

	bool operator<(const Info& A)const
	{
		return this->g == A.g ? A.name > this->name : A.g < this->g;
	}
	friend ostream& operator<<(ostream& os,const Info& I)
	{
		os << I.name << " " << I.gb << " " << I.g1 << " " << I.g2 << " " << I.g << endl;
		return os;
	}
};

int main() {
	int p, m, n;
	string str;
	map<string, Info> Map;
	vector<Info> v;
	int score;
	cin >> p >> m >> n;
	for(int i=0;i<p;i++)
	{
		cin >> str >> score;
		if(score>=200)
		{
			Map[str] = Info(str, score, -1, -1, 0);
		}
	}
	for(int i=0;i<m;i++)
	{
		cin >> str >> score;
		if(Map.count(str))
		{
			Map[str].g1 = score;
		}
		else
		{
			continue;
		}
	}

	for(int i=0;i<n;i++)
	{
		cin >> str >> score;
		if(Map.count(str))
		{
			Map[str].g2 = score;
			if(Map[str].g1>Map[str].g2)
			{
				Map[str].g = (Map[str].g1*0.4 + Map[str].g2*0.6 + 0.5);
			}
			else
			{
				Map[str].g = score;
			}
			if(Map[str].g>=60)
			{
				v.push_back(Map[str]);
			}
		}
		else
		{
			continue;
		}
	}
	sort(v.begin(), v.end());
	for(const auto& elem:v)
	{
		cout << elem;
	}
	return 0;
}