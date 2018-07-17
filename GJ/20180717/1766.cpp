#include<iostream>
#include<queue>
#include<vector>
using namespace std; 

typedef vector <int> list;
typedef greater<int> gt;

vector        <list>          adj;
vector        <int>           indeg;
priority_queue<int, list, gt> q;
vector        <int>           result;

void topo(int N){
	for(int i = 1; i <= N; i++)
		if(indeg[i] == 0) q.push(i);

	while(!q.empty()){
		int cur = q.top();
		q.pop();

		result.push_back(cur);

		for(const auto& next : adj[cur]){
			indeg[next]--;
			if(indeg[next] == 0) q.push(next);
		}
	}
}

int main(void){
	int N, M; cin >> N >> M;

	adj.resize(N + 1);
	indeg.resize(N + 1);

	for(int i = 0; i < M; i++){
		int from, to; cin >> from >> to;
		adj[from].push_back(to);
		indeg[to]++;
	}

	topo(N);

	for(const auto& i : result)
		cout << i << " ";

	return 0;
}
