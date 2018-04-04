/*

L3-002. 堆栈
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
大家都知道“堆栈”是一种“先进后出”的线性结构，基本操作有“入栈”（将新元素插入栈顶）和“出栈”（将栈顶元素的值返回并从堆栈中将其删除）。现请你实现一种特殊的堆栈，它多了一种操作叫“查中值”，即返回堆栈中所有元素的中值。对于N个元素，若N是偶数，则中值定义为第N/2个最小元；若N是奇数，则中值定义为第(N+1)/2个最小元。

输入格式：

输入第一行给出正整数N（<= 105）。随后N行，每行给出一个操作指令，为下列3种指令之一：

Push key
Pop
PeekMedian
其中Push表示入栈，key是不超过105的正整数；Pop表示出栈；PeekMedian表示查中值。

输出格式：

对每个入栈指令，将key入栈，并不输出任何信息。对每个出栈或查中值的指令，在一行中打印相应的返回结果。若指令非法，就打印“Invalid”。

输入样例：
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
输出样例：
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid


*/

/* 解题思路：树状数组 */
#include<cstdio>
#include<vector>
#define lowbit(x) ((x)&(-x))

const size_t maxn=100001;
int c[maxn];
std::vector<int> s;

void update(int k,int x){
    for(int i=k;i<=maxn;i+=lowbit(i)){
        c[i]+=x;
    }
}
int getsum(int x){
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i))
        sum+=c[i];
    return sum;
}
void PeekMedian(){
    int l=1,r=maxn,mid,k=(s.size()+1)/2;
    while(l<r){
        mid=(l+r)/2;
        if(getsum(mid)>=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
}
int main()
{
    int n,t;
    scanf("%d",&n);
    char str[11];
    for(int i=0;i<n;i++){
        scanf("%s",str);
        if(str[1]=='u'){
            scanf("%d",&t);
            s.push_back(t);
            update(t,1);
        }else if(str[1]=='o'){
            if(s.empty()){
                printf("Invalid\n");
            }else{
                update(s.back(),-1);
                printf("%d\n",s.back());
                s.pop_back();
            }
        }else{
            if(s.empty()){
                printf("Invalid\n");
            }else{
                PeekMedian();
            }
        }
    }

    return 0;
}