
/*

L2-024. 部落
时间限制
120 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
在一个社区里，每个人都有自己的小圈子，还可能同时属于很多不同的朋友圈。我们认为朋友的朋友都算在一个部落里，于是要请你统计一下，在一个给定社区中，到底有多少个互不相交的部落？并且检查任意两个人是否属于同一个部落。

输入格式：

输入在第一行给出一个正整数N（<= 104），是已知小圈子的个数。随后N行，每行按下列格式给出一个小圈子里的人：

K P[1] P[2] ... P[K]

其中K是小圈子里的人数，P[i]（i=1, .., K）是小圈子里每个人的编号。这里所有人的编号从1开始连续编号，最大编号不会超过104。

之后一行给出一个非负整数Q（<= 104），是查询次数。随后Q行，每行给出一对被查询的人的编号。

输出格式：

首先在一行中输出这个社区的总人数、以及互不相交的部落的个数。随后对每一次查询，如果他们属于同一个部落，则在一行中输出“Y”，否则输出“N”。

输入样例：
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
输出样例：
10 2
Y
N

*/

#include<iostream>

using namespace std;

const size_t Max=10001;
int visit[Max],f[Max];

int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) f[x]=y;
}

int main(){
    int n,t,t1,t2;
    cin>>n;
    for(int i=0;i<10001;i++) f[i]=i,visit[i]=0;
    for(int i=0;i<n;i++){
        cin>>t>>t1;
        visit[t1]=1;
        for(int j=1;j<t;j++){
            cin>>t2;
            visit[t2]=1;
            Union(t1,t2);
        }
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<10001;i++){
        if(visit[i])  cnt1++;
        if(find(i)==i&&visit[i])    cnt2++;
    }
    cout<<cnt1<<" "<<cnt2<<endl;
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b))  cout<<"Y"<<endl;
        else    cout<<"N"<<endl;
    }

    return 0;
}