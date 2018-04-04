
/*

1102. Invert a Binary Tree (25)

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
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1

*/

#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

//invert binary tree
void inverseTree(vector<int> treeNode[], int root) {
	swap(treeNode[root][0], treeNode[root][1]);
	if (treeNode[root][0] != -1) { inverseTree(treeNode, treeNode[root][0]); }
	if (treeNode[root][1] != -1) { inverseTree(treeNode, treeNode[root][1]); }
}

//compute level order of binary tree
void levelOrder(const vector<int> treeNode[], int root, vector<int>& ret) {
	queue<int> q;
	q.push(root);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		ret.push_back(node);
		if (treeNode[node][0] != -1)	q.push(treeNode[node][0]);
		if (treeNode[node][1] != -1)	q.push(treeNode[node][1]);
	}
}

//compute inorder of binary tree
void inOrder(const vector<int> treeNode[], int root, vector<int>& ret) {
	if (root == -1)	return;
	inOrder(treeNode, treeNode[root][0], ret);
	ret.push_back(root);
	inOrder(treeNode, treeNode[root][1], ret);
}

//print the answer
void printAnswer(const vector<int> &result) {
	if (!result.empty()) {
		printf("%d", result[0]);
		for (int i = 1; i < result.size(); i++) {
			printf(" %d", result[i]);
		}
	}
	printf("\n");
}

int main()
{
	int n;
	char a, b;
	scanf("%d", &n);
	vector<int> treeNode[10]; //tree structure,it seems like adjacent table
	int root = n * (n - 1) / 2;	//math method to compute root
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &a, &b);
		treeNode[i].push_back(a == '-' ? -1 : (root -= (a - '0'), a - '0'));
		treeNode[i].push_back(b == '-' ? -1 : (root -= (b - '0'), b - '0'));
	}
	inverseTree(treeNode, root);
	vector<int> levelOrderResult, inOrderResult;
	levelOrder(treeNode, root, levelOrderResult);
	inOrder(treeNode, root, inOrderResult);
	printAnswer(levelOrderResult);
	printAnswer(inOrderResult);

	return 0;
}