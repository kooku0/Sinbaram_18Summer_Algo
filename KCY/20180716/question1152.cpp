#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	ios::sync_with_stdio(false);
	std::getline(std::cin, s);				// getline�Լ�(������� ������ string�Է�)

	int num_voca = 0; 
	
	for (int i = 0; i < (signed)s.length(); i++) {
		if (s.at(i) == ' ') {
			num_voca++;
		}
	}
	/*
	������ ���۰� ���� ����� �ִ� ��츦 ��������� �Ѵ�.
	*/
	if (s.at(0) == ' ')
		num_voca -= 1;

	if (s.at(s.length() - 1) == ' ')
		num_voca -= 1;

	std::cout << num_voca + 1 << "\n";
	
	return 0;
}