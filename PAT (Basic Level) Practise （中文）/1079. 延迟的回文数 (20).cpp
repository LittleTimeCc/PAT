
/*

1079. �ӳٵĻ����� (20)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����һ�� k+1 λ�������� N��д�� ak...a1a0 ����ʽ�����ж����� i �� 0 <= ai < 10 �� ak > 0��N ����Ϊһ�������������ҽ��������� i �� ai = ak-i����Ҳ������Ϊһ����������

�ǻ�����Ҳ����ͨ��һϵ�в�����������������Ƚ���������ת���ٽ���ת���������ӣ�����ͻ�����һ�������������ظ������ת����ӵĲ�����ֱ��һ�����������֡����һ���ǻ��������Ա�����������ͳ������Ϊ�ӳٵĻ������������巭���� https://en.wikipedia.org/wiki/Palindromic_number��

��������һ��������������Ҫ�����ҵ��������Ǹ���������

�����ʽ��

������һ���и���һ��������1000λ����������

�����ʽ��

�Ը�����������һ��һ����������������Ĺ��̡�ÿ�и�ʽ����

A + B = C
����A��ԭʼ�����֣�B��A����ת����C�����ǵĺ͡�A�������������ʼ���ظ�����ֱ��C��10�����ڱ�ɻ���������ʱ��һ���������C is a palindromic number.�����������10����û�ܵõ���������������һ���������Not found in 10 iterations.����

�������� 1��
97152
������� 1��
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
�������� 2��
196
������� 2��
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.

*/


/*
 *  ����˼·�������ʵ���Ͽ�����Ǵ������ļӷ�:(��ѡ�ַ���);
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

static string s1, s2, result;

void add_Str()
{
	result.clear();
	int len = s1.size();
	int carry = 0;
	for(int i=len-1;i>=0;i--)
	{
		carry += (s1[i] - '0') + (s2[i] - '0');
		result.insert(result.begin(), (carry % 10) + '0');
		carry /= 10;
	}
	if (carry)	result.insert(result.begin(), carry + '0');
}

bool judge_Palindromic_Number()
{
	int len = result.size();
	for(int i=0;i<len/2;i++)
	{
		if(result[i]!=result[len-1-i])
		{
			return false;
		}
	}
	return true;
}

int main() {
	cin >> s1;
	int count = 1;
	result = s1;
	if(judge_Palindromic_Number())
	{
		cout << result << " is a palindromic number.\n";
		return 0;
	}
	while (count<=10)
	{
		count++;
		s2.clear();
		s2 = s1;
		reverse(s2.begin(), s2.end());
		cout << s1 << " + " << s2 << " = ";
		add_Str();
		cout << result << endl;
		if (judge_Palindromic_Number() && count <= 10)
		{
			cout << result << " is a palindromic number.\n";
			break;
		}
 		else if(count>10)
		{
			cout<<"Not found in 10 iterations.\n";
		}
		s2.clear();
		s1 = result;
	}

	return 0;
}