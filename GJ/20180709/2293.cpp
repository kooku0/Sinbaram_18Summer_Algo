#include<iostream>
#include<algorithm>
using namespace std;

int dp[101][10001];
int coin[101];

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> coin[i];
	sort(coin + 0, coin + n);

	for(int i = 0; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(j % coin[i] == 0)
				dp[i][j] = 1;
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j <= k; j++){
			int prev_pos = j - coin[i] > 0 ? j - coin[i] : 0;
			int prev = dp[i - 1][ prev_pos ];
			dp[i][j] = dp[i][j] + prev;
		} // end of for
	} // end of for
	cout << dp[n - 1][k] << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < k + 1; j++){
			cout << dp[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}
