#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	ios::sync_with_stdio(false);
	std::getline(std::cin, s);				// getline함수(띄워쓰기 가능한 string입력)

	int num_voca = 0; 
	
	for (int i = 0; i < (signed)s.length(); i++) {
		if (s.at(i) == ' ') {
			num_voca++;
		}
	}
	/*
	문장의 시작과 끝이 띄워져 있는 경우를 생각해줘야 한다.
	*/
	if (s.at(0) == ' ')
		num_voca -= 1;

	if (s.at(s.length() - 1) == ' ')
		num_voca -= 1;

	std::cout << num_voca + 1 << "\n";
	
	return 0;
}