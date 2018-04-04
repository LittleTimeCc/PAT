/*

1040. Longest Symmetric String (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11

*/

#include<cstdio>
#include<cstring>

size_t work(char* str){
    //分奇、偶两种情况
    char *left,*right;
    size_t ans=1;
    char *ptr=str;
    while(*ptr!='\0'){
        //奇数情况
        left=ptr-1;
        right=ptr+1;
        while(left>=str&&*right!='\0'&&*left==*right)
        {
            left--;
            right++;
        }
        if(right-left-1>ans)
            ans=right-left-1;
        //偶数情况
        left=ptr;
        right=ptr+1;
        while(left>=str&&*right!='\0'&&*left==*right)
        {
            left--;
            right++;
        }
        if(right-left-1>ans)
            ans=right-left-1;
        ptr++;
    }
    return ans;
}

int main()
{
    char str[1001];
    scanf("%[^\n]",str);
    printf("%u\n",work(str));

    return 0;
}