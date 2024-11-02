#include <iostream>
using namespace std;

#define MAX 100
struct stack {
	int a[MAX];
	int t;
};
void CreateEmptyStack(stack& s) {
	s.t = -1;
}
bool isEmpty(stack s) {
	if (s.t == -1)
		return 1;
	return 0;
}
bool isFull(stack s) {
	if (s.t >= MAX)
		return 1;
	return 0;
}
bool Push(stack& s, int x) {
	if (isFull(s) == 0)
	{
		s.a[++s.t] = x;
		return 1;
	}
	return 0;
}
int Pop(stack& s, int& x) {
	if (isEmpty(s) == 0)
	{
		x = s.a[s.t--];
		return 1;
	}
	return 0;
}

void createStack(stack& s) {
	CreateEmptyStack(s);
	int x;
	cin >> x;
	while (x != -1) {
		Push(s, x);
		cin >> x;
	}
}
void PrintStack(stack s)
{
	for (int i = 0; i <= s.t; i++)
		cout << s.a[i] << " ";
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
