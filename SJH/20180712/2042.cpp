#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(const vector<long long>& arr, vector<long long>& tree, int nodeIdx, int start, int end);
long long changeTree(vector<long long>& tree, int node, int start, int end, int targetIdx, int targetNum);
long long getSum(const vector<long long>& tree, int node, int start, int end, int left, int right);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numCount, changeCount, sumCount;
    cin >> numCount >> changeCount >> sumCount;
    int orderCount = changeCount + sumCount;

    vector<long long> sequence(numCount);

    for (int i = 0; i < numCount; ++i)
        cin >> sequence[i];

    
    const int height = static_cast<int>(ceil(log2(numCount)));
    const int treeSize = (1 << height + 1);

    vector<long long> sTree(treeSize);

    init(sequence, sTree, 1, 0, numCount - 1);

    int order, arg1, arg2;
    for (int i = 0; i < orderCount; ++i)
    {
        cin >> order >> arg1 >> arg2;
        
        if (order == 1)
        {
            changeTree(sTree, 1, 0, numCount - 1, arg1 - 1, arg2);
        }
        else
        {
            //get sum of arg1 th num and arg2 th num.
            cout << getSum(sTree, 1, 0, numCount - 1, arg1 - 1, arg2 - 1) << '\n';
        }
    }

    return 0;
}

long long init(const vector<long long>& arr, vector<long long>& tree, int nodeIdx, int start, int end)
{
    if (start == end)
    {
        return tree[nodeIdx] = arr[start];
    }
    else
    {
        return tree[nodeIdx] = init(arr, tree, nodeIdx * 2, start, static_cast<int>((start+end)/2)) + 
                                init(arr, tree, nodeIdx * 2 + 1, static_cast<int>((start+end)/2) + 1, end);
    }
}

long long changeTree(vector<long long>& tree, int node, int start, int end, int targetIdx, int targetNum)
{
    if (start == end) {
        if (start == targetIdx)
            tree[node] = targetNum;
        return tree[node];
    }

    const int middle = static_cast<int>((start + end) / 2);
    long long left = tree[node * 2];
    long long right = tree[node * 2 + 1];

    if (start <= targetIdx && targetIdx <= middle)
        left = changeTree(tree, node * 2, start, middle, targetIdx, targetNum);
    if (middle < targetIdx && targetIdx <= end)
        right = changeTree(tree, node * 2 + 1, middle + 1, end, targetIdx, targetNum);

    return tree[node] = left + right;
}

long long getSum(const vector<long long>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    
    return getSum(tree, node * 2, start, static_cast<int>((start + end) / 2), left, right) + 
            getSum(tree, node * 2 + 1, static_cast<int>((start + end) / 2) + 1, end, left, right);
}