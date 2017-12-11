/*

1048. ���ּ���(20)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��

������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��

��һ����������ܺ�Ľ����

����������
1234567 368782971
���������
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

