#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int* arrA = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arrA[i];
	}
	sort(arrA, arrA + N);

	int max = 0;
	for (int j = 0; j < N; j++) {
		arrA[j]*=(N-j);
		if (arrA[j] > max)
			max = arrA[j];
	}
	
	cout << max << endl;
	// 배열의 원소값들 중에 최대원소 찾기
		

	return 0;
}