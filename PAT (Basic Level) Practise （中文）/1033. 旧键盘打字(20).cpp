/*

1033. 旧键盘打字(20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst

*/

#include<iostream>
#include<string>
#include<set>
#include<cctype>

using namespace std;

int main() {
	string str1,str2;
	set<char> Set;
	getline(cin, str1);
	getline(cin, str2);
	if (str1.empty()) {
		cout << str2;
		return 0;
	}
	for (int i = 0; i < str1.size(); i++) {	
			Set.insert(str1[i]);	
	}
	for (int j = 0; j < str2.size(); j++) {
		if (!Set.count(str2[j])) {
			if (isupper(str2[j]) && Set.count('+'))
				continue;
			else if (islower(str2[j]) && Set.count(toupper(str2[j])))
				continue;
			else
				cout << str2[j];
		}
	}
	cout << endl;
	return 0;
}