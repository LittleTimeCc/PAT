/*

1059. C���Ծ���(20)
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
C���Ծ������㽭��ѧ�����ѧԺ���ֵ�һ�����ֵľ�������Ȼ������ּ��Ϊ�˺��棬�佱����Ҳ���ƶ��úܻ�����

0. �ھ���Ӯ��һ�ݡ����ش󽱡�������ܾ޴��һ��ѧ���о����ļ���������
1. ����Ϊ������ѧ����Ӯ����õĽ�Ʒ ���� С������ż��
2. �����˽��õ��ɿ�����

�������������������Լ�һϵ�в����ߵ�ID����Ҫ������Щ������Ӧ�û�õĽ�Ʒ��

�����ʽ��

�����һ�и���һ��������N��<=10000�����ǲ��������������N�и�������������ÿ�а�����˳�����һλ�����ߵ�ID��4λ������ɣ�������������һ��������K�Լ�K����Ҫ��ѯ��ID��

�����ʽ��

��ÿ��Ҫ��ѯ��ID����һ���������ID: ��Ʒ�������н�Ʒ�����ǡ�Mystery Award�������ش󽱣��������ǡ�Minion����С���ˣ��������ǡ�Chocolate�����ɿ��������������ID���������������ӡ��Are you kidding?����ˣ���أ����������ID�Ѿ�����ˣ�����Ʒ�Ѿ�����ˣ�����ӡ��ID: Checked�������ܶ�Զ�ռ����

����������
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
���������
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

*/

#include<iostream>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;

bool isPrime(int x) {
	for (int i = 2; i < static_cast<int>((x)); i++) {
		if (x%i == 0)	return false;
	}
	return true;
}


bool check[10000] = { 0 };
int main() {
	unordered_map<string, int> Map;
	string s;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		Map[s] = i;
	}
	int M;
	cin >> M;
	string ss;
	for (int j = 0; j < M; j++) {
		cin >> ss;
		if (Map.count(ss) > 0) {
			if (Map[ss] == 1) {
				if (check[Map[ss]] == 0){
					cout << ss << ": Mystery Award" << endl;
					check[Map[ss]] = 1;
			}
				else
					cout << ss << ": Checked" << endl;
			}
			else if (isPrime(Map[ss])) {
				if (check[Map[ss]] == 0) {
					cout << ss << ": Minion" << endl;
					check[Map[ss]] = 1;
				}
				else
					cout << ss << ": Checked" << endl;
			}
			else
			{
				if (check[Map[ss]] == 0) {
					cout << ss << ": Chocolate" << endl;
					check[Map[ss]] = 1;
				}
				else
					cout << ss << ": Checked" << endl;
			}
		}
		else{
			cout << ss << ": Are you kidding?" << endl;
		}		
	}

	return 0;
}