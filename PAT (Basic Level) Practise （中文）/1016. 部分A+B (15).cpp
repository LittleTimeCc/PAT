/*

1016. 部分A+B (15)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0

*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

	int A, DA, B, DB, PA=0, PB=0, countA = 0,countB=0;
	cin >> A >> DA >> B >> DB;
	string strA = to_string(A);
	string strB = to_string(B);
	for (int i = 0; i < strA.size(); i++) {
		if (strA[i] - '0' == DA) {
			countA++;
		}
	}

	for (int j = 0; j < strB.size(); j++) {
		if (strB[j] - '0' == DB) {
			countB++;
		}
	}

	for (int k =0; k < countA; k++){
		PA += DA * static_cast<int>(pow(10, k));
	}

	for (int x = 0; x < countB; x++) {
		PB += DB * static_cast<int>(pow(10,x));
	}

	cout << PA + PB << endl;
	return 0;
}