#include<iostream>
using namespace std;

int numOf[10] = {0,};

int main(){
    int A, B, C, T;
    cin >> A >> B >> C;
    T = A * B * C;
    while(T - 1 >= 0){
        numOf[T%10]++;
        T /= 10;
    }
    for(int i = 0; i < 10; i++)
        cout << numOf[i] << endl;
    return 0;
}

