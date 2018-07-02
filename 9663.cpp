#include <iostream>

using namespace std;

int QueenNum;
int Board[15][15];
int Num = 0;

bool Check(int a, int b) {
	for (int i = 0; i<QueenNum; i++) {
		if (Board[a][i] == 1)return false;
	}
	for (int i = 0; i<QueenNum; i++) {
		if (Board[i][b] == 1)return false;
	}
	int row = a;
	int col = b;
	while (row != 0 && col != 0) {
		row--;
		col--;
		if (Board[row][col] == 1)return false;
	}
	row = a;
	col = b;
	while (row != QueenNum-1 && col != QueenNum-1) {
		row++;
		col++;
		if (Board[row][col] == 1)return false;
	}
	row = a;
	col = b;
	while (row != 0 && col != QueenNum-1) {
		row--;
		col++;
		if (Board[row][col] == 1)return false;
	}
	row = a;
	col = b;
	while (col != 0 && row != QueenNum-1) {
		row++;
		col--;
		if (Board[row][col] == 1)return false;
	}
	return true;
}

int set(int count) {
	count--;
	for (int i = 0; i < QueenNum; i++) {
		if (!Check(count, i))continue;
		Board[count][i] = 1;
		if(count!=0)set(count);	
		if (count == 0) {
			Num++;
		}
		Board[count][i] = 0;
	}
	return 0;
}



int main() {
	cin >> QueenNum;

	set(QueenNum);


	cout << Num;
}