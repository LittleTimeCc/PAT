/*

L2-012. ���ڶѵ��ж�

ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
��һϵ�и�������˳�����һ����ʼΪ�յ�С����H[]������ж�һϵ����������Ƿ�Ϊ�档��������м��֣�

��x is the root����x�Ǹ���㣻
��x and y are siblings����x��y���ֵܽ�㣻
��x is the parent of y����x��y�ĸ���㣻
��x is a child of y����x��y��һ���ӽ�㡣
�����ʽ��

ÿ����Ե�1�а���2��������N��<= 1000����M��<= 20�����ֱ��ǲ���Ԫ�صĸ������Լ���Ҫ�жϵ�����������һ�и�������[-10000, 10000]�ڵ�N��Ҫ������һ����ʼΪ�յ�С���ѵ�������֮��M�У�ÿ�и���һ�����⡣��Ŀ��֤�����еĽ���ֵ���Ǵ��ڵġ�

�����ʽ��

�������ÿ�����⣬�����Ϊ�棬����һ���������T�������������F����

����������
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
���������
F
T
F
T

*/


#include<cstdio>  
#include<map> 
#include<algorithm>

int s[1005];
int main()
{
	int n, m, a, b, f, k;
	char str[10];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		f = i / 2;
		k = i;
		while (f > 0 && s[k] < s[f])
		{
			std::swap(s[k], s[f]);
			k = f;
			f = f / 2;
		}
	}
	std::map<int, int> Map;
	for (int i = 1; i <= n; i++) {
		Map[s[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %s", &a, str);
		if (str[0] == 'a') {
			scanf("%d %s %s", &b, str, str);
			if (Map[a] / 2 == Map[b] / 2) printf("T\n");
			else printf("F\n");
		}
		else
		{
			scanf("%s %s", str, str);
			if (str[0] == 'r') {
				if (Map[a] == 1)	printf("T\n");
				else printf("F\n");
			}
			else if (str[0] == 'p') {
				scanf("%s %d", str, &b);
				if (Map[a] == Map[b] / 2)	printf("T\n");
				else printf("F\n");
			}
			else {
				scanf("%s %d", str, &b);
				if (Map[a] / 2 == Map[b])	printf("T\n");
				else printf("F\n");
			}
		}
	}

	return 0;
}