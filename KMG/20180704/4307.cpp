#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int length, N;
		cin >> length >> N;
		vector<int> v(N);
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		int Sort , Long=0;
		int tmpSort = length;
		int half = length/2;
		for (int j = 0; j < N; j++) {
			if (abs(v[j] - (double)length / 2) < tmpSort) {
				tmpSort = abs(v[j] - (double)length / 2);
				Sort = min(length - v[j], v[j]);
			}
			if (max(length - v[j], v[j]) > Long)Long = max(length - v[j],v[j]);
		}
		cout << Sort << " " << Long << endl;

	}
	return 0;
}