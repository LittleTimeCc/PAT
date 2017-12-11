/*

1069. ΢��ת���齱(20)

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
С��PAT�������֣�����֮���������΢��ת���齱�����ת���������а�˳��ÿ��N���˾ͷ���һ������������д���������ȷ���н�������

�����ʽ��

�����һ�и�������������M��<= 1000����N��S���ֱ���ת����������С���������н�������Լ���һλ�н��ߵ���ţ���Ŵ�1��ʼ�������M�У�˳�����ת��΢�������ѵ��ǳƣ�������20���ַ����������ո�س��ķǿ��ַ�������

ע�⣺��������ת����Σ��������н���Ρ�����������ڵ�ǰ�н�λ�õ������Ѿ��й�������������˳��ȡ��һλ��

�����ʽ��

���������˳������н�������ÿ���ǳ�ռһ�С����û�����н����������Keep going...����

��������1��
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
�������1��
PickMe
Imgonnawin!
TryAgainAgain
��������2��
2 3 5
Imgonnawin!
PickMe
�������2��
Keep going...

*/

#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main() {
	int M, N, S;
    	cin >> M >> N >> S;
	vector<string> users;
	map<string, bool> Hash;
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		users.push_back(str);
		Hash[str] = true;
	}
	if (N > M||S > M) {
		cout << "Keep going..." << endl;
		return 0;
	}
	int l = S - 1;
	while (l < M) {
		if (Hash[users[l]])
		{
			cout << users[l] << endl;
			Hash[users[l]] = false;
			l += N;
		}
		else
		{
			l++;
		}
	}
	return 0;
}