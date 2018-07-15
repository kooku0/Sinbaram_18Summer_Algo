#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int count;
	if (num <= 99)
	{
		count = num;
	}
	else {
		count = 99;
	}
	if (num < 100)
	{
		goto ReturnPhase;
	}
	
	for (int i = 100; i <= num; ++i)
	{
		int temp = i;
		bool check = true;
		while (temp > 99)
		{
			int compA = temp % 10 - (temp % 100) / 10 ;
			int compB = (temp % 100)/10 - (temp % 1000)/100;
			if (compA != compB)
			{
				check = false;
			}
			temp = temp / 10;
		}
		if (check)
		{
			count++;
		}
	}

ReturnPhase:
	cout << count << endl;

	return 0;
}