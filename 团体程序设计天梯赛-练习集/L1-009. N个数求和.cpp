/*

L1-009. N个数求和
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数“分子/分母”的形式给出的，你输出的和也必须是有理数的形式。

输入格式：

输入第一行给出一个正整数N（<=100）。随后一行按格式“a1/b1 a2/b2 ...”给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：

输出上述数字和的最简形式 —— 即将结果写成“整数部分 分数部分”，其中分数部分写成“分子/分母”，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24

*/

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

using BigInt=long long int;

static inline BigInt Gcd(BigInt a, BigInt b) {
	a = abs(a);
	b = abs(b);
	return b == 0 ? a : Gcd(b, a%b);
}	

class Fraction {
public:
	friend Fraction operator+(const Fraction& lhs,const Fraction& rhs){
		Fraction result;
		result.a=lhs.a*rhs.b+lhs.b*rhs.a;
		result.b=lhs.b*rhs.b;
		result.deal_with__simple();
		return	result;
	}

	void deal_with__simple(){
		BigInt gc=Gcd(a,b);
		a/=gc;
		b/=gc;
	}

	void print()const{
		if(a==0)	cout<<"0\n";
		else if(abs(a)<b)	cout<<a<<"/"<<b<<endl;
		else if(a%b==0)	cout<<a/b<<endl;
		else cout<<a/b<<" "<<a%b<<"/"<<b<<endl;
	}
	
	BigInt a,b;
};


int main(){
    int n;
	Fraction ans,t;
	cin>>n;
	scanf("%lld/%lld",&ans.a,&ans.b);
	for(int i=1;i<n;i++){
		scanf("%lld/%lld",&t.a,&t.b);
		ans=ans+t;
	}
	ans.print();

    return 0;   
}