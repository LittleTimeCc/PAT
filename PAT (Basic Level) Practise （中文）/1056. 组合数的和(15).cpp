/*

1056. ������ĺ�(15)
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
����N����0�ĸ�λ���֣�����������2�����ֶ�������ϳ�1��2λ�����֡�Ҫ�����п�����ϳ�����2λ���ֵĺ͡��������2��5��8���������ϳ���25��28��52��58��82��85�����ǵĺ�Ϊ330��

�����ʽ��

������һ�����ȸ���N��1<N<10���������N����ͬ�ķ�0��λ���֡����ּ��Կո�ָ���

�����ʽ��

������п�����ϳ�����2λ���ֵĺ͡�

����������
3 2 8 5
���������
330

*/


#include<set>
#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int *p = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> *(p + i);
	}
	set<int> s;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (p[j] != p[k]) {
				s.insert(p[j] * 10 + p[k]);
			}
		}
	}
	int sum = 0;
	for (auto elem : s){
		sum += elem;
	}
	
	cout << sum << endl;

	delete[]p;
	return 0;
}



