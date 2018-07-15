#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll N, M;
	cin >> N >> M;
	vector<ll> card(N, 0);

	for(ll i = 0; i < N; i++)
		cin >> card[i];

	sort(card.begin(), card.end());

	for(ll i = 0; i < M; i++){
		ll sum = card[0] + card[1];
		card[0] = sum;
		card[1] = sum;
		sort(card.begin(), card.end());
	}
	ll result = 0;
	for(auto i : card)
		result += i;
	cout << result << endl;
	return 0;
}