#include<iostream>
using namespace std;

#define MAX_SIZE 2188

typedef struct _POINT{
	int x; 
	int y;
}Point;

int display[MAX_SIZE][MAX_SIZE];
int result[3]; // 0 : -1, 0 : 1, 1 : 2

void solve(int x, int y, int size){
	if(size == 1){
		int N = display[x][y] + 1;
		result[N]++;
		return;
	}

	bool isSame = true;
	int first = display[x][y];

	for(int dx = x; dx < x + size; dx++){
		for(int dy = y; dy < y + size; dy++){
			if(first != display[dx][dy]){
				isSame = false;
				break;
			}
		}
	}

	if(isSame){
		int N = display[x][y] + 1;
		result[N]++;
		return;
	}

	int split_size = size / 3;
	for(int dx = 0; dx < 3; dx++)
		for(int dy = 0; dy < 3; dy++)
			solve(x + split_size*dx, y + split_size*dy, split_size);
}


int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	for(int dx = 0; dx < N; dx++)
		for(int dy = 0; dy < N; dy++)
			cin >> display[dx][dy];

	solve(0, 0, N);

	for(auto i : result)
		cout << i << endl;

	return 0;
}
