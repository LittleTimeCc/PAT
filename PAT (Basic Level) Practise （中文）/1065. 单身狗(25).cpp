/*

1065. 单身狗(25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：

输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：

首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
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
