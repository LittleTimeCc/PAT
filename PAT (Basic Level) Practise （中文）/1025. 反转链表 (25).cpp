/*

1025. ��ת���� (25)
ʱ������
300 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)���Լ�������K(<=N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
���������
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
�ύ����

*/

#include<utility>
#include<iostream>
#include<vector>
#include<map>
#include<cstdio>

using namespace std;
struct Node {
	int address, data, next;
}tmp;

pair<int, int> node[100000];
vector<Node> VList;



int main() {
	int start, n, k, prev, data, nxt;
	cin >> start >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> prev >> data >> nxt;
		node[prev].first = data;
		node[prev].second = nxt;
	}
	int cur_node = start;
	while (cur_node != -1) {
		tmp.address = cur_node;
		tmp.data = node[cur_node].first;
		tmp.next = node[cur_node].second;
		cur_node = tmp.next;
		VList.push_back(tmp);
	}
	int num = VList.size() / k;
	for (int i = 0; i < num; i++) 
	{
		for (int j = (i + 1)*k - 1; j >= i*k; j--)
		{
			printf("%05d %d ", VList[j].address, VList[j].data);
			if (j == i*k)
			{
				if (i < num - 1)
				{
					printf("%05d", VList[(i + 2)*k - 1].address);
				}
				else
				{
					if ((i + 1)*k < VList.size())
					{
						printf("%05d", VList[(i + 1)*k].address);
					}
					else
					{
						printf("-1");
					}
				}
			}
			else
			{
				printf("%05d",VList[j - 1].address);
			}
			printf("\n");
			
		}
	}
	if(VList.size() % k != 0) {
		num = VList.size() % k;
		for (int i = VList.size() - num; i < VList.size(); i++) {
			printf("%05d %d ", VList[i].address, VList[i].data);
			if (i == VList.size() - 1)	printf("-1\n");
			else printf("%05d\n", VList[i + 1].address);
		}
	}

	return 0;
}


