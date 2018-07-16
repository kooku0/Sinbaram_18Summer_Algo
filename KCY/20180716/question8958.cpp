#include <iostream>
#include <string>

using namespace std;

int main() {
	int Test;

	ios::sync_with_stdio(false);
	
	cin >> Test;

	// OX 입력을 string으로 취급
	string* str = new string[Test];					

	for (int i = 0; i < Test; i++) {
		cin >> str[i];
		// 각각 문제의 점수를 담을 배열 선언
		int* question_score = new int[str[i].length()];
		
		if (str[i].at(0) == 'O')
			question_score[0] = 1;
		else
			question_score[0] = 0;
		// 핵심 알고리즘(25~33)
		for (int k = 1; k < str[i].length(); k++) {
			if ((str[i].at(k - 1) == 'O') && (str[i].at(k) == 'O')) 
				question_score[k] = question_score[k-1] + 1;
			else if ((str[i].at(k - 1) == 'X') && (str[i].at(k) == 'O'))
				question_score[k] = 1;
			else 
				question_score[k] = 0;
		}

		int sum = 0;
		for (int l = 0; l < str[i].length(); l++) {
			sum += question_score[l];
		}
		cout << sum << "\n";
		
	}

	return 0;
}