#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

#define MAX_SIZE 101
#define INF 300000

int dp[MAX_SIZE][MAX_SIZE];

void run(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < MAX_SIZE; i++)
        for(int j = 0; j < MAX_SIZE; j++)
            dp[i][j] = i == j ? 0 : INF;

    for(int i = 0; i < m; i++){
        int src,dst,cost;
        cin >> src >> dst >> cost;
        dp[src][dst] = min(dp[src][dst], cost);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    run();
    return 0;
}
