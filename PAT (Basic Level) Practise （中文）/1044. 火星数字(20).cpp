/*

1044. ��������(20)
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
����������13���Ƽ����ģ�

 �����˵�0�������˳�Ϊtret��
 ����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
 �����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
 ��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��

�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�

�����ʽ��

��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�

����������
4
29
5
elo nov
tam
���������
hel mar
may
115
13

*/

#include<iostream>
#include<string>
using namespace std;

typedef void(*FuncStr)(const string&);
const string a[] = { "","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const string b[] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void Fun1_Str(const string& s) {
	unsigned int Len = s.size();
	int index;
	if (Len == 1)	index = s[0] - '0';
	else if (Len == 2)	index = (s[0] - '0') * 10 + (s[1] - '0');
	else index = (s[0] - '0') * 100 + (s[1] - '0')*10+(s[2]-'0');

	if (index <= 12)	cout << a[index] << endl;
	else if (index % 13 == 0) cout << b[index / 13] << endl;
	else cout << b[index / 13] << " " << a[index % 13] << endl;
}

void Fun2_Str(const string& s) {
	unsigned int Len = s.size();
	if (Len == 3) {
		for (int i = 1; i <= 12; i++) {
			if (s[0] == a[i][0] && s[1] == a[i][1] && s[2] == a[i][2]) {
				cout << i << endl;
			}
			else if (s[0] == b[i][0] && s[1] == b[i][1] && s[2] == b[i][2]) {
				cout << 13 * i << endl;
			}
		}
	}
	else {
		int high = 0, low = 0;
		for (int j = 1; j <= 12; j++) {
			if (s[0] == b[j][0] && s[1] == b[j][1] && s[2] == b[j][2]) {
				high = j;
			}
			if (s[4] == a[j][0] && s[5] == a[j][1] && s[6] == a[j][2]) {
				low = j;
			}
		}
		cout << high * 13 + low << endl;
	}
}

int main(){
	int N;
	cin >> N;
	getchar();
	FuncStr NumToChar = Fun1_Str, CharToNum = Fun2_Str;
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		if (s.size() == 1 && s[0] == '0')
			cout << "tret" << endl;
		else {
			if (s[0]  >= '0'&&s[0] <= '9') {
				NumToChar(s);
			}
			else {
				CharToNum(s);
			}
		}

	}
	return 0;
}