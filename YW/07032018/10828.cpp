#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	stack<int> st;

	int num;
	string snum;
	getline(cin, snum);
	num = atoi(snum.c_str());

	string *command = new string[num];
	for (int i = 0; i < num; ++i)
	{
		getline(cin, command[i]);
	}

	for (int i = 0; i < num; ++i)
	{
		if (command[i][0] == 's')
		{
			cout << st.size() << endl;
		}
		else if (command[i][0] == 't')
		{
			if (st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << st.top()-48 << endl;
			}
		}
		else if (command[i][0] == 'e')
		{
			if (st.empty())
			{
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (command[i][0] == 'p' && command[i][1] == 'o')
		{
			if (st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << st.top()-48 << endl;
				st.pop();
			}
		}
		else if (command[i][0] == 'p' && command[i][1] == 'u')
		{
			char tempS[8];
			strcpy(tempS, command[i].c_str());
			st.push(tempS[5]);
		}
	}
	return 0;
}