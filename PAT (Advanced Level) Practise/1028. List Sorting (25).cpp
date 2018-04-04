
/*

1028. List Sorting (25)

时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90

*/

#include<cstring>
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Info {
	int id;
	char name[20];
	int score;
};

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	Info t;
	vector<Info> v(N);
	for (size_t i = 0; i<N; i++) {
		scanf("%d%s%d", &(v[i].id), v[i].name, &(v[i].score));
	}
	switch (K)
	{
	case 1:
		sort(v.begin(), v.end(), [](const Info& lhs, const Info& rhs) {return lhs.id<rhs.id; });
		break;

	case 2:
	{
		sort(v.begin(), v.end(), [](const Info& lhs, const Info& rhs) {
			if (strcmp(lhs.name,rhs.name)<0) return true;
			else if (!strcmp(lhs.name, rhs.name)) return lhs.score>rhs.score;
			else return false;
		}
		);
	}
	break;

	case 3:
	{
		sort(v.begin(), v.end(), [](const Info& lhs, const Info& rhs) {
			if (lhs.score < rhs.score) return true;
			else if (lhs.score == rhs.score)  return lhs.id < rhs.id;
			else return false; });
	}
	break;
	}

	for (size_t i = 0; i<N; i++) {
		printf("%06d %s %d\n", v[i].id, v[i].name, v[i].score);
	}

	return 0;
}