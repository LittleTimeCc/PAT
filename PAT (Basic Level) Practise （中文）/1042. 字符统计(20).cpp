/*

1042. �ַ�ͳ��(20)
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
���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��

������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��

��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��

����������
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
���������
e 7

*/

#include<iostream>
#include<cctype>
#include<string>
#include<vector>
using namespace std;

int main() 
{
	vector<int> buffer(26,0);
	string str;
	getline(cin, str);
	for (char &ch : str) {
		ch = tolower(ch);
		if (ch >= 'a'&&ch <= 'z') {
			buffer[ch - 'a']++;
		}
	}
	int maxNum = buffer[0],index=0;

	for (int i = 1; i < 26; i++) {
		if (buffer[i] > maxNum) {
			maxNum = buffer[i];
			index = i;
		}
	}
	
	char ch = index + 'a';
	cout << ch << " " << maxNum << endl;
	return 0;
}
