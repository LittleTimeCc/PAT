
/*

L3-010. 是否完全二叉搜索树
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
将一系列给定数字顺序插入一个初始为空的二叉搜索树（定义为左子树键值大，右子树键值小），你需要判断最后的树是否一棵完全二叉树，并且给出其层序遍历的结果。

输入格式：

输入第一行给出一个不超过20的正整数N；第二行给出N个互不相同的正整数，其间以空格分隔。

输出格式：

将输入的N个正整数顺序插入一个初始为空的二叉搜索树。在第一行中输出结果树的层序遍历结果，数字间以1个空格分隔，行的首尾不得有多余空格。第二行输出“YES”，如果该树是完全二叉树；否则输出“NO”。

输入样例1：
9
38 45 42 24 58 30 67 12 51
输出样例1：
38 45 24 58 42 30 12 67 51
YES
输入样例2：
8
38 24 12 45 58 67 42 51
输出样例2：
38 45 24 58 42 12 67 51
NO

*/

#include<iostream>

using namespace std;


int Tree[1<<20];
int num;

void Build_BST(int n){
    if(Tree[n]==0)  
        Tree[n]=num;
    else if(num>Tree[n])     
        Build_BST(n<<1);
    else    
        Build_BST(n<<1|1);
}

int main(){
    int n,tag=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        Build_BST(1);
    }
    bool flag=true;
    for(int i=1;tag<=n;i++){
        if(Tree[i]==0){
            flag=false;
        }else{
            cout<<Tree[i];
            if(tag++ != n)    cout<<" ";
        }
    }
    if(flag)    cout<<"\nYES";
    else    cout<<"\nNO";
    return 0;
}