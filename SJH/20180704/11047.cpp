#include <iostream>
#include <vector>

using namespace std;
using uint = unsigned int;

int main(void)
{
	int count, target;
	cin >> count >> target;
	
	vector<uint> wallet(count, 0);

	for (int i = 0; i < count; ++i)
		cin >> wallet[i];

	int sum = 0;
	int order = count - 1;
	int use_count = 0;

	while (sum != target) {
		if (sum + wallet[order] > target) {
			if (order > 0)	
				--order;
		}	
		else {
			int temp = (target - sum) / wallet[order];
			sum += temp * wallet[order];	
			use_count += temp;
		}
	}

	cout << use_count << endl;

	return 0;
}
