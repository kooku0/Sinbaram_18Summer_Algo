#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

vector<vector<int>> graph;
vector<bool> visitNode;

void dfs(int node);
void bfs(int node);

int main(void)
{
    int numNode, numEdge, startNode;
    cin >> numNode >> numEdge >> startNode;

    graph.resize(numNode + 1);
    
    int node1, node2;
    for (int i = 0; i < numEdge; ++i)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    for (int i = 1; i < numNode + 1; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }

    visitNode.resize(numNode + 1, false);
    dfs(startNode);
    cout << endl;

    visitNode = vector<bool>(numNode + 1, false);
    bfs(startNode);

    return 0;
}

void dfs(int node)
{
    if (visitNode[node])
        return;

    cout << node << ' ';
    visitNode[node] = true;

    for (const auto& targetNode : graph[node])
    {
        dfs(targetNode);
    }
}

void bfs(int node)
{
    queue<int> bfsQueue;
    bfsQueue.push(node);
    visitNode[node] = true;

    while (!bfsQueue.empty())
    {
        int targetNode = bfsQueue.front();
        bfsQueue.pop();
        cout << targetNode << ' ';

        for (const auto& childNode : graph[targetNode])
            if (!visitNode[childNode]) 
            {
                bfsQueue.push(childNode);
                visitNode[childNode] = true;
            }
    }
    cout << endl;
}