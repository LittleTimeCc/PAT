
/*

1076. Wifi���� (15)
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
������΢����������һ����Ƭ������λ�װ���ͬѧ�ǣ����ڴ����ʱ��Ҫʹ��wifi�����µ������ǵ�ѧϰ���ֽ�wifi��������Ϊ������ѧ��𰸣�A-1��B-2��C-3��D-4����ͬѧ���Լ�����ÿ����һ����лл��������~������ ��ʦ��Ϊ�˴ٽ�ѧ��ѧϰҲ��ƴ�ˡ��� �����Ҫ����д�����һϵ����Ŀ�Ĵ𰸰��վ����ϸ����Ķ�Ӧ��ϵ�����wifi�����롣����򵥼���ÿ��ѡ���ⶼ��4��ѡ�����ֻ��1����ȷ�𰸡�

�����ʽ��

�����һ�и���һ��������N��<= 100�������N�У�ÿ�а��ա����-�𰸡��ĸ�ʽ����һ�����4��ѡ���T����ʾ��ȷѡ���F����ʾ����ѡ�ѡ����ÿո�ָ���

�����ʽ��

��һ�������wifi���롣

����������
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
���������
13224143

*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream> 

using namespace  std;

int main()
{
	int n;
	cin >> n;
	string str,s;
	map<string, int> Map{ {"A-T",1},{ "B-T",2 },{ "C-T",3 },{ "D-T",4 } };
	vector<int> v;
	for(int i=0;i<n+1;i++){
		getline(cin, s);
		stringstream ss(s);
		while(ss>>str)
		{
			if (Map[str])
				v.push_back(Map[str]);
		}
	}
	for (auto it : v) { cout << it; }
	return 0;
}