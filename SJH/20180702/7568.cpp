#include <iostream>
#include <vector>

using namespace std;

	
int main(void)
{
	int num_people;

	
	cin >> num_people;
	vector<short> weights(num_people, 0);
	vector<short> heights(num_people, 0);

	for (int i = 0; i < num_people; ++i)
		cin >> weights[i] >> heights[i];

	vector<short> win_num(num_people, 0);

	for (int i = 0; i < num_people; ++i) {
		for (int j = 0; j < num_people; ++j) {
			if (weights[i] < weights[j] && heights[i] < heights[j])
				++win_num[i];
		}
		cout << win_num[i] + 1 << ' ';
	}

	cout << endl;

	return 0;
}