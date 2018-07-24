#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numCase;
    cin >> numCase;

    vector<vector<int>> lastYear(numCase);
    vector<vector<int>> teamOrder(numCase);
    vector<vector<vector<int>>> graph(numCase);
    vector<stack<int>> orderStack(numCase);
    vector<vector<bool>> changed(numCase);
    vector<vector<int>> degree(numCase);

    int numTeam, numComp, arg1, arg2;
    for (int i = 0; i < numCase; ++i)
    {
        cin >> numTeam;
        lastYear[i].resize(numTeam + 1);
        teamOrder[i].resize(numTeam + 1);
        graph[i].resize(numTeam + 1);
        degree[i].resize(numTeam + 1, 0);
        changed[i].resize(numTeam + 1, false);

        for (int j = 1; j < numTeam + 1; ++j) {
            cin >> lastYear[i][j];
            teamOrder[i][lastYear[i][j]] = j;
        }

        cin >> numComp;

        bool cannot = false;
        for (int j = 0; j < numComp; ++j)
        {
            cin >> arg1 >> arg2;

            if (teamOrder[i][arg1] > teamOrder[i][arg2]) {
                graph[i][arg2].push_back(arg1);
                ++ degree[i][arg1];
                changed[i][arg1] = true;
                if (degree[i][arg2] > 1) {
                    cannot = true;
                    break;
                }
            }
            else {
                graph[i][arg1].push_back(arg2);
                ++ degree[i][arg2];
                changed[i][arg2] = true;
                if (degree[i][arg1] > 1) {
                    cannot = true;
                    break;
                }
            }
            
        }

        cout << "Team : ";
            for (int j = 1; j < numTeam + 1;++j)
                cout << degree[i][j] << ' ';
            cout << endl;
        
        if (cannot) {
            cout << "?" << endl;
        }
        else {
            int previousTeam = 0;
            for (int j = numTeam; j > 0; --j)
            {
                int team = lastYear[i][j]; // j등인 team
                if (!changed[i][team])
                {
                    if (previousTeam != 0) {
                        graph[i][previousTeam].push_back(team);
                        ++ degree[i][team];
                    }
                    previousTeam = team;
                }
            }   
            cout << "Team : ";
            for (int j = 1; j < numTeam + 1;++j)
                cout << degree[i][j] << ' ';
            cout << endl;
            int numVisit = 0;
            bool inconsistent = false;
            while (numVisit < numTeam)
            {
                int prior = numTeam;
                for (int j = numTeam; j > 0; --j)
                    if (degree[i][j] == 0 && teamOrder[i][prior] < teamOrder[i][j]) 
                        prior = j;

                degree[i][prior] = -1 ;
                if (!orderStack[i].empty() && orderStack[i].top() == prior) 
                {
                    inconsistent = true;
                    break;
                }
                orderStack[i].push(prior);
                for (const auto& team : graph[i][prior]) {
                    -- degree[i][team];
                }
                ++numVisit;
            }
            if (inconsistent) {
                cout << "IMPOSSIBLE" << endl;
            }
            else {
                for (int j = 0; j < numTeam; ++j)
                {
                    cout << orderStack[i].top() << ' ';
                    orderStack[i].pop();
                }
                cout << endl;
            }
        }

    }

    return 0;
}