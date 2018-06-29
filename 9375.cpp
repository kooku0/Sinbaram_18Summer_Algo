#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> result;
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int dress_num;
		cin >> dress_num;
		vector<string> string_v;
		vector<int> int_v;
		
		for (int j = 0; j < dress_num; j++) {
			int check = 0;
			string s1, s2;
			cin >> s1 >> s2;
			for (int z = 0; z < string_v.size(); z++) {
				if (string_v[z] == s2) {
					int_v[z]++;
					check = 1;
					break;
				}
			}
			if (check == 0) {
				string_v.push_back(s2);
				int_v.push_back(1);
			}
		
		}
		int mul = 1;
		for (int z = 0; z < int_v.size(); z++) {
			mul = mul * (int_v[z] + 1);
		}
		result.push_back(mul-1);
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}




	return 0;
}