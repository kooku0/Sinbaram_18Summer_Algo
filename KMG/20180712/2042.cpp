#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;

long long init(vector<long long> &tree, vector<int> &v, int node, int start, int end) {
	if (start == end) {
		return tree[node] = v[end];
	}
	return tree[node] = init(tree, v, node * 2, start, (start + end) / 2) + init(tree, v, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long search(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return search(tree, node * 2, start, (start + end) / 2, left, right) + search(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

long long update(vector<long long> &tree, int node, int start, int end, int index, int value) {
	if (index < start || end < index) return tree[node];
	if (start == index && end == index) return tree[node] = value;
	return tree[node] = update(tree, node * 2, start, (start + end) / 2, index, value) + update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
}

int main() {

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int tree_size = pow(2,ceil(log2(N)) + 1)+1;
	vector<long long> tree(tree_size);
	init(tree, arr, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		int tmp;
		cin >> tmp;
		int a, b;
		cin >> a >> b;
		if (tmp == 1) update(tree, 1, 0, N - 1, a - 1, b);
		else cout << search(tree, 1, 0, N - 1, a - 1, b - 1) << '\n';
	}


	return 0;
}