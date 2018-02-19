
/*

L1-024. 后天
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
如果今天是星期三，后天就是星期五；如果今天是星期六，后天就是星期一。我们用数字1到7对应星期一到星期日。给定某一天，请你输出那天的“后天”是星期几。

输入格式：

输入第一行给出一个正整数D（1 <= D <=7），代表星期里的某一天。

输出格式：

在一行中输出D天的后天是星期几。

输入样例：
3
输出样例：
5

*/
#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int result=n+2;
    if(result>7){
        cout<<result%7<<endl;
    }else{
        cout<<result<<endl;
    }

    return 0;
}