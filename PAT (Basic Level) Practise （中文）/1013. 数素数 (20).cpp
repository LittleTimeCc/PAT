/*
1013. ������ (20)

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
��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�

����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/

#include<iostream>
#include<cmath>
using namespace std;

int a[10000];
bool isPrime(int x) {
	bool flag = true;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			flag = false;
			return flag;
		}
	}
	return flag;
}

int main()
{
	int j=0,k = 2,t=0;
	int M, N;
	cin >> M >> N;
	while (t<N){
		if (isPrime(k)) {
			t++;
			if (t >= M) {
				a[++j] = k;
			}
		}
		k++;
	}
	int row = j/10;
	if (j % 10 == 0) {
		row--;
	}
	for (int i = 0; i < row; i++) {
		for (int k = 1; k < 10; k++) {
			cout << a[10 * i + k] << " ";
		}
		cout  << a[(i+1)*10] << endl;
	}
	for (int i = row * 10 + 1; i < j; i++) {
		cout <<a[i]<<" ";
	}
	cout << a[j];
	return 0;
}