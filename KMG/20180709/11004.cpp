#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, K;

//void swap(int *a, int *b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
//int func(int begin, int end, int* arr) {
//
//	int pivot = begin;
//
//	for (int i = begin; i < end; i++) {
//		if (arr[i]<arr[pivot] && i>pivot) {
//			if (i == pivot+1) {
//				swap(arr[pivot], arr[i]);
//				pivot++;
//			}
//			else {
//				swap(arr[pivot], arr[pivot + 1]);
//				swap(arr[pivot], arr[i]);
//				pivot++;
//			}
//		}
//	}
//	if (pivot == K-1) {
//		return arr[pivot];
//	}
//	else if(pivot < K-1){
//		return func( pivot + 1, end, arr);
//		
//	}
//	else {
//		return func(0, pivot, arr);
//	}
//}
int v[5000001];

void swap(int *arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}


int myQuickSort(int *arr, int start, int end) {
	//int pivot = arr[start];
	//int left = start + 1;
	//int right = end;
	int i = start, j = end, h;
	int pivot = arr[start+end/2];
	do {
		while (arr[i] < pivot)i++;
		while (arr[j] > pivot)i--;
		if (i <= j) {
			h = arr[i];
			arr[i] = arr[j];
			arr[j] = h;
			i++;
			j--;
		}
	} while (i <= j);
	
		if (pivot == K - 1) {
			cout << arr[pivot] << endl;
			return arr[pivot];
		}
		else if(pivot > K-1) return myQuickSort(arr, start, j);  //앞 부분
		else return myQuickSort(arr, i, end);    //뒷 부분
//	}

}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	//cout << func(0,N,v);

	//myQuickSort(v,0,N-1);
	sort(v, v + N);
	cout << v[K-1] << endl;

	return 0;
}