#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<int> visitNode;
stack<int> orderStack;

void dfs(int graphIdx, int previousIdx);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numStd, numComp;
    cin >> numStd >> numComp;
    graph = vector<vector<int>>(numStd + 1, vector<int>());
    visitNode = vector<int>(numStd + 1);

    int left, right;
    for (int i = 0; i < numComp; ++i) 
    {
        cin >> left >> right;
        graph[left].push_back(right);
    }
    
    for (int i = 1; i < numStd + 1; ++i) 
        if (visitNode[i] == 0)
            dfs(i, i);
    
    const int stackSize = orderStack.size();
    for (int i = 0; i < stackSize; ++i) {
        cout << orderStack.top() << ' ';
        orderStack.pop();
    }
    cout << endl;

    return 0;
}

void dfs(int graphIdx, int previousIdx)
{
    bool leaf = false;
    int currentIdx = 0;
    while (!leaf)
    {
        if (currentIdx == graph[graphIdx].size()) {
            leaf = true;
        }
        else
        {
            if (visitNode[graph[graphIdx][currentIdx]] == 0)
                dfs(graph[graphIdx][currentIdx], graphIdx);
            else 
                ++currentIdx;
        }
        
    }

    if (leaf)
    {
        orderStack.push(graphIdx);
        visitNode[graphIdx] = 1;
    }
}