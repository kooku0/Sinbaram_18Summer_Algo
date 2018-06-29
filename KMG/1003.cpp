#include <iostream>
#include <vector>
using namespace std;



int main() {
	int size;
	cin >> size;
	int arr[40][2];
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	int currMax = 2;
	vector<int> v;
	for (int i = 0; i < size; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (currMax<tmp) {
			for (int j = currMax; j <= tmp; j++) {
				arr[j][0] = arr[j - 1][0] + arr[j - 2][0];
				arr[j][1] = arr[j - 1][1] + arr[j - 2][1];
			}
			currMax = tmp;
			
		}

	}
	for (int i = 0; i < size; i++) {
		cout << arr[v[i]][0] << " "<<arr[v[i]][1] << endl;
	}

	return 0;
}