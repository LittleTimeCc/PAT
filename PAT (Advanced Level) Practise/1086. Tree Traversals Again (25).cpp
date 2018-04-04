/*

1086. Tree Traversals Again (25)

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
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1

*/
#include<cstdio>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){ }
};
char str[5];
int index=0,t,n;
bool flag=true;

TreeNode* build_Tree()
{
    TreeNode* root=nullptr;
    if(index<2*n)
    {
        scanf("%s",str);
        if(str[1]=='u')
        {
            scanf("%d",&t);
            root=new TreeNode(t);
            index++;
        }
        else if(str[1]=='o')
        {
            index++;
            return nullptr;
        }
        root->left=build_Tree();
        root->right=build_Tree();
    }
    return root;
}
void postOrder(TreeNode* root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        if(flag)
        {
            printf("%d",root->val);
            flag=false;
        }
        else
        {
            printf(" %d",root->val);
        }
    }
}
int main()
{
    scanf("%d",&n);
    TreeNode* root=build_Tree();
    postOrder(root);

    return 0;
}