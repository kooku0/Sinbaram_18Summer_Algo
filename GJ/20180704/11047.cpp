#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_SIZE 1000000

int A[MAX_SIZE];

int main(void){
    int N; int K;
    int cnt = 0;
    cin >> N; cin >> K;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    int temp;
    int pos;
    for(int i = N-1; i >= 0; i--){
        if(A[i] < K){
            pos = i;
            temp = A[i];
            break;
        }
    }
    while(K > 0){
       while(temp <= K){
            K -= temp;
            cnt++;
        }
        temp = A[--pos];
    }

    cout << cnt << endl;
    return 0;
}
