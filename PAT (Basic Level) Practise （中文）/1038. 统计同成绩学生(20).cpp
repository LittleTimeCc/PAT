/*

1038. ͳ��ͬ�ɼ�ѧ��(20)
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
����Ҫ�����N��ѧ���ĳɼ��������ĳһ����������ѧ�����������

�����ʽ��

�����ڵ�1�и���������105��������N����ѧ�������������1�и���N��ѧ���İٷ��������ɼ����м��Կո�ָ������1�и���Ҫ��ѯ�ķ�������K��������N�����������������K���������м��Կո�ָ���

�����ʽ��

��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�

����������
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
���������
3 2 0

*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	int N;
	vector<int> scores;
	map<int, int> Map;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		Map[num]++;
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		scores.push_back(num);
	}

	cout << Map[scores[0]];
	for (int j = 1; j < scores.size(); j++) {
		cout << " " << Map[scores[j]];
	}

	return 0;
}
