/*

L1-010. 比较大小
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
杨起帆（浙江大学城市学院）
本题要求将输入的任意3个整数从小到大输出。

输入格式：

输入在一行中给出3个整数，其间以空格分隔。

输出格式：

在一行中将3个整数从小到大输出，其间以“->”相连。

输入样例：
4 2 8
输出样例：
2->4->8

*/

#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    using BigInt=long long int;
    BigInt nums[3];
    for(int i=0;i<3;i++){
        cin>>nums[i];
    }
    sort(nums,nums+3);
    cout<<nums[0]<<"->"<<nums[1]<<"->"<<nums[2]<<endl;       
    
    return 0;

}