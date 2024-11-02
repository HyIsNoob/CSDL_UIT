#include <iostream>
using namespace std;
#define MAX 100
struct STACK {
	int a[MAX];
	int t;
};
void CreateEmptyStack(STACK& s) {
	s.t = -1;
}
bool isEmpty(STACK s) {
	if (s.t == -1)
		return 1;
	return 0;
}
bool isFull(STACK s) {
	if (s.t >= MAX)
		return 1;
	return 0;
}
bool Push(STACK& s, int x) {
	if (isFull(s) == 0)
	{
		s.a[++s.t] = x;
		return 1;
	}
	return 0;
}
int Pop(STACK& s, int& x) {
	if (isEmpty(s) == 0)
	{
		x = s.a[s.t--];
		return 1;
	}
	return 0;
}

void createStack(STACK& s) {
	CreateEmptyStack(s);
	int x;
	cin >> x;
	while (x != -1) {
		Push(s, x);
		cin >> x;
	}
}
void PrintStack(STACK s)
{
	for (int i = 0; i <= s.t; i++)
		cout << s.a[i] << " ";
}

void ThapToNhi(STACK q) {
	int n;
	cout << "Nhap so thap phan: ";
	cin >> n;
	while (n != 0) {
		if (n % 2 == 0)
			Push(q, 0);
		else
			Push(q, 1);
		n = n / 2;
	}
	for (int i = q.t; i > -1; i--)
		cout << q.a[i] << " ";
}

int main() {
	STACK q;
	CreateEmptyStack(q);
	ThapToNhi(q);
	return 0;
}
