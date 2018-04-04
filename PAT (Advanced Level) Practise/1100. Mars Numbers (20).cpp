/*

1100. Mars Numbers (20)

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
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13

*/

#include<string>
#include<iostream>
using namespace std;

const string a[] = { "","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const string b[] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void numToStr(const string& str);
void strToNum(const string& str);

int main()
{
    int n;
    cin>>n;
    string s;
    getchar();
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        if(s[0]=='0'&&s.size()==1)
        {
            cout<<"tret"<<endl;
        }
        else
        {
            if(s[0]>='0'&&s[0]<='9')
            {
                numToStr(s);
            }
            else
            {
                strToNum(s);
            }
        }
    }

    return 0;
}


void numToStr(const string& str)
{
    int t=stoi(str);
    if(t<13)
    {
        cout<<a[t%13]<<endl;
    }
    else if(t%13==0)
    {
        cout<<b[t/13]<<endl;
    }
    else
    {
        cout<<b[t/13]<<" "<<a[t%13]<<endl;
    }
    
}
void strToNum(const string& str)
{
    if(str.size()==3)
    {
        for(int i=1;i<=12;i++)
        {
            if(str[0]==a[i][0]&&str[1]==a[i][1]&&str[2]==a[i][2])
            {
                cout<<i<<endl;
            }
            else if(str[0]==b[i][0]&&str[1]==b[i][1]&&str[2]==b[i][2])
            {
                cout<<13*i<<endl;
            }
        }
    }
    else
    {
        int high=0,low=0;
        for(int j=1;j<=12;j++)
        {
            if(str[0]==b[j][0]&&str[1]==b[j][1]&&str[2]==b[j][2])
            {
                high=j;
            }
            if(str[4]==a[j][0]&&str[5]==a[j][1]&&str[6]==a[j][2])
            {
                low=j;
            }
        }
        cout<<high*13+low<<endl;
    }
}