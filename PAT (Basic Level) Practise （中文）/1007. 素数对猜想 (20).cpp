/*
1007. 素数对猜想 (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime_Num(int num)
{
	int k = sqrt(num);
	bool flag = true;
	for (int j = 2; j <= k; j++) {
		if (num%j == 0) {
			flag = false;
		}
	}
	
	return flag;
}

int main()
{
	vector<int> primes;
	int N,count=0;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		if (isPrime_Num(i))
			primes.push_back(i);
	}


	for (int j = 0; j < primes.size()-1; j++)
	{
		if (primes[j + 1] - primes[j] == 2)
			count++;
	}

	cout << count << endl;
 
	return 0;
}