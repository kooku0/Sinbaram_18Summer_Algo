#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int result = 0;
	for (int i = 0; i < num; ++i)
	{
		int k = i;
		int sum = k;
		while (k > 0)
		{
			int modulo = k % 10;
			sum += modulo;
			k = k / 10;
		}
		if (sum == num)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;

	return 0;
}