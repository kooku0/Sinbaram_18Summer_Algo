#include <iostream>
using namespace std;

int main() {
	
	int prev;
	cin >> prev;
	int countP = 0, countM = 0;
	for (int i = 1; i < 8; i++) {
		int tmp;
		cin >> tmp;
		if (tmp < prev) countM++;
		else countP++;
		prev = tmp;
	}
	if (countP == 7) cout << "ascending" << endl;
	else if (countM == 7) cout << "descending" << endl;
	else cout << "mixed" << endl;
	return 0;
}