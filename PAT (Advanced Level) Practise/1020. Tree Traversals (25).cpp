
/*

1020. Tree Traversals (25)
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
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2

*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x), left(nullptr), right(nullptr) { }
};



class Solution {
public:

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size(), i = 0;
		for (auto val : inorder)	inorder_m[val] = i++;
		return DFS(inorder, 0, n - 1, postorder, 0, n - 1);
	}

private:
	TreeNode* DFS(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright) {
		if (ileft > iright)	return nullptr;
		int val = postorder[pright];  //root value;
		TreeNode* root = new TreeNode(val);
		if (ileft == iright)	return root;

		int iroot = inorder_m[val];
		int nleft = iroot - ileft;	//length of left subtree
		root->right = DFS(inorder, iroot + 1, iright, postorder, pleft + nleft, pright - 1);
		root->left = DFS(inorder, ileft, iroot - 1, postorder, pleft, pleft + nleft - 1);
		return root;
	}

	unordered_map<int, int> inorder_m;	//inorder map[inorder[i],i];
};



vector<int> Leves(TreeNode* root) {
	vector<int> ret{};
	if (root == nullptr)	return ret;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			TreeNode* temp = q.front();
			q.pop();
			ret.push_back(temp->val);
			if (temp->left != nullptr)	q.push(temp->left);
			if (temp->right != nullptr)	q.push(temp->right);
		}
	}
	return ret;
}


int main() {
	int N;
	cin >> N;
	vector<int> inorder(N), postorder(N);
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
	}

	Solution s;
	TreeNode* root=s.buildTree(inorder, postorder);
	vector<int> ret=Leves(root);
	cout << ret[0];
	for (int i = 1; i < ret.size(); i++) {
		cout << " " << ret[i];
	}

	return 0;
}


