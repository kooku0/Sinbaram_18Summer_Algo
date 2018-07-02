#include <iostream>
#include <map>

using namespace std;


//global variable
using uint = unsigned int;
uint zero_storage[100000];
uint one_storage[100000];

//global function
void fibonachi(uint origin, uint value);

int main(void)
{
	zero_storage[0] = 1;
	one_storage[1] = 1;

	short count = 0;
	cin >> count;

	uint temp;

	for (short i = 0; i < count; ++i) {
		cin >> temp;
		fibonachi(temp, 0);
		cout << zero_storage[temp] << ' ' << one_storage[temp] << endl;
	}
	
}

void fibonachi(uint origin, uint value)
{
	if (value == origin - 1 || origin <= 1)
		return;

	zero_storage[value + 2] = zero_storage[value] + zero_storage[value + 1];
	one_storage[value + 2] = one_storage[value] + one_storage[value + 1];

	fibonachi(origin, value + 1);
}