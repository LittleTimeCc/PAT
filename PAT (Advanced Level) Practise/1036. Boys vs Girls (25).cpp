
/*

1036. Boys vs Girls (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Person
{
	string name;
	char sex;
	string id;
	int score;

	friend istream& operator>>(istream& in,Person& P){
		in >> P.name >> P.sex >> P.id >> P.score;			
		return in;
	}
	bool operator<(const Person& p) const{
		return this->score < p.score;
	}
};


int main() {
	int N;
	bool b = false, g = false;
	Person p;
	vector<Person> boys, girls;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> p;
		if (p.sex == 'M') { boys.push_back(p); }
		else { girls.push_back(p); }
	}
	if (!boys.empty()) { b = true; sort(boys.begin(), boys.end()); }
	if (!girls.empty()) { g = true; sort(girls.begin(), girls.end()); }
	if (!g) {
		cout << "Absent" << endl;
		if (!b)	cout << "Absent" << endl;
		else	cout<< boys.front().name<<" "<< boys.front().id<<endl;
		cout << "NA" << endl;
	}
	else
	{
		cout << girls.back().name << " " << girls.back().id << endl;
		if(!b)
		{
			cout << "Absent" << endl;
			cout << "NA" << endl;
			return 0;
		}
		cout << boys.front().name << " " << boys.front().id << endl;
		cout << girls.back().score - boys.front().score << endl;
	}

	return 0;
}