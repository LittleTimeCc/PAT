/*

1040. �м���PAT��25��
ʱ������
120 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CAO, Peng
�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P),��4λ(A),��6λ(T)���ڶ���PAT�ǵ�3λ(P),��4λ(A),��6λ(T)��

�ָ����ַ�������һ�������γɶ��ٸ�PAT��

�����ʽ��

����ֻ��һ�У�����һ���ַ��������Ȳ�����105��ֻ����P��A��T������ĸ��

�����ʽ��

��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����

����������
APPAPT
���������
2

*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int A = 0,P = 0,T = 0,Min=0;
	T = count(s.begin(), s.end(), 'T');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P')	P++;
		if (s[i] == 'T')	T--;
		if (s[i] == 'A')	Min=(Min+(P*T)% 1000000007) % 1000000007;
	}
	cout << Min;
	return 0;
}