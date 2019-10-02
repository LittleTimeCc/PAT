
/*

1087 有多少不同的值 （20 分）
当自然数 n 依次取 1、2、3、……、N 时，算式 ⌊n/2⌋+⌊n/3⌋+⌊n/5⌋ 有多少个不同的值？（注：⌊x⌋ 为取整函数，表示不超过 x 的最大自然数，即 x 的整数部分。）

输入格式：
输入给出一个正整数 N（2≤N≤10000）。
输出格式：
在一行中输出题面中算式取到的不同值的个数。
输入样例：
2017
输出样例：
1480

*/

#include<iostream>
#include<map>
using namespace std;

int main()
{
    int N;
    map<int,int> M;
    cin>>N;
    for(int i=1;i<=N;i++){
        M[i/2+i/3+i/5]++;
    }
    cout<<M.size()<<endl;
    return 0;
}