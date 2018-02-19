/*

L1-043. 阅览室
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
天梯图书阅览室请你编写一个简单的图书借阅统计程序。当读者借书时，管理员输入书号并按下S键，程序开始计时；当读者还书时，管理员输入书号并按下E键，程序结束计时。书号为不超过1000的正整数。当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。

注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有S没有E，或者只有E没有S的纪录，系统应能自动忽略这种无效纪录。另外，题目保证书号是书的唯一标识，同一本书在任何时间区间内只可能被一位读者借阅。

输入格式：

输入在第一行给出一个正整数N（<= 10），随后给出N天的纪录。每天的纪录由若干次借阅操作组成，每次操作占一行，格式为：

书号（[1, 1000]内的整数） 键值（“S”或“E”） 发生时间（hh:mm，其中hh是[0,23]内的整数，mm是[0, 59]内整数）

每一天的纪录保证按时间递增的顺序给出。

输出格式：

对每天的纪录，在一行中输出当天的读者借书次数和平均阅读时间（以分钟为单位的精确到个位的整数时间）。

输入样例：
3
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00
输出样例：
2 196
0 0
1 60

*/

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<bool> isVisit(1001,false);
struct Time{
    int hh,mm;
    int get_Minutes()const{
        return hh*60+mm;
    }
    friend istream& operator>>(istream& is,Time& T){
        char ch;
        is>>T.hh>>ch>>T.mm;
        return is;
    }
};

struct Info{
    int id;
    char record;
    Time time;
    friend istream& operator>>(istream& is,Info& I){
        is>>I.id>>I.record>>I.time;
        return is;
    }

}t;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> minutes(1001);
        int cnt=0,sum=0;
        while(cin>>t){
            if(t.id==0) break;
            if(t.record=='S'){
                minutes[t.id-1]=t.time.get_Minutes();
                isVisit[t.id-1]=true;
            }
            else{
                if(isVisit[t.id-1])
                {
                    isVisit[t.id-1]=false;
                    cnt++;
                    sum=sum+t.time.get_Minutes()-minutes[t.id-1];
                }
            }
        }
        if(cnt==0)  cout<<0<<" "<<0<<endl;
        else printf("%d %.0f\n",cnt,(double)sum/cnt);
    }

    return 0;
}