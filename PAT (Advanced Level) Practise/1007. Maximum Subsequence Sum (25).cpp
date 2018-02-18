/*

1007. Maximum Subsequence Sum (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

*/

#include<cstdio>
#include<vector>

int* get_Max(std::vector<int>& v) {
	int *result = new int[3]{ -1 };
	auto size = v.size();
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = i; j < size; j++) {
			sum += v[j];
			if (sum > result[0]) {
				result[0] = sum;
				result[1] = v[i];
				result[2] = v[j];
			}
		}
	}
	return result;
}
int main() {
	int n, m;
	std::vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		v.push_back(m);
	}
	int* result = get_Max(v);
	if (result[0] < 0) {
		printf("0 %d %d\n", v.front(), v.back());
		return 0;
	}
	printf("%d %d %d\n", result[0], result[1], result[2]);
	delete []result;

	return 0;
}