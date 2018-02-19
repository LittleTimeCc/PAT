/*

L1-032. Left-pad
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
根据新浪微博上的消息，有一位开发者不满NPM（Node Package Manager）的做法，收回了自己的开源代码，其中包括一个叫left-pad的模块，就是这个模块把javascript里面的React/Babel干瘫痪了。这是个什么样的模块？就是在字符串前填充一些东西到一定的长度。例如用“*”去填充字符串“GPLT”，使之长度为10，调用left-pad的结果就应该是“******GPLT”。Node社区曾经对left-pad紧急发布了一个替代，被严重吐槽。下面就请你来实现一下这个模块。

输入格式：

输入在第一行给出一个正整数N（<=104）和一个字符，分别是填充结果字符串的长度和用于填充的字符，中间以1个空格分开。第二行给出原始的非空字符串，以回车结束。

输出格式：

在一行中输出结果字符串。

输入样例1：
15 _
I love GPLT
输出样例1：
____I love GPLT
输入样例2：
4 *
this is a sample for cut
输出样例2：
 cut

*/

#include<string>
#include<iostream>

using namespace std;

int main(){
    int n;
    char ch;
    cin>>n>>ch;
    getchar();
    string s;
    getline(cin,s);
    int len=s.size();
    if(n>=len){
        int len=n-s.size();
        while(len--){
            s.insert(s.begin(),ch);
        }
        cout<<s<<endl;
    }else{
        cout<<s.substr(s.size()-n)<<endl;
    }

    return 0;
}