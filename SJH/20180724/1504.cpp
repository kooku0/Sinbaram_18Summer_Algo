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

    int numNode, numEdge;
    cin >> numNode >> numEdge;

    const int maxWeight = numeric_limits<int>::max() / 6;
    const int maxWeightHalf = maxWeight / 2;

    vector<vector<Edge>> graph(numNode + 1);

    for (int i = 0; i < numEdge; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        bool found = false;
        for (auto& edge : graph[from])
            if (edge.node == to) {
                found = true;
                edge.weight = edge.weight > weight ? weight : edge.weight;
                graph[to][from].weight = edge.weight;
            }
        if (!found) {
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }
    }

    int mustNode1, mustNode2;
    cin >> mustNode1 >> mustNode2;

    int startToMust1, startToMust2, must1ToMust2, endToMust1, endToMust2;

    queue<int> willVisit;
    int startNode = 1;
    vector<int> weightsTable(numNode + 1, maxWeight);
    weightsTable[startNode] = 0;

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

    startToMust1 = weightsTable[mustNode1];
    startToMust2 = weightsTable[mustNode2];

    startNode = numNode;
    weightsTable = vector<int>(numNode + 1 , maxWeight);

    weightsTable[startNode] = 0;
    willVisit.push(startNode);

    while (!willVisit.empty())
    {
        int currentNode = willVisit.front();
        willVisit.pop();

        for (const auto& edge : graph[currentNode])
        {
            if (weightsTable[currentNode] + edge.weight < weightsTable[edge.node]) {
                weightsTable[edge.node] = weightsTable[currentNode] + edge.weight;

                if (edge.node != mustNode1 && edge.node != mustNode2)
                    willVisit.push(edge.node);
            }
        }
    }    

    endToMust1 = weightsTable[mustNode1];
    endToMust2 = weightsTable[mustNode2];

    startNode = mustNode1;
    weightsTable = vector<int>(numNode + 1 , maxWeight);
    weightsTable[startNode] = 0;
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


    must1ToMust2 = weightsTable[mustNode2];

    int result = numeric_limits<int>::max();

    int case1 = startToMust1 + must1ToMust2 + endToMust2;
    int case2 = startToMust2 + must1ToMust2 + endToMust1;
    
    result = min(min(case1, case2), result);

    if (result > maxWeightHalf)
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}
