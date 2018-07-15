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
		return tree[node] = min(
					init(a, tree, node*2, start, (start + end) / 2),
					init(a, tree, node*2 + 1, (start + end) / 2 + 1, end)
				);
}

ll search(vtype &tree, int node, int start, int end, int left, int right){
	if(left > end || right < start) return numeric_limits<int>::max();
	if(left <= start && end <= right) return tree[node];
	return min(
				search(tree, node*2, start, (start + end) / 2, left, right)
		       ,search(tree, node*2 + 1, (start + end) / 2 + 1, end, left, right)
			);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M; cin >> N >> M;

	vtype a(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];

	int   h        = ceil(log2(N));
	int	  ts       = (1 << (h + 1));
	vtype tree(ts);

	init(a, tree, 1, 0, N - 1);

	for(int i = 0; i < M; i++){
		int left, right;
		cin >> left >> right;
		cout << search(tree, 1, 0, N - 1, left - 1, right - 1) << "\n";
	}
	return 0;
}
