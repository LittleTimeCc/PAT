

/*

1005. Spell It Right (20)
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
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

*/

#include<string>
#include<iostream>

using namespace std;

const string digits[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
int main(){
    string input;
    cin>>input;
    int sum=0;
    for(const auto ch:input){
        sum+=(ch-'0');
    }
    string t=to_string(sum);
    cout<<digits[t[0]-'0'];
    for(int i=1;i<t.size();i++){
        cout<<" "<<digits[t[i]-'0'];
    }

    return 0;
}