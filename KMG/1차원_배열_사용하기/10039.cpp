#include <iostream>

using namespace std;

int main() {

	int sum = 0;
	for (int i = 1; i <= 5; i++) {
		int tmp;
		cin >> tmp;
		if (tmp < 40) sum += 40;
		else sum += tmp;
	}
	cout << sum / 5 << endl;
	return 0;
}