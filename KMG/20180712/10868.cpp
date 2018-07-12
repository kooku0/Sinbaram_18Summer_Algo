#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int init(vector<int> &tree, vector<int> &v, int node, int start, int end) {
	if (start == end) {
		return tree[node] = v[end];
	}
	return tree[node] = min(init(tree, v, node * 2, start, (start + end) / 2), init(tree, v, node * 2 + 1, (start + end) / 2 + 1, end));
}

int search(vector<int> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INT_MAX;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return min(search(tree, node * 2, start, (start + end) / 2, left, right), search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
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

	vector<int> tree(treeSize);
	init(tree, v, 1, 1, N);
	int a, b;
	for (int i = 0; i < M; i++) {

		cin >> a >> b;
		cout << search(tree, 1, 1, N, a, b) << '\n';
	}

	return 0;
}