
/*

1069. The Black Hole of Numbers (20)

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
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000

*/

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

const int len=4;
int main()
{
    string s;
    cin>>s;
    s.insert(s.begin(),len-s.size(),'0');
    do
    {
        string lhs=s,rhs=s;
        sort(lhs.begin(),lhs.end(),[](const char a,const char b){return a>b;});
        sort(rhs.begin(),rhs.end());
        int result=stoi(lhs)-stoi(rhs);
        s=to_string(result);
        s.insert(s.begin(),len-s.size(),'0');
        cout<<lhs<<" - "<<rhs<<" = "<<s<<endl;
    }while(s!="6174" && s!="0000");

    return 0;
}