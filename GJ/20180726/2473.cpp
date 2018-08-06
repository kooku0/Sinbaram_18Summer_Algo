#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    /** Initializae **/
    int N; cin >> N;
    vector<ll> data(N, 0);
    for(auto& now : data) cin >> now;
    sort(data.begin(), data.end());

    /** Solve **/
    ll result[3] = {-1, -1, -1};
    ll sum       = numeric_limits<ll>::max();
    for(int pivot = 0; pivot < N; pivot++){
        pair<int, int> idx   = {0, N - 1};

        while(idx.first  != N  &&
              idx.second != -1 &&
              idx.first  != idx.second){

            if(idx.first  == pivot){ idx.first++;  continue; }
            if(idx.second == pivot){ idx.second--; continue; }

            ll left  = data[idx.first];
            ll right = data[idx.second];
            ll cmp   = data[pivot] + left + right;
            
            if(abs(cmp) <= abs(sum)){
                result[0] = data[pivot];
                result[1] = left;
                result[2] = right;
                sum       = cmp;
            }

            if     (cmp < 0) idx.first++;
            else if(cmp > 0) idx.second--;
            else{ // find!!!!!!
                sort(result+0, result+3);
                for(auto& i : result) cout << i << " ";
                return 0;
            } // end of if
        } // end of while
    } // end of for
    sort(result+0, result+3);
    for(auto& i : result) cout << i << " ";

    return 0;
}
