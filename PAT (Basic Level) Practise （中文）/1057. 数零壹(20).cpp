/*

1057. ����Ҽ(20)
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����һ�����Ȳ�����105���ַ���������Ҫ���㽫��������Ӣ����ĸ����ţ���ĸa-z��Ӧ���1-26�����ִ�Сд����ӣ��õ�����N��Ȼ���ٷ���һ��N�Ķ����Ʊ�ʾ���ж���0������1����������ַ�����PAT (Basic)��������ĸ���֮��Ϊ��16+1+20+2+1+19+9+3=71����71�Ķ�������1000111������3��0��4��1��

�����ʽ��

������һ���и������Ȳ�����105���Իس��������ַ�����

�����ʽ��

��һ�����Ⱥ����0�ĸ�����1�ĸ���������Կո�ָ���

����������
PAT (Basic)
���������
3 4

*/

#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> toBinary(unsigned int num) {
	vector<int> ret;
	while (num)
	{
		ret.push_back(num % 2);
		num /= 2;
	}
	return ret;
}

int main() {
	string str;
	getline(cin, str);
	int sum = 0;
	for (char& ch : str) {
		ch = tolower(ch);
	}
	for (char ch : str) {
		if (ch >= 'a' && ch <= 'z') {
			sum += ch - 'a' + 1;
		}
	}
	vector<int> v = toBinary(sum);
	int count0 = count(v.cbegin(), v.cend(), 0);
	int count1 = count(v.cbegin(), v.cend(), 1);

	cout << count0 << " " << count1 << endl;
	return 0;
}