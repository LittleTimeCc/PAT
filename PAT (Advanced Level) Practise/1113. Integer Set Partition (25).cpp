/*

1113. Integer Set Partition (25)

时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a set of N (> 1) positive integers, you are supposed to partition them into two disjoint sets A1 and A2 of n1 and n2 numbers, respectively. Let S1 and S2 denote the sums of all the numbers in A1 and A2, respectively. You are supposed to make the partition so that |n1 - n2| is minimized first, and then |S1 - S2| is maximized.

Input Specification:

Each input file contains one test case. For each case, the first line gives an integer N (2 <= N <= 105), and then N positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than 231.

Output Specification:

For each case, print in a line two numbers: |n1 - n2| and |S1 - S2|, separated by exactly one space.

Sample Input 1:
10
23 8 10 99 46 2333 46 1 666 555
Sample Output 1:
0 3611
Sample Input 2:
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
Sample Output 2:
1 9359

*/

#include<cstdio>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    int n=0;
    scanf("%d",&n);
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    sort(arr,arr+n);
    printf("%d %d",n%2,accumulate(arr,arr+n,0)-2*accumulate(arr,arr+(n/2),0));

    return 0;
}