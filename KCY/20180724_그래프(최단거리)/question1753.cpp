#include <iostream>

using namespace std;

/*
처음에 배열로 접근하되, 그래도 안되면 벡터로
*/
int main() {
	int V, E;
	ios::sync_with_stdio(false);

	cin >> V;
	cin >> E;

	int K;
	cin >> K;
	int* startArr = new int[E+1];
	int* endArr = new int[E+1];
	int* weightArr = new int[E+1];
	for (int i = 1; i <= E; i++) {
		cin >> startArr[i];
		cin >> endArr[i];
		cin >> weightArr[i];
	}

	// startArr 내부에 K값이 들어있는 원소의 인덱스들을 찾기 -> 배열 arr에 저장
	// 배열 arr 생성 및 모든 원소의 값을 0으로 초기화 
	// 	
	int* arr = new int[E+1];
	std::fill_n(arr, E + 1, 0);
	for (int a = 1; a <= E; a++) {
		if (startArr[a] == K) {
			arr[a] = a;
		}
	}
	
	/*
	최단경로 알고리즘
	int sum = 0;
	for (int j = 1; j <= E; j++) { // 
		for (int k = 1; k <= E; k++) {
			if (endArr[j] == startArr[k]) {

			}
		}
	}
	*/
		



	return 0;
}

