#include<iostream>
#include<queue>
using namespace std;

#define INF 999999999
#define MAX 126

typedef struct _POINT{
    int cost;
    int row;
    int col;
}Point;

int adj[MAX][MAX];
int dist[MAX][MAX];

void run(const int N){
    static int counter = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = INF;
            cin >> adj[i][j];
        } // end of for
    } // end of for

    queue<Point> q;

    dist[0][0] = adj[0][0];
    q.push({dist[0][0], 0, 0});

    while(!q.empty()){
        const Point &cur = q.front();

        int cost = cur.cost;
        int row  = cur.row;
        int col  = cur.col;

        q.pop();

        if(dist[row][col] < cost) continue;

        int up    = row + 1;
        int down  = row - 1;
        int left  = col - 1;
        int right = col + 1;

        if(up < N && dist[up][col] > cost + adj[up][col]){
            dist[up][col] = cost + adj[up][col];
            q.push({dist[up][col], up, col});
        }

        if(down >= 0 && dist[down][col] > cost + adj[down][col]){
            dist[down][col] = cost + adj[down][col];
            q.push({dist[down][col], down, col});
        }

        if(right < N && dist[row][right] > cost + adj[row][right]){
            dist[row][right] = cost + adj[row][right];
            q.push({dist[row][right], row, right});
        }

        if(left >= 0 && dist[row][left] > cost + adj[row][left]){
            dist[row][left] = cost + adj[row][left];
            q.push({dist[row][left], row, left});
        }
    } // end of while
    cout << "Problem " << counter++ << ": " << dist[N-1][N-1] << '\n';
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    while(true){
        int N = 0; cin >> N;
        if(N == 0) break;
        run(N);
    }
    return 0;
}
