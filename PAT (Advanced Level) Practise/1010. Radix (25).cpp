/*

1010. Radix (25)

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
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible

*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using LL=long long int;
const LL INF=(1LL<<63)-1;
struct Number{
    char digit[12];
    int radix;

    int minRadix(){
        int max=-1;
        int len=strlen(digit);
        for(int i=0;i<len;i++){
            int tmp;
            if(digit[i]>='0'&&digit[i]<='9'){
                tmp=digit[i]-'0';
            }else{
                tmp=digit[i]-'a'+10;
            }
            if(tmp>max){
                max=tmp;
            }
        }
        return max+1;
    }
    LL decimal(){
        LL ans=0,weight=1;
        int len=strlen(digit);
        for(int i=len-1;i>=0;i--){
            int tmp;
            if(digit[i]>='0'&&digit[i]<='9'){
                tmp=digit[i]-'0';
            }else{
                tmp=digit[i]-'a'+10;
            }
            ans+=tmp*weight;
            weight*=radix;
            if(ans<0)   return -1;
        }
        return ans;
    }
}num1,num2;
int binarySearch(){
    LL x=num1.decimal();
    LL l=num2.minRadix(),r=std::max(l,x)+1,mid;
    while(l<=r){
        mid=(l+r)/2;
        num2.radix=mid;
        if(num2.decimal()==x)   return mid;
        if(num2.decimal()<0||num2.decimal()>x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    scanf("%s %s",num1.digit,num2.digit);
    int flag,radix;
    scanf("%d %d",&flag,&radix);
    if(flag==2){
        std::swap(num1.digit,num2.digit);
    }
    num1.radix=radix;
    int ans=binarySearch();
    if(ans==-1){
        printf("Impossible\n");
    }
    else{
        printf("%d\n",ans);
    }
    
    return 0;
}
