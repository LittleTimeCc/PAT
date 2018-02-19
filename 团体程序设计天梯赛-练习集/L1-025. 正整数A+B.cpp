/*

L1-025. 正整数A+B
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
本题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：

输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：

如果输入的确是两个正整数，则按格式“A + B = 和”输出。如果某个输入不合要求，则在相应位置输出“?”，显然此时和也是“?”。

输入样例1：
123 456
输出样例1：
123 + 456 = 579
输入样例2：
22. 18
输出样例2：
? + 18 = ?
输入样例3：
-100 blabla bla...33
输出样例3：
? + ? = ?

*/

#include<cctype>
#include<iostream>
#include<string>

using namespace std;

bool is_Range_Number(const string& s){
    if(s.empty())
        return false;
    for(const auto& ch:s){
        if(!isdigit(ch)){
            return false;
        }
    }
    int t=stoi(s);
    if(t<1||t>1000){
        return false;
    }
    return true;
}

int main(){
    string a,b,line;
    getline(cin,line);
    for(auto i=0;i<line.size();i++){
        if(line[i]==' '){
            a=line.substr(0,i);
            b=line.substr(i+1,line.size()-i-1);
            break;
        }
    }
    
    if(!is_Range_Number(a)){a="?";}
    if(!is_Range_Number(b)){b="?";}
    cout<<a<<" + "<<b<<" = ";
    if(a!="?"&&b!="?"){
        cout<<stoi(a)+stoi(b)<<endl;
    }else{
        cout<<"?"<<endl;
    }
    
    return 0;
}