/*

1033. �ɼ��̴���(20)
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
�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������

�����ʽ��

������2���зֱ������������Щ�����Լ�Ӧ����������֡����ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����105���ַ��Ĵ������õ��ַ�������ĸ[a-z, A-Z]������0-9���Լ��»��ߡ�_��������ո񣩡���,������.������-������+���������ϵ���������Ŀ��֤��2����������ִ��ǿա�

ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������

�����ʽ��

��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�

����������
7+IE.
7_This_is_a_test.
���������
_hs_s_a_tst

*/

#include<iostream>
#include<string>
#include<set>
#include<cctype>

using namespace std;

int main() {
	string str1,str2;
	set<char> Set;
	getline(cin, str1);
	getline(cin, str2);
	if (str1.empty()) {
		cout << str2;
		return 0;
	}
	for (int i = 0; i < str1.size(); i++) {	
			Set.insert(str1[i]);	
	}
	for (int j = 0; j < str2.size(); j++) {
		if (!Set.count(str2[j])) {
			if (isupper(str2[j]) && Set.count('+'))
				continue;
			else if (islower(str2[j]) && Set.count(toupper(str2[j])))
				continue;
			else
				cout << str2[j];
		}
	}
	cout << endl;
	return 0;
}