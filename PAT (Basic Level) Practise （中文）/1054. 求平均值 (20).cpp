/*

1054. ��ƽ��ֵ (20)
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
����Ļ���Ҫ��ǳ��򵥣�����N��ʵ�����������ǵ�ƽ��ֵ�������ӵ�����Щ�������ݿ����ǷǷ��ġ�һ�����Ϸ�����������[-1000��1000]�����ڵ�ʵ����������ྫȷ��С�����2λ���������ƽ��ֵ��ʱ�򣬲��ܰ���Щ�Ƿ������������ڡ�

�����ʽ��

�����һ�и���������N��<=100�������һ�и���N��ʵ�������ּ���һ���ո�ָ���

�����ʽ��

��ÿ���Ƿ����룬��һ���������ERROR: X is not a legal number��������X�����롣�����һ��������������The average of K numbers is Y��������K�ǺϷ�����ĸ�����Y�����ǵ�ƽ��ֵ����ȷ��С�����2λ�����ƽ��ֵ�޷����㣬���á�Undefined���滻Y�����KΪ1���������The average of 1 number is Y����

��������1��
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
�������1��
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
��������2��
2
aaa -9999
�������2��
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

*/

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main() {
	int n, count = 0;
	double t, sum = 0.0;
	cin >> n;
	char s[1000], ss[1000];

	for (int i = 0; i < n; i++) {
		bool flag = false;
		scanf("%s", s);
		sscanf(s, "%lf", &t);
		sprintf(ss, "%.2lf", t);

		for (int j = 0; j < strlen(s); j++) {
			if (s[j] != ss[j])	flag = true;
		}
		if (flag || t < -1000 || t>1000) {
			printf("ERROR: %s is not a legal number\n", s);
			continue;
		}
		else {
			sum += t;
			count++;
		}
	}
	if (count == 1) {
		printf("The average of 1 number is %.2lf", sum);
	}
	else if (count>1) {
		printf("The average of %d numbers is %.2lf", count,sum/count);
	}
	else {
		printf("The average of 0 numbers is Undefined");
	}
	
	return 0;
}