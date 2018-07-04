//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main(void)
//{
//	stack<int> s;
//
//	char paren;
//	bool correct = true;
//
//	while ((paren = getchar()) != '\n' && correct) {
//		if (paren == '(' || paren == '[') {
//			s.push(paren);
//		}
//		else if (paren == ')') {
//			if (s.empty()) {
//				correct = false;
//				break;
//			}
//			
//			int sum = 0, temp = 0;
//
//			while (temp != '(') {
//				if (s.empty()) {
//					correct = false;
//					break;
//				}
//				temp = s.top();
//				s.pop();
//
//				if (temp == '(') {
//					if (sum == 0) {
//						sum = -2;
//					}
//					else {
//						sum *= 2;
//					}
//				}
//				else if (temp == '[') {
//					correct = false;
//					break;
//				}
//				else {
//					sum += temp;
//				}
//			}
//
//			s.push(sum);
//		}
//		else {
//			if (s.empty()) {
//				correct = false;
//				break;
//			}
//
//			int sum = 0, temp = 0;
//
//			while (temp != '[') {
//				if (s.empty()) {
//					correct = false;
//					break;
//				}
//				temp = s.top();
//				s.pop();
//
//				if (temp == '[') {
//					if (sum == 0) {
//						sum = -3;
//					}
//					else {
//						sum *= 3;
//					}
//				}
//				else if (temp == '(') {
//					correct = false;
//					break;
//				}
//				else {
//					sum += temp;
//				}
//			}
//
//			s.push(sum);
//		}
//	}
//
//	int result = 0;
//	int size = s.size(), temp = 0;
//	for (int i = 0; i < size; ++i) {
//		temp = s.top();
//		s.pop();
//
//		if (temp == '(' || temp == '[') {
//			correct = false;
//			break;
//		}
//		else {
//			result += temp;
//		}
//	}
//
//	cout << (correct ? -result : 0) << endl;
//
//	return 0;	
//}