
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE {
	float info;
	NODE* pNext;
};

NODE* CreateNode(float x) {
	NODE* p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}
struct stack {
	NODE* top;
};
bool empty(const stack& s) {
	return (s.top == NULL);
}
void CreateEmptyStack(stack& s) {
	s.top = NULL;
}
void push(stack& s, float x) {
	NODE* p = CreateNode(x);
	if (s.top == NULL) s.top = p;
	else {
		p->pNext = s.top;
		s.top = p;
	}
}
void pop(stack& s) {
	if (s.top == NULL) return;
	NODE* p = s.top;
	s.top = s.top->pNext;
	delete p;
}
float& top(stack s) {
	return s.top->info;
}
bool isOperator(char x) {
	return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}
bool isBracket(char x) {
	return ((x == '(') || (x == ')'));
}
void InputPostFix(char postix[], int& n) {
	char k;
	cin >> k;
	n = 0;
	while (k != '#') {
		postix[n++] = k;
		cin >> k;
	}
}

float applyOperator(float operand1, float operand2, char op) {
	switch (op) {
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	case '^':
		return pow(operand1, operand2);
	default:
		exit(1);
	}
}

float evaluate_expression(char postfix[], int n) {
	stack A;
	for (int i = 0; i < n; i++) {
		if (isdigit(postfix[i])) {
			push(A, postfix[i] - '0');
		}
		else if (isOperator(postfix[i])) {
			float operand2 = top(A);
			pop(A);
			float operand1 = top(A);
			pop(A);
			float result = applyOperator(operand1, operand2, postfix[i]);
			push(A, result);
		}
	}

	return top(A);
}

int main() {
	char postfix[MAXN];
	int np;

	InputPostFix(postfix, np);
	// Output(postfix, np);

	cout.precision(3);
	cout << evaluate_expression(postfix, np);

	return 0;
}
