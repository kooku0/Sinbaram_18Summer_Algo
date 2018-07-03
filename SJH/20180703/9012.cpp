#include <iostream>
#include <stack>


using namespace std;


int main(void)
{
	stack<char> pStack;

	int count;
	cin >> count;
	getchar();

	char temp;
	bool correct;
	for (int i = 0; i < count; ++i) {
		pStack = stack<char>();
		correct = true;
		int num = 0;
		temp = 0;

		while ((temp = getchar()) != '\n') {
			if (temp == '(') {
				pStack.push(temp);
			}
			else {
				if (pStack.empty()) {
					correct = false;
				}
				else {
					pStack.pop();
				}
			}
		}
		cout << (correct && pStack.empty() ? "YES" : "NO") << endl;
	}

	return 0;
}