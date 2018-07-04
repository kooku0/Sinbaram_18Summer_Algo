#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_SIZE 1000

int main(void){
    int N;
    int P[MAX_SIZE];
    int result = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> P[i];
    vector<int> tP(P, P+N);
    sort(tP.begin(), tP.end());
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < i; j++)
            result += tP.at(j);
    cout << result << endl;
    return 0;
}
