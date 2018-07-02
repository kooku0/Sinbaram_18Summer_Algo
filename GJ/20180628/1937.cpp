// 현재 작업 중
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX_SIZE 501

typedef struct _POINT{
	int row;
	int col;
	int val;
	bool operator<(const _POINT& rhs) const{
		return val > rhs.val;
	}
}Point;

priority_queue<Point> q;

int dp[MAX_SIZE][MAX_SIZE];

int main(void){
	int n = 0; cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int temp;
			cin >> temp; 
			q.push({i, j, temp});
		}
	}

	for(int i = 0; i < n*n; i++){
		Point t = q.top();
		q.pop();

		// Priority 순서대로 순회하도록 할 것!!!!
	}
	return 0;
}
