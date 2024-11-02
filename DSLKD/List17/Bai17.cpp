#include <iostream>
using namespace std;

struct Node {
	int Infor;
	Node* next;
};
typedef struct Node NODE;
struct List {
	Node* pHead;
	Node* pTail;
};
typedef struct List LIST;

void CreateEmptyList(LIST& l);
NODE* CreateNode(int x);
void CreateList(LIST& l);
void PrintList(LIST l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
bool RemoveX(LIST&, int);
bool RemoveHead(LIST&, int&);
bool RemoveAfterQ(LIST&, NODE*, int&);

bool RemoveHead(LIST& L, int& x) {
	NODE* p;
	if (L.pHead != NULL) {
		x = L.pHead->Infor;
		p = L.pHead;
		L.pHead = L.pHead->next;
		if (L.pHead == NULL)
			L.pTail = NULL;
		delete p;
		return 1;
	}
	return 0;
}

bool RemoveAfterQ(LIST& l, NODE* Q, int& x) {
	NODE* p;
	if (Q != NULL) {
		p = Q->next;
		if (p != NULL) {
			if (p == l.pTail)
				l.pTail = Q;
			Q->next = p->next;
			x = p->Infor;
			delete p;
		}
		return 1;
	}
	return 0;
}

bool RemoveX(LIST& L, int x) {
	NODE* Q, * p;
	Q = NULL;
	p = L.pHead;
	while (p != NULL && p->Infor != x) {
		Q = p;
		p = p->next;
	}
	if (p == NULL) return 0;
	if (Q != NULL) RemoveAfterQ(L, Q, x);
	else RemoveHead(L, x);
	return 1;
}

void PrintList(LIST l) {
	for (NODE* p = l.pHead; p != NULL; p = p->next)
		cout << p->Infor << " ";
	if (l.pHead == NULL)
		cout << "Empty List.";
}

void CreateList(LIST& l) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		AddTail(l, CreateNode(temp));
		cin >> temp;
	}
}

void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else {
		l.pTail->next = p;
		l.pTail = p;
	}
}

void AddHead(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		p->next = l.pHead;
		l.pHead = p;
	}
}

NODE* CreateNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		exit(1);
	p->Infor = x;
	p->next = NULL;
	return p;
}

void CreateEmptyList(LIST& l) {

	l.pHead = l.pTail = NULL;
}


int main() {
	LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	RemoveX(L, X);
	PrintList(L);

	return 0;
}
