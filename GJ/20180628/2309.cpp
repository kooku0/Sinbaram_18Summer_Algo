#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	int arr[9];
	int S1 = 0;
	for(int i = 0; i < 9; i++){
		cin >> arr[i];
		S1 += arr[i];
	}
	sort(arr + 0, arr + 9);
	int T = S1 - 100;
	int left = 0, right = 8;
	while(left < right){
		int temp = arr[left] + arr[right];
		if(temp > T) right--;
		else if(temp < T) left++;
		else break;
	}
	for(int i = 0; i < 9; i++){
		if(i == left || i == right) continue;
		cout << arr[i] << endl;
	}

	return 0;
}
