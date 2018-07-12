#include <iostream>
#include <vector>

using namespace std;

int N;
int count0 = 0, count1 = 0, count2 = 0;
vector<vector<int>> v;


void divide(int x1,int x2,int y1,int y2) {
	int check0 = 0, check1 = 0, check2 = 0;
	bool flag = true;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			
			if (v[i][j] == 0) {
				
				if (check1 != 0 || check2 != 0) {
					flag = false;
					break;
				}
				check0++;
			}
			else if(v[i][j] == 1) {
				check1++;
				if (check0 != 0 || check2 != 0) {
					flag = false;
					break;
				}
			}
			else {
				check2++;
				if (check1 != 0 || check0 != 0) {
					flag = false;
					break;
				}
			}
		}
		if (flag == false) {
			divide(x1, (x2 - x1) / 3 + x1, y1, y1 + (y2 - y1) / 3);
			divide((x2 - x1) / 3 + x1, (x2 - x1) / 3 * 2 + x1, y1, y1 + (y2 - y1) / 3);
			divide((x2 - x1) / 3 * 2 + x1, x2, y1, y1 + (y2 - y1) / 3);
			////
			divide(x1, (x2 - x1) / 3 + x1, y1 + (y2 - y1) / 3, y1 + (y2 - y1) / 3 * 2);
			divide((x2 - x1) / 3 + x1, (x2 - x1) / 3 * 2 + x1, y1 + (y2 - y1) / 3, y1 + (y2 - y1) / 3 * 2);
			divide((x2 - x1) / 3 * 2 + x1, x2, y1 + (y2 - y1) / 3, y1 + (y2 - y1) / 3 * 2);
			///
			divide(x1, (x2 - x1) / 3 + x1, y1 + (y2 - y1) / 3 * 2, y2);
			divide((x2 - x1) / 3 + x1, (x2 - x1) / 3 * 2 + x1, y1 + (y2 - y1) / 3 * 2, y2);
			divide((x2 - x1) / 3 * 2 + x1, x2, y1 + (y2 - y1) / 3 * 2, y2);
			return;
		}
	}

	if (check0 > 0) {
		count0++;
	}
	else if (check1 > 0) {
		count1++;
	}
	else count2++;

	return;
}

int main() {
	
	cin >> N;
	v.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	divide(0,N,0,N);
	cout << count2 << endl << count0 << endl << count1 << endl;
	return 0;
}