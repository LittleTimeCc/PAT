/*

1090. Highest Price in Supply Chain (25)

时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2

*/

/*解题思路：邻接表+BFS*/

#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 100005;
vector<int> adjList[maxn];

int main() {
	int n, v, root;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		if (v == -1) root = i;
		else adjList[v].push_back(i);
	}
	int max_dep = 0, max_dep_cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int cur = p.first, dep = p.second;
		q.pop();
		if (dep > max_dep) {
			max_dep = dep;
			max_dep_cnt = 1;
		}
		else if (dep == max_dep) {
			max_dep_cnt += 1;
		}
		for (int i = 0; i < adjList[cur].size(); i++)
			q.push(make_pair(adjList[cur][i], dep + 1));
	}
	printf("%.2lf %d\n", p*pow((1 + r / 100), max_dep), max_dep_cnt);

	return 0;
}