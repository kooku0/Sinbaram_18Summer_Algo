#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<limits>
using namespace std;

typedef long long ll;
typedef vector<ll> vtype;

ll init(vtype &a, vtype &tree, int node, int start, int end){
	if(start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node*2, start, (start + end) / 2)
					      + init(a, tree, node*2 + 1, (start + end) / 2 + 1, end);
}

void update(vtype &tree, int node, int start, int end, int index, ll diff){
	if(index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if(start != end){
		update(tree, node*2, start, (start + end)/2, index, diff);
		update(tree, node*2 + 1, (start + end)/2 + 1, end, index, diff);

	}
}

ll sum(vtype &tree, int node, int start, int end, int left, int right){
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(tree, node*2, start, (start + end) / 2, left, right)
		 + sum(tree, node*2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K; cin >> N >> M >> K;


	vtype a(N);
	int   h        = ceil(log2(N));
	int	  ts       = (1 << (h + 1));
	vtype tree(ts);
	M += K;

	for(int i = 0; i < N; i++) cin >> a[i];
	init(a, tree, 1, 0, N - 1);

	while(M--){
		ll T1, T2, T3;
		cin >> T1 >> T2 >> T3;
		if(T1 == 1){
			T2 -= 1;
			ll diff = T3 - a[T2];
			a[T2] = T3;
			update(tree, 1, 0, N-1, T2, diff);
		}
		else if(T1 == 2){
			cout << sum(tree, 1, 0, N-1, T2-1, T3-1) << endl;
		}
	}
	return 0;
}
