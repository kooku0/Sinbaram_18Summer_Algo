#include <iostream>
#include <vector>
using namespace std;

long long memo[101][10];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		memo[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int lastNum = 0; lastNum <= 9; lastNum++) {
			if (lastNum - 1 < 0 ) {
				memo[i][lastNum] = (memo[i][lastNum] + memo[i - 1][lastNum + 1])%1000000000;
			}
			else if(lastNum + 1 > 9){
				memo[i][lastNum] = (memo[i][lastNum] + memo[i - 1][lastNum - 1]) % 1000000000;
			}
			else {
				memo[i][lastNum] = (memo[i][lastNum] + memo[i - 1][lastNum + 1] + memo[i - 1][lastNum - 1]) % 1000000000;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += memo[N][i] ;
	}
	cout << sum % 1000000000 << endl;

	return 0;
}