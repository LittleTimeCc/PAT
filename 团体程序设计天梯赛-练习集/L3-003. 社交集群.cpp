
/*

L3-003. 社交集群
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
在社交网络平台注册时，用户通常会输入自己的兴趣爱好，以便找到和自己兴趣相投的朋友。有部分兴趣相同的人们就形成了“社交集群”。现请你编写程序，找出所有的集群。

输入格式：

输入的第一行给出正整数N（<=1000），即社交网络中的用户总数（则用户从1到N编号）。随后N行，每行按下列格式列出每个人的兴趣爱好：

Ki: hi[1] hi[2] ... hi[Ki]

其中Ki（>0）是第i个人的兴趣的数量，hi[j]是第i个人的第j项兴趣的编号，编号范围为[1, 1000]内的整数。

输出格式：

首先在第一行输出整个网络中集群的数量，然后在第二行按非递增的顺序输出每个集群中用户的数量。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
输出样例：
3
4 3 1

*/

#include<iostream>
#include<cstdio>
#include<functional>
#include<algorithm>

using namespace std;

const size_t Max=1001;
int c[Max],f[Max];

int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) f[x]=y;
}

int main(){
    int n,m,t1,t2;
    cin>>n;
    for(int i=0;i<1001;i++) f[i]=i;
    for(int i=0;i<n;i++){
        scanf("%d: ",&t1);
        cin>>t2;
        c[i]=t2;
        for(int j=1;j<t1;j++){
            cin>>m;
            Union(t2,m);
        }
    }
    int num[1001]={0},cnt=0;
    for(int i=0;i<n;i++){
        num[find(c[i])]++;
    }
    for(int i=0;i<1001;i++){
        if(num[i])  cnt++;
    }
    sort(num,num+1001,greater<int>());
    cout<<cnt<<endl;
    cout<<num[0];
    for(int i=1;i<cnt;i++){
        cout<<" "<<num[i];
    }
    cout<<endl;
    return 0;
}