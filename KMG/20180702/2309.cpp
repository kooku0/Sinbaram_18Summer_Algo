#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);

	for (int i = 0; i < 8; i++) {

		for (int j = i+1; j < 9; j++) {
			int sum = 0;
			for (int z = 0; z < 9; z++) {
				if (z != i && z != j) {
					sum += arr[z];
				}
			}
			if (sum == 100) {
				for (int p = 0; p < 9; p++) {
					if (p != i && p != j) {
						cout << arr[p]<<endl;
					}
				}
			}
		}
	}
	return 0;
}