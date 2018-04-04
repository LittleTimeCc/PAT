
/*

L2-014. 列车调度

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
火车站的列车调度铁轨的结构如下图所示。


Figure
两端分别是一条入口（Entrance）轨道和一条出口（Exit）轨道，它们之间有N条平行的轨道。每趟列车从入口可以选择任意一条轨道进入，最后从出口离开。在图中有9趟列车，在入口处按照{8，4，2，5，3，9，1，6，7}的顺序排队等待进入。如果要求它们必须按序号递减的顺序从出口离开，则至少需要多少条平行铁轨用于调度？

输入格式：

输入第一行给出一个整数N (2 <= N <= 105)，下一行给出从1到N的整数序号的一个重排列。数字间以空格分隔。

输出格式：

在一行中输出可以将输入的列车按序号递减的顺序调离所需要的最少的铁轨条数。

输入样例：
9
8 4 2 5 3 9 1 6 7
输出样例：
4

*/

#include<iostream>
#include<set>

using namespace std;

int main(){
    int n,m;
    cin>>n;
    set<int> s;
    s.insert(0);
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(m<*s.rbegin()){
            s.erase(*(s.upper_bound(m)));
        }
        s.insert(m);
    }
    cout<<s.size()-1<<endl;

    return 0;
}