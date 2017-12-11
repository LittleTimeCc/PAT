/*

1019. 数字黑洞 (20)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000

*/

#include<iostream>
#include<string>
#include<functional>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	string str1;
	cin >> str1;	
	str1.insert(0, 4 - str1.size(), '0');
	do {
		string s1 = str1, s2 = str1;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end(), greater<char>());
		if (s2 == s1) {
			cout << s2 << " - " << s1 << " = " << "0000";
			return 0;
		}
		int num1 = stoi(s1);
		int num2 = stoi(s2);
		int temp = num2 - num1;
		printf("%04d - %04d = %04d\n", num2, num1, temp);
		str1 = to_string(temp);
		str1.insert(0, 4 - str1.size(), '0');
	} while (str1 != "6174" && str1!="0000");

	return 0;
}