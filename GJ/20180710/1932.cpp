#include<iostream>
using namespace std;

#define MAX_N 500

void readTriangle(int temp[MAX_N][MAX_N], int max);
int returnMax(int temp[MAX_N][MAX_N], int max);

/** 메인부 */
int main(void){
    int levelOfTriangle;
    cin >> levelOfTriangle;

    // [level][length]
    int triangle[MAX_N][MAX_N];
    int table[MAX_N][MAX_N];

    readTriangle(triangle, levelOfTriangle);

    /** 주요 알고리즘 구현부 */
    table[0][0] = triangle[0][0];

    for(int level = 1; level < levelOfTriangle; level++){
        for(int length = 0; length < level+1; length++){
            // 초기화
            table[level][length] = triangle[level][length];

            // 좌측
            if(length == 0){
                table[level][length] += table[level-1][length];
            }
            // 우측
            else if(length == level){
                table[level][length] += table[level-1][length-1];
            }
            // 중간
            else{
                int tempLeft = table[level-1][length-1];
                int tempRight = table[level-1][length];

                table[level][length] += max(tempLeft,tempRight);
            }
        }
    }

    cout << returnMax(table, levelOfTriangle) << endl;
    return 0;
}

/** 함수부 */
void readTriangle(int temp[MAX_N][MAX_N], int max){
    for(int i = 0; i < max; i++){
        for(int j = 0; j < i+1; j++){
            cin >> temp[i][j];
        }
    }
}

int returnMax(int temp[MAX_N][MAX_N], int max){
    int result = 0;
    for(int i = 0; i < max; i++){
        if(result < temp[max-1][i]){
            result = temp[max-1][i];
        }
    }

    return result;
}
