/*

1025. 反转链表 (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
提交代码

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


