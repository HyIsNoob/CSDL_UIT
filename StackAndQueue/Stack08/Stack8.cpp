#include <iostream>
using namespace std;



#define MAX 300
struct stack {
	char a[MAX];
	int t;
};
void CreateEmptyStack(stack& s) {
	s.t = -1;
}
bool isEmpty(stack s) {
	return s.t == -1;
}
bool isFull(stack s) {
	return s.t >= MAX - 1;
}
bool Push(stack& s, char x) {
	if (!isFull(s)) {
		s.a[++s.t] = x;
		return true;
	}
	return false;
}
bool Pop(stack& s, char& x) {
	if (!isEmpty(s)) {
		x = s.a[s.t--];
		return true;
	}
	return false;
}
bool isOpeningBracket(char c) {
	return (c == '(' || c == '[' || c == '{');
}
bool isClosingBracket(char c) {
	return (c == ')' || c == ']' || c == '}');
}
bool isMatchingBracket(char open, char close) {
	return ((open == '(' && close == ')') ||
		(open == '[' && close == ']') ||
		(open == '{' && close == '}'));
}
bool isValidExpression(stack& s, const char* st) {
	int i = 0;
	while (st[i] != '\0') {
		if (isOpeningBracket(st[i])) {
			Push(s, st[i]);
		}
		else if (isClosingBracket(st[i])) {
			char temp;
			if (isEmpty(s) || !isMatchingBracket(s.a[s.t], st[i])) {
				return false;
			}
			Pop(s, temp);
		}
		i++;
	}
	return isEmpty(s);
}
void BracketMatching(stack& s, char st[MAX]) {
	CreateEmptyStack(s);
	cin.getline(st, MAX);
	if (isValidExpression(s, st))
		cout << "True";
	else
		cout << "False";
}



int main() {
	stack s;
	char st[100];
	BracketMatching(s, st);
	return 0;
}
