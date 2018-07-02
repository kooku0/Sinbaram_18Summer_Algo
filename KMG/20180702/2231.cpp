#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {

	int N;
	cin >> N;
	
	int Size = log10(N)+1;
	int kk = 9 * (Size-1);
	for (unsigned i = N - kk; i < N; i++) {
		string s = to_string(i);
		int sum = i;
		for (int j = 0; j < s.size(); j++) {
			sum = sum + s[j]-'0';
		}
		if (sum == N) {
			cout << i << endl;
			return 0;
		}

	}
	cout << 0 << endl;
	return 0;
}