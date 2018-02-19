
/*

L1-004. 计算摄氏温度
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈建海
给定一个华氏温度F，本题要求编写程序，计算对应的摄氏温度C。计算公式：C = 5*(F-32)/9。题目保证输入与输出均在整型范围内。

输入格式：

输入在一行中给出一个华氏温度。

输出格式：

在一行中按照格式“Celsius = C”输出对应的摄氏温度C的整数值。

输入样例：
150
输出样例：
Celsius = 65

*/

#include<iostream>

using namespace std;

int main() {
    int input;
    cin>>input;
    int C=5*(input-32)/9;
    cout<<"Celsius = "<<C<<endl;

	return 0;
}