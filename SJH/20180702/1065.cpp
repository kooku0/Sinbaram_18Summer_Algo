#include <iostream>

using namespace std;

int main(void)
{
	int upper_bound;
	cin >> upper_bound;

	int count;
	int sum = 0, sum_2 = 0;

	if (upper_bound < 100)
		count = upper_bound;
	else {
		count = 99;

		for (int diff = 0; diff < 5; ++diff) 
			for (int num = 0; num < 10; ++num) {
				sum = num + (num + diff) * 10 + (num + 2 * diff) * 100;
				sum_2 = num + (num - diff) * 10 + (num - 2 * diff) * 100;

				if (sum <= upper_bound) 
					++count;
				if (sum != sum_2 && sum_2 <= upper_bound && sum_2 >= 100)
					++count;
			}

		--count;
	}

	cout << count << endl;

	return 0;
}