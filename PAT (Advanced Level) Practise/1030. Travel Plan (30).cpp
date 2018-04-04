
/*

1030. Travel Plan (30)
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
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40

*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

struct City{
    int dis,cost;
}**cities;

bool *isVisited;
int final_len=INT32_MAX,final_cost;
vector<int> final_path;

void Dfs(int cur,int dest,int len,int cost,vector<int> &path,int n){
    if(cur==dest){
        if(len<final_len){
            final_len=len;
            final_cost=cost;
            final_path=path;
        }else if(len==final_len&&cost<final_cost){
            final_cost=cost;
            final_path=path;
        }
        return;
    }
    for(int i=0;i<n;i++){
        City c=cities[cur][i];
        if(c.dis!=-1&&!isVisited[i]){
            isVisited[i]=1;
            path.push_back(i);
            Dfs(i,dest,len+c.dis,cost+c.cost,path,n);
            path.pop_back();
            isVisited[i]=0;
        }
    }
}

void printPath(){
    for(int i=0;i<final_path.size();i++){
        cout<<final_path[i]<<" ";
    }
}

int main(){
    int n=0,m=0,s=0,d=0;
    cin>>n>>m>>s>>d;
    cities=new City* [n];
    isVisited=new bool[n];
    for(int i=0;i<n;i++){
        cities[i]=new City[n];
        isVisited[i]=0;
        for(int j=0;j<n;j++){
            cities[i][j].dis=cities[i][j].dis=-1;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,dis,cost;
        cin>>a>>b>>dis>>cost;
        cities[a][b].dis=cities[b][a].dis=dis;
        cities[a][b].cost=cities[b][a].cost=cost;
    }

    vector<int> path;
    path.push_back(s);
    isVisited[s]=1;
    Dfs(s,d,0,0,path,n);
    printPath();
    cout<<final_len<<" "<<final_cost<<endl;

    for(int i=0;i<n;i++){
        delete [] cities[i];
    }
    delete []cities;
    delete []isVisited;
    return 0;
}