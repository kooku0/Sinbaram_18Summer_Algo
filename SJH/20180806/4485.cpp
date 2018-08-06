#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef struct _edge 
{
    int node;
    int weight;
} Edge;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxWeight = 10;
    int caveSize;
    int problemIndex = 1;

    while(cin >> caveSize) 
    {
        if (caveSize == 0)
            break;
        
        vector<vector<int>> weights(caveSize + 1, vector<int>(caveSize + 1));
        vector<vector<Edge>> graph(caveSize * caveSize + 1);
        
        for (int i = 1; i < caveSize + 1; ++i)
            for (int j = 1; j < caveSize + 1; ++j)
                cin >> weights[i][j];

        for (int i = 1; i < caveSize + 1; ++i)
            for (int j = 1; j < caveSize + 1; ++j)
            {
                if (j != caveSize)
                    graph[(i - 1) * caveSize + j].push_back({(i - 1) * caveSize + j + 1, weights[i][j + 1]});

                if (i != caveSize)
                    graph[(i - 1) * caveSize + j].push_back({i * caveSize + j, weights[i + 1][j]});

                if (i != 1)
                    graph[(i - 1) * caveSize + j].push_back({(i - 2) * caveSize + j, weights[i - 1][j]});
                
                if (j != 1)
                    graph[(i - 1) * caveSize + j].push_back({(i - 1) * caveSize + j - 1, weights[i][j - 1]});
            }

        const int maxDist = numeric_limits<int>::max();

        vector<bool> visitNode(caveSize * caveSize + 1, false);
        vector<int> dist(caveSize * caveSize + 1, maxDist);
        
        const int source = 1;
        const int destination = caveSize * caveSize;

        dist[source] = 0;

        queue<int> willVisit;
        willVisit.push(source);

        while (!willVisit.empty())
        {
            int currentNode = willVisit.front();
            willVisit.pop();

            for (const auto& edge : graph[currentNode])
            {
                if (dist[currentNode] + edge.weight < dist[edge.node]) {
                    dist[edge.node] = dist[currentNode] + edge.weight;
                    willVisit.push(edge.node);
                }
            }
        }

        cout << "Problem " << problemIndex++ << ": " << dist[destination] + weights[1][1] << '\n';
    }

    return 0;
}