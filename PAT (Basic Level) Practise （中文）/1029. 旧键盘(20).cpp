/*

1029. �ɼ���(20)
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
�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ�ʵ�ʱ���������֣������г��϶���������Щ����

�����ʽ��

������2���зֱ����Ӧ����������֡��Լ�ʵ�ʱ���������֡�ÿ�������ǲ�����80���ַ��Ĵ�������ĸA-Z��������Сд��������0-9���Լ��»��ߡ�_��������ո���ɡ���Ŀ��֤2���ַ������ǿա�

�����ʽ��

���շ���˳����һ������������ļ�������Ӣ����ĸֻ�����д��ÿ������ֻ���һ�Ρ���Ŀ��֤������1��������

����������
7_This_is_a_test
_hs_s_a_es
���������
7TI

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string str1,str2;
	vector<char> Set;
	cin >> str1 >> str2;
	int i = 0, j=0;
	if (str1.size() == str2.size())
		return 0;
	else
	{
		for (; i < str2.size(),j<str1.size(); ) 
		{
			if (str1[j] != str2[i]) 
			{
				if (find(Set.begin(), Set.end(), toupper(str1[j])) == Set.end())
				{
					Set.push_back(toupper(str1[j]));
				}
				j++;
			}
			else
			{
				i++;
				j++;
			}
		}
	 }
	
	for (auto elem : Set) {
		cout << elem;
	}
	cout << endl;
	return 0;
}