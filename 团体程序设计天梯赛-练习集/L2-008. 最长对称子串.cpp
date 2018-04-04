
/*

L2-008. 最长对称子串

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
对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定"Is PAT&TAP symmetric?"，最长对称子串为"s PAT&TAP s"，于是你应该输出11。

输入格式：

输入在一行中给出长度不超过1000的非空字符串。

输出格式：

在一行中输出最长对称子串的长度。

输入样例：
Is PAT&TAP symmetric?
输出样例：
11

*/

#include<string>
#include<iostream>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    int ans=0,t;
    size_t len=s.length();
    for(int i=0;i<len;i++){
        t=1;
        for(int j=1;j<len;j++){
            if(i-j<0||i+j>=len||s[i-j]!=s[i+j])
                break;
            t+=2;
        }
        ans=t>ans?t:ans;
        t=0;
        for(int j=1;j<len;j++){
            if(i-j+1<0||i+j>=len||s[i-j+1]!=s[i+j])
                break;
            t+=2;
        }
        ans=t>ans?t:ans;
    }
    cout<<ans<<endl;

    return 0;
}