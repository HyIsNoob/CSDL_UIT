#include <iostream>
using namespace std;
#define MAX 300

struct STACK {
	int a[MAX];
	int t;
};

bool isEmpty(STACK);
bool isFull(STACK);
void CreateEmptyStack(STACK&);
void Push(STACK&, int);
void Pop(STACK&, int&);
void CreateStack(STACK&);
void PrintStack(STACK);

void PrintStack(STACK s) {
	for (int i = 0; i <= s.t; i++)
		cout << s.a[i] << " ";
}

void CreateStack(STACK& s) {
	CreateEmptyStack(s);
	int temp;
	cin >> temp;
	while (temp != -1) {
		Push(s, temp);
		cin >> temp;
	}
}

void Pop(STACK& s, int& x) {
	if (!isEmpty(s))
		x = s.a[s.t--];
}

void Push(STACK& s, int x) {
	if (!isFull(s))
		s.a[++s.t] = x;
}

void CreateEmptyStack(STACK& s) {
	s.t = -1;
}

bool isFull(STACK s) {
	if (s.t >= MAX)
		return true;
	return false;
}

bool isEmpty(STACK s) {
	if (s.t == -1)
		return true;
	return false;
}

int main() {
	STACK s;
	CreateStack(s);
	PrintStack(s);
	return 0;
}