#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int K;
	cin >> K;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	int count = 0; 
	
	for (int j = N - 1; j >= 0;)
	{
		
		if (arr[j] <= K) {
			K = K - arr[j];
			count++;
			if (K == 0) break;
		}
		else j--;		
			

	}

	cout << count << endl;

	return 0;
}