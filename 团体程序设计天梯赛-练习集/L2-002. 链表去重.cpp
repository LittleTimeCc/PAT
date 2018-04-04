
/*

L2-002. 链表去重
时间限制
300 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
给定一个带整数键值的单链表L，本题要求你编写程序，删除那些键值的绝对值有重复的结点。即对任意键值K，只有键值或其绝对值等于K的第一个结点可以被保留。同时，所有被删除的结点必须被保存在另外一个链表中。例如：另L为21→-15→-15→-7→15，则你必须输出去重后的链表21→-15→-7、以及被删除的链表-15→15。

输入格式：

输入第一行包含链表第一个结点的地址、以及结点个数N（<= 105 的正整数）。结点地址是一个非负的5位整数，NULL指针用-1表示。

随后N行，每行按下列格式给出一个结点的信息：

Address Key Next

其中Address是结点的地址，Key是绝对值不超过104的整数，Next是下一个结点的地址。

输出格式：

首先输出去重后的链表，然后输出被删除结点组成的链表。每个结点占一行，按输入的格式输出。

输入样例：
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
输出样例：
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1

*/

#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

const size_t MAXN=100000;

struct Node{
    int key,next;
}node[MAXN];

vector<bool> isVisit(MAXN,false);
vector<int> ans(MAXN),res(MAXN);

int main(){
    int addr,Addr,n,cnt1=0,cnt2=0;
    cin>>addr>>n;
    for(int i=0;i<n;i++){
        cin>>Addr;
        cin>>node[Addr].key>>node[Addr].next;
    }
    for(int i=addr;i!=-1;i=node[i].next){
        int t=abs(node[i].key);
        if(!isVisit[t]){
            isVisit[t]=true;
            ans[cnt1++]=i;
        }else{
            res[cnt2++]=i;
        }
    }
    printf("%05d %d ",ans[0],node[ans[0]].key);
    for(int i=1;i<cnt1;i++){
        printf("%05d\n",ans[i]);
        printf("%05d %d ",ans[i],node[ans[i]].key);
    }
    printf("-1\n");
    if(cnt2){
        printf("%05d %d ",res[0],node[res[0]].key);
        for(int i=1;i<cnt2;i++){
            printf("%05d\n",res[i]);
            printf("%05d %d ",res[i],node[res[i]].key);
        }
        printf("-1\n");
    }

    return 0;
}