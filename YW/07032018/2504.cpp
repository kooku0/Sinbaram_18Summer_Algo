#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string input;
	cin >> input;

	bool check = true;
	int count1 = 0;
	int count2 = 0;

	stack<char> result;

	int sum = 0;

	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '(')
		{
			if (i > 0 && (input[i - 1] == '(' || input[i - 1] == '['))
			{
				result.push('*');
			}
			else if(i > 0 && ( input[i - 1] == ')' || input[i - 1] == ']'))
			{
				result.push('+');
			}
			count1++;
		}
		else if (input[i] == '[')
		{
			if (i > 0 && (input[i - 1] == '(' || input[i - 1] == '['))
			{
				result.push('*');
			}
			else if (i > 0 && (input[i - 1] == ')' || input[i - 1] == ']'))
			{
				result.push('+');
			}
			count2++;
		}
		else if (input[i] == ')')
		{
			result.push('2');
			sum+= 2;
			count1--;
		}
		else if (input[i] == ']')
		{
			result.push('3');
			sum += 3;
			count2--;
		}
		if (count1 < 0 || count2 < 0)
		{
			check = false;
			break;
		}
	}
	if (count1 != 0 || count2 != 0)
	{
		check = false;
	}

	if (check)
	{
		//cout << sum << endl;
		while( result.size() > 0)
		{
			cout << result.top() << " ";
			result.pop();
		}
		cout << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}