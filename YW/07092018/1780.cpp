#include <iostream>

using namespace std;

bool checkOne(int **Arr, int x, int y, int size);
bool checkZero(int **Arr, int x, int y,int size);
bool checkOneNegetive(int **Arr, int x,int y, int size);

void check(int **Arr, int x, int y, int size);

int countZero = 0;
int countOneNegetive = 0;
int countOne = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int size;
	cin >> size;

	int **Arr = new int*[size];
	for (int i = 0; i < size; ++i)
	{
		Arr[i] = new int[size];
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cin >> Arr[i][j];
		}
	}

	check(Arr, 0, 0, size);

	cout << countOneNegetive << endl << countZero << endl << countOne << endl;


	return 0;
}

bool checkOne(int **Arr, int x, int y, int size)
{
	bool check = true;
	if (size == 1)
	{
		if (Arr[x][y] == 1)
		{
			return check;
		}
		else {
			return false;
		}
	}
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (Arr[i][j] != 1)
			{
				check = false;
				break;
			}
		}
	}
	return check;
}

bool checkZero(int **Arr, int x, int y, int size)
{

	bool check = true;
	if (size == 1)
	{
		if (Arr[x][y] == 0)
		{
			return check;
		}
		else {
			return false;
		}
	}
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (Arr[i][j] != 0)
			{
				check = false;
				break;
			}
		}
	}
	return check;
}
bool checkOneNegetive(int **Arr, int x, int y, int size)
{
	bool check = true;
	if (size == 1)
	{
		if (Arr[x][y] == -1)
		{
			return check;
		}
		else {
			return false;
		}
	}
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (Arr[i][j] != -1)
			{
				check = false;
				break;
			}
		}
	}
	return check;
}


void check(int **Arr, int x, int y, int size)
{
	if (checkOneNegetive(Arr, x, y, size))
	{
		countOneNegetive++;
		return;
	}
	if (checkZero(Arr, x, y, size))
	{
		countZero++;
		return;
	}
	if (checkOne(Arr, x, y, size))
	{
		countOne++;
		return;
	}

	size = size / 3;

	for (int i = x; i < x+3*size; i += size)
	{
		for (int j = y; j < y+3 * size; j += size)
		{
			check(Arr, i, j, size);
		}
	}
}