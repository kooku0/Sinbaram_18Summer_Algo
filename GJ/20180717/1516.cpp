#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int>> edge;
vector<int> indeg;
vector<int> Time;

vector<int> result;

void topobfs(int N){
	queue<int> q;

	for(int i = 1; i <= N; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(const auto &next : edge[cur]){
			indeg[next] = indeg[next] - 1;
			result[next] = max(result[next], result[cur] + Time[next]);
			if(!indeg[next]) q.push(next);
		}
	}
}

void toposort(int N){
	topobfs(N);
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	edge.resize(N + 1);
	Time.resize(N + 1);
	result.resize(N + 1);
	indeg.resize(N + 1,0);
	for(int i = 1; i <= N; i++){
		int to = i;
	    cin >> Time[i];
		result[i] = Time[i];
		while(true){
			int from; cin >> from;
			if(from == -1)   break;
			edge[from].push_back(to);
			indeg[to]++;
		} // end of for
	} // end of for

	toposort(N); // 주의

	for(int i = 1; i <= N; i++){
		cout << result[i] << '\n';
	}
	return 0;
}
