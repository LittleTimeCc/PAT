/*

1023. Have Fun with Numbers (20)

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
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798

*/

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int cnt1[10]={0},cnt2[10]={0};
string Double(const string& s)
{
    string ans,t=s;
    if(s.empty())   return ans;
    int carry=0,remain=0,sum=0;
    auto size=s.size();
    for(int i=size-1;i>=0;i--)
    {
        sum=s[i]-'0'+t[i]-'0'+carry;
        remain=sum%10;
        carry=sum/10;
        ans+=to_string(remain);
    }
    if(carry)
    {
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s;
    cin>>s;
    for(auto ch:s)
    {
        cnt1[ch-'0']++;
    }
    s=Double(s);
    for(auto ch:s)
    {
       cnt2[ch-'0']++;
    }
    bool flag=true;
    for(int i=0;i<10;i++)
    {
        if(cnt1[i]!=cnt2[i])
        {
            flag=false;
            break;
        }
    }
    if(flag){cout<<"Yes"<<endl<<s;}
    else{cout<<"No"<<endl<<s;}
    
    return 0;
}