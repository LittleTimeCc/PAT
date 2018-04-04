/*

1130. Infix Expression (25)

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
Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N ( <= 20 ) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the i-th line corresponds to the i-th node) in the format:

data left_child right_child

where data is a string of no more than 10 characters, left_child and right_child are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by -1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.

Output Specification:

For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.

Sample Input 1:
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
Sample Output 1:
(a+b)*(c*(-d))
Sample Input 2:
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
Sample Output 2:
(a*2.35)+(-(str%871))

*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    string data;
    int left,right;
};
vector<Node> T;
int root;
void dfs(int r);
int main()
{
    int n;
    cin>>n;
    T.resize(n+1);
    vector<int> id(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>T[i].data>>T[i].left>>T[i].right;
        if(T[i].left!=-1)
            id[T[i].left]=1;
        if(T[i].right!=-1)
            id[T[i].right]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(id[i]==0)
        {
            root=i;
            break;
        }
    }
    dfs(root);

    return 0;
}

void dfs(int r)
{
    if(r==-1)
        return;
    bool hasPth=false; //判断是否输出括号
    if(r!=root&&(T[r].left!=-1||T[r].right!=-1))
        hasPth=true;
    if(hasPth)
    {
        cout<<"(";
    }
    dfs(T[r].left);
    cout<<T[r].data;
    dfs(T[r].right);
    if(hasPth)
    {
        cout<<")";
    }
}