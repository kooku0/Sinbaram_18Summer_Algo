#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		sort(v.begin(), v.end());
		long long sum = v[0] + v[1];
		v[0] = sum;
		v[1] = sum;
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}