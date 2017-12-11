/*

1003. ��Ҫͨ����(20)
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
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
YES
YES
YES
YES
NO
NO
NO
NO

*/

#include<iostream>
#include<string>
using namespace std;

bool Include_PAT(const string& s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] != 'P'&&s[i] != 'A'&&s[i] != 'T')
			return false;
		else
		{
			return true;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++){
		cin >> s;
		if (Include_PAT(s)) {
			int Alen = 0, Blen = 0, Clen = 0;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] != 'P')	Alen++;
				else break;
			}
			for (int j = 0,count=0; j < s.size(); j++) {
				if (s[j] != 'T')	count++;
				else {
					Blen = count - Alen - 1;
					Clen = s.size() - count - 1;
					break;
				}
			}

			if (Blen == 0)
				cout << "NO" << endl;
			else
			{
				if (Alen*Blen == Clen) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
		}
		else {
			cout << "NO" << endl;
		}

	}

	return 0;
}