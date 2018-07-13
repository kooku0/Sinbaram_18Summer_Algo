#include <iostream>
#include <string>

using namespace std;

int main()
{
	string snum;
	int num;
	getline(cin, snum);
	num = atoi(snum.c_str());

	string *inputs = new string[num];
	bool *results = new bool[num];
	int i;
	int count;
	for (i = 0; i < num; ++i)
	{
		results[i] = true;
		getline(cin, inputs[i]);
		count = 0;
		for (int j = 0; j < inputs[i].size(); ++j)
		{
			if (inputs[i][j] == '(')
			{
				count++;
			}
			else if (inputs[i][j] == ')')
			{
				count--;
			}
			if (count < 0)
			{
				results[i] = false;
				break;
			}
		}
		if (count != 0)
		{
			results[i] = false;
		}
	}

	for (i = 0; i < num; ++i)
	{
		if (results[i])
		{
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}