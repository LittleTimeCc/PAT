
/*

1080. MOOC���ճɼ� (25)
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
�������й���ѧMOOC��http://www.icourse163.org/��ѧϰ�����ݽṹ���γ̵�ѧ������Ҫ���һ�źϸ�֤�飬�������Ȼ�ò�����200�ֵ����߱����ҵ�֣�Ȼ��������ò�����60�֣�����100���������ɼ��ļ��㹫ʽΪ G = (G����x 40% + G��ĩx 60%)����� G���� > G��ĩ���������� G ���� G��ĩ������ G���� �� G��ĩ �ֱ�Ϊѧ�������к���ĩ�ɼ���

���ڵ������ǣ�ÿ�ο��Զ�����һ�Ŷ����ĳɼ���������������д���򣬰Ѳ�ͬ�ĳɼ�����Ϊһ�š�

�����ʽ��

�����ڵ�һ�и���3���������ֱ��� P���������߱����ҵ��ѧ��������M���μ������п��Ե�ѧ��������N���μ�����ĩ���Ե�ѧ��������ÿ������������10000��

���������������롣��һ����� P �����߱�̳ɼ� G��̣��ڶ������ M �����п��Գɼ� G���У���������� N ����ĩ���Գɼ� G��ĩ��ÿ���ɼ�ռһ�У���ʽΪ��ѧ��ѧ�� ����������ѧ��ѧ��Ϊ������20���ַ���Ӣ����ĸ�����֣������ǷǸ�����������ܷ����Ϊ900�֣����к���ĩ����߷�Ϊ100�֣���

�����ʽ��

��ӡ����úϸ�֤���ѧ��������ÿ��ѧ��ռһ�У���ʽΪ��

ѧ��ѧ�� G��� G���� G��ĩ G

����еĳɼ������ڣ�����ĳ��û�μ����п��ԣ���������Ӧ��λ�������-1�������˳��Ϊ���������������������뾫ȷ���������ݼ������в��У���ѧ�ŵ�������Ŀ��֤ѧ��û���ظ��������ٴ���1���ϸ��ѧ����

����������
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
���������
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84

*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Info
{
	string name;
	int gb,g1, g2, g;
	Info(const string n="",int a=-1,int b=-1,int c=-1,int d=0):name(n),gb(a),g1(b),g2(c),g(d){}

	bool operator<(const Info& A)const
	{
		return this->g == A.g ? A.name > this->name : A.g < this->g;
	}
	friend ostream& operator<<(ostream& os,const Info& I)
	{
		os << I.name << " " << I.gb << " " << I.g1 << " " << I.g2 << " " << I.g << endl;
		return os;
	}
};

int main() {
	int p, m, n;
	string str;
	map<string, Info> Map;
	vector<Info> v;
	int score;
	cin >> p >> m >> n;
	for(int i=0;i<p;i++)
	{
		cin >> str >> score;
		if(score>=200)
		{
			Map[str] = Info(str, score, -1, -1, 0);
		}
	}
	for(int i=0;i<m;i++)
	{
		cin >> str >> score;
		if(Map.count(str))
		{
			Map[str].g1 = score;
		}
		else
		{
			continue;
		}
	}

	for(int i=0;i<n;i++)
	{
		cin >> str >> score;
		if(Map.count(str))
		{
			Map[str].g2 = score;
			if(Map[str].g1>Map[str].g2)
			{
				Map[str].g = (Map[str].g1*0.4 + Map[str].g2*0.6 + 0.5);
			}
			else
			{
				Map[str].g = score;
			}
			if(Map[str].g>=60)
			{
				v.push_back(Map[str]);
			}
		}
		else
		{
			continue;
		}
	}
	sort(v.begin(), v.end());
	for(const auto& elem:v)
	{
		cout << elem;
	}
	return 0;
}