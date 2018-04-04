
/*

1063. Set Similarity (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%

*/

#include<iostream>
#include<set>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int n,m,k,x,a,b;
    cin>>n;
    vector<set<int>> vs(n);
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>x;
            vs[i].insert(x);
        }
    }
    cin>>k;
    
    for(int i=0;i<k;i++){
        cin>>a>>b;
        int nc=0,nt=vs[b-1].size();
        for(auto it=vs[a-1].begin();it!=vs[a-1].end();it++){
            if(vs[b-1].find(*it)==vs[b-1].end()){
                nt++;
            }else{
                nc++;
            }
        }
        double result=static_cast<double>(nc)/nt*100;
        printf("%.1lf%%\n",result);
    }

    return 0;
}