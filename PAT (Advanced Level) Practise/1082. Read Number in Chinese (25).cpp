
/*

1082. Read Number in Chinese (25)
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
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const string num[] { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" }; 
const string p[]{ "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi", "Shi", "Bai", "Qian"};
vector<string> ans;//store the result;

int main(){
   int sign=1;
   string in;
   cin>>in;
   if(in[0]=='-'){
       sign=0;
       in=in.substr(1,string::npos);
   }

    //处理输入前置为0的情况,除去所有的前置0;
    while(in.size()>1&&in[0]=='0'){
        in=in.substr(1);
    }
    if(in=="0"){
        cout<<"ling"<<endl;
    }else{
        //negative number
        if(!sign)   ans.push_back("Fu");
        reverse(in.begin(),in.end());
        int ok=1;
        int ok_p=1;
        for(int i=in.size()-1;i>=0;i--){
            if(in[i]=='0'){
                ok=0;
                if(ok_p&&(i==8||i==4)){ //处理亿和万，100000000 yi Yi 不要输出yi Yi Wan
                    ans.push_back(p[i]);
                    ok_p=0;
                }
            }else{
                if(!ok){
                    ans.push_back(num[0]);
                    ok=1;
                }
                ans.push_back(num[in[i]-'0']);
                if(i!=0)    ans.push_back(p[i]);
                if(i==8) {  //处理亿和万，100000000 yi Yi 不要输出yi Yi Wan
                    ok_p=0;
                }
            }
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }

    return 0;
}