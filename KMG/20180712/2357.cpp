#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;

struct MinMax {
	int Min, Max;
};
MinMax cmp(MinMax a, MinMax b) {
	return { a.Min<b.Min ? a.Min : b.Min,a.Max>b.Max ? a.Max : b.Max };
}
MinMax init(vector<MinMax> &tree, vector<int> &v, int node, int start, int end) {
	if (start == end) {
		return tree[node] = {v[end],v[end]};
	}
	return tree[node] = cmp(init(tree, v, node * 2, start, (start + end) / 2), init(tree, v, node * 2 + 1, (start + end) / 2 + 1, end));
}

MinMax search(vector<MinMax> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return { INT_MAX, INT_MIN };
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return cmp(search(tree, node * 2, start, (start + end) / 2, left, right), search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	int treeSize = pow(2, (ceil(log2(N)) + 1));

	vector<MinMax> tree(treeSize);
	init(tree, v, 1, 1, N);
	int a, b;
	for (int i = 0; i < M; i++) {

		cin >> a >> b;
		MinMax tmp = search(tree, 1, 1, N, a, b);
		cout <<  tmp.Min << ' ' << tmp.Max << '\n';
	}

	return 0;
}