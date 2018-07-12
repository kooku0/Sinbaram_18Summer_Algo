#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
    int N;
    vector<int> w;
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        w.push_back(temp);
    }
    sort(w.begin(),w.end(),greater<int>());
    int cur = 0;
    int pos = 1;
    int result = 0;
    for(vector<int>::iterator it = w.begin(); it != w.end(); it++){
        cur = *it*pos;
        pos++;
        result = max(cur,result);
    }
    cout << result << endl;
    return 0;
}
