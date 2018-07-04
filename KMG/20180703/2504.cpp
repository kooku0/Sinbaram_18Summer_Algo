#include <iostream>
#include <string>
using namespace std;

string s;
int index = 0;
int func1();
int func2();

int main() {
	string t;
	cin >> s;
	t = s;
	while (true) {
		if (t.find("()") != string::npos) {
			t.erase(t.find("()"), 2);
			
		}
		else if (t.find("[]") != string::npos) {
			t.erase(t.find("[]"), 2);
		}
		else if (t.size() == 0) {
			break;
		}
		else {
			cout << "0" << endl;
			return 0;
		}
	}

	int sum = 0;
	while (index < s.size()) {

		if (s[index] == '(') sum += func1();
		else sum+=func2();
	}
	cout << sum << endl;

	return 0;
}

int func1() {
	index++;
	int sum = 0;
	while (true) {
		if (s[index] == ')') {
			index++;
			if (sum != 0)return 2 * sum;
			else return 2;
		}
		else {
			if (s[index] == '(') {
				sum += func1();
				
			}
			else {
				sum += func2();
			}
		}
	}
}
int func2() {
	index++;
	int sum = 0;
	while (true) {
		if (s[index] == ']') {
			index++;
			if (sum != 0)return 3 * sum;
			else return 3;
		}
		else {
			if (s[index] == '(') {
				sum += func1();
			}
			else {
				sum += func2();
			}
		}
	}
}