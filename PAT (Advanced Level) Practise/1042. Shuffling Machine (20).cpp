
/*

1042. Shuffling Machine (20)
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
Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order:

S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer K (<= 20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.

Sample Input:
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
Sample Output:
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
提交代码

*/

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string ans[55];     //global value and store Num_to_Card;
void Init_Shuffling();  

int main(){
    Init_Shuffling();
    int i,k,Shu[55];
    string tmp[55];
    cin>>k;
    for(i=1;i<=54;i++)  cin>>Shu[i];
    while(k--){
        for(i=1;i<=54;i++){
            tmp[Shu[i]]=ans[i];
        }
        for(i=1;i<=54;i++){
            ans[i]=tmp[i];
        }
    }
    cout<<ans[1];
    for(i=2;i<=54;i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}

void Init_Shuffling(){
    int len=1,i;
    for(i=1;i<=9;i++,len++){
        ans[len]="  ";
        ans[len][0]='S';
        ans[len][1]='0'+i;
    }
    ans[len++]="S10";
    ans[len++]="S11";
    ans[len++]="S12";
    ans[len++]="S13";

    for(i=1;i<=9;i++,len++){
        ans[len]="  ";
        ans[len][0]='H';
        ans[len][1]='0'+i;
    }
    ans[len++]="H10";
    ans[len++]="H11";
    ans[len++]="H12";
    ans[len++]="H13";

    for(i=1;i<=9;i++,len++){
        ans[len]="  ";
        ans[len][0]='C';
        ans[len][1]='0'+i;
    }
    ans[len++]="C10";
    ans[len++]="C11";
    ans[len++]="C12";
    ans[len++]="C13";

    for(i=1;i<=9;i++,len++){
        ans[len]="  ";
        ans[len][0]='D';
        ans[len][1]='0'+i;
    }

    ans[len++]="D10";
    ans[len++]="D11";
    ans[len++]="D12";
    ans[len++]="D13";
    ans[len++]="J1";
    ans[len++]="J2";
}
