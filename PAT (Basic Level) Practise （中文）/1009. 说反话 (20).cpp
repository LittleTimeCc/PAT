/*
1009. ˵���� (20)

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
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�

�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�

����������
Hello World Here I Come
���������
Come I Here World Hello

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

int main()
{
	string str,temp,result="";
	getline(cin, str);
	reverse(str.begin(), str.end());
	stringstream ss(str);
	while (ss >>temp) {
		reverse(temp.begin(), temp.end());
		result += (temp+" ");
	}
	result=result.substr(0,result.size() - 1);
	cout <<result;
	return 0;
}