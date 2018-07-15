#include <iostream>

using namespace std;

int main()
{
	int numA;
	int numB;
	int numC;

	cin >> numA >> numB >> numC;

	int numRecord[10] = { 0, };

	int multi = numA * numB*numC;

	int m;

	for (int i = 0; multi > 10; ++i)
	{
		m = multi % 10;
		numRecord[m]++;
		multi = multi / 10;
	}
	numRecord[multi]++;

	for (int i = 0; i < 10; ++i)
	{
		cout << numRecord[i] << endl;
	}

	return 0;
}