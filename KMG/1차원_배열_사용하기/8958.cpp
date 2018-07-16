#include <iostream>
#include <string>
#include <vector>
using namespace std;

int func(string s) {
	int sum = 0;
	int prevPoint;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			if (s[i] == 'X')prevPoint = 0;
			else prevPoint = 1;
			sum += prevPoint;
			continue;
		}
		if (s[i] == 'X')prevPoint = 0;
		else prevPoint++;
		sum += prevPoint;
	}
	return sum;
}

int main() {
	int testCase;
	cin >> testCase;
	string s;
	for (int i = 1; i <= testCase; i++) {
		cin >> s;
		cout << func(s) <<endl;
	}
	return 0;
}