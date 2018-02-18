/*

1003. Emergency (25)

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
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4

*/

#include<cstdio>
#include<vector>

using namespace std;

const size_t N=501;
int n,m,s,e;
int team[N],vis[N],numDis,minDis,maxTeam;
int matrix[N][N];
vector<int> path;

void DFS(int next){ //深搜 + 回溯
    if(next==e){    //如果当前节点是目标点
        int curTeam=0,curDis=0;
        for(int i=0;i<path.size();i++){
            curTeam+=team[path[i]];
        }
        for(int i=0;i<path.size()-1;i++){
            curDis+=matrix[path[i]][path[i+1]];
        }
        if(curDis < minDis)
        {
            numDis = 1;
            minDis = curDis;
            maxTeam = curTeam;
        }
        else if(curDis == minDis)
        {
            numDis++;
            if(curTeam > maxTeam)   maxTeam = curTeam;
        }
        return;
    }
    for(int i = 0; i < n; i++){
        if(matrix[next][i] != -1){
            if(!vis[i])
            {
                vis[i] = 1;
                path.push_back(i);
                DFS(i);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }
    
}
int main(){
    int a,b,d;
    while(scanf("%d %d %d %d",&n,&m,&s,&e)==4){
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(int j=0;j<n;j++){
                matrix[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            scanf("%d",&team[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&d);
            matrix[a][b]=matrix[b][a]=d;
        }
        path.clear();
        numDis=0;
        minDis=0x7fffffff;
        maxTeam=-1;
        vis[s]=1;
        path.push_back(s);
        DFS(s);
        path.pop_back();
        vis[s]=0;
        printf("%d %d\n",numDis,maxTeam);
    }
    return 0;
}