/*

1051. �����˷� (15)

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
��������д��(A + Bi)�ĳ�����ʽ������A��ʵ����B���鲿��i��������λ������i2 = -1��Ҳ����д�ɼ������µ�ָ����ʽ(R*e(Pi))������R�Ǹ���ģ��P�Ƿ��ǣ�i��������λ����ȼ���������ʽ R(cos(P) + isin(P))��

�ָ�������������R��P��Ҫ����������˻��ĳ�����ʽ��

�����ʽ��

������һ�������θ�������������R1, P1, R2, P2�����ּ��Կո�ָ���

�����ʽ��

��һ���а��ա�A+Bi���ĸ�ʽ��������˻��ĳ�����ʽ��ʵ�����鲿������2λС����ע�⣺���B�Ǹ�������Ӧ��д�ɡ�A-|B|i������ʽ��

����������
2.3 3.5 5.2 0.4
���������
-8.68-8.23i

*/

// ###ps���������������0��0.01��ʱ��ǵ�����ȡ0;

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main() {
	double R1, P1, R2, P2,result1,result2;
	cin >> R1 >> P1 >> R2 >> P2;

	result1 = (R1*R2)*cos(P1 + P2);
	result2 = (R1*R2)*sin(P1 + P2);

	if (fabs(result1) < 0.01) {
		result1 = 0;
	}
	if (fabs(result2) < 0.01) {
		result2 = 0;
	}

	if (result2 < 0) {
		printf("%.2lf-%.2lfi", result1, fabs(result2));
	}
	else
	{
		printf("%.2lf+%.2lfi", result1, result2);
	}



	return 0;
}