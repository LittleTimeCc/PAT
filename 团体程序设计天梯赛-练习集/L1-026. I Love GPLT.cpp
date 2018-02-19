/*

L1-026. I Love GPLT
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
这道超级简单的题目没有任何输入。

你只需要把这句很重要的话 —— “I Love GPLT”——竖着输出就可以了。

所谓“竖着输出”，是指每个字符占一行（包括空格），即每行只能有1个字符和回车。

*/

#include<iostream>
#include<string>

using namespace std;

int main(){
	const string s="I Love GPLT";
	for(const auto ch:s){
		cout<<ch<<endl;
	}

    return 0;   
}