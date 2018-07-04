#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<cmath>
using namespace std;

void run();

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int test;
	int len, numAnt;
	cin >> test;
	for(int _t = 0 ; _t < test; _t++)
		run();
	return 0;
}

void run(){
	int len, numAnt;
	vector<int> largest;
	vector<int> smallest;
	vector<int> pos;
	vector<int> list;
	cin >> len >> numAnt;
	pos.resize(numAnt);
	for(int i = 0; i < numAnt; i++) cin >> pos[i];
	sort(pos.begin(), pos.end());
	for(auto current = pos.begin(); current != pos.end(); current++){
		int left = *current - 0;
		int crash_left = -1, crash_right = -1;
		int right = len - *current;
		if(current - 1 > pos.begin())
			crash_left = ceil((*current - *(current - 1))/2.0) + (len - *current);
		if(current + 1 < pos.end())
			crash_right = ceil((*(current+1) - *current)/2.0) + *current;
		largest.push_back(max(max(left, right),max(crash_left, crash_right)));
		crash_left = crash_left == -1 ? numeric_limits<int>::max() : crash_left;
		crash_right = crash_right == -1 ? numeric_limits<int>::max() : crash_right;
		smallest.push_back(min(min(left, right), min(crash_left, crash_right)));
	}
	sort(smallest.begin(), smallest.end());
	sort(largest.begin(), largest.end());
	cout << smallest.back() << " " << largest.back() << endl;
}
