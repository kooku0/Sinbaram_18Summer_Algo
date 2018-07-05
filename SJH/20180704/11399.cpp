#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main(void)
{
	int num;
	cin >> num;

	vector<int> times(num, 0);
	for (int i = 0; i < num; ++i)
		cin >> times[i];

	sort(times.begin(), times.end());

	int sum = 0;
	
	for (int i = 0; i < num; ++i) 
		sum += times[i] * (num - i);
	
	cout << sum << endl;

	return 0;
}
