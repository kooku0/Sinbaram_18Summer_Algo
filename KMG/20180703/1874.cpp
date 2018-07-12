#include <iostream>
#include <vector>
using namespace std;

class Node {
	friend class Stack;
private:
	int data;
	Node *next;

public:
	Node(int data);
	~Node() {};
	int getData() {
		if (data == NULL)
			return 0.0;
		return data;
	}
};
Node::Node(int data) {
	this->data = data;
	next = NULL;
}


class Stack {
private:
	Node *top;
	int size;
public:
	Stack();
	~Stack() {};
	void push(int data);
	int pop();
	bool isEmpty();
	int getSize();
	Node* getTop() {
		if (top == NULL) {
			Node *newNode = new Node(0.0);
			return newNode;
		}
		return top;
	}
};
Stack::Stack() {
	this->top = NULL;
	this->size = 0;
}
void Stack::push(int data) {
	if (isEmpty() == true) {
		this->top = new Node(data);
	}
	else {
		Node *newNode = new Node(data);
		newNode->next = top;
		top = newNode;
	}
	size++;
}
int Stack::pop() {
	if (top == NULL) {
		cout << "NO" << endl;
		exit(1);
	}
	int tmpData = top->data;
	Node *tmpNode = top;
	top = top->next;
	size--;
	delete tmpNode;
	return tmpData;
}

bool Stack::isEmpty() {
	if (this->top == NULL)return true;
	else return false;
}
int Stack::getSize() {
	return size;
}

int main() {
	int count;
	cin >> count;
	vector<int> v;
	for (int i = 0; i < count; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<int> v2;
	int j = 1;
	Stack *stack = new Stack();
	vector<char> result;

	for (int i = 0; i < count; i++) {
		if (v[i] >= i + 1) {
 			for (; j <= count; j++) {
				if (v[i] >= j) {
					stack->push(j);
					result.push_back('+');
				}
				else break;
			}
			v2.push_back(stack->pop());
			result.push_back('-');
		}
		else {
			v2.push_back(stack->pop());
			result.push_back('-');
		}
	}
	if (v != v2) {
		printf("NO");
		return 0;
	}
	for (int i = 0; i < result.size(); i++) {
		printf("%c\n", result[i]);
	}


	return 0;
}