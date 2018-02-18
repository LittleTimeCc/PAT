
/*
 
 1001. A+B Format (20)
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
 Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

 Input

 Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

 Output

 For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

 Sample Input
 -1000000 9
 Sample Output
 -999,991

*/

#include<iostream>
#include<string>

using namespace  std;

int main()
{
	string s;
	int a, b;
	cin >> a >> b;
	s=to_string(a + b);
	const size_t len = s.size();
	for(int i=0;i<len;i++)
	{
		cout << s[i];
		if(s[i]=='-')	continue;
		if ((i + 1) % 3 == len % 3 && i != len - 1)	cout << ",";
	}

	return 0;
}