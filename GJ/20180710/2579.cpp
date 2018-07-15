#include<iostream>
#include<algorithm>
using namespace std;

#define PREV_MAX 2

#define ONE 0
#define TWO 1

int main(void){
    int numOfStair;
    cin >> numOfStair;

    int stair[numOfStair];
    for(int i = 0; i < numOfStair; i++){
        cin >> stair[i];
    }
    
    int table[numOfStair][PREV_MAX];
    table[0][ONE] = stair[0];
    table[0][TWO] = stair[0];
    table[1][ONE] = stair[1] + table[0][ONE];
    table[1][TWO] = stair[1];
    for(int i = 2; i < numOfStair; i++){
        table[i][ONE] = stair[i] + table[i-1][TWO];
        table[i][TWO] = stair[i] + max(table[i-2][ONE],table[i-2][TWO]);
    }
    cout << max(table[numOfStair-1][ONE], table[numOfStair-1][TWO]) << endl;

    return 0;
}
