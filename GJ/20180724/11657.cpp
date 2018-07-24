#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

#define MAX_SIZE 501
#define START 1
#define INF numeric_limits<ll>::max()
#define endl '\n'

typedef long long ll;

typedef struct _VERTEX{
	ll pos;
	ll wgt;
}Vertex;

typedef vector<Vertex> Graph;

Graph edge[MAX_SIZE];
ll   wgt [MAX_SIZE];

bool  hasCycle = false;

void get(const ll& M){
	for(ll _ = 1 ; _ <= M; _++){
		ll    from,   to,   wgt;
		cin >> from >> to >> wgt;

		edge[from].push_back({to, wgt});
	}
}

bool execute(const ll& N){
	for(ll _try_ = 1; _try_ <= N; _try_++){
		bool update = false;
		for(ll from = 1; from <= N; from++){
			for(Vertex& to : edge[from]){
				if(wgt[from] != INF &&
				   wgt[to.pos] > wgt[from] + to.wgt){
					wgt[to.pos] = wgt[from] + to.wgt;
					update = true;
				} // end of if
			} // end of for
		} // end of for
		if(_try_ == N && update){
			return true;
		}
	}
	return false;
}

void bford(const ll& N){
	// llialize
	for(ll v = 1; v <= N; v++) wgt[v] = INF;
	wgt[START] = 0;

	hasCycle = execute(N);
}


int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll N, M;
	cin >> N >> M;
	get(M);
	bford(N);

	if(hasCycle)
		cout << -1 << endl;
	else
		for(ll i = 2; i <= N; i++){
			if(wgt[i] != INF) cout << wgt[i] << endl;
			else              cout << -1 << endl;
		} // end of for
	return 0;
}
