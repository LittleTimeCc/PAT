/*

L2-022. ��������

ʱ������
500 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
����һ�������� L1��L2��...��Ln-1��Ln�����д����������������Ϊ Ln��L1��Ln-1��L2��...�����磺����LΪ1��2��3��4��5��6�������Ӧ��Ϊ6��1��5��2��4��3��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ�ͽ���ܸ�������������N (<= 105)�����ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣������ݣ�Ϊ������105����������Next����һ���ĵ�ַ����Ŀ��֤������������������������㡣

�����ʽ��

��ÿ������������˳��������ź�Ľ����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
���������
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