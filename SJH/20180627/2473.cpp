#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int totalNum = 0;
	int liquids[5000] = { 0, };

	cin >> totalNum;

	for (int i = 0; i < totalNum; ++i)
		cin >> liquids[i];

	sort(liquids, liquids + totalNum);
	//-100 -99 -98 -97 -94
	int negative_idx = totalNum  -1;
	int positive_idx = totalNum - 1;

	for (int i = 0; i < totalNum; ++i)
		if (liquids[i] >= 0) {
			negative_idx = i - 1;
			positive_idx = i;
			break;
		}

	long long globalMin, localMin;

	globalMin = numeric_limits<long long>::max();

	int rl, rr, rm;

	if (positive_idx == 0) {
		rl = 0;
		rm = 1;
		rr = 2;
	}
	else if (negative_idx == totalNum - 1) {
		rl = totalNum - 3;
		rm = totalNum - 2;
		rr = totalNum - 1;
	}
	else {
		int left = 0, right = totalNum - 1, middle;
		long long sum;

		while (right - left > 1) {
			localMin = numeric_limits<long long>::max();

			sum = static_cast<long long>(liquids[left] + liquids[right]);
			
			for (int i = left + 1; i < right; ++i) {
				if (localMin > abs(sum + liquids[i])) {
					localMin = abs(sum + liquids[i]);
					middle = i;
				}
			}

			if (globalMin > localMin) {
				globalMin = localMin;
				rl = left;
				rr = right;
				rm = middle;
			}

			if (abs(liquids[right] + liquids[middle] + liquids[left + 1]) > abs(liquids[right - 1] + liquids[middle] + liquids[left]))
				--right;
			else
				++left;
		}
	}


	cout << liquids[rl] << ' ' << liquids[rm] << ' ' << liquids[rr] << endl;

	return 0;
}