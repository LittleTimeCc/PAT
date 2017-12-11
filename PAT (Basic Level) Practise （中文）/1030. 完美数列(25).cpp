/*

1030. ��������(25)
ʱ������
300 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CAO, Peng
����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�

���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�

�����ʽ��

�����һ�и�������������N��p������N��<= 105����������������ĸ�����p��<= 109���Ǹ����Ĳ������ڶ��и���N����������ÿ����������109��

�����ʽ��

��һ�������������ѡ����ٸ����������������һ���������С�

����������
10 8
2 3 20 4 5 1 6 7 8 9
���������
8

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long BigInt;
int main()
{
	int N;
	BigInt p;
	cin >> N >> p;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	int result = 0;
	for (int i = 0; i < N; i++) {
		int pos = upper_bound(num.begin(), num.end(), num[i] * p) - num.begin();
		if (pos - 1 >= 0)	pos--;
		result = max(result, pos - i + 1);
	}
	cout << result << endl;

	return 0;
}
