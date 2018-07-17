#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef vector<vector<int>> list2d;
typedef vector<int>         list;

#define MAX 501

int edge[MAX][MAX];
int order[MAX], indeg[MAX];

bool ambiguous = false;

template<typename T>
void reverse(T& a, T& b){
	const T _a = a;
	const T _b = b;
	b = _a; a = _b;
}

list topo(const int N){
	list result;
	queue<int> q;
	for(int i = 1; i <= N; i++)
		if(!indeg[i]) q.push(i);
	while(!q.empty()){
		if(q.size() > 1){
			ambiguous = true;
			break;
		}

		int from = q.front();
		q.pop();
		result.push_back(from);

		for(int to = 1; to <= N; to++){
			if(edge[from][to] == 1){
				indeg[to]--;
				if(!indeg[to]) q.push(to);
			}
		} // end of for
	} // end of while
	return result;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case; cin >> test_case;
	while(test_case--){
		ambiguous = false;
		memset(edge, 0, sizeof(edge));
		memset(indeg, 0, sizeof(indeg));

		int N; cin >> N;

		// 이전의 순서
		for(int cur = 1; cur <= N; cur++){
			for(int next = cur + 1; next <= N; next++){
				edge[order[cur]][order[next]] = 1;
				indeg[order[next]]++;
			} // end of for
		} // end of for

		int M; cin >> M;

		// 변경된 순서
		for(int i = 0; i < M; i++){
			int from, to; cin >> from >> to;

			reverse(edge[from][to], edge[to][from]);

			int plus  = edge[from][to] == 1 ? from : to;
			int minus = edge[from][to] == 1 ? to   : from;
			
			indeg[minus]--; indeg[plus]++;
		} // end of for

		list ans = topo(N);

		if(!ambiguous) cout << "?";
		else{
			if(ans.size() == (size_t)N){
				for(int i = 0; i < N; i++) cout << ans[i] << " ";
			}
			else cout << "IMPOSSIBLE";
		} 
		cout << endl;
	} // end of while
	return 0;
}
