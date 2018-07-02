#include <iostream>
#include <vector>
#include <math.h>


using namespace std;
using uint = unsigned int;

int main(void)
{
	uint number;
	cin >> number;

	uint num_of_digit = int(log10(number)) + 1;

	vector<int> temp_digits(num_of_digit, 0);

	bool exit = false, found = false;
	uint temp = 0, sum = 0;
	int i;
	while (!exit) {
		for (i = 0; i < temp_digits.size(); ++i)
			if (temp_digits[i] != 9) {
				exit = false;
				break;
			}
			else
				exit = true;

		temp = 0;
		select = 1;
		sum = 0;
		for (i = 0; i < temp_digits.size(); ++i) {
			temp += temp_digits[temp_digits.size() - i - 1] * select;
			sum += temp_digits[temp_digits.size() - i - 1];
			select *= 10;
		}

		sum += temp;
		
		for (i = temp_digits.size() - 1; i >= 0; --i) 
			if (temp_digits[i] == 9)
				temp_digits[i] = 0;
			else
				break;
		if (i >= 0)
			++temp_digits[i];

		if (sum == number) {
			cout << temp << endl;
			found = true;
			exit = true;
		}
	}

	if (found == false)
		cout << 0 << endl;

	return 0;
}