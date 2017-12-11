/*

1014. 福尔摩斯的约会 (20)
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
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
THU 14:04

*/

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int flag = 0;
	int len1 = s1.size(), len2 = s2.size();
	for (int i = 0; i < len1&&i < len2; i++) {
		if (s1[i] >= 'A'&&s1[i] <= 'G'&&s1[i] == s2[i] && flag == 0) {
			switch (s1[i]-'A')
			{
			case 0:
				cout << "MON ";
				break;
			case 1:
				cout << "TUE ";
				break;
			case 2:
				cout << "WED ";
				break;
			case 3:
				cout << "THU ";
				break;
			case 4:
				cout << "FRI ";
				break;
			case 5:
				cout << "SAT ";
				break;
			case 6:
				cout << "SUN ";
				break;
			}
			flag++;
		}
		else if ((s1[i] >= '0'&&s1[i] <= '9'&&s1[i] == s2[i] && flag == 1)
			|| (s1[i] >= 'A'&&s1[i] <= 'N'&&s1[i] == s2[i] && flag == 1)) {
			if (s1[i] >= '0'&&s1[i] <= '9')
				printf("0%d:", s1[i] - '0');
			else if (s1[i] >= 'A'&&s1[i] <= 'N')
				printf("%d:", s1[i] - 'A' + 10);
			flag++;
		}
	}
	int len3 = s3.size(), len4 = s4.size();
	for (int j = 0; j < len3&&j < len4; j++) {
		if ((s3[j] >= 'a'&&s3[j] <= 'z'&&s3[j] == s4[j])
			|| (s3[j] >= 'A'&&s3[j] <= 'Z'&&s3[j] == s4[j])) {
			if (j < 9) {
				printf("0%d", j);
			}
			else {
				printf("%d", j);
			}
			break;
		}
	}

	return 0;
}