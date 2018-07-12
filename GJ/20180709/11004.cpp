#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int K;
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
		if(low > K) return;
        quickSort(arr, low, pi - 1);
		if(pi + 1 > K) return;
        quickSort(arr, pi + 1, high);
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N >> K;
	int A[N];
	for(int i = 0; i < N; i++)
		cin >> A[i];
	quickSort(A, 0, N - 1);
	cout << A[K - 1] << endl;
}
