#include<iostream>
#include<vector>
using namespace std;

void Eratos(vector<bool>& base, const int N, const int K){
    int counter = 0; 
    for(int i = 2; i <= N; i++){
        if(base[i]){
            counter++;
            if(counter == K){
                cout << i << endl;
                return;
            }
            for(int j = 2; i*j <= N; j++){
                if(base[i*j]){
                    counter++;
                    base[i*j] = false;
                    if(counter == K){
                        cout << i*j << endl;
                        return;
                    }
                }
            }
        }
    }
    base[0] = false;
    base[1] = false;
}

void run(){
    int N, K; cin >> N >> K;
    vector<bool> isPrime(N + 1, true);
    Eratos(isPrime, N, K);
}

int main(void){
    run();
    return 0;
}
