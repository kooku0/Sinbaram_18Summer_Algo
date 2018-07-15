#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;



int main() {
	int Size;
	cin >> Size;
	int arr[301];
	memset(arr,0,sizeof(int)*301);
	int memo[301];
	memset(memo, 0, sizeof(int) * 301);
	for (int i = 1; i <= Size; i++) {
		cin >> arr[i];
	}
	memo[1] = arr[1];
	memo[2] = arr[1] + arr[2];
	memo[3] = max(arr[2] + arr[3],arr[1]+arr[3]);

	if (memo[Size] == 0) {
		for (int i = 4; i <= Size; i++) {
			memo[i] = max(memo[i - 3] + arr[i-1] + arr[i], memo[i - 2] + arr[i]);
		}
	}
	cout << memo[Size] << endl;

	return 0;
}