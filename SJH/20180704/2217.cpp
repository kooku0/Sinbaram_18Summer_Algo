#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int rope_count;
	cin >> rope_count;

	vector<int> ropes(rope_count, 0);

	for (int i = 0; i < rope_count; ++i)
		cin >> ropes[i];

	sort(ropes.begin(), ropes.end());

	int max_weights = 0, temp_weights = 0;

	for (int i = 0; i < rope_count; ++i) {
		temp_weights = ropes[rope_count - i - 1] * (i + 1);

		if (max_weights < temp_weights)
			max_weights = temp_weights;
	}

	cout << max_weights << endl;

	return 0;
}
