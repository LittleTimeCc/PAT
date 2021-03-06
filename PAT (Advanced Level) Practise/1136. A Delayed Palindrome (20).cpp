
/*

1136. A Delayed Palindrome (20)
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
Consider a positive integer N written in standard notation with k+1 digits ai as ak...a1a0 with 0 <= ai < 10 for all i and ak > 0. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 and is also palindromic by definition.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number)

Given any positive integer, you are supposed to find its paired palindromic number.

Input Specification:

Each input file contains one test case which gives a positive integer no more than 1000 digits.

Output Specification:

For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:

A + B = C
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line "C is a palindromic number."; or if a palindromic number cannot be found in 10 iterations, print "Not found in 10 iterations." instead.

Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.

*/

#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string BigInteger_Add(const string& s){
	string result,t=s;
	reverse(t.begin(),t.end());
	size_t len=s.size(),carry=0;
	for(int i=0;i<len;i++){
			int num=(s[i]-'0'+t[i]-'0')+carry;
			carry=0;
			if(num>=10){
					carry=1;
					num-=10;
			}
			result+=to_string(num);
	}
	if(carry)       result+="1";
	reverse(result.begin(),result.end());
	return result;
}

int main()
{
	string input;
	cin>>input;
	int count=0;
	while(count<10){
			string t=input;
			reverse(t.begin(),t.end());
			if(t==input){
					cout<<input<<" is a palindromic number.";
					return 0;
			}else{
					cout<<input<<" + "<<t<<" = "<<BigInteger_Add(input)<<endl;
					input=BigInteger_Add(input);
					count++;
			}
	}

	if (count == 10) cout << "Not found in 10 iterations."; 


	return 0;
}