#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int *Arr = new int[num];

	for (int i = 0; i < num; ++i)
	{
		cin >> Arr[i];
	}

	int *score = new int[num];

	score[0] = Arr[0];
	score[1] = Arr[0] + Arr[1];

	bool check[300] = { false, };

	for (int i = 2; i < num; ++i)
	{
		if (i > 2 && i < num - 1)
		{
			score[i] = Arr[i] + max(Arr[i - 1] + score[i - 3], score[i - 2]);
			if (Arr[i - 1] + score[i - 3] <= score[i - 2])
			{
				check[i] = true;
			}
		}
		else if (i == num - 1)
		{
			if (!check[i - 1])
			{
				score[i] = Arr[i] + score[i - 2];
				check[i] = true;
			}
			else
			{
				score[i] = Arr[i] + max(Arr[i - 1] + score[i - 3], score[i - 2]);
				if (Arr[i - 1] + score[i - 3] <= score[i - 2])
				{
					check[i] = true;
				}
			}
		}
		else
		{
			score[i] = Arr[i] + max(Arr[i - 1], Arr[i - 2]);
			if (Arr[i - 1] <= Arr[i - 2])
			{
				check[i] = true;
			}
		}
	}

	cout << score[num-1] << endl;

	return 0;
}