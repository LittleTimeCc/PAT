/*

1014. ����Ħ˹��Լ�� (20)
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
���������
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