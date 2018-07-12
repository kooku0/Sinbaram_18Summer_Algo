#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	stack<int> S;
	vector<char> result_vec;

	int seq_count;
	cin >> seq_count;

	int seq_value, temp = 1, prev = 0;
	bool exit = false;
	S.push(0);

	for (int i = 0; i < seq_count && !exit; ++i) {
		cin >> seq_value;
		prev = 0;

		while (prev != seq_value) {
			if (S.top() < seq_value) {
				if (temp > seq_value) {
					exit = true;
					break;
				}
				else {
					S.push(temp++);
					result_vec.push_back('+');
				}
			}
			else {
				prev = S.top();
				S.pop();
				result_vec.push_back('-');
			}
		}
	}

	if (exit == true) {
		cout << "NO" << endl;
	}
	else {
		for (int i = 0; i < result_vec.size(); ++i)
			cout << result_vec[i] << endl;
	}

	return 0;
}