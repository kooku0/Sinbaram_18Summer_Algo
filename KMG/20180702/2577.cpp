#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int mul = A*B*C;
	string s = to_string(mul);
	vector<int> result(10,0);
	for (int i = 0; i < s.size(); i++) {
		result[s[i]-'0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << result[i] << endl;
	}
	return 0;
}