/*

1012. 数字分类 (20)

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
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9

*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int A1=0, A2=0, A3=0, A5=0;
	float A4=0.0f;
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
	int N,float_Count=0,max_Num=0;
	cin >> N;
	vector<int> inputs, buffer;;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		inputs.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		if (inputs[i] % 10 == 0) {
			A1 += inputs[i];
			flag1 = true;
		}

		else if (inputs[i] % 5 == 1) {
			buffer.push_back(inputs[i]);
			flag2 = true;
		}
		else if (inputs[i] % 5 == 2) {
			A3++;
			flag3 = true;
		}
		else if (inputs[i] % 5 == 3) {
			A4 = A4 + inputs[i];
			float_Count++;
			flag4 = true;
		}
		else if (inputs[i] % 5 == 4) {
			if (inputs[i] > A5) {
				A5 = inputs[i];
				flag5 = true;
			}
		}
	}

	for (int i = 0; i < buffer.size(); i++) {
		if (i==0||i%2==0) {
			A2 = A2+buffer[i];
		}
		else {
			A2 =A2- buffer[i];
		}
	}

	A4 = A4 / float_Count;

	if (flag1 == false) {
		cout << "N" << " ";
	}
	else
		cout << A1 << " ";

	if (flag2 == false) {
		cout << "N" << " ";
	}
	else
		cout << A2 << " ";

	if (flag3 == false) {
		cout << "N" << " ";
	}
	else
		cout << A3 <<" ";

	if (flag4 == false) {
		cout << "N"<<" ";
	}
	else
		printf("%.1f ", A4);

	if (flag5 == false) {
		cout << "N";
	}
	else
		cout << A5 ;

	return 0;
}