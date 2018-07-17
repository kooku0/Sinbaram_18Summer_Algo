#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int>> edge;
vector<bool> isVisit;
stack<int> result;

void topodfs(int node){
	isVisit[node] = true;

	for(const auto& next : edge[node])
		if(!isVisit[next]) topodfs(next);
	result.push(node);
}

void toposort(int N){
	for(int start = 1; start <= N; start++)
		if(!isVisit[start]) topodfs(start);
}

int main(void){
	int N, M;
	cin >> N >> M;
	edge.resize(N+1);
	isVisit.resize(N+1,false);
	for(int i = 0; i < M; i++){
		int from, to; cin >> from >> to;
		edge[from].push_back(to);
	}
	toposort(N); // 주의
	while(!result.empty()){
		cout << result.top() << " ";
		result.pop();
	}
	cout << endl;
	return 0;
}
