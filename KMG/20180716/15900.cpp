#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _count = 0;
int n;
vector<vector<int>> v;
//vector<bool> visit;
void recursive(int parent,int count,int prev) {
	
	int tmp = 0;
	for (int i = 0; i < v[parent].size(); i++) {
		if (v[parent][i] != prev) recursive(v[parent][i], count + 1, parent);
		else tmp++;
	}
	if (tmp == v[parent].size())_count += count;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.resize(n+1);
	//visit.resize(n - 1,true);
	for (int i = 0; i < n - 1 ; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		
	}

	recursive(1,0,0);
	//cout << _count << endl;
	if (_count % 2 == 0)cout << "No" << '\n';
	else cout << "Yes" << '\n';
	return 0;
}