/*

1043. ���PATest(20)
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
����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ�����Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��ֱ�������ַ����������

�����ʽ��

������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��

��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
redlesPayBestPATTopTeePHPereatitAPPT
���������
PATestPATestPTetPTePePee

*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int P=0, A=0, T=0,e=0, s=0, t=0;
	for (auto ch : str) {
		if (ch == 'P')	P++;
		if (ch == 'A')	A++;
		if (ch == 'T')	T++;
		if (ch == 'e')	e++;
		if (ch == 's')	s++;
		if (ch == 't')	t++;
	}
	for (;;) {
		if (P != 0) { cout << "P"; P--; }
		if (A != 0) { cout << "A"; A--; }
		if (T != 0) { cout << "T"; T--; }
		if (e != 0) { cout << "e"; e--; }
		if (s != 0) { cout << "s"; s--; }
		if (t != 0) { cout << "t"; t--; }
		if (P == 0 && A == 0 && T == 0 && e == 0 && s == 0 && t == 0) break;

	}

	
	cout << endl;
	return 0;
}