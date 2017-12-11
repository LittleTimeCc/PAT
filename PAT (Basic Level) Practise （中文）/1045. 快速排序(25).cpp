/*

1045. 快速排序(25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CAO, Peng
著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的N个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定N = 5, 排列是1、3、2、4、5。则：

 的左边没有元素，右边的元素都比它大，所以它可能是主元；
 尽管3的左边元素都比它小，但是它右边的2它小，所以它不能是主元；
 尽管2的右边元素都比它大，但其左边的3比它大，所以它不能是主元；
 类似原因，4和5都可能是主元。
 因此，有3个元素可能是主元。

输入格式：

输入在第1行中给出一个正整数N（<= 105）； 第2行是空格分隔的N个不同的正整数，每个数不超过109。

输出格式：

在第1行中输出有可能是主元的元素个数；在第2行中按递增顺序输出这些元素，其间以1个空格分隔，行末不得有多余空格。

输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v1(N),v2(N),res;
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
	}
	copy(v1.begin(), v1.end(), v2.begin());
	sort(v2.begin(), v2.end());
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (v1[i] > t) {
			t = v1[i];
		}
		if (v1[i] == v2[i] && v1[i] == t){
			res.push_back(t);
		}
		
	}

	cout << res.size() << endl;
	for (auto it = res.begin(); it != res.end(); it++) {
		if (it != res.begin())	cout << " ";
		cout << *it;
	}
	cout << endl;

	return 0;
}