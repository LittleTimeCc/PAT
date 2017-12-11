/*

1015. 德才论 (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Li
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info {
	int id, l, r;

	Info() = default;
	friend bool operator<(const Info& lhs, const Info& rhs) {
		if (lhs.l + lhs.r != rhs.l + rhs.r)
			return lhs.l + lhs.r > rhs.l + rhs.r;
		else if (lhs.l != rhs.l)
			return lhs.l > rhs.l;
		else
			return lhs.id < rhs.id;
	}

};


int main() {
	int N, low, high,count=0;
	cin >> N >> low >> high;
	vector<Info> v1, v2, v3,v4;
	Info t;
	for (int i = 0; i < N; i++) {
		cin >> t.id >> t.l >> t.r;
		if (t.l >= low&&t.r >= low) {
			count++;
			if (t.l >= high&&t.r >= high)
				v1.push_back(t);
			else if (t.l >= high)
				v2.push_back(t);
			else if (t.l >= t.r)
				v3.push_back(t);
			else
				v4.push_back(t);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	sort(v4.begin(), v4.end());
	cout << count << endl;
	for (auto it = v1.begin(); it != v1.end(); it++)
		cout << it->id<<" "<<it->l<<" "<<it->r << endl;
	for (auto it = v2.begin(); it != v2.end(); it++)
		cout << it->id << " " << it->l << " " << it->r << endl;
	for (auto it = v3.begin(); it != v3.end(); it++)
		cout << it->id << " " << it->l << " " << it->r << endl;
	for (auto it = v4.begin(); it != v4.end(); it++)
		cout << it->id << " " << it->l << " " << it->r << endl;

	return 0;
}