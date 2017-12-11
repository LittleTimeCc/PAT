/*

1022. D���Ƶ�A+B (20)

ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
���������Ǹ�10��������A��B(<=230-1)�����A+B��D (1 < D <= 10)��������

�����ʽ��

������һ�������θ���3������A��B��D��

�����ʽ��

���A+B��D��������

����������
123 456 8
���������
1103

*/

#include<iostream>
#include<stack>
using namespace std;

stack<int> Dnum(int num,int D)
{
	stack<int> result;
	while (num) {
		result.push(num%D);
		num /= D;
	}
	return result;
}

int main()
{
	int A, B, D;
	cin >> A >> B >> D;
	int temp = A + B;
	if (!temp) {
		cout << 0 << endl;
		return 0;
	}
	stack<int> result = Dnum(temp,D);
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	cout << endl;
	return 0;
}