#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> s;

	int order_count;
	cin >> order_count;

	char temp_order[8];
	int temp_data;

	while (order_count--) {
		cin >> temp_order;
		
		if (temp_order[1] == 'u') {
			cin >> temp_data;
			s.push(temp_data);
		}
		else if (temp_order[0] == 'p') {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (temp_order[0] == 't') {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
		else if (temp_order[0] == 's') {
			cout << s.size() << endl;
		}
		else if (temp_order[0] == 'e') {
			cout << s.empty() << endl;
		}
		else {
			//unknown order
		}
	}

	return 0;
}