/*

1004. Counting Leaves (30)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1

*/

#include<cstdio>

struct TreeNode {
	int father, level;
	bool hasChild;
	TreeNode() :father(0), level(0), hasChild(false) {}
}v[100];
int flag[101] = { 0 };

int main() {
	int n, m, ID, k,child, MAXLevel = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &ID, &k);
		v[ID].hasChild = true;
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			v[child].father = ID;
		}
	}
	v[1].level = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[j].father == i) {
				v[j].level = v[v[j].father].level + 1;
				if (v[j].level > MAXLevel) {
					MAXLevel = v[j].level;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].hasChild == false) {
			flag[v[i].level]++;
		}
	}
	printf("%d", flag[1]);
	for (int i = 2; i <= MAXLevel; i++) {
		printf(" %d", flag[i]);
	}

	return 0;
}