#include <iostream>
#include <vector>

using namespace std;

int _min=99999999;
int tmpmin=0;
int DP(int input) {
	if (tmpmin > _min) {
		tmpmin--;
		return 0;
	}
	if (input == 1) {
		if (_min > tmpmin) {
			_min = tmpmin;
			tmpmin--;
		}
		else tmpmin--;
		return 1;
	}
	
	if (input % 3 == 0) {
		tmpmin++;
		DP(input / 3);
	}
	if (input % 2 == 0) {
		tmpmin++;
		DP(input / 2);
	}
	tmpmin++;
	DP(input - 1);
	tmpmin--;
	return 0;
}


int main() {

	int input;
	cin >> input;

	if (input == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (input == 2) {
		cout << 1 << endl;
		return 0;
	}

	DP(input);
	cout << _min << endl;
	return 0;	
}