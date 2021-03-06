
/*

L3-008. 喊山

时间限制
150 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
喊山，是人双手围在嘴边成喇叭状，对着远方高山发出“喂—喂喂—喂喂喂……”的呼唤。呼唤声通过空气的传递，回荡于深谷之间，传送到人们耳中，发出约定俗成的“讯号”，达到声讯传递交流的目的。原来它是彝族先民用来求援呼救的“讯号”，慢慢地人们在生活实践中发现了它的实用价值，便把它作为一种交流工具世代传袭使用。（图文摘自：http://news.xrxxw.com/newsshow-8018.html）


一个山头呼喊的声音可以被临近的山头同时听到。题目假设每个山头最多有两个能听到它的临近山头。给定任意一个发出原始信号的山头，本题请你找出这个信号最远能传达到的地方。

输入格式：

输入第一行给出3个正整数n、m和k，其中n（<=10000）是总的山头数（于是假设每个山头从1到n编号）。接下来的m行，每行给出2个不超过n的正整数，数字间用空格分开，分别代表可以听到彼此的两个山头的编号。这里保证每一对山头只被输入一次，不会有重复的关系输入。最后一行给出k（<=10）个不超过n的正整数，数字间用空格分开，代表需要查询的山头的编号。

输出格式：

依次对于输入中的每个被查询的山头，在一行中输出其发出的呼喊能够连锁传达到的最远的那个山头。注意：被输出的首先必须是被查询的个山头能连锁传到的。若这样的山头不只一个，则输出编号最小的那个。若此山头的呼喊无法传到任何其他山头，则输出0。

输入样例：
7 5 4
1 2
2 3
3 1
4 5
5 6
1 4 5 7
输出样例：
2
6
4
0

*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

const size_t maxn=10001;
vector<int> G[maxn];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=0;i<k;i++){
        int start,maxlevel=0;
        vector<int> levels(n,0);
        vector<bool> isVisit(maxn,false);
        cin>>start;
        queue<int> q;
        q.push(start);
        isVisit[start]=true;
        int result=start;
        while(!q.empty()){
            int pre=q.front();
            q.pop();
            if(levels[pre]>maxlevel){
                maxlevel=levels[pre];
                result=pre;
            }else if(levels[pre]==maxlevel){    //if distance equal,so chose the min number
                result=min(pre,result);
            }

            for(int i=0;i<G[pre].size();i++){
                if(!isVisit[G[pre][i]]){
                    q.push(G[pre][i]);
                    isVisit[G[pre][i]]=true;
                    levels[G[pre][i]]=levels[pre]+1;
                }
            }
        }
        if(result==start)   cout<<0<<endl;
        else cout<<result<<endl;
    }

    return 0;
}