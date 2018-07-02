#include <iostream>
#include <string>

using namespace std;

int main() {

	int N;
	cin >> N;
	
	int count = 0;
	for (int a = 1; a <= N; a++) {
		string s = to_string(a);

		if (s.size() == 1 || s.size() == 2) {
			count++;
			continue;
		}
		int invert = s[1] - s[0];
		int i;
		for (i = 2; i < s.size(); i++) {
			if((s[i] - s[i - 1]) != invert)break;
		}
		if (i == s.size()) {
			count++;
		}
		
	}
	cout << count << endl;

	return 0;
}