#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(),v.end(),greater<int>());
	int Max = 0;
	
	for (int i = 0; i < N; i++) {
		if (Max <= v[i] * (i + 1))Max = v[i] * (i + 1);
	}
	cout << Max << endl;

	return 0;
}