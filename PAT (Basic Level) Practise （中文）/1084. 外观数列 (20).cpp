
/*

1084. 外观数列 (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
外观数列是指具有以下特点的整数序列：

d, d1, d111, d113, d11231, d112213111, ...
它从不等于 1 的数字 d 开始，序列的第 n+1 项是对第 n 项的描述。比如第 2 项表示第 1 项有 1 个 d，所以就是 d1；第 2 项是 1 个 d（对应 d1）和 1 个 1（对应 11），所以第 3 项就是 d111。又比如第 4 项是 d113，其描述就是 1 个 d，2 个 1，1 个 3，所以下一项就是 d11231。当然这个定义对 d = 1 也成立。本题要求你推算任意给定数字 d 的外观数列的第 N 项。

输入格式：

输入第一行给出[0,9]范围内的一个整数 d、以及一个正整数 N（<=40），用空格分隔。

输出格式：

在一行中给出数字 d 的外观数列的第 N 项。

输入样例：
1 8
输出样例：
1123123111

*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string d;
    int n;
    cin>>d>>n;
    while(--n){     //注意这是--n不能n--  因为只需要n-1次就ok;
        string ans;
        char ch=d[0];
        auto len=d.size();
        int cnt=0;
        for(int i=0;i<len;i++){
            if(d[i]==ch)   {cnt++;}
            else{
                ans+=ch;
                ans+=cnt+'0';
                ch=d[i];
                cnt=1;
            }
        }
        if(cnt>0){
            ans+=ch;
            ans+=cnt+'0';
        }
        d=ans;
    }
    cout<<d<<endl;

    return 0;
}