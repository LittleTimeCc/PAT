/*

1050. 螺旋矩阵(25)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入格式：

输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
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