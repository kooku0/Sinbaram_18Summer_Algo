#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef struct _edge {
    int node;
    int weight;
} Edge;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numNode, numEdge, startNode;
    cin >> numNode >> numEdge >> startNode;

    const int maxWeight = numeric_limits<int>::max() / 3;
    const int maxWeightHalf = maxWeight / 2;

    vector<vector<Edge>> graph(numNode + 1);
    vector<int> weightsTable(numNode + 1, maxWeight);

    for (int i = 0; i < numEdge; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        bool found = false;
        for (auto& edge : graph[from])
            if (edge.node == to) {
                found = true;
                edge.weight = edge.weight > weight ? weight : edge.weight;
            }
        if (!found)
            graph[from].push_back({to, weight});
    }

    weightsTable[startNode] = 0;

    queue<int> willVisit;
    willVisit.push(startNode);

    while (!willVisit.empty())
    {
        int currentNode = willVisit.front();
        willVisit.pop();

        for (const auto& edge : graph[currentNode])
        {
            if (weightsTable[currentNode] + edge.weight < weightsTable[edge.node]) {
                weightsTable[edge.node] = weightsTable[currentNode] + edge.weight;
                willVisit.push(edge.node);
            }
        }
    }

    for (int i = 1; i < numNode + 1; ++i) {
        if (weightsTable[i] > maxWeightHalf)
            cout << "INF" << '\n';
        else
            cout << weightsTable[i] << '\n';
    }

    return 0;
}
