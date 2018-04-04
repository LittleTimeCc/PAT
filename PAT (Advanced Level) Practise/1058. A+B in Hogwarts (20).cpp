
/*

1058. A+B in Hogwarts (20)
时间限制
50 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28

*/

#include<cstdio>

struct Hog{
    int a,b,c;
}A,B,C;

int main(){
    scanf("%d.%d.%d %d.%d.%d",&A.a,&A.b,&A.c,&B.a,&B.b,&B.c);
    int count=0;
    C.c=(A.c+B.c+count)%29;
    count=(A.c+B.c+count)/29;
    C.b=(A.b+B.b+count)%17;
    count=(A.b+B.b+count)/17;
    C.a=A.a+B.a+count;
    printf("%d.%d.%d\n",C.a,C.b,C.c);
    return 0;
}