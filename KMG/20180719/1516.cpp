#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> v;
vector<int> time;
vector<bool> visit;

int dfs(int node) {
	visit[node] = true;
	int _time = 0;
	_time += time[node];
	int _max = 0;
	for (auto x : v[node]) {

		if (visit[x]) _max = max(_max, time[x]);
		else _max = max(_max,dfs(x));

	}
	_time += _max;
	return time[node] = _time;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	v.resize(n + 1);
	time.resize(n + 1);
	visit.resize(n + 1, false);
	for (int i = 1; i <= n;i++) {
		cin >> time[i];
		while (1) {
			int node;
			cin >> node;
			if (node == -1) break;
			v[i].push_back(node);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i]) cout << time[i] << '\n';
		else cout << dfs(i) << '\n';
	}
	

	return 0;
}