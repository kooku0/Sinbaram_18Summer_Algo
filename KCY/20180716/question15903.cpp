#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	int m;
	cin >> m;

	long long* arr = new long long[n];		
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int j = 0; j < m; j++) {
		long long first = arr[0];
		long long second = arr[1];
		arr[0] = first + second;
		arr[1] = first + second;
		sort(arr, arr + n);
	}
	
	long long sum = 0;
	for (int k = 0; k < n; k++) {
		sum += arr[k];
	}
	cout << sum << "\n";
	return 0;
}