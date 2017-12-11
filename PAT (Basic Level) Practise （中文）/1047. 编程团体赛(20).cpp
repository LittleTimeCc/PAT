/*

1047. ���������(20)
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
����������Ĺ���Ϊ��ÿ�������������ɶ�Ա��ɣ����ж�Ա���������������ӵĳɼ�Ϊ���ж�Ա�ĳɼ��ͣ��ɼ���ߵĶӻ�ʤ��

�ָ������ж�Ա�ı����ɼ��������д�����ҳ��ھ��ӡ�

�����ʽ��

�����һ�и���һ��������N��<=10000���������в�����Ա���������N�У�ÿ�и���һλ��Ա�ĳɼ�����ʽΪ����������-��Ա��� �ɼ��������С������š�Ϊ1��1000��������������Ա��š�Ϊ1��10�������������ɼ���Ϊ0��100��������

�����ʽ��

��һ��������ھ��ӵı�ź��ܳɼ��������һ���ո�ָ���ע�⣺��Ŀ��֤�ھ�����Ψһ�ġ�

����������
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
���������
11 176

*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef const pair<int, int> U;
int n[10000] = { 0 };
int main(){
	vector<int> v;
	vector<pair<int, int>> Pairs;
	int N, a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d-%d%d", &a, &b, &c);
		v.push_back(a);
		n[a] += c;
	}
	
	for (int i = 0; i < v.size(); i++) {
		Pairs.push_back(make_pair(v[i],n[v[i]]));
	}
	sort(Pairs.begin(), Pairs.end(), [](const U& lhs, const U& rhs) {return lhs.second > rhs.second; });
	printf("%d %d\n", Pairs.front().first, Pairs.front().second);
	return 0;
}