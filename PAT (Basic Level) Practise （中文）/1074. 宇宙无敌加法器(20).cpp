/*

1074. 宇宙无敌加法器(20)
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
地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在PAT星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。每个PAT星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是7进制数、第2位是2进制数、第3位是5进制数、第4位是10进制数，等等。每一位的进制d或者是0（表示十进制）、或者是[2，9]区间内的整数。理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT星人通常只需要记住前20位就够用了，以后各位默认为10进制。

在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203+415”呢？我们得首先计算最低位：3+5=8；因为最低位是7进制的，所以我们得到1和1个进位。第2位是：0+1+1（进位）=2；因为此位是2进制的，所以我们得到0和1个进位。第3位是：2+4+1（进位）=7；因为此位是5进制的，所以我们得到2和1个进位。第4位是：6+1（进位）=7；因为此位是10进制的，所以我们就得到7。最后我们得到：6203+415=7201。

输入格式：

输入首先在第一行给出一个N位的进制表（0 < N <=20），以回车结束。 随后两行，每行给出一个不超过N位的正的PAT数。

输出格式：

在一行中输出两个PAT数之和。

输入样例：
30527
06203
415
输出样例：
7201

*/

#include<iostream>
#include<string>

using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	size_t len1 = s2.size(), len2 = s3.size();
	len1 > len2 ? (s3.insert(0, len1 - len2, '0')) : (s2.insert(0, len2 - len1, '0'));
	int temp = s1.length() - 1, carry = 0;
	string result = "";

	for (int i = s2.length() - 1; i >= 0; i--) {
		int sum = (s2[i] - '0') + (s3[i] - '0') + carry;
		int r = s1[temp] - '0';
		temp--;
		if (r == 0) { r = 10; }
		carry = sum / r;
		result = char(sum%r + '0') + result;
	}

	while (carry!=0&&temp>=0)//有进位并且有进制
	{
		int sum = carry;
		int r = s1[temp] - '0';
		temp--;
		if (r == 0) { r = 10; }
		carry = sum / r;
		result = char(sum%r + '0') + result;
	}
	if (carry != 0)//有进位但没有进制
	{
		result = char(carry + '0') + result;
	}

	bool flag = false;
	for (size_t i = 0; i < result.length(); i++) {
		if (flag == true) {
			cout << result[i];
			continue;
		}
		if (result[i] != '0') {
			if (flag == false) {
				flag = true;
			}
			cout << result[i];
		}
	}
	if (flag == false)	cout << 0;
	return 0;
}