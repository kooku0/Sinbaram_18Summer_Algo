#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push"){
			int input;
			cin >> input;
			s.push(input);
		}
		if (str == "top") {
			if (s.size() == 0)cout << "-1" << endl;
			else cout << s.top() << endl;
		}
		if (str == "size") {
			cout << s.size() << endl;
		}
		if (str == "empty") {
			cout << s.empty() << endl;
		}
		if (str == "pop") {
			if (s.empty())cout << "-1" << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}

		
	}

	return 0;
}