/*

1052. ������ (20)

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

�����ձ������ͨ���ɡ��֡������ۡ������ڡ�������Ҫ������ɡ�����������Ǽ���һ����������ǰ����и�ʽ����ģ�

[����]([����][��][����])[����]
�ָ�����ѡ�õķ��ż��ϣ����㰴�û���Ҫ��������顣

�����ʽ��

����������ǰ����˳���Ӧ�����֡��ۡ��ڵĿ�ѡ���ż���ÿ����������һ�Է�����[]�ڡ���Ŀ��֤ÿ�����϶�������һ�����ţ���������10�����ţ�ÿ�����Ű���1��4���ǿ��ַ���

֮��һ�и���һ��������K��Ϊ�û�����ĸ��������K�У�ÿ�и���һ���û��ķ���ѡ��˳��Ϊ���֡����ۡ��ڡ����ۡ����֡�������ֻ������������Ӧ�����е���ţ���1��ʼ�������ּ��Կո�ָ���

�����ʽ��

��ÿ���û�������һ����������ɵı��顣���û�ѡ�����Ų����ڣ��������Are you kidding me? @\/@����

����������
[�r][�q][o][~\][/~]  [<][>]
[�s][�t][^][-][=][>][<][@][��]
[��][��][_][��][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
���������
�r(�s���t)�q
<(@��=)/~
o(^��^)o
Are you kidding me? @\/@

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	vector<vector<string>> Map;
	for (int i = 0; i < 3; i++){
		string str;
		getline(cin,str);
		vector<string> looks;
		int j = 0,k = 0;
		while (j < str.size()) {
			if (str[j] == '[') {
				while (k++ < str.size()) {
					if (str[k] == ']') {
						looks.push_back(str.substr(j + 1, k - j - 1));
						break;
					}
				}
			}
			j++;
		}
		Map.push_back(looks);
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (a > Map[0].size() || b > Map[1].size() || c > Map[2].size() || d > Map[1].size() || e > Map[0].size() || a < 1 || b < 1 || c < 1 || d < 1 || e < 1) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		cout << Map[0][a-1] << "(" << Map[1][b - 1] << Map[2][c - 1] << Map[1][d - 1] << ")" << Map[0][e - 1] << endl;
	}


	return 0;
}



