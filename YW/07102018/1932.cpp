#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int Maxrecord = INT32_MIN;

/*
void recursive(int *arr, int currentdepth, int num, int index, int sum)
{
	sum = sum + arr[index];
	if (currentdepth == num)
	{
		Maxrecord = max(Maxrecord, sum);
		return;
	}
	else 
	{
		recursive(arr, currentdepth + 1, num, currentdepth+index, sum);
		recursive(arr, currentdepth + 1, num, currentdepth + index+1, sum);
	}
}
*/

int main()
{
	int num;
	cin >> num;
	int size = num * (num + 1) / 2;
	int *numArr = new int[size];

	int depth = 1;
	int j = 0;
	for (int i = 0; i < size; ++i)
	{
		cin >> numArr[i];
		if (depth > 1)
		{

			if (i == (depth - 1)*(depth) / 2)
			{
				numArr[i] = numArr[i] + numArr[i - depth + 1];
			}
			else if (i == (depth - 1)*(depth) / 2 + depth - 1)
			{
				numArr[i] = numArr[i] + numArr[i - depth];
			}
			else 
			{
				numArr[i] = numArr[i] + max(numArr[i - depth], numArr[i - depth + 1]);
			}
		}
		if (depth == num)
		{
			Maxrecord = max(Maxrecord, numArr[i]);
		}
		j++;
		if (j == depth)
		{
			j = 0;
			depth++;
		}
	}
	depth--;

	cout << Maxrecord << endl;

	return 0;
}