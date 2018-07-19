#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>v;
vector<bool> visited;
vector<int> result;
vector<int> indegree;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	v.resize(N + 1);
	visited.resize(N + 1, false);
	indegree.resize(N + 1, 0);
	for (int i = 1; i <= M; i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	while (true) {
		int i;
		for (i = 1; i <= N; i++) {
			if (visited[i] == false && indegree[i] == 0) {
				visited[i] = true;
				result.push_back(i);
				for (auto x : v[i]) {
					indegree[x]--;
				}
				break;
			}
		}
		if (i > N)break;
	}
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';

	}
	cout << '\n';

	return 0;
}