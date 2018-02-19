/*

L1-007. 念数字
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
翁恺
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出“fu”字。十个数字对应的拼音如下：

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
输入格式：

输入在一行中给出一个整数，如： 1234 。

提示：整数包括负数、零和正数。

输出格式：

在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如 yi er san si。

输入样例：
-600
输出样例：
fu liu ling ling

*/

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>


using namespace std;

static string map[]={ "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

int main(){
    int n;
    cin>>n;
    vector<string> ans;
    if(!n){
        cout<<"ling"<<endl;
        return 0;
    }
    if(n<0){
        cout<<"fu ";
    }
    n=abs(n);
    while(n){
        ans.push_back(map[n%10]);
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans[0];
    for(int i=1;i<ans.size();i++){
        cout<<" "<<ans[i];
    }
    return 0;

}