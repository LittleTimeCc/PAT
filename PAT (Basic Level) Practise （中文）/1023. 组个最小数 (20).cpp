/*
1023. 组个最小数 (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CAO, Peng
给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意0不能做首位）。例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：

每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、……数字9的个数。整数间用一个空格分隔。10个数字的总个数不超过50，且至少拥有1个非0的数字。

输出格式：

在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	vector<int> nums,Nums;
	for(int i=0;i<10;i++) {
		cin >> num;
		nums.push_back(num);
	}	
	for (int j = 0; j < 10; j++) {
		int t = nums[j];
		while (t--) {
			Nums.push_back(j);
		}
	}
	sort(Nums.begin(), Nums.end());
	auto it = count(Nums.begin(), Nums.end(), 0);
	if (it == 0) {
		for (auto elem : Nums) {
			cout << elem;
		}
	}
	else
	{
		swap(Nums[0], Nums[it]);
		for (auto elem : Nums) {
			cout << elem;
		}
	}
	return 0;
}
