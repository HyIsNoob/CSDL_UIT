#include <iostream>
using namespace std;

struct NODE {
	int info;
	NODE* pNext;
};

struct STACK {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x) {
	NODE* p = new NODE();
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyStack(STACK& s) {
	s.pHead = NULL;
	s.pTail = NULL;
}

void Push(STACK& s, NODE* p) {
	if (s.pHead == NULL) 
		s.pHead = s.pTail = p;
	else {
		p->pNext = s.pHead;
		s.pHead = p;
	}
}

int Pop(STACK& s, int& x) {
	if (s.pHead == NULL)
		return -1;
	x = s.pHead->info;
	NODE* p = s.pHead;
	s.pHead = s.pHead->pNext;
	if (s.pHead == NULL)
		s.pTail == NULL;
	delete p;
	return 0;
}

int Top(STACK s) {
	return s.pHead->info;
}

void createStack(STACK& s) {
	CreateEmptyStack(s);
	int temp;
	cin >> temp;
	while (temp != -1) {
		Push(s, CreateNode(temp));
		cin >> temp;
	}
}

void PrintStack(STACK s) {
	for (NODE* i = s.pHead; i != NULL; i = i->pNext)
		cout << i->info << " ";
}

int main() {
	STACK s;
	createStack(s);
	PrintStack(s);
	return 0;
}