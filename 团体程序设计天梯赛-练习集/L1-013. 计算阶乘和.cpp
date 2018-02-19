/*

L1-013. 计算阶乘和
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
对于给定的正整数N，需要你计算 S = 1! + 2! + 3! + ... + N!。

输入格式：

输入在一行中给出一个不超过10的正整数N。

输出格式：

在一行中输出S的值。

输入样例：
3
输出样例：
9

*/

#include<iostream>
#include<cmath>

using namespace std;

using BigInt=long long int;
BigInt Factorial(BigInt n){
    if(n==0)    return 1;
    return n*Factorial(n-1);
}


int main(){
    int sum=0,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        sum+=Factorial(i);
    }
    cout<<sum<<endl;

    return 0;   
}