/*

1020. �±� (25)
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ������г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г���������������һ�и���N��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��

��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��

����������
3 20
18 15 10
75 72 45
���������
94.50

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;
typedef const pair<double, double> DoubleP;
int main(){
	int N,need;
	double sum=0;
	cin >> N >> need;
	vector<double> stores(N), total_Sales(N), unit_Sales(N);
	vector<pair<double, double>> Pairs;
	for (int i = 0; i < N; i++) {
		cin >> stores[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> total_Sales[i];
	}
	for (int i = 0; i < N; i++) {
		unit_Sales[i] = total_Sales[i] / stores[i];
	}
	for (int i = 0; i < N; i++) {
		Pairs.push_back({ unit_Sales[i],total_Sales[i] });
	}
	sort(Pairs.begin(), Pairs.end(), [](DoubleP& lhs, DoubleP& rhs) {return lhs.first > rhs.first; });
	for (auto elem : Pairs) {
		if (elem.second / elem.first < need) {
			sum += elem.second;
			need -= elem.second / elem.first;
		}
		else {
			sum += elem.first*need;
			break;
		}
	}
	cout << fixed << setprecision(2) << sum << endl;
	return 0;
}