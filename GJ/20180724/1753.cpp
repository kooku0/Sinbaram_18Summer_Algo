#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<limits>
using namespace std;

#define MAX_VERTEX  20001
#define MAX_EDGE    300001
#define INF numeric_limits<int>::max()

class Graph{
    private:
        int V;
        vector<pair<int, int>> E[MAX_VERTEX];
        int numOfEdge;

        ///dijkstra searching을 하기 위함
        int d[MAX_VERTEX];
        queue<int> S; // 방문한 노드들의 집합
        vector<int> Q; // 방문하지 않은 노드들의 집합
    public:
        Graph(int V, int E):V(V + 1),numOfEdge(E){ // 주의 사항 V는 V+1이므로 V는 그대로 둘 것
            for(int i = 0; i < this->V; i++){
                d[i] = INF;
                if(i > 0) Q.push_back(i); // 0은 노드 집합에 들어가지 않으므로
            }
        };
        int getDijkstraResult(int index){ // index는 1부터 시작된다.
            if(index == 0 || index > MAX_VERTEX){
                cerr << "invalid index" << endl;
                return -1;
            }
            return d[index];
        }
        void setEdge(int src, int dst, int weight){
            bool isExist = false;
            for(auto i : E[src]){
                if(i.first == dst){
                    if(i.second < weight){
                        isExist = true;
                        break;
                    }
                }
            }
            if(!isExist) E[src].push_back(make_pair(dst, weight));
        }
        void dijkstra_traverse(int pos){
            S.push(pos);
            Q.erase(Q.begin() + find(Q, pos));
            for(auto i : E[pos]){
                d[i.first] = min(d[i.first] , d[pos] + i.second);
            }
            int next = 0; int minimum = INF;
            bool nextExist = false;
            for(auto i : Q){
                if(d[i] < minimum){
                    next = i;
                    minimum = d[i];
                    nextExist = true;
                }
            }
            if(nextExist) dijkstra_traverse(next);
        }
        void dijkstra(int start){
            d[start] = 0;
            S.push(start);
            Q.erase(Q.begin() + find(Q,start)); // Q에는 1부터 값이 들어가있으므로
            int next = 0; int minimum = INF;
            for(auto i: E[start]){
                d[i.first] = i.second;
                if(i.second < minimum){
                    next = i.first; 
                    minimum = i.second;
                }
            }
            dijkstra_traverse(next);
        }
        int find(vector<int> v, int data){
            for(unsigned int i = 0; i < v.size(); i++){
                if(v.at(i) == data){
                    return i;
                }
            }
            return -1;
        }
};

int main(void){
	ios::sync_with_stdio(false);
    int V, E, K;
    cin >> V >> E;
    Graph graph(V, E);
    cin >> K;
    for(int i = 0; i < E; i++){
        int src, dst, weight;
        cin >> src >> dst >> weight;
        graph.setEdge(src, dst, weight);
    }
    graph.dijkstra(K);
    for(int i = 1; i <= V; i++){
        if(graph.getDijkstraResult(i) == INF){
            cout << "INF" << endl;
        }
        else{
            cout << graph.getDijkstraResult(i) << endl;
        }
    }
    return 0;
}
