/*

1018. Public Bike Management (30)

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
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0

*/

#include<cstdio>
#include<vector>

const int INF=65536;
const int MAX=505;  
int G[MAX][MAX]={0};    //adj_matrix
int station[MAX]={0};  //存储每个站点的自行车数目
int C,N,S,M,perfect;    //站点容量、站点数、需要调整的站点、路径条数、最佳自行车数目
std::vector<int> min_path,cur_path; //分别表示最优路径、当前路径；
int min_send=INF;
int min_back=INF;
int cur_send=0;
int cur_back=0;
int visit[MAX]={0};
int min_len=INF;
int cur_len=0;

void dfs(int point);
int main()
{
    scanf("%d %d %d %d",&C,&N,&S,&M);
    perfect=C/2;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&station[i]);
    }
    for(int i=0;i<M;i++)
    {
        int start,end,weight;
        scanf("%d %d %d",&start,&end,&weight);
        G[start][end]=G[end][start]=weight;
    }
    dfs(0);
    printf("%d 0",min_send); //容器中的路径不含起点0；
    for(int i=0;i<min_path.size();i++)
    {
        printf("->%d",min_path[i]);
    }
    printf(" %d\n",min_back);

    return 0;
}

void dfs(int point)
{
    visit[point]=1;
    if(cur_len>min_len)
        return;
    if(point==S)    //访问到了目的地
    {
        if(cur_len<min_len)
        {
            min_path=cur_path;
            min_len=cur_len;
            min_send=cur_send;
            min_back=cur_back;
        }
        else if(cur_len==min_len)
        {
            if(cur_send<min_send)
            {
                min_path=cur_path;
                min_send=cur_send;
                min_back=cur_back;
            }
            else if(cur_send==min_send&&cur_back<min_back)
            {
                min_path=cur_path;
                min_back=cur_back;
            }
        }
        return;
    }
    //还未访问到目的地,循环dfs
    for(int i=1;i<=N;i++)
    {
        if(visit[i]==0&&G[point][i])
        {
            int last_send=cur_send;
            int last_back=cur_back;
            cur_len+=G[point][i];
            cur_path.push_back(i);
            if((cur_back+station[i])<perfect)
            {
                cur_send+=perfect-cur_back-station[i];
                cur_back=0;
            }
            else
            {
                cur_back+=station[i]-perfect;
            }
            dfs(i);
            cur_path.pop_back();
            visit[i]=0;
            cur_len-=G[point][i];
            cur_send=last_send;
            cur_back=last_back;
        }
    }

    return;
}