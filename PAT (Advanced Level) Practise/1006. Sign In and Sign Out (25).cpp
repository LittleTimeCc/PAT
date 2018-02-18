/*

1006. Sign In and Sign Out (25)
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
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

struct LogIn
{
	string id;
	int Begin, End;
};

int main()
{
	int n,hh,mm,ss;
	cin >> n;
	LogIn L;
	vector<LogIn> v;
	for(int i=0;i<n;i++)
	{
		cin >> L.id;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		L.Begin = hh * 3600 + mm * 60 + ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		L.End = hh * 3600 + mm * 60 + ss;
		v.push_back(L);
	}
	sort(v.begin(), v.end(), [](const LogIn& lhs, const LogIn& rhs) {return lhs.Begin < rhs.Begin; });
	cout << v.front().id << " ";
	sort(v.begin(), v.end(), [](const LogIn& lhs, const LogIn& rhs) {return lhs.End> rhs.End; });
	cout << v.front().id << endl;

	return 0;
}
