/*
1002. д������� (20)

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

����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10100��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789
���������
yi san wu

*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main()
{
	string	map[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	vector<string> ret;
	int sum = 0;
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		sum += input[i] - '0';
	}

	if (sum == 0)	ret.push_back(map[0]);

	while (sum)
	{
		ret.push_back(map[sum % 10]);
		sum /= 10;
	}

	cout << ret[ret.size()-1];
	for (int j = ret.size()-2; j>=0; j--) {
		cout << " " << ret[j];
	}
	cout << endl;

	return 0;
}