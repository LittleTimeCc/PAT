/*
1004. �ɼ����� (20)

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


����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
�����ʽ��ÿ�������������1��������������ʽΪ

��1�У�������n
��2�У���1��ѧ�������� ѧ�� �ɼ�
��3�У���2��ѧ�������� ѧ�� �ɼ�
... ... ...
��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Stu {
	string name;
	string num;
	int score;

	friend istream& operator >> (istream& is, Stu& obj) {
		is >> obj.name >> obj.num >> obj.score;
		return is;
	}
};

int main()
{
	vector<Stu> inputs;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Stu temp;
		cin >> temp;
		inputs.push_back(temp);
	}

	sort(inputs.begin(), inputs.end(), [](const Stu& lhs, const Stu& rhs) {return lhs.score > rhs.score; });
	cout << inputs.front().name << " " << inputs.front().num << endl;
	cout << inputs.back().name << " " << inputs.back().num << endl;

	return 0;
}