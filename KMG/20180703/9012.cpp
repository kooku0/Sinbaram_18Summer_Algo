#include <iostream>
#include <string>
using namespace std;

void func(char* arr) {


}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		while (true) {
			if (s.find("()") != string::npos) {
				int p = s.find("()");
				s.erase(p,2);
			}
			else if(s.size()==0){
				cout << "YES" << endl;
				break;
			}
			else {
				cout << "NO" << endl;
				break;
			}
		}
	}
	return 0;
}