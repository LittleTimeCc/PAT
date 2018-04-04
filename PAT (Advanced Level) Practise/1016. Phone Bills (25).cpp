/*
1016. Phone Bills (25)

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
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

*/

#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

/*

ps1:数据的有效性
如果 1-on, 2-on, 3-off, 则1会被抛弃；

ps2:没有有效记录,不输出

*/
struct Node
{
    bool operator<(const Node& n){
        return (startTime<n.startTime);
    }
    Node(int s,int mo,int d,int h,int m,int t):startTime(s),month(mo),dd(d),hh(h),mm(m),tag(t){}
    int startTime;
    int month,dd,hh,mm;
    int tag; //0表示 on-line, 1表示off-line
};

int main()
{
    int fare[24];
    for(int i=0;i<24;i++)
    {
        scanf("%d",&fare[i]);
    }
    int n;
    scanf("%d",&n);
    map<string,vector<Node>> mp;  //一个人一个vector,存储他的记录
    for(int i=0;i<n;i++)
    {
        char tmp[25]={0};
        char status[10];
        int month,dd,hh,mm;
        scanf("%s %d:%d:%d:%d %s",tmp,&month,&dd,&hh,&mm,status);
        string name(tmp);
        int start=dd*1440+hh*60+mm;
        int tag=(status[1]=='n'?0:1);
        Node tNode(start,month,dd,hh,mm,tag);
        if(mp.count(name))
        {
            mp[name].push_back(tNode);
        }
        else
        {
            vector<Node> v;
            v.push_back(tNode);
            mp.insert(make_pair(name,v));
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int flag=0; //标记是否输出该人的记录,无有效记录不输出;
        int Total=0;
        sort(it->second.begin(),it->second.end());
        auto size=it->second.size();
        for(int i=0;i<size;)
        {
            if(it->second[i].tag==0)
            {
                for(int j=i+1;j<size;j++)
                {
                    if(it->second[j].tag==0)
                    {
                        i=j;
                        break;
                    }
                    else    //找到两条配对的记录
                    {
                        int total=0;
                        int duration=it->second[j].startTime-it->second[i].startTime;

                        int hhs=it->second[i].dd*24+it->second[i].hh+1;
                        int hhe=it->second[j].dd*24+it->second[j].hh;
                        if(hhs>hhe)     //这里表示开始和结束的小时一样,不一样的话需要单独处理
                        {
                            total += (it->second[j].mm - it->second[i].mm) * fare[it->second[i].hh];
                        }
                        else
                        {
                            total+=(60-it->second[i].mm)*fare[it->second[i].hh];
                            total+=(it->second[j].mm)*fare[it->second[j].hh];
                        }
                        for(int k=hhs;k<hhe;k++)
                        {
                            total+=60*fare[k%24];
                        }
                        Total+=total;
                        if(flag==0)
                        {
                            printf("%s %02d\n",it->first.c_str(),it->second[0].month);
                            flag=1;
                        }
                        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
							it->second[i].dd, it->second[i].hh, it->second[i].mm,
							it->second[j].dd, it->second[j].hh, it->second[j].mm,
							duration, total / 100.0);

						i = j + 1;
						break;
                    }
                }
                if(i==size-1)
                    i++;
            }
            else
            {
                i++;
            }
        }
        if(flag==1)
        {
            printf("Total amount: $%.2f\n", Total / 100.0);
        }
    }

    return 0;
}