
/*

1017. A����B (20)

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
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������

�����ʽ��

������1�������θ���A��B���м���1�ո�ָ���

�����ʽ��

��1�����������Q��R���м���1�ո�ָ���

����������
123456789050987654321 7
���������
17636684150141093474 3

*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string divided,result;
	int divider, r;
	cin >> divided >> divider;
	int first = divided[0] - '0';
	if (first >= divider) {
		result.push_back(first / divider + '0');
	}
	
	for (int i = 1; i < divided.size(); i++) {
		r = first % divider;
		first = r * 10 + (divided[i] - '0');
		result.push_back(first / divider + '0');
	}
	r = first% divider;
	
	
	if (divided.size() == 1 && ((result[0] - '0') < divider)) {
		cout << "0" << " " << divided[0] - '0' << endl;
	}
	else{
		cout << result << " " << r << endl;
	}


	return 0;
}