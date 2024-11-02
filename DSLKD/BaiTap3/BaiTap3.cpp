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

void DaoMang(STACK s, int a[], int n) {
	int dem = 0;
	for (int i = 0; i < n; i++)
		Push(s, a[i]);
	for (int i = 0; i < n; i++)
		Pop(s, a[i]);
}

int main() {
	STACK s;
	CreateEmptyStack(s);
	//createStack(p);
	//PrintStack(p);
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = 10;
	DaoMang(s, a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
