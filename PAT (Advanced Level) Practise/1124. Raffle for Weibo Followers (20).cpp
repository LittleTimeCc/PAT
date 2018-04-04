/*

1124. Raffle for Weibo Followers (20)

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
John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers M (<= 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.

Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.

Output Specification:

For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print "Keep going..." instead.

Sample Input 1:
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
Sample Output 1:
PickMe
Imgonnawin!
TryAgainAgain
Sample Input 2:
2 3 5
Imgonnawin!
PickMe
Sample Output 2:
Keep going...

*/
#include<string>
#include<set>
#include<iostream>
using namespace std;

int main()
{
    int m,n,s;
    set<string> flag;
    cin>>m>>n>>s;
    string* vs=new string[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>vs[i];
    }
    if(n>m||s>m)
    {
        cout<<"Keep going..."<<endl;
        return 0;
    }
    cout<<vs[s]<<endl;
    flag.insert(vs[s]);
    int index=0;
    for(int i=s+1;i<=m;i++)
    {
        if(flag.count(vs[i])==0)
        {
            index++;
            if(index==n)
            {
                cout<<vs[i]<<endl;
                flag.insert(vs[i]);
                index=0;
            }
        }
    }

    return 0;
}