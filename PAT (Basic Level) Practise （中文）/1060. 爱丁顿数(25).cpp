/*

1060. ��������(25)
ʱ������
250 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
Ӣ������ѧ�Ұ����ٺ�ϲ���ﳵ����˵��Ϊ����ҫ�Լ����ﳵ��������������һ��������������E����������E���ﳵ����EӢ����������E����˵�������Լ���E����87��

�ָ���ĳ��N����ﳵ���룬���������Ӧ�İ�������E��<=N����

�����ʽ��

�����һ�и���һ��������N��<=105�����������ﳵ���������ڶ��и���N���Ǹ�����������ÿ����ﳵ���롣

�����ʽ��

��һ���и���N��İ���������

����������
10
6 7 6 9 3 10 8 2 7 8
���������
6

*/

//PS:  ###### �������Ͱ���򼴿�
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int Bucket[100000];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Bucket[i];
	}
	sort(begin(Bucket) + 1, begin(Bucket) + 1 + N, greater<int>());
	int j = 1,ret=0;
	for (;j <= N;) {
		if (Bucket[j] > j) {
			j++; ret++;		
		}
		else
		{
			break;
		}
	}
	cout << ret << endl;

	return 0;
}