#include<iostream>
#include<vector>
using namespace std;

void Eratos(vector<bool>& base, const int N){
    for(int i = 2; i <= N; i++){
        if(base[i]){
            for(int j = 2; i*j <= N; j++){
                if(base[i*j]) base[i*j] = false;
            } // end of for 
        } // end of if
    } // end of for
    base[0] = false;
    base[1] = false;
}

void run(){
    int from, to; cin >> from >> to;
    vector<bool> isPrime(to + 1, true);
    Eratos(isPrime, to+1);
    int minimum = -1;
    int sum = 0;
    bool hasPrime = false;

    for(int i = from; i <= to; i++){
        hasPrime = hasPrime | isPrime[i];
        if(isPrime[i]){
            if(minimum < 0) minimum = i;
            sum += i;
        }
    }

    if(hasPrime){
        cout << sum << endl;
        cout << minimum << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(void){
    run();
    return 0;
}
