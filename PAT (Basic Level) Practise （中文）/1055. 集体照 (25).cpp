/*

1055. ������ (25)
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
�ļ�����ʱ���κ���Ҫ������Ը�����N����K�ŵĶ�������Ŷӹ������£�

ÿ������ΪN/K������ȡ���������������ȫ��վ�����һ�ţ�
���������˵ĸ��Ӷ�����ǰ���κ��˰���
ÿ���������վ�м䣨�м�λ��Ϊm/2+1������mΪ������������������ȡ������
ÿ�����������м���Ϊ�ᣬ����߷��������Һ��������վ���м��˵����ࣨ����5�����Ϊ190��188��186��175��170�������Ϊ175��188��190��186��170�������������������ߣ��������������м��˵��ұߣ���
�����������ͬ�������ֵ��ֵ����������С����ﱣ֤��������
�ָ���һ�������ˣ����д����������ǵĶ��Ρ�

�����ʽ��

ÿ���������1������������ÿ������������1�и�������������N��<=10000������������K��<=10���������������N�У�ÿ�и���һ���˵����֣��������ո񡢳��Ȳ�����8��Ӣ����ĸ������ߣ�[30, 300]�����ڵ���������

�����ʽ��

������յĶ��Ρ���K������������Կո�ָ�����ĩ�����ж���ո�ע�⣺��������������ߣ����ŵ���������Ϸ���ǰ��������·���

����������
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
���������
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Info {
	string name;
	int high;
	
	bool operator<(const Info& I) {
		if (this->high == I.high)
			return this->name > I.name;
		else
			return this->high < I.high;
	}

	friend istream& operator>>(istream& in, Info& I) {
		in >> I.name >> I.high;
		return in;
	}

};



int main() {
	int N, K;
	cin >> N >> K;
	if (K > N)	K = 1;
	int nums = N / K;
	vector<Info> v(N);
	Info t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		v[i] = t;
	}
	sort(v.begin(), v.end());
	
	string result;
	for (int i = 0; i < K; i++) {
		int l = i*nums, h = (i + 1)*nums;
		if (h + nums > N) h = N;
		string line = v[h - 1].name;
		for (int j = h - 2; j >= l; j--) {
			if (j % 2 == h % 2)
				line = v[j].name + " " + line;
			else
				line = line + " " + v[j].name;
		}
		result = line + "\n" + result;
	}
	cout << result;

	return 0;
}	