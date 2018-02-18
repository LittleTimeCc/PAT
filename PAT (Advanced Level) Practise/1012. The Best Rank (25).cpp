/*

1012. The Best Rank (25)
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
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A

*/

#include<cstdio>
#include<map>
#include<vector>
#include<functional>
using namespace std;

struct Node{
    int rank[4];
};

int main(){
    map<int,vector<int>,greater<int>> mp[4]; //4个map对应4个不同成绩的排名
    int n,m,id;
    int score[4];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&id,&score[1],&score[2],&score[3]);
        score[0]=score[1]+score[2]+score[3];
        for(int j=0;j<4;j++){
            if(mp[j].count(score[j]))
                mp[j][score[j]].push_back(id);
            else{
                vector<int> v;
                v.push_back(id);
                mp[j].insert(make_pair(score[j],v));
            }
        }
    }

    map<int,Node> result;
    int cnt=1;
    for(int i=0;i<4;i++){
        cnt=1;
        for(auto it=mp[i].begin();it!=mp[i].end();it++){
            for(size_t j=0;j<it->second.size();j++){
                id=it->second[j];
                result[id].rank[i]=cnt;
            }
            cnt+=it->second.size();
        }
    }
    const char ch[4]={'A','C','M','E'};
    for(int i=0;i<m;i++){
        scanf("%d",&id);
        if(result.count(id)){
            int min=result[id].rank[0];
            int min_pos=0;
            for(int j=1;j<4;j++)
            {
                if(result[id].rank[j]<min){
                    min=result[id].rank[j];
                    min_pos=j;
                }
            }
            printf("%d %c\n",min,ch[min_pos]);
        }
        else{
            printf("N/A\n");
        }
    }
    
    return 0;
}
