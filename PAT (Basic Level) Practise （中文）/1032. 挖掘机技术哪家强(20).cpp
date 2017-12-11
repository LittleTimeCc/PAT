/*

1032. �ھ�������ļ�ǿ(20)
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��

�����ڵ�1�и���������105��������N�����������������N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ���1��ʼ������ţ�����������ɼ����ٷ��ƣ����м��Կո�ָ���

�����ʽ��

��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�

����������
6
3 65
2 80
1 100
2 70
3 40
3 0
���������
2 150

*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N,id,score;
	cin >> N;
	vector<int> result(N+1);
	for (int i = 0; i < N; i++) {
		cin >> id >> score;
		result[id] += score;
	}
	int maxScore = result[1], index = 1;
	for (int i = 1; i < result.size(); i++) {
		if (maxScore < result[i]) {
			maxScore = result[i];
			index = i;
		}
	}
	cout << index << " " << maxScore << endl;

	return 0;
}
