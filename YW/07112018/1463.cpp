#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int *calArr = new int[num+1];
	int i;

	if (num == 1)
	{
		printf("0\n");
		goto finish;
	}
	if (num == 2 || num == 3)
	{
		printf("1\n");
		goto finish;
	}
	
	calArr[0] = 0;
	calArr[1] = 0;
	calArr[2] = 1;
	calArr[3] = 1;

	for (i = 4; i <= num; ++i)
	{
		if (i % 3 == 0 && i % 2 == 0)
		{
			calArr[i] = 1 + min(calArr[i / 3], calArr[i / 2]);
		}
		else if (i % 3 == 0 && i % 2 != 0)
		{
			calArr[i] = 1 + min(calArr[i / 3], calArr[i-1]);
		}
		else if (i % 3 != 0 && i % 2 == 0)
		{
			calArr[i] = 1 + min(calArr[i - 1], calArr[i / 2]);
		}
		else {
			calArr[i] = 1 + calArr[i - 1];
		}
	}

	std::cout << calArr[num] << endl;

finish:

	return 0;
}