/*

1065. ����(25)
ʱ������
300 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
�������������Ķ��ڵ�����ʿ��һ�ְ��ơ���������������˵Ĵ����ɶ����ҳ��䵥�Ŀ��ˣ��Ա��������ذ���

�����ʽ��

�����һ�и���һ��������N��<=50000��������֪����/���µĶ��������N�У�ÿ�и���һ�Է���/���¡���Ϊ���������ÿ�˶�Ӧһ��ID�ţ�Ϊ5λ���֣���00000��99999����ID���Կո�ָ���֮�����һ��������M��<=10000����Ϊ�μ��ɶԵ������������һ�и�����Mλ���˵�ID���Կո�ָ�����Ŀ��֤�����ػ��Ų���������

�����ʽ��

���ȵ�һ������䵥���˵������������ڶ��а�ID����˳���г��䵥�Ŀ��ˡ�ID����1���ո�ָ����е���β�����ж���ո�

����������
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
���������
5
10000 23333 44444 55555 88888

*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;


int main(){
	int N, M,l,r;
	cin >> N;
	set<int> singleDog;
	vector<int> lovers(100000, -1),IsExist(100000);
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		lovers[l] = r;
		lovers[r] = l;
	}
	cin >> M;
	vector<int> test(M);
	for (int j = 0; j < M; j++) {
		cin >> test[j];
		if (lovers[test[j]] != -1) {
			IsExist[lovers[test[j]]] = 1;
		}
	}
	for (int k = 0; k < M;k++) {
		if (!IsExist[test[k]]) {
			singleDog.insert(test[k]);
		}
	}

	cout << singleDog.size() << endl;
	for (auto it = singleDog.cbegin(); it != singleDog.cend(); it++) {
		if (it != singleDog.cbegin()) {
			cout << " ";
		}
		printf("%05d", *it);
	}

	return 0;
}
