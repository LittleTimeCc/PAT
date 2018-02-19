/*

L1-039. 古风排版
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
中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

输入格式：

输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

输出格式：

按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）

输入样例：
4
This is a test case
输出样例：
asa T
st ih
e tsi
 ce s

*/

#include<string>
#include<iostream>
#include<vector>

using namespace std;

void print_2D_Array(const vector<vector<char>>& v){
    for(const auto a:v){
        for(const auto b:a){
            cout<<b;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    getchar();
    string s;
    getline(cin,s);
    int t=s.size();
    int cols=(t%n==0)?t/n:t/n+1;
    vector<vector<char>> result(n,vector<char>(cols,' '));
    int index=0;
    for(int j=cols-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(index<s.size()){
                result[i][j]=s[index++]; 
            }
                   
        }     
    }
    print_2D_Array(result);
    
    return 0;
}