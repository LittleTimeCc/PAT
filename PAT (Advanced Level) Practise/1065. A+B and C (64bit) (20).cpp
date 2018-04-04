
/*

1065. A+B and C (64bit) (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false

*/


//该题要考虑同符号数运算时溢出的情况,上溢出和下溢出;
#include<iostream>

using namespace std;

typedef long long int BigInt;

int main(){
    int n;
    cin>>n;
    BigInt a,b,c,sum;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        sum=a+b;
        if(a>0&&b>0&&sum<0){
            cout<<"Case #"<<i+1<<": true"<<endl;
        }else if(a<0&&b<0&&sum>=0){
            cout<<"Case #"<<i+1<<": false"<<endl;
        }else if(sum>c){
            cout<<"Case #"<<i+1<<": true"<<endl;
        }else{
            cout<<"Case #"<<i+1<<": false"<<endl;
        }
    }

    return 0;
}
