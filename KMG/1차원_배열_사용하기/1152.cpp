#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char cstr[1000000];

	cin.getline(cstr, 1000000);
	int count = 0;
	char* token = strtok(cstr, " ");
	while (token) {
		count++;
		token = strtok(NULL, " ");
	}

	cout << count << endl;
	return 0;
}