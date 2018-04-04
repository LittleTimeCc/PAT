/*

1029. Median (25)

时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13

*/

#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

using LL=long long int;
vector<LL> v;

int main()
{
    int T=2;
    while(T--)
    {
        int n,t;
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&t);
            v.push_back(t);
        }
    }
    nth_element(v.begin(),v.begin()+(v.size()-1)/2,v.end());
    printf("%lld",v[(v.size()-1)/2]);

    return 0;
}