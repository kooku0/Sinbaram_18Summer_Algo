#include <iostream>

using namespace std;
using uint = unsigned int;

int main(void)
{
	uint digit[10] = { 0, };

	uint A, B, C;
	cin >> A >> B >> C;

	uint result = A * B * C;
	uint select = 1;
	uint index = 0;

	while (select < result) {
		index = (result % (select * 10) - result % select) / select;
		++digit[index];
		select *= 10;
	}

	for (int i = 0; i < 10; ++i)
		cout << digit[i] << endl;

	return 0;
}