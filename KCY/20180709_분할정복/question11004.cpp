#include <iostream>
#include <algorithm>

using namespace std;
int arr[10000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int K;
	cin >> K;

	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cout << arr[K - 1] << endl;

	return 0;
}

/*
// ³»°¡ Â§°Å
#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(&data[j], &data[i]);
			}
		}
	}
	swap(&data[left], &data[j]);
	pivot = j;

	quickSort(left, pivot - 1, data);
	quickSort(pivot + 1, right, data);
}

int main()
{
	int N;
	cin >> N;
	int K;
	cin >> K;
	
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	quickSort(0, sizeof(arr), arr);
	for (int v = 0; v < N; v++) {
		cout << arr[v] << " ";
	}
	cout << endl;
	return 0;
}

*/