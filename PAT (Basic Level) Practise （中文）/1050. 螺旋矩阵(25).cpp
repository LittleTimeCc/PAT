/*

1050. ��������(25)
ʱ������
150 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡���ν���������󡱣���ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣Ҫ�����Ĺ�ģΪm��n�У�����������m*n����N��m>=n����m-nȡ���п���ֵ�е���Сֵ��

�����ʽ��

�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����104�����������Կո�ָ���

�����ʽ��

�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո�

����������
12
37 76 20 98 76 42 53 95 60 81 58 93
���������
98 95 93
42 37 81
53 20 76
58 60 76

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<functional>
using namespace std;

int m, n;			//row and col
void find_min_Distance(int N) {
	int i, j;
	for (i = 2; i*i <= N; i++) {
		if (N%i == 0) {
			j = N / i;
			if (abs(m - n) > abs(i - j)) {
				m = max(i, j);
				n = min(i, j);
			}
		}
	}
}


int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(),greater<int>());
	m = N;
	n = 1;
	find_min_Distance(N);
	vector<vector<int>> vv(m, vector<int>(n));

	int i = 0, j = 0, k = 0;
	vv[i][j] = v[k];
	k++;
	while (k < N) {
		while (j < n - 1 && vv[i][j + 1] == 0) {
			j++;
			vv[i][j] = v[k];
			k++;
		}
		while (i < m - 1 && vv[i + 1][j] == 0) {
			i++;
			vv[i][j] = v[k];
			k++;
		}
		while (j > 0 && vv[i][j - 1] == 0) {
			j--;
			vv[i][j] = v[k];
			k++;
		}
		while (i > 0 && vv[i - 1][j] == 0){
			i--;
			vv[i][j] = v[k];
			k++;
		}
	}

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (y != 0)	cout << " ";
			cout << vv[x][y];
		}
		cout << endl;
	}
	
	return 0;
}