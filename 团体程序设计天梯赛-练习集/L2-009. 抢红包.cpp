
/*

L2-009. �����

ʱ������
300 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
û����û��������ɡ��� �������N����֮�以�෢�����������ļ�¼������ͳ��һ��������������ջ�

�����ʽ��

�����һ�и���һ��������N��<= 104���������뷢������������������������Щ�˴�1��N��š����N�У���i�и������Ϊi���˷�����ļ�¼����ʽ���£�

K N1 P1 ... NK PK

����K��0 <= K <= 20���Ƿ���ȥ�ĺ��������Ni������������˵ı�ţ�Pi��> 0�����������ĺ�����Է�Ϊ��λ����ע�⣺����ͬһ���˷����ĺ����ÿ�����ֻ����1�Σ������ظ�����

�����ʽ��

����������Ӹߵ��͵ĵݼ�˳�����ÿ���˵ı�ź��������ԪΪ��λ�����С�����2λ����ÿ���˵���Ϣռһ�У������ּ���1���ո�����������в��У�����������ĸ����ݼ������������в��У��򰴸��˱�ŵ��������

����������
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10
���������
1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32

*/

#include<algorithm>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

struct Info {
	int id,cnt,balance;
};

int main() {
	int n, k, a, b;
	cin >> n;
	vector<Info> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i].id = i;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			v[i].balance -= b;
			v[a].balance += b;
			v[a].cnt++;
		}
	}
	sort(v.begin() + 1, v.end(), [](const Info& lhs,const Info& rhs) {
		if (lhs.balance == rhs.balance) {
			if (lhs.cnt == rhs.cnt)	return lhs.id < rhs.id;
			else  return lhs.cnt > rhs.cnt;
		}
		else  return lhs.balance > rhs.balance;
	});

	for (auto it = v.begin() + 1; it != v.end(); it++) {
		double t = static_cast<double>(it->balance*1.0 / 100);
		printf("%d %.2lf\n", it->id, t);
	}

	return 0;
}