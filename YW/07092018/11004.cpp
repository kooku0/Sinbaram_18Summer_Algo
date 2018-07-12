#include <iostream>

using namespace std;

void findK(int k, int *Arr, int left, int right);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num, knum;
	cin >> num >> knum;
	
	knum--;

	int *Arr = new int[num];
	for (int i = 0; i < num;++i)
	{
		cin >> Arr[i];
	}
	
	findK(knum, Arr, 0, num-1);

	cout << Arr[knum] << endl;

	return 0;
}

void findK(int k, int *Arr, int left, int right)
{
	int pivot = Arr[left];
	int pivotIndex;
	int l = left;
	int r = right;

	while (left < right)
	{
		while (pivot <= Arr[right] && left < right)
		{
			right--;
		}
		if (left != right)
		{
			Arr[left] = Arr[right];
		}
		while (pivot >= Arr[left] && left < right)
		{
			left++;
		}
		if (left != right)
		{
			Arr[right] = Arr[left];
			right--;
		}
	}

	Arr[left] = pivot;
	pivotIndex = left;
	left = l;
	right = r;

	if (pivotIndex < k)
	{
		findK(k, Arr, pivotIndex + 1, right);
	}
	else if (pivotIndex > k)
	{
		findK(k, Arr, left, pivotIndex - 1);
	}

	return;
}