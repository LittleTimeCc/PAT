/*

1116. Come on! Let's C (20)

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
"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the idea of the contest is for fun, the award rules are funny as the following:

0. The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
1. Those who ranked as a prime number will receive the best award -- the Minions (小黄人)!
2. Everyone else will receive chocolates.

Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10000), the total number of contestants. Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer K followed by K query ID's.

Output Specification:

For each query, print in a line "ID: award" where the award is "Mystery Award", or "Minion", or "Chocolate". If the ID is not in the ranklist, print "Are you kidding?" instead. If the ID has been checked before, print "ID: Checked".

Sample Input:
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
Sample Output:
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

*/

#include<map>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;

map<int, int> Map;
set<int> s;
int index = 1;

inline bool is_Prime(int x)
{
	int n = static_cast<int>(sqrt(x));
	for (int i = 2; i <= n; i++)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n, t, k;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &t);
		Map[t] = index++;
	}
	scanf("%d", &k);
	for (int i = 0; i<k; i++)
	{
		scanf("%d", &t);
		if (!s.count(t))
		{
			if (Map.find(t) == Map.end())
			{
				printf("%04d: Are you kidding?\n", t);
			}
			else if (Map[t] == 1)
			{
				printf("%04d: Mystery Award\n", t);
				s.insert(t);
			}
			else if (is_Prime(Map[t]))
			{
				printf("%04d: Minion\n", t);
				s.insert(t);
			}
			else
			{
				printf("%04d: Chocolate\n", t);
				s.insert(t);
			}
		}
		else
		{
			printf("%04d: Checked\n", t);
		}
	}

	return 0;
}