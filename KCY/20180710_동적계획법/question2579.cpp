#include <iostream>

using namespace std;

int arr[301];		// 계단에 적힌 수 담는 배열 
int arr_sum[301];	// 해당 계단까지의 최대값을 담는 배열

int main() 
{
	int num_stair;
	cin >> num_stair;

	for (int i = 1; i <= num_stair; i++) {
		cin >> arr[i];
	}

	arr_sum[1] = arr[1];
	arr_sum[2] = arr[1] + arr[2];

	/*
	j>=3일 때, arr_sum[j]은 arr[j] + arr[j - 1] + arr_sum[j - 3]와 arr[j] + arr_sum[j - 2] 중에 더 큰 값이다.  
	*/
	for (int j = 3; j <= num_stair; j++) {
		if (arr[j] + arr[j - 1] + arr_sum[j - 3] <= arr[j] + arr_sum[j - 2])
			arr_sum[j] = arr[j] + arr_sum[j - 2];
		else
			arr_sum[j] = arr[j] + arr[j - 1] + arr_sum[j - 3];
		
	}
	cout << arr_sum[num_stair] << endl;
	
	
	return 0;
}