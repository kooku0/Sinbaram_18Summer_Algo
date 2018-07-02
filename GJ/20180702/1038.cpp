#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef unsigned long long ull;

pair<ull, bool> ordertest(const vector<ull>& A){
	for(size_t i = 0; i < A.size() - 1 ; i++){
		if(A[i] >= A[i+1]) return {i, false};
	}
	return {-1, true};
}

void push(vector<ull>& list, ull i){
	do{
		list.push_back(i % 10);
	}while(i /= 10);
}

int main(void){
	ull N = 0; cin >> N;
	ull cnt = 0;
	ull cur = 0;
	if(N == 0){
		cout << 0 << endl;
		return 0;
	}
	for(ull i = 1; i <= 9876543210; i++){
		vector<ull> list;
		push(list, i);
		pair<ull, bool> result = ordertest(list);
		if(result.second == true){
			cnt++; cur = i;
		}
		else
			i = (i / (ull)pow(10, result.first + 1) + 1) * (ull)pow(10, result.first + 1) - 1;

		if(cnt == N) break;
	}

	if(cnt != N) cout << -1 << endl;
	else cout << cur << endl;
	return 0;
}
