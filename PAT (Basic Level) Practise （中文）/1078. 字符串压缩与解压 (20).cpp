
/*

1078. �ַ���ѹ�����ѹ (20)
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
�ı�ѹ���кܶ��ַ�������������ֻ������򵥵�һ�֣�������ͬ�ַ���ɵ�һ��������Ƭ��������ַ���Ƭ���к�������ַ��ĸ�������ʾ������ ccccc ���� 5c ����ʾ������ַ�û���ظ�����ԭ����������� aba ѹ������Ȼ�� aba��

��ѹ�������Ƿ������������� 5c �����ı�ʾ�ָ�Ϊ ccccc��

������Ҫ�����ѹ�����ѹ��Ҫ�󣬶Ը����ַ������д����������Ǽ򵥵ؼ���ԭʼ�ַ�������ȫ��Ӣ����ĸ�Ϳո���ɵķǿ��ַ�����

�����ʽ��

�����һ�и���һ���ַ�������� C �ͱ�ʾ������ַ�����Ҫ��ѹ��������� D �ͱ�ʾ������ַ�����Ҫ����ѹ���ڶ��и�����Ҫ��ѹ�����ѹ�Ĳ�����1000���ַ����ַ������Իس���β����Ŀ��֤�ַ��ظ����������ͷ�Χ�ڣ�������ļ�������1MB��

�����ʽ��

����Ҫ��ѹ�����ѹ�ַ���������һ������������

�������� 1��
C
TTTTThhiiiis isssss a   tesssst CAaaa as
������� 1��
5T2h4is i5s a3 te4st CA3a as
�������� 2��
D
5T2h4is i5s a3 te4st CA3a as10Z
������� 2��
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ


*/

#include<iostream>
#include<string>

using namespace std;

int main() {
	string choice, t;
	getline(cin, choice);
	getline(cin, t);
	int sum = 1;
	if(choice=="C")
	{
		for(int i=1;i<t.size()+1;i++)	//�ӵڶ�����ʼ�ȽϵĻ��������������'\0';
		{
			if(t[i]==t[i-1])
			{
				sum++;
			}else
			{
				if (sum == 1)
					cout << t[i - 1];
				else
				{
					cout << sum << t[i - 1];
				}
				sum = 1;
			}
		}
	}
	else
	{
		int flag = 1;
		for(int i=0;i<t.size();i++)
		{
			/*
			 * �ַ���ת���֣�ע�����9�������
			 */
			if(t[i]>='0'&&t[i]<='9')
			{
				if(flag)
				{
					sum = t[i] - '0';
					flag = 0;
				}
				else
				{
					sum = sum * 10 + (t[i] - '0');
				}
			}else
			{
				for(int j=0;j<sum;j++)
				{
					cout << t[i];
				}
				sum = 1;
				flag = 1;
			}
		}		
	}

	return 0;
}