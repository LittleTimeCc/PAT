
/*

L1-041. 寻找250
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

对方不想和你说话，并向你扔了一串数…… 而你必须从这一串数字中找到“250”这个高大上的感人数字。

输入格式：

输入在一行中给出不知道多少个绝对值不超过1000的整数，其中保证至少存在一个“250”。

输出格式：

在一行中输出第一次出现的“250”是对方扔过来的第几个数字（计数从1开始）。题目保证输出的数字在整型范围内。

输入样例：
888 666 123 -233 250 13 250 -222
输出样例：
5

*/


#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
   string s;
   getline(cin,s);
   stringstream ss(s);
   int cnt=0,num;

   while(ss>>num){
       cnt++;
       if(num==250){
           cout<<cnt;
           break;
       }
       
   }

    return 0;
}