#include <iostream>
#include <string.h>
using namespace std;
struct node {
	int info;
	node* next;
};
struct Stack {
	node* head;
	node* tail;
};
void CreateEmptyStack(Stack& l)
{
	l.head = NULL;
	l.tail = NULL;
}
node* CreateNode(int x)
{
	node* p = new node();
	if (p == NULL) exit(1);
	p->info = x;
	p->next = NULL;
	return p;
}


int Pop(Stack& s, int& x) {
	if (s.head == NULL)
		return -1;
	x = s.head->info;
	node* p = s.head;
	s.head = s.head->next;
	if (s.head == NULL)
		s.tail = NULL;
	delete p;
	return 0;
}

void Push(Stack& l, node* x) {
	if (l.head == NULL)
		l.head = l.tail = x;
	else {
		l.tail->next = x;
		l.tail = x;
	}
}

bool isExist(Stack l, int x) {
	if (l.head != NULL) {
		for (node* p = l.head; p != NULL; p = p->next)
			if (p->info == x)
				return true;
		return false;
	}
	else
		return false;
}

void CreateStack(Stack& l) {
	CreateEmptyStack(l);
	int temp;
	cin >> temp;
	while (temp != -1) {
		if (!isExist(l, temp))
			Push(l, CreateNode(temp));
		cin >> temp;
	}
}

bool isPrime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

void PrintStack(Stack l) {
	int lc = 0;
	int x[100], k = 0;
	if (l.head == NULL) {
		cout << "No SNT";
		lc = -1;
	}
	else
		for (node* i = l.head; i != NULL; i = i->next)
			if (isPrime(i->info)) {
				x[k++] = i->info;
				lc = 1;
			}
	if (lc == 0)
		cout << "No SNT";
	else
		for (int i = k - 1; i > -1; i--)
			cout << x[i] << "\t";
}

int main() {
	Stack L;
	CreateEmptyStack(L);
	CreateStack(L);
	PrintStack(L);
	return 0;
}
