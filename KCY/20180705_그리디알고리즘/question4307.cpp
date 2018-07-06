#include <iostream>

using namespace std;

int main()
{
	int Test;
	cin >> Test;
	int* max_arrSmall = new int[Test];
	int* max_arrBig = new int[Test];

	for (int k = 0; k < Test; k++)
	{
		int l;
		cin >> l;
		int n;
		cin >> n;
		int* arr = new int[n]; // 개미들의 각자 위치를 담은 배열
		int* arrSmall = new int[n]; // 개미들의 각자 위치에서 양 끝과의 거리 2개값 중 더 작은 값
		int* arrBig = new int[n]; // 개미들의 각자 위치에서 양 끝과의 거리 2개값 중 더 큰 값
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] > l - arr[i])
			{
				arrSmall[i] = l - arr[i];
				arrBig[i] = arr[i];
			}
			else
			{
				arrSmall[i] = arr[i];
				arrBig[i] = l - arr[i];
			}
		}
		max_arrBig[k] = arrBig[0]; // 
		max_arrSmall[k] = arrSmall[0];
		for (int a = 1; a<n; a++)
		{
			if (max_arrBig[k] < arrBig[a])
			{
				max_arrBig[k] = arrBig[a];
			}
			
			else if (max_arrSmall[k] < arrSmall[a])
			{
				max_arrSmall[k] = arrSmall[a];
			}


		}

		// 오름차순으로 생각
		// 가장 빠른 경우 : 각 개미별로 제 위치에서 양 끝과의 거리값 중 작은값들 3개중에서 가장 큰 값
		// 가장 늦은 경우 : 각 개미별로 제 위치에서 양 끝과의 거리값 중 큰값들 3개중에서 가장 큰 값
		
	}	
	for (int b = 0; b < Test; b++)
	{
		cout << max_arrSmall[b] << " " << max_arrBig[b] << "\n";
	}
	
	return 0;
}