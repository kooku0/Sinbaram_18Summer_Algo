#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int graphIdx);

vector<vector<int>> graph;
vector<bool> visitNode;
vector<int> durationVector;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numbuilding;
    cin >> numbuilding;

    graph.resize(numbuilding + 1);
    durationVector.resize(numbuilding + 1);
    visitNode.resize(numbuilding + 1);

    int prenode;
    for (int i = 1; i < numbuilding + 1; ++i)
    {
        cin >> durationVector[i];
        while (cin >> prenode)
            if (prenode == -1)
                break;
            else
                graph[i].push_back(prenode);
    }

    for (int i = 1; i < numbuilding + 1; ++i) 
        if (visitNode[i])
            cout << durationVector[i] << ' ';
        else
            cout << dfs(i) << ' ';
    cout << endl;

    return 0;   
}

int dfs(int graphIdx)
{
    visitNode[graphIdx] = true;

    int time = durationVector[graphIdx];
    int _max = 0;
    for (const auto& idx : graph[graphIdx])
    {
        if (visitNode[idx]) _max = max(_max, durationVector[idx]);
        else _max = max(_max, dfs(idx));
    }

    time += _max;
    durationVector[graphIdx] = time;
    return time;    
}