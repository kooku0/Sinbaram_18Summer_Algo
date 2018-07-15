#include <iostream>
#include <vector>

using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int nodeIdx, int start, int end);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numCount, changeCount, sumCount;
    cin >> numCount >> changeCount >> sumCount;
    int orderCount = changeCount + sumCount;

    vector<long long> arr(numCount);

    for (int i = 0; i < numCount; ++i)
        cin >> arr[i];

    
    vector<long long> sTree(numCount * 2 - 1);
    init(arr, sTree, 0, 0, numCount);

    for (int i = 0; i < numCount * 2 - 1; ++i) {
        cout << sTree[i] << ' ';
    }
    cout << endl;
    
    int order, arg1, arg2;
    for (int i = 0; i < orderCount; ++i)
    {
        cin >> order >> arg1 >> arg2;
        
        if (order == 1)
        {
            //change arg1 th num to arg2
        }
        else
        {
            //get sum of arg1 th num and arg2 th num.
        }
    }

    return 0;
}

long long init(vector<long long>& arr, vector<long long>& tree, int nodeIdx, int start, int end)
{
    if (nodeIdx == start)
    {
        return tree[nodeIdx] = arr[start];
    }
    else
    {
        return tree[nodeIdx] = init(arr, tree, nodeIdx * 2, start, (start+end)/2) + init(arr, tree, nodeIdx * 2 + 1, (start+end)/2+1, end);
    }
}