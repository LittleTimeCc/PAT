
/*

1058. ѡ����(20)
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
���Ķ�ѡ���ǱȽ��鷳�����飬���������д�����������ʦ���Ķ�ѡ�⣬����ָ���ĵ���������ࡣ

�����ʽ��

�����ڵ�һ�и�������������N��<=1000����M��<=100�����ֱ���ѧ�������Ͷ�ѡ��ĸ��������M�У�ÿ��˳�θ���һ���������ֵ��������5������������ѡ�������������2�Ҳ�����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ���ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ������N�У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)��������Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������

�����ʽ��

���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�ע������ʱֻ��ѡ��ȫ����ȷ���ܵõ�����ķ��������һ��������������Ŀ�Ĵ�������ͱ�ţ���Ŀ���������˳���1��ʼ��ţ�������в��У��򰴱�ŵ���˳����������ּ��ÿո�ָ�������β�����ж���ո����������Ŀ��û���˴��������һ�������Too simple����

����������
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
���������
3
6
5
2 2 3 4

*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int main() {
	int n, m, temp, k;
	cin >> n >> m;
	vector<set<char>> right(m);	//��Ŀ��ѡ��
	vector<int> total(m), wrongCount(m);	//��Ŀ���ܷ֣��������ļ�¼
	for (int i = 0; i < m; i++) {
		cin >> total[i] >> temp >> k;
		for (int j = 0; j < k; j++) {
			char ch;
			scanf(" %c", &ch);
			right[i].insert(ch);
		}
	}
	for(int i=0;i<n;i++){
		int score = 0;
		scanf("\n");
		for(int j=0;j<m;j++){
			if (j != 0)	scanf(" ");
			scanf("(%d", &k);
			set<char> st;
			char ch;
			for(int l=0;l<k;l++)
			{
				scanf(" %c", &ch);
				st.insert(ch);
			}
			scanf(")");
			if(st==right[j])
			{
				score += total[j];
			}else
			{
				wrongCount[j]++;
			}
		}
		printf("%d\n", score);
	}
	int maxWrongCnt = 0;
	for(int i=0;i<m;i++)
	{
		if(wrongCount[i]>maxWrongCnt)
		{
			maxWrongCnt = wrongCount[i];
		}
	}
	if (maxWrongCnt == 0)
		printf("Too simple");
	else
	{
		printf("%d", maxWrongCnt);
		for(int i=0;i<m;i++)
		{
			if(wrongCount[i]==maxWrongCnt)
			{
				printf(" %d", i + 1);
			}
		}
	}
	return 0;
}