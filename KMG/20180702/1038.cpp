#include <iostream>
#include <string>
#include <limits.h>
#include <math.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int num = 1;
	if (N > 1022) {
		cout << "-1" << endl;
		return 0;
	}
	if (N == 1022) {
		cout << "9876543210" << endl;
		return 0;
	}
	if (N == 0) {
		cout << 0 << endl;
		return 0;
	}
	int count = 0;
	while (true) {
		
		if (count == N) {
			cout << num << endl;
			return 0;
		}
		int flag = 1;

		string s = to_string(num);
		if (s.size() == 1) {
			count++;
		}
		else {
			int i;
			for (i = 1; i < s.size(); i++) {
				if (s[i] - s[i - 1] >= 0) {
					
					int sizeP = s.size() - i;
					int t = pow(10, sizeP);
					num -= (num % t);
					num += t;
					flag = 0;
					
					break;
				}
			}
			if (i == s.size()) {
				count++;
				
			}

		}
		if (count == N) {
			cout << num << endl;
			return 0;
		}
		
		if(flag==1)num++;
	}
	return 0;
}