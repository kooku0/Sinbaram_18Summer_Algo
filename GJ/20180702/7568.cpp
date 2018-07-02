#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N = 0; cin >> N;
	vector<pair<int, int>> person;
	for(int i = 0; i < N; i++){
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		person.push_back(temp);
	}
	for(auto point : person){
		int rank = 1;
		for(auto compare : person){
			if(point.first == compare.first \
					&& point.second == compare.second) continue;
			if(point.first < compare.first
					&& point.second < compare.second) rank++;
		}
		cout << rank << " ";
	}
}
