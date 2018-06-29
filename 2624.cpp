#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int _count = 0;
int memoization[1001][10001];
int DP(int cash, int arr[][2], int num) {
	if (arr[num][0] == 0)return 0;
	for (int i = 0; i <= arr[num][1]; i++) {
		int tmp = cash - arr[num][0] * i;
		if (tmp < 0) return memoization[num][cash];
		if (tmp > 0) {
			if (memoization[num+1][tmp] != 0) {
				memoization[num][cash] += memoization[num+1][tmp];
			}
			else { memoization[num][cash] += DP(tmp, arr, num + 1); }
		}
		if (tmp == 0) {
			memoization[num][cash]++;
			return memoization[num][cash];
		}
	}
	
	return memoization[num][cash];
}


int main() {

	int cash, num;
	scanf("%d", &cash);
	scanf("%d", &num);
	int arr[1001][2];

	for (int i = 0; i < num; i++) {
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	printf("%d\n", DP(cash, arr, 0));

	

	return 0;
}