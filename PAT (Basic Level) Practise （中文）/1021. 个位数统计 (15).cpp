/*

1021. ��λ��ͳ�� (15)

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
����һ��kλ����N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)�����д����ͳ��ÿ�ֲ�ͬ�ĸ�λ���ֳ��ֵĴ��������磺����N = 100311������2��0��3��1����1��3��

�����ʽ��

ÿ���������1��������������һ��������1000λ��������N��

�����ʽ��

��N��ÿһ�ֲ�ͬ�ĸ�λ���֣���D:M�ĸ�ʽ��һ���������λ����D������N�г��ֵĴ���M��Ҫ��D�����������

����������
100311
���������
0:2
1:3
3:1

*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string input;
	map<char, int> Map;

	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		Map[input[i]]++;
	}
	for (map<char, int>::iterator it = Map.begin(); it != Map.end();it++) {
		cout << (it->first)-'0' << ":" << it->second << endl;
	}
	return 0;
}