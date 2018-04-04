/*

L2-022. 重排链表

时间限制
500 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
给定一个单链表 L1→L2→...→Ln-1→Ln，请编写程序将链表重新排列为 Ln→L1→Ln-1→L2→...。例如：给定L为1→2→3→4→5→6，则输出应该为6→1→5→2→4→3。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址和结点总个数，即正整数N (<= 105)。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址；Data是该结点保存的数据，为不超过105的正整数；Next是下一结点的地址。题目保证给出的链表上至少有两个结点。

输出格式：

对每个测试用例，顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1

*/

#include<cstdio>

const size_t maxn = 100001;
struct Node{
	int data, next;
}node[maxn];
int a[maxn], b[maxn];

int main() {
	int begin, n, addr, data, next;;
	scanf("%d %d", &begin, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &addr, &data, &next);
		node[addr].data = data;
		node[addr].next = next;
	}
	int cnt = 0;
	while (begin != -1) {
		a[cnt++] = begin;
		begin = node[begin].next;
	}
	int cntt = 0, l = 0, r = cnt - 1;
	while (l <= r) {
		if (l == r) {
			b[cntt++] = a[r--];
		}
		else {
			b[cntt++] = a[r--];
			b[cntt++] = a[l++];
		}
	}
	for (int i = 0; i < cnt - 1; i++) {
		printf("%05d %d %05d\n", b[i], node[b[i]].data, b[i + 1]);
	}
	printf("%05d %d -1\n", b[cnt - 1], node[b[cnt - 1]].data);

	return 0;
}