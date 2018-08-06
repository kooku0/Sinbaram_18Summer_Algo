#include<iostream>
using namespace std;

typedef long long ll;

void solve(ll x, ll y){
	ll dist = y - x;
	ll n = 1;
	ll cnt = -1;

	while(true){
		ll           pow_n_2  = n * n;
		pair<ll, ll> N        = {pow_n_2 - n + 1,
			                     pow_n_2 + 1 + n - 1};
		bool         is_in    = dist >= N.first && 
			                    dist <= N.second;
		bool         is_lower = dist >= N.first &&
			                    dist <= pow_n_2;

		if(is_in){
			cnt = is_lower ? (n << 1) - 1 : n << 1;
			break;
		}

		n = n + 1;
	}
	cout << cnt << '\n';
}

int main(void){
	ios::sync_with_stdio(false);
	ll T; cin >> T;
	for(ll _ = 0 ; _ < T; _++){
		ll x, y; cin >> x >> y;
		solve(x, y);
	}

	return 0;
}
