/*

1075. ����Ԫ�ط���(25)
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
����һ�����������д��������Ԫ�ؽ��з������У�ʹ�����и�ֵԪ�ض����ڷǸ�ֵԪ�ص�ǰ�棬��[0, K]�����ڵ�Ԫ�ض����ڴ���K��Ԫ��ǰ�档��ÿһ���ڲ�Ԫ�ص�˳���ǲ��ܸı�ġ����磺��������Ϊ 18��7��-4��0��5��-6��10��11��-2��KΪ10�������Ӧ��Ϊ -4��-6��-2��7��0��5��10��18��11��

�����ʽ��

ÿ���������1������������ÿ������������1�и�������1�����ĵ�ַ������ܸ�������������N (<= 105)���Լ�������K (<=1000)�����ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣������ݣ�Ϊ[-105, 105]�����ڵ�������Next����һ���ĵ�ַ����Ŀ��֤����������Ϊ�ա�

�����ʽ��

��ÿ�������������������ͷ��β��˳��������ź�Ľ����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
���������
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdio>
#include<algorithm>
#include<iterator>
#include<utility>

using namespace std;

int main() {
	unordered_map<int, pair<int, int>> LinkList;
	vector<pair<int, int>> negative, less_eq_k, greater_k, result;
	int begin, n, k, addr, data, next;
	cin >> begin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> addr >> data >> next;
		LinkList[addr] = make_pair(data, next);
	}

	int ptr = begin;
	while (ptr != -1) {
		int data = LinkList[ptr].first;
		int next = LinkList[ptr].second;
		auto New_Node = make_pair(ptr, data);
		if (data < 0)	negative.push_back(New_Node);
		else if (data <= k)	less_eq_k.push_back(New_Node);
		else greater_k.push_back(New_Node);
		ptr = next;
	}

	copy(negative.begin(), negative.end(), back_inserter(result));
	copy(less_eq_k.begin(), less_eq_k.end(), back_inserter(result));
	copy(greater_k.begin(), greater_k.end(), back_inserter(result));
	int index = result.size()-1;
	for (int i = 0; i < index; i++) {
		printf("%05d %d %05d\n", result[i].first, result[i].second, result[i + 1].first);
	}
	printf("%05d %d -1\n", result[index].first, result[index].second);

	return 0;
}