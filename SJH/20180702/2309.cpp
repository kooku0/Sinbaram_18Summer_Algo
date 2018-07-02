#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int height[9];
	int sum = 0;

	for (int i = 0; i < 9; ++i) {
		cin >> height[i];
		sum += height[i];
	}


	sort(height, height + 9);

	for (int i = 0; i < 8; ++i)
		for (int j = i + 1; j < 9; ++j) {
			if (sum - height[i] - height[j] == 100) {
				for (int k = 0; k < 9; ++k)
					if (k != i && k != j)
						cout << height[k] << endl;
			}
		}
	
	return 0;
}