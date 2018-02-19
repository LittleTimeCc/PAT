/*

L1-006. 连续因子
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
一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。给定任一正整数N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：

输入在一行中给出一个正整数N（1<N<231）。

输出格式：

首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出最小的连续因子序列，其中因子按递增顺序输出，1不算在内。

输入样例：
630
输出样例：
3
5*6*7

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    int max_len=0,max_begin=0;
    for(int i=2;i<=sqrt(n)+1;i++){
        if(n%i==0){ //find the first number n is divided by i;
            int j=i,t=n,new_begin=i,new_len=0;
            while(t%j==0){
                t/=j;
                j++;
                new_len++;
            }
            if(new_len>max_len){
                max_len=new_len;
                max_begin=new_begin;
            }
        }   
    }

    if(max_len==0)  //prime number
    {
        max_begin=n;
        max_len=1;
    }
    cout<<max_len<<endl;
    cout<<max_begin;
    for(int i=max_begin+1;i<max_begin+max_len;i++){
        cout<<"*"<<i;
    }
    cout<<endl;


    return 0;

}