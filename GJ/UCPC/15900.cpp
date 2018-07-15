#include<iostream>
#include<vector>
using namespace std;

#define MAX_SIZE 500001

vector<int> src[MAX_SIZE];
vector<bool> visited(MAX_SIZE, 0);

int result = 0;


void dfs(int node, int count) {
	visited[node] = true;
	bool traverse = false;

	for (auto i : src[node]) {
		int next = i;
		if (visited[next] == false) {
			traverse = true;
			dfs(next, count + 1);
		}
	}
	if(!traverse)
		result += count;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	int temp[2];
	while(cin >> temp[0] >> temp[1]){
		src[temp[0]].push_back(temp[1]);
		src[temp[1]].push_back(temp[0]);
	}
	dfs(1, 0);
	cout << (result % 2 != 0 ? "Yes" : "No")<< endl;
	return 0;
}