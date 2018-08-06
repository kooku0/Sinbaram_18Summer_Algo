#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
const int undefined = 100001;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numRoute, numCity;
    cin >> numCity >> numRoute;

    vector<vector<int>> weights(numCity + 1, vector<int>(numCity + 1, undefined));

    int a, b, weight;
    for (int i = 0; i < numRoute; ++i)
    {
        cin >> a >> b >> weight;
        weights[a][b] = min(weights[a][b], weight);
    }

    for (int i = 1; i < numCity + 1; ++i)
        weights[i][i] = 0;

    for (int k = 1; k < numCity + 1; ++k)
        for (int i = 1; i < numCity + 1; ++i)
            for (int j = 1; j < numCity + 1; ++j)
                weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);

    for (int i = 1; i < numCity + 1; ++i)
        for (int j = 1; j < numCity + 1; ++j)
            weights[i][j] = weights[i][j] == undefined ? 0 : weights[i][j];
            
    for (int i = 1; i < numCity + 1; ++i)
    {
        copy(weights[i].begin() + 1, weights[i].end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }

    return 0;
}