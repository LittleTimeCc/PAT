/*
1007. �����Բ��� (20)

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
�����Ƕ��� dn Ϊ��dn = pn+1 - pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1�� dn ��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N (< 105)������㲻����N���������������Եĸ�����

�����ʽ��ÿ�������������1����������������������N��

�����ʽ��ÿ���������������ռһ�У�������N���������������Եĸ�����

����������
20
���������
4
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime_Num(int num)
{
	int k = sqrt(num);
	bool flag = true;
	for (int j = 2; j <= k; j++) {
		if (num%j == 0) {
			flag = false;
		}
	}
	
	return flag;
}

int main()
{
	vector<int> primes;
	int N,count=0;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		if (isPrime_Num(i))
			primes.push_back(i);
	}


	for (int j = 0; j < primes.size()-1; j++)
	{
		if (primes[j + 1] - primes[j] == 2)
			count++;
	}

	cout << count << endl;
 
	return 0;
}