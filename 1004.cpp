#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct point {
	int x, y;
};
struct circle {
	int x, y, r;
};

bool check(point p,circle c) {
	//cout << pow(c.x - p.x, 2) << " " << pow(c.y - p.y, 2) << " " << pow(c.r, 2) << endl;
	if (pow(c.x - p.x, 2) + pow(c.y - p.y, 2) < pow(c.r, 2))return true;
	else return false;
}
int main() {

	int testCaseNum;
	cin >> testCaseNum;
	point SP,DP;
	int *result = new int[testCaseNum];
	
	for (int i = 0; i < testCaseNum; i++) {
		cin >> SP.x >> SP.y >> DP.x >> DP.y;
		int Num;
		cin >> Num;

		int start_in=0, dest_in=0, dup_in=0;
		for (int j = 0; j < Num; j++) {
			circle c;
			cin >> c.x >> c.y >> c.r;
			bool check1 = check(SP, c);
			bool check2 = check(DP, c);
			if (check1)start_in++;
			if (check2)dest_in++;
			if (check1 && check2) {
				start_in--;
				dest_in--;
			};
		}
		result[i]=start_in + dest_in;
	}

	for (int i = 0; i < testCaseNum; i++) {
		cout << result[i]<<endl;
	}

	return 0;
}