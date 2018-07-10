#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		int k=0;
		for (int j = 1; j <= i; j++) {
			int tmp;
			cin >> tmp;
			int p;
			p = max(k,v[j])+tmp;
			k = v[j];
			v[j] = p;

		}

	}
	int Max=0;
	for (int i = 1; i <= n; i++) {
		if (Max < v[i])Max = v[i];
	}
	cout << Max << endl;
	return 0;
}