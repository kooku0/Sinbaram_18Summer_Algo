#include <iostream>

using namespace std;

int checkingOver(int *arr, int left, int right);
int quickChecking(int *arr, int left, int right);

int targetIdx;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int totalSize;
	cin >> totalSize >> targetIdx;
	--targetIdx;

    int *sequence = new int[totalSize];
	for (int i = 0; i < totalSize; ++i)
		cin >> sequence[i];

	quickChecking(sequence, 0, totalSize);

	cout << sequence[targetIdx] << endl;

	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int sortWithPivot(int *arr, int left, int right)
{
	int pivot = arr[right - 1];

	int i = left, j = right - 2;

	if (i <= j)
	{
		while (i <= j)
		{
			if (arr[i] > pivot && arr[j] < pivot)
				swap(&arr[i++], &arr[j--]);
            		else {
                		if (arr[i] <= pivot)
				    	++i;
                		if (arr[j] >= pivot)
                    			--j;
            	}
			}			
		swap(&arr[i], &arr[right - 1]);
	}

	return i;
}

int quickChecking(int *arr, int left, int right)
{
	int pivotIdx = sortWithPivot(arr, left, right);

	if (pivotIdx == targetIdx)
		return pivotIdx;
	else
	{
        	if (pivotIdx < targetIdx)
        	{
        	    int rightPivotIdx = quickChecking(arr, pivotIdx + 1, right);
        	    if (rightPivotIdx == targetIdx)
        	        return rightPivotIdx;
        	}
        	else
        	{
        	    int leftPivotIdx = quickChecking(arr, left, pivotIdx);
        	    if (leftPivotIdx == targetIdx)
        	        return leftPivotIdx;
        	}

		return -1;
	}
}
