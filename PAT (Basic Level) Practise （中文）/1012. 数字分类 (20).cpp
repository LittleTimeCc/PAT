/*

1012. ���ַ��� (20)

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
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���

�����ʽ��

�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N����

��������1��
13 1 2 3 4 5 6 7 8 9 10 20 16 18
�������1��
30 11 2 9.7 9
��������2��
8 1 2 4 5 6 7 9 16
�������2��
N 11 2 N 9

*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int A1=0, A2=0, A3=0, A5=0;
	float A4=0.0f;
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
	int N,float_Count=0,max_Num=0;
	cin >> N;
	vector<int> inputs, buffer;;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		inputs.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		if (inputs[i] % 10 == 0) {
			A1 += inputs[i];
			flag1 = true;
		}

		else if (inputs[i] % 5 == 1) {
			buffer.push_back(inputs[i]);
			flag2 = true;
		}
		else if (inputs[i] % 5 == 2) {
			A3++;
			flag3 = true;
		}
		else if (inputs[i] % 5 == 3) {
			A4 = A4 + inputs[i];
			float_Count++;
			flag4 = true;
		}
		else if (inputs[i] % 5 == 4) {
			if (inputs[i] > A5) {
				A5 = inputs[i];
				flag5 = true;
			}
		}
	}

	for (int i = 0; i < buffer.size(); i++) {
		if (i==0||i%2==0) {
			A2 = A2+buffer[i];
		}
		else {
			A2 =A2- buffer[i];
		}
	}

	A4 = A4 / float_Count;

	if (flag1 == false) {
		cout << "N" << " ";
	}
	else
		cout << A1 << " ";

	if (flag2 == false) {
		cout << "N" << " ";
	}
	else
		cout << A2 << " ";

	if (flag3 == false) {
		cout << "N" << " ";
	}
	else
		cout << A3 <<" ";

	if (flag4 == false) {
		cout << "N"<<" ";
	}
	else
		printf("%.1f ", A4);

	if (flag5 == false) {
		cout << "N";
	}
	else
		cout << A5 ;

	return 0;
}