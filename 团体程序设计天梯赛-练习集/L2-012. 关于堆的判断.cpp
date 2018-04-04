/*

L2-012. 关于堆的判断

时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
将一系列给定数字顺序插入一个初始为空的小顶堆H[]。随后判断一系列相关命题是否为真。命题分下列几种：

“x is the root”：x是根结点；
“x and y are siblings”：x和y是兄弟结点；
“x is the parent of y”：x是y的父结点；
“x is a child of y”：x是y的一个子结点。
输入格式：

每组测试第1行包含2个正整数N（<= 1000）和M（<= 20），分别是插入元素的个数、以及需要判断的命题数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。之后M行，每行给出一个命题。题目保证命题中的结点键值都是存在的。

输出格式：

对输入的每个命题，如果其为真，则在一行中输出“T”，否则输出“F”。

输入样例：
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
输出样例：
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