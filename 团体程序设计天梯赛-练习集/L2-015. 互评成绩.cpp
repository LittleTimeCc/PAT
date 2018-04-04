
/*

L2-015. 互评成绩
时间限制
250 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
学生互评作业的简单规则是这样定的：每个人的作业会被k个同学评审，得到k个成绩。系统需要去掉一个最高分和一个最低分，将剩下的分数取平均，就得到这个学生的最后成绩。本题就要求你编写这个互评系统的算分模块。

输入格式：

输入第一行给出3个正整数N（3< N <= 104，学生总数）、k（3<= k <= 10，每份作业的评审数）、M（<= 20，需要输出的学生数）。随后N行，每行给出一份作业得到的k个评审成绩（在区间[0, 100]内），其间以空格分隔。

输出格式：

按非递减顺序输出最后得分最高的M个成绩，保留小数点后3位。分数间有1个空格，行首尾不得有多余空格。

输入样例：
6 5 3
88 90 85 99 60
67 60 80 76 70
90 93 96 99 99
78 65 77 70 72
88 88 88 88 88
55 55 55 55 55
输出样例：
87.667 88.000 96.000

*/

#include<algorithm>
#include<cstdio>
#include<functional>
#include<numeric>

using namespace std;

const size_t MAX=10000;
double score[MAX]={0};
double grade[MAX]={0};


int main(){
    int n,k,m;
    double t=0.0;
    scanf("%d %d %d", &n, &k, &m); 
    for(int i=0;i<n;i++){
        double sum=0.0;
        for(int j=0;j<k;j++){
            scanf("%lf", &grade[j]); 
        }
        sort(grade,grade+k,greater<double>());
        for(int j = 1; j < k-1; j++) sum += grade[j];
        score[i]=sum/(double)(k-2);
    }
    sort(score,score+n,greater<double>());
    bool flag=true;
    for(int i=m-1;i>=0;i--){
        if(flag){
            printf("%.3lf",score[i]);
            flag=false;
        }
        else{
            printf(" %.3lf",score[i]);
        }
    }

  return 0;
}