#include<iostream>
using namespace std;

int divide(const int constructor){
	int temp = constructor;
	int result = 0;
	while(true){
		if(temp <= 0) break;
		result += temp % 10;
		temp /= 10;
	}
	return result;
}

int main(){
	int N; cin >> N;
	int constructor = -1;
	for(int i = 0; i < N; i++){
		int temp = i + divide(i);
		if(temp == N){
			constructor = i;
			break;
		}
	}
	if(constructor == -1) cout << 0 << endl;
	else cout << constructor << endl;
	return 0;
}
