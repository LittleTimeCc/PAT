/*

1048. 数字加密(20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118

*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

char trans[4] = { 'J','Q','K' ,'\0'};
int main() {
	string s1, s2,result;
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	int count = 1;
	while (len2 < len1) {
		s2 = "0" + s2;
		len2++;
	}
	for (; count <= len1;count++) {
		if (count & 0x1) {
			int temp = (s1[len1-count] - '0' + s2[len2 - count] - '0') % 13;
			switch (temp)
			{
			case 10:s2[len2 - count] = 'J';
				break;
			case 11:s2[len2 - count] = 'Q';
				break;
			case 12:s2[len2 - count] = 'K';
				break;
			default:s2[len2 - count] = temp + '0';
			}
		}
		else {
			int temp = s2[len2 - count] - s1[len1 - count];
			temp = temp < 0 ? temp + 10 : temp;
			s2[len2 - count] = temp + '0';				
		}
	}

	cout << s2;
	return 0;
}

