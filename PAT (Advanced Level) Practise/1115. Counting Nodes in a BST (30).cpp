/*

1115. Counting Nodes in a BST (30)

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
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:

For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n

where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6

*/

#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

int level_record[1000]={0};
int max_depth=-1;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* bulid_BST(TreeNode* root,int val)
{
    if(root==nullptr)
    {
        root=new TreeNode(val);
    }
    else if(val<=root->val)
    {
        root->left=bulid_BST(root->left,val);
    }
    else
    {
        root->right=bulid_BST(root->right,val);
    }
    return root;
}
void dfs(TreeNode* root,int depth)
{
    if(root==nullptr)
    {
        max_depth=max(depth,max_depth);
        return;
    }
    level_record[depth]++;
    dfs(root->left,depth+1);
    dfs(root->right,depth+1);
}

int main()
{
    int n,t;
    scanf("%d",&n);
    TreeNode* root=nullptr;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        root=bulid_BST(root,t);
    }
    dfs(root,0);
    printf("%d + %d = %d\n",level_record[max_depth-1],level_record[max_depth-2],level_record[max_depth-1]+level_record[max_depth-2]);
    return 0;
}