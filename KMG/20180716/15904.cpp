#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string s;
	getline(cin, s);
	string find = "UCPC";

	int now = 0;
	for (int i = 0; i < s.size(); i++) {
		if (find[now] == s[i]) now++;


	}

	if (now==4) cout << "I love UCPC" << endl;
	else cout << "I hate UCPC" << endl;
	return 0;
}