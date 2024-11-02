#include <iostream>
using namespace std;
#define MAX 300


struct stack {
	int a[MAX];
	int t;
};

void CreateEmptyStack(stack& s) {
	s.t = -1;
}

bool isEmpty(stack s) {
	if (s.t == -1)
		return true;
	return false;
}

bool isFull(stack s) {
	if (s.t >= MAX)
		return true;
	return false;
}

void Push(stack& s, int x) {
	if (!isFull(s))
		s.a[++s.t] = x;
}

void Pop(stack& s, int& x) {
	if (!isEmpty(s))
		x = s.a[s.t--];
}

void array_reverse(stack& s, int a[], int& n) {
	CreateEmptyStack(s);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		Push(s, a[i]);
	for (int i = 0; i < n; i++)
		Pop(s, a[i]);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main() {
	stack s;
	int a[100], n;
	array_reverse(s, a, n);
	return 0;
}
