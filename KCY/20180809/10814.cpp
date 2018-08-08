#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct std_inf {
	int age;
	string name;
};

struct std_inf arr[100000];

int main() {
	int N;
	ios::sync_with_stdio(false);
	cin >> N;

	int AGE;
	string NAME;
	for (int i = 0; i < N; i++) {
		cin >> AGE >> NAME;
		arr[i].age = AGE;
		arr[i].name = NAME;
	}
	sort(arr, arr + N);
	for (int j = 0; j < N; j++) {
		cout << (int) arr[j].age << arr[j].name << "\n";
	}

	return 0;
}