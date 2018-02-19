
/*

L1-031. 到底是不是太胖了
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
据说一个人的标准体重应该是其身高（单位：厘米）减去100、再乘以0.9所得到的公斤数。真实体重与标准体重误差在10%以内都是完美身材（即 |真实体重-标准体重| < 标准体重x10%）。已知1市斤=0.5公斤。现给定一群人的身高和实际体重，请你告诉他们是否太胖或太瘦了。

输入格式：

输入第一行给出一个正整数N（<= 20）。随后N行，每行给出两个整数，分别是一个人的身高H（120 < H < 200；单位：厘米）和真实体重W（50 < W <= 300；单位：市斤），其间以空格分隔。

输出格式：

为每个人输出一行结论：如果是完美身材，输出“You are wan mei!”；如果太胖了，输出“You are tai pang le!”；否则输出“You are tai shou le!”。

输入样例：
3
169 136
150 81
178 155
输出样例：
You are wan mei!
You are tai shou le!
You are tai pang le!

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        float h,w;
        cin>>h>>w;
        float std_w=(h-100)*0.9*2;
        if(abs(std_w-w)<(std_w*0.1)){
            cout<<"You are wan mei!"<<endl;
        }
        else if(std_w>w){
            cout<<"You are tai shou le!"<<endl;
        }else{
            cout<<"You are tai pang le!"<<endl;
        }
    }

    return 0;
}