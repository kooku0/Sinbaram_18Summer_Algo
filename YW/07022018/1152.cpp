#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string S;
	int count = 0;
	getline(cin, S);
	int size = S.length()+1;
	char *Schar = new char[size];
	for (int i = 0; i < size; ++i)
	{
		Schar[i] = S[i];
	}
	for (int i = 0; i < size; ++i)
	{
		if (Schar[i] == ' ' )
		{
			count++;
		}
	}
	if (Schar[0] != ' ')
	{
		count++;
	}
	if (Schar[size-2] == ' ')
	{
		count--;
	}

	cout << count << endl;
	
	return 0;
}