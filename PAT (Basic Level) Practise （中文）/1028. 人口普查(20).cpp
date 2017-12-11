/*

1028. 人口普查(20)
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
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct People {
	string name;
	int year;
	int month;
	int day;
	friend istream& operator>>(istream& in, People& P) {
		char ch1, ch2;
		in >> P.name >> P.year>>ch1 >> P.month >> ch2 >> P.day;
		return in;
	}
	bool operator<(const People& rhs){
		if (this->year == rhs.year) {
			if (this->month == rhs.month)	
				return this->day < rhs.day;
			else  
				return this->month < rhs.month;		
			}
		else
		{
			return this->year < rhs.year;
		}
	}

};

int main()
{
	int N;
	vector<People> v;;
	cin >> N;
	People people;
	for (int i = 0; i < N; i++) {
		cin >> people;
		int age = 2014 - people.year;
		if (age > 200 || (age == 200 && (people.month < 9 || (people.month == 9 && people.day < 6))))
			continue;
		else if (age < 0 || (age == 0 && (people.month > 9 || (people.month == 9 && people.day > 6))))
			continue;
		else{
			v.push_back(people);
		}

	}	 

	sort(v.begin(), v.end());
	if (v.empty())
		cout << "0\n";
	else
		cout << v.size() <<" " << v.front().name << " " << v.back().name << endl;
	return 0;
}

