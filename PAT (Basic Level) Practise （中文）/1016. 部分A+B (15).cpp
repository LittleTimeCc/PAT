/*

1016. ����A+B (15)

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
������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��

������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��

��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0

*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

	int A, DA, B, DB, PA=0, PB=0, countA = 0,countB=0;
	cin >> A >> DA >> B >> DB;
	string strA = to_string(A);
	string strB = to_string(B);
	for (int i = 0; i < strA.size(); i++) {
		if (strA[i] - '0' == DA) {
			countA++;
		}
	}

	for (int j = 0; j < strB.size(); j++) {
		if (strB[j] - '0' == DB) {
			countB++;
		}
	}

	for (int k =0; k < countA; k++){
		PA += DA * static_cast<int>(pow(10, k));
	}

	for (int x = 0; x < countB; x++) {
		PB += DB * static_cast<int>(pow(10,x));
	}

	cout << PA + PB << endl;
	return 0;
}