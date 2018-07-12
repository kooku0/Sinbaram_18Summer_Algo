#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
using uint = unsigned int;

uint init(const vector<uint>& arr, vector<uint>& tree, int node, int start, int end);
uint findMin(const vector<uint>& tree, int node, int start, int end, int left, int right);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<uint> sequence(N);
    
    for (int i = 0; i < N; ++i)
        cin >> sequence[i];

    int height = static_cast<int>(ceil(log2(N)));
    int treeSize = (1 << height + 1);

    vector<uint> sTree(treeSize);
    init(sequence, sTree, 1, 0, N - 1);


    int a, b;
    for (int i = 0; i < M; ++i) 
    {
        cin >> a >> b;

        cout << findMin(sTree, 1, 0, N - 1, a - 1, b - 1) << '\n';
    }

    return 0;
}

uint init(const vector<uint>& arr, vector<uint>& tree, int node, int start, int end)
{
    if (start == end) 
        tree[node] = arr[start];
    else {
        uint left = init(arr, tree, node * 2, start, static_cast<int>((start + end) / 2));
        uint right = init (arr, tree, node * 2 + 1, static_cast<int>((start + end) / 2) + 1, end);

        tree[node] = left > right ? right : left;
    }
                    
    
    return tree[node];
}

uint findMin(const vector<uint>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return numeric_limits<uint>::max();
    if (left <= start && end <= right)
        return tree[node];
    
    return min(findMin(tree, node * 2, start, static_cast<int>((start + end) / 2), left, right), 
                findMin(tree, node * 2 + 1, static_cast<int>((start + end) / 2) + 1, end, left, right));
}