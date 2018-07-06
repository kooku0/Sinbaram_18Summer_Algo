#include <iostream>
#include <stack>
#include <string>

using namespace std;
// stl 이용하여 스택 구현

int main()
{
	int N;
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int X;
			cin >> X;
			s.push(X);
		}
		else if (str == "top")
		{
			if (s.size() != 0)
				cout << s.top() << endl;
			else
				cout << "-1" << endl;
		}
		else if (str == "pop")
		{
			if (s.size() != 0)
			{
				cout << s.top() << endl;
				s.pop();
			}
			else
				cout << "-1" << endl;
		}
		else if (str == "size")
		{
			cout << s.size() << endl;
		}
		else if (str == "empty")
		{
			if (s.size() == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}		
	}
	return 0;
}
