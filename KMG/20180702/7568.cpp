#include <iostream>
#include <vector>
using namespace std;

struct person {
	int x, y;
	int idx;
	int count;
};


int main() {
	int N;
	cin >> N;
	vector<person> v(N);
	for (int i = 0; i < N; i++) {
		person p;
		cin >> p.x >> p.y;
		p.idx = i;
		v[i] = p;
	}
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (v[j].x > v[i].x && v[j].y > v[i].y) {
				count++;
			}
		}
		v[i].count = count;
	}
	
	for (int i = 0; i < N; i++) {

		cout << v[i].count + 1 << " ";
	}
	cout << endl;
	return 0;
}