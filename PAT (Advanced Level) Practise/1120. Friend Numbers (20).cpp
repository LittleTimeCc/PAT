
/*

1120. Friend Numbers (20)
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
Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different friend ID's among them. Note: a number is considered a friend of itself.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than 104.

Output Specification:

For each case, print in the first line the number of different frind ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line.

Sample Input:
8
123 899 51 998 27 33 36 12
Sample Output:
4
3 6 9 26

*/

#include<iostream>
#include<set>

using namespace std;

int help(int a){
    int sum=0;
    while(a){
        sum+=(a%10);
        a/=10;
    }
    return sum;
}

int main(){
    int n;
    set<int> ans;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++){
        cin>>*(p+i);
        ans.insert(help(*(p+i)));
    }
    cout<<ans.size()<<endl;
    for(auto it=ans.begin();it!=ans.end();it++){
        if(it!=ans.begin()){
            cout<<" "<<*it;
        }
        else cout<<*it;
    }
    delete []p;
    return 0;
}