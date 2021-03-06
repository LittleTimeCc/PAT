
/*

L1-047. 装睡
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
你永远叫不醒一个装睡的人 —— 但是通过分析一个人的呼吸频率和脉搏，你可以发现谁在装睡！医生告诉我们，正常人睡眠时的呼吸频率是每分钟15-20次，脉搏是每分钟50-70次。下面给定一系列人的呼吸频率与脉搏，请你找出他们中间有可能在装睡的人，即至少一项指标不在正常范围内的人。

输入格式：

输入在第一行给出一个正整数N（<= 10）。随后N行，每行给出一个人的名字（仅由英文字母组成的、长度不超过3个字符的串）、其呼吸频率和脉搏（均为不超过100的正整数）。

输出格式：

按照输入顺序检查每个人，如果其至少一项指标不在正常范围内，则输出其名字，每个名字占一行。

输入样例：
4
Amy 15 70
Tom 14 60
Joe 18 50
Zoe 21 71
输出样例：
Tom
Zoe

*/
#include<iostream>
#include<string>

using namespace std;

struct Info{
    string name;
    int a,b;
}t;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t.name>>t.a>>t.b;
        if(t.a<15||t.a>20||t.b<50||t.b>70){
            cout<<t.name<<endl;
        }
    }

    return 0;
}