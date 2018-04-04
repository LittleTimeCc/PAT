/*

1025. PAT Ranking (25)

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
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4

*/

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct Stu {
	char id[14];
	int score;
	int location;
	int location_rank;
	int total_rank;

	bool operator<(const Stu& a) const {
		if (this->score != a.score)
		{
			return this->score>a.score;
		}
		else
			return (strcmp(this->id, a.id)<0);
	}
};
int main()
{
	int n, k;
	vector<Stu> person;
	int total_num = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		total_num += k;
		for (int j = 0; j<k; j++)
		{
			Stu stu;
			scanf("%s %d", stu.id, &stu.score);
			stu.location = i;
			person.push_back(stu);
		}
		auto it = person.end() - k;
		sort(it, person.end());  //local sort;
		int cur_rank = 1;
		int cnt = 0;
		int last_score = -1;
		for (it; it != person.end(); it++)   //local rank;
		{
			cnt++;
			if (it->score != last_score)
			{
				it->location_rank = cnt;
				cur_rank = cnt;
				last_score = it->score;
			}
			else
			{
				it->location_rank = cur_rank;
			}
		}
	}
	sort(person.begin(), person.end());
	int cur_rank = 1;
	int cnt = 0;
	int last_score = -1;

	for (auto it = person.begin(); it != person.end(); it++)
	{
		cnt++;
		if (it->score != last_score)
		{
			it->total_rank = cnt;
			cur_rank = cnt;
			last_score = it->score;
		}
		else
			it->total_rank = cur_rank;
	}
	printf("%d\n", total_num);
	for (auto it = person.begin(); it != person.end(); it++)
	{
		printf("%s %d %d %d\n", it->id, it->total_rank, it->location, it->location_rank);
	}

	return 0;
}