
/*

1085. PAT单位排行 (25)

时间限制
500 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：

输入第一行给出一个正整数N（<=105），即考生人数。随后N行，每行按下列格式给出一个考生的信息：

准考证号 得分 学校

其中“准考证号”是由6个字符组成的字符串，其首字母表示考试的级别：“B”代表乙级，“A”代表甲级，“T”代表顶级；“得分”是 [0,100] 区间内的整数；“学校”是由不超过6个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：

首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：

排名 学校 加权总分 考生人数

其中“排名”是该单位的排名（从1开始）；“学校”是全部按小写字母输出的单位码；“加权总分”定义为“乙级总分/1.5 + 甲级总分 + 顶级总分*1.5”的整数部分；“考生人数”是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2

*/

#include<cctype>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct Info{
    int rank;
    string school;
    int score,num;
    Info(int _rank,string _school,int _score,int _num)
        :rank(_rank),school(_school),score(_score),num(_num) { }

};

int main()
{
    int n;
    scanf("%d",&n);
    map<string,pair<int,double>> Map;
    for(int i=0;i<n;i++)
    {
        double score=0.0;
        char name[7];char school[7];
        scanf("%s %lf %s",name,&score,school);
        if(name[0]=='B')    score/=1.5;
        if(name[0]=='T')    score*=1.5;
        for(auto &ch:school){
            if(isupper(ch)){
                ch=tolower(ch);
            }
        }

        auto &t=Map[school];
        t.first++;
        t.second+=score;
    }
    vector<Info> v;
    for(const auto& elem:Map)
    {
        string school=elem.first;
        int num=elem.second.first;
        int score=elem.second.second;
        v.push_back(Info(0,school,score,num));
    }
    sort(v.begin(),v.end(),[](const Info& lhs,const Info& rhs){
        if(lhs.score!=rhs.score)    return lhs.score>rhs.score;
        else if(lhs.num!=rhs.num)   return lhs.num<rhs.num;
        else    return lhs.school<rhs.school;
    });
    cout<<v.size()<<endl;
    auto size=v.size();
    for(int i=0;i<size;)
    {
        int j=i+1;
        v[i].rank=j;
        while(v[i].score==v[j].score&&j<size)
        {
            v[j].rank=v[i].rank;
            j++;
        }
        i=j;
    }
    for(const auto& elem:v){
        cout<<elem.rank<<" "<<elem.school<<" "<<elem.score<<" "<<elem.num<<endl; 
    }

    return 0;
}