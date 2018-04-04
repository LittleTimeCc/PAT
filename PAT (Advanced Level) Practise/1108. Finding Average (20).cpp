
/*

1108. Finding Average (20)

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
The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A "legal" input is a real number in [-1000, 1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then N numbers are given in the next line, separated by one space.

Output Specification:

For each illegal input number, print in a line "ERROR: X is not a legal number" where X is the input. Then finally print in a line the result: "The average of K numbers is Y" where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case the average cannot be calculated, output "Undefined" instead of Y. In case K is only 1, output "The average of 1 number is Y" instead.

Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

Sample Input 2:
2
aaa -9999

Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

*/
#include<cstdio>
#include<vector>
#include<cstring>

std::vector<double> ans;

bool is_Valid(const char* str);
int main()
{
	int n;
	char a[50];
	double sum = 0.0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%s", a);
		if (!is_Valid(a))
		{
			printf("ERROR: %s is not a legal number\n", a);
		}
	}
	auto cnt = ans.size();
	if (cnt == 0)	 //注意number 和 numbers
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (cnt == 1)   
	{
		printf("The average of 1 number is %.2lf\n", ans.front());
	}
	else
	{
		for (const auto num : ans)
		{
			sum += num;
		}
		printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt * 1.0);
	}

	return 0;
}

bool is_Valid(const char* str)
{
	char s[100];
	double t;
	sscanf(str, "%lf", &t);
	sprintf(s, "%.2lf", t);
	if (strlen(str)>strlen(s))
		return false;
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] != s[i])
			return false;
	}
	if (t>1000.0 || t<-1000.0)
		return false;

	ans.push_back(t);
	return true;
}