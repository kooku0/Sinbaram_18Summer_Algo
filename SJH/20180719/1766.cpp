#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<int>> graph;
vector<int> order;
vector<int> degree;
vector<bool> visitNode;

int numVisit = 1;

void checkDegree(void);
void indegree(void);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numProb, numComp;
    cin >> numProb >> numComp;

    graph.resize(numProb + 1);
    order.resize(numProb);
    degree.resize(numProb + 1, 0);
    visitNode.resize(numProb + 1, false);
    vector<int> rootGraph(numProb + 1, 0);

    int prenode, postnode;
    for (int i = 0; i < numComp ; ++i)
    {
        cin >> prenode >> postnode;
        graph[prenode].push_back(postnode);
        ++ rootGraph[postnode];
    }

    checkDegree();
    indegree();

    for (int i = 1; i < numVisit; ++i)
        cout << order[i] << ' ';
    cout << endl;

    return 0;
}

void checkDegree(void)
{
    for (int i = 1; i < graph.size(); ++i)
        if (!visitNode[i])
            for (const auto& idx : graph[i])
            {
                ++ degree[idx];
            }
}

void indegree(void)
{
    bool found = false;
    int i;
    for (i = 1; i < degree.size(); ++i)
    {
        if (!visitNode[i] && degree[i] == 0) {
            found = true;
            break;
        }
    }

    if (found) {
        order[numVisit] = i;
        visitNode[i] = true;
        ++numVisit;

        for (const auto& idx : graph[i])
            degree[idx] --;
    }
        
    if (numVisit != visitNode.size())
        indegree();
}   