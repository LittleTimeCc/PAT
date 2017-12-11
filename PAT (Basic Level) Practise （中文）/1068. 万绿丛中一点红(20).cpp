
/*

1068. 万绿丛中一点红(20)
时间限制
500 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
对于计算机而言，颜色不过是像素点对应的一个24位的数值。现给定一幅分辨率为MxN的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围8个相邻像素的颜色差充分大。

输入格式：

输入第一行给出三个正整数，分别是M和N（<= 1000），即图像的分辨率；以及TOL，是所求像素点与相邻点的颜色差阈值，色差超过TOL的点才被考虑。随后N行，每行给出M个像素的颜色值，范围在[0, 224)内。所有同行数字间用空格或TAB分开。

输出格式：

在一行中按照“(x, y): color”的格式输出所求像素点的位置以及颜色值，其中位置x和y分别是该像素在图像矩阵中的列、行编号（从1开始编号）。如果这样的点不唯一，则输出“Not Unique”；如果这样的点不存在，则输出“Not Exist”。

输入样例1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例1：
(5, 3): 16711680
输入样例2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
输出样例2：
Not Unique
输入样例3：
3 3 5
1 2 3
3 4 5
5 6 7
输出样例3：
Not Exist

*/

#include<map>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int dir[8][2] = { { -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 } }; //Eight Directions
int M, N, TOL;
vector<vector<int>> v;
bool IsRed(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];
		if (x1>=0&&x1<N&&y1>=0&&y1<M&&v[x][y]-v[x1][y1]<=TOL&&v[x][y] - v[x1][y1] >= 0-TOL)
			return false;
	}
	return true;
}
int main() {
	int x = 0, y = 0,count=0;
	cin >> M >> N >> TOL;
	v.resize(N, vector<int>(M));
	map<int, int> Map;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			Map[v[i][j]]++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[v[i][j]] == 1 && IsRed(i, j)==true) {
				count++;
				x = i + 1;
				y = j + 1;
			}
		}
	}
	if (count == 1) {
		printf("(%d, %d): %d", y, x, v[x - 1][y - 1]);
	}
	else if (count == 0) {
		cout << "Not Exist";
	}
	else{
		cout << "Not Unique";
	}

	return 0;
}