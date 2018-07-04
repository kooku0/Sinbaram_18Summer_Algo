#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* timeArray = new int[N];

	for (int i = 0; i < N; i++)
	{
		int time;
		cin >> time;
		timeArray[i] = time;
	}
	sort(timeArray, timeArray+N);
	
	for (int j = 1; j < N; j++) 
	{
		timeArray[j] += timeArray[j-1];
	}

	int sum = 0; // 기다린 시간 합
	for (int k = 0; k < N; k++)
	{
		sum += timeArray[k];
	}
	cout << sum << endl;
	return 0;
}