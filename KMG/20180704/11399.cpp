#include <iostream>

using namespace std;

int main() {
	int PeapleNum;
	cin >> PeapleNum;
	int *Time = new int[PeapleNum];

	for (int i = 0; i < PeapleNum; i++) {
		int EachPersonTime;
		cin >> EachPersonTime;
		Time[i] = EachPersonTime;
	}
	int a = PeapleNum;

	for (int k = 0; k < PeapleNum; k++) {
		for (int i = 1; i < a; i++) {
			if (Time[i] < Time[i - 1]) {
				int tum = 0;
				tum = Time[i];
				Time[i] = Time[i - 1];
				Time[i - 1] = tum;

			}
			else;

		}
		a--;
	}
	int* sum = new int[PeapleNum];
	for (int i = 0; i < PeapleNum; i++) {
		int _sum = 0;
		for (int p = 0; p <= i; p++) {
			_sum += Time[p];
		}
		sum[i] = _sum;
	}
	int fsum = 0;
	for (int p = 0; p <PeapleNum; p++) {
		fsum += sum[p];
	}

	cout << fsum;
	return 0;
}