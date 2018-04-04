
/*

L2-003. 月饼
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50

*/

#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

struct Info{
    double w,v,pro;
}a[1001];

int main(){
    int n,need;
    cin>>n>>need;
    for(int i=0;i<n;i++){
        cin>>a[i].w;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].v;
        a[i].pro=a[i].v/a[i].w;
    }
    sort(a,a+n,[](const Info& lhs,const Info& rhs){
        return lhs.pro>rhs.pro;
    });
    double sum=0;
    for(int i=0;i<n;i++){
        if(need>=a[i].w){
            sum+=a[i].v;
            need-=a[i].w;
        }else{
            sum+=a[i].pro*need;
            break;
        }
    }
    printf("%.2lf\n",sum);
    return 0;
}