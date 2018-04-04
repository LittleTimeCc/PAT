/*

L2-005. 集合相似度
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
给定两个整数集合，它们的相似度定义为：Nc/Nt*100%。其中Nc是两个集合都有的不相等整数的个数，Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。

输入格式：

输入第一行给出一个正整数N（<=50），是集合的个数。随后N行，每行对应一个集合。每个集合首先给出一个正整数M（<=104），是集合中元素的个数；然后跟M个[0, 109]区间内的整数。

之后一行给出一个正整数K（<=2000），随后K行，每行对应一对需要计算相似度的集合的编号（集合从1到N编号）。数字间以空格分隔。

输出格式：

对每一对需要计算的集合，在一行中输出它们的相似度，为保留小数点后2位的百分比数字。

输入样例：
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
输出样例：
50.00%
33.33%

*/

#include<iostream>
#include<set>
#include<cstdio>

using namespace std;

int main()
{
    set<int> s[51];
    int n,m,x,k,y,z;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>x;
            s[i].insert(x);
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>y>>z;
        int same=0;
        for(auto it=s[y].begin();it!=s[y].end();it++){
            if(s[z].find(*it)!=s[z].end()) same++;
        }
        double ans=same*1.0/(s[y].size()+s[z].size()-same);
        printf("%.2lf%%\n",ans*100);
    }
    return 0;
}