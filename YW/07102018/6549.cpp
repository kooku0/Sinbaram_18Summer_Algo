#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> numvec;
	string line;
	int start = 0;
	do {
		getline(cin,line);
		cout << line << endl;
		start++;
	} while (atoi(line.c_str()) != 0);



	int num[8] = { 2,1,4,5,3,1,3,3 };
	int maxRecord = INT32_MIN;

	for (int i = 0; i < 8; ++i)
	{
		int tempnum = num[i];
		while (tempnum > 0)
		{
			int count = 1;
			for (int j = i + 1; j < 8; ++j)
			{
				if (tempnum > num[j])
				{
					break;
				}
				count++;
			}
			int space = count * tempnum;
			maxRecord = max(maxRecord, space);
			tempnum--;
		}
	}
	
	cout << maxRecord << endl;

	return 0;
}