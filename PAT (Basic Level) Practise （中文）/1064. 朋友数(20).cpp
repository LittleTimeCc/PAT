/*

1064. ������(20)
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
�������������λ���ֵĺ���һ���ģ��򱻳�Ϊ�ǡ��������������Ǹ������ĺ;������ǵġ�����֤�š�������123��51��������������Ϊ1+2+3 = 5+1 = 6����6�������ǵ�����֤�š�����һЩ������Ҫ����ͳ��һ���������ж��ٸ���ͬ������֤�š�ע�⣺����Ĭ��һ�������Լ����Լ������ѡ�

�����ʽ��

�����һ�и���������N�����һ�и���N�������������ּ��Կո�ָ�����Ŀ��֤��������С��104��

�����ʽ��

���ȵ�һ��������������в�ͬ������֤�ŵĸ��������һ�а�����˳�������Щ����֤�ţ����ּ��һ���ո�����ĩ�����ж���ո�

����������
8
123 899 51 998 27 33 36 12
���������
4
3 6 9 26

*/

#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int sum_Help(int num)
{
	int sum = 0;
	string str = to_string(num);
	for (auto n : str) {
		sum += (n - '0');
	}
	return sum;
}

int main() {
	int N,count=0;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	set<int> result;
	result.insert(sum_Help(v[0]));
	count++;
	for (int i = 1; i < v.size(); i++) {
		if (result.count(sum_Help(v[i]))==0) {
			result.insert(sum_Help(v[i]));
			count++;
		}
	}
	cout << count << endl;
	for (auto it = result.begin(); it != result.end(); it++){
		if (it != result.begin())	cout << " ";
		cout << *it;
	}
	return 0;
}