
/*
1008. ����Ԫ��ѭ���������� (20)

ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard

һ������A�д���N��N>0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M��M>=0����λ�ã�����A�е������ɣ�A0 A1����AN-1���任Ϊ��AN-M ���� AN-1 A0 A1����AN-M-1�������M����ѭ��������ǰ���M��λ�ã��������Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����

�����ʽ��ÿ���������һ��������������1������N ( 1<=N<=100)��M��M>=0������2������N��������֮���ÿո�ָ���

�����ʽ����һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�

����������
6 2
1 2 3 4 5 6
���������
5 6 1 2 3 4

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int N, M,num;
	cin >> N >> M;
	vector<int> nums;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		nums.push_back(num);
	}

	if (M != N&&M != 0) {
		if (M > N)	M = M - N;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + M);
		reverse(nums.begin() + M, nums.end());
	}

	cout << nums[0];
	for (int i = 1; i < nums.size(); i++) {
		cout << " " << nums[i];
	}

	cout << endl;

	return 0;
}
