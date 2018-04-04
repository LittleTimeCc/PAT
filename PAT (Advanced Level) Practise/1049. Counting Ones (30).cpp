
/*

1049. Counting Ones (30)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5

*/

#include<cstdio>

int main() {
	int n,left=0,right=0,flag=1,now=1,ans=0;
    scanf("%d",&n);
    while(n/flag){
        left=n/(flag*10);
        now=n/flag%10;
        right=n%flag;
        if(now==0)  ans+=left*flag;
        else if(now==1) ans+=left*flag+right+1;
        else    ans+=(left+1)*flag;
        flag*=10;
    }
    printf("%d\n",ans);

	return 0;
}