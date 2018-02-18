
/*
 
 1001. A+B Format (20)
 ʱ������
 400 ms
 �ڴ�����
 65536 kB
 ���볤������
 16000 B
 �������
 Standard
 ����
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