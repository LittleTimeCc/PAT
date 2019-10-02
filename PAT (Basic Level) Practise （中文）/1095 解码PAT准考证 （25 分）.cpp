/*

1095 解码PAT准考证 (25 分)

PAT 准考证号由 4 部分组成：

第 1 位是级别，即 T 代表顶级；A 代表甲级；B 代表乙级；
第 2~4 位是考场编号，范围从 101 到 999；
第 5~10 位是考试日期，格式为年、月、日顺次各占 2 位；
最后 11~13 位是考生编号，范围从 000 到 999。
现给定一系列考生的准考证号和他们的成绩，请你按照要求输出各种统计信息。

输入格式：
输入首先在一行中给出两个正整数 N（≤10
​4
​​ ）和 M（≤100），分别为考生人数和统计要求的个数。

接下来 N 行，每行给出一个考生的准考证号和其分数（在区间 [0,100] 内的整数），其间以空格分隔。

考生信息之后，再给出 M 行，每行给出一个统计要求，格式为：类型 指令，其中

类型 为 1 表示要求按分数非升序输出某个指定级别的考生的成绩，对应的 指令 则给出代表指定级别的字母；
类型 为 2 表示要求将某指定考场的考生人数和总分统计输出，对应的 指令 则给出指定考场的编号；
类型 为 3 表示要求将某指定日期的考生人数分考场统计输出，对应的 指令 则给出指定日期，格式与准考证上日期相同。
输出格式：
对每项统计要求，首先在一行中输出 Case #: 要求，其中 # 是该项要求的编号，从 1 开始；要求 即复制输入给出的要求。随后输出相应的统计结果：

类型 为 1 的指令，输出格式与输入的考生信息格式相同，即 准考证号 成绩。对于分数并列的考生，按其准考证号的字典序递增输出（题目保证无重复准考证号）；
类型 为 2 的指令，按 人数 总分 的格式输出；
类型 为 3 的指令，输出按人数非递增顺序，格式为 考场编号 总人数。若人数并列则按考场编号递增顺序输出。
如果查询结果为空，则输出 NA。

输入样例：
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 999
输出样例：
Case 1: 1 A
A107180908108 100
A107180908021 98
A112180318002 98
Case 2: 2 107
3 260
Case 3: 3 180908
107 2
123 2
102 1
Case 4: 2 999
NA

*/

#include<iostream>
#include<string>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    string s;
    int value;
};

int main(){
    int n,m,t;
    string s;
    cin>>n>>m;
    vector<Node> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].s>>v[i].value;
    }
    for(int i=1;i<=m;i++){
        cin>>t>>s;
        printf("Case %d: %d %s\n",i,t,s.c_str());
        vector<Node> ans;
        int cnt=0,sum=0;
        if(t==1){
            for(const auto& elem:v){
                if(elem.s[0]==s[0]){
                    ans.push_back(elem);
                }
            }
        }else if(t==2){
            for(const auto& elem:v){
                if(elem.s.substr(1,3)==s){
                   cnt++;
                   sum+=elem.value;
                }
            }
            if(cnt){printf("%d %d\n",cnt,sum);} 
        }else if(t==3){
            unordered_map<string,int> m;
            for(const auto& elem:v){
                if(elem.s.substr(4,6)==s){
                    m[elem.s.substr(1,3)]++;
                }
            }
            for(const auto& elem:m){
                ans.push_back({elem.first,elem.second});
            }
        }
        sort(ans.begin(),ans.end(),[](const Node& lhs,const Node& rhs){
            return lhs.value!=rhs.value?lhs.value>rhs.value:lhs.s<rhs.s;
        });
        for(const auto& elem:ans){
            printf("%s %d\n",elem.s.c_str(),elem.value);
        }
        if(((t==1||t==3)&&ans.empty())||(t==2&&cnt==0)){
            printf("NA\n");
        }
    }



    return 0;
}