
/*

L2-021. 点赞狂魔
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
微博上有个“点赞”功能，你可以为你喜欢的博文点个赞表示支持。每篇博文都有一些刻画其特性的标签，而你点赞的博文的类型，也间接刻画了你的特性。然而有这么一种人，他们会通过给自己看到的一切内容点赞来狂刷存在感，这种人就被称为“点赞狂魔”。他们点赞的标签非常分散，无法体现出明显的特性。本题就要求你写个程序，通过统计每个人点赞的不同标签的数量，找出前3名点赞狂魔。

输入格式：

输入在第一行给出一个正整数N（<=100），是待统计的用户数。随后N行，每行列出一位用户的点赞标签。格式为“Name K F1 ... FK”，其中 Name 是不超过8个英文小写字母的非空用户名，1<=K<=1000，Fi（i=1, ..., K）是特性标签的编号，我们将所有特性标签从1到107编号。数字间以空格分隔。

输出格式：

统计每个人点赞的不同标签的数量，找出数量最大的前3名，在一行中顺序输出他们的用户名,其间以1个空格分隔,且行末不得有多余空格。如果有并列，则输出标签出现次数平均值最小的那个，题目保证这样的用户没有并列。若不足3人，则用“-”补齐缺失，例如“mike jenny -”就表示只有2人。

输入样例：
5
bob 11 101 102 103 104 105 106 107 108 108 107 107
peter 8 1 2 3 4 3 2 5 1
chris 12 1 2 3 4 5 6 7 8 9 1 2 3
john 10 8 7 6 5 4 3 2 1 7 5
jack 9 6 7 8 9 10 11 12 13 14
输出样例：
jack chris john

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct Info{
    string name;
    int k,size;
}t;

int main(){
    int n,val;
    cin>>n;
    set<int> s;
    vector<Info> v;
    for(int i=0;i<n;i++){
        cin>>t.name>>t.k;
        s.clear();
        int m=t.k;
        for(int j=0;j<m;j++){
            cin>>val;
            s.insert(val);
        }
        t.size=s.size();
        v.push_back(t);
    }
    sort(v.begin(),v.end(),[](const Info& lhs,const Info& rhs){
        return (lhs.size==rhs.size?lhs.k<rhs.k:lhs.size>rhs.size);
    });
    int cnt=0;
    for(int i=0;i<min(3,n);i++){
        if(cnt++)
            cout<<" ";
        cout<<v[i].name;
    }

    for(int i=n;i<3;i++)
    {
        if(cnt++)
            cout<<" ";
        cout<<"-";
    }
    cout<<endl;
    return 0;
}