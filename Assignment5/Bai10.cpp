#include <iostream>
#include <string.h>
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

void CreateEmptyList(List& l);
Node* CreateNode(int x);
void CreateList(List& l);
void PrintList(List l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
string searchX(NODE*, int);

string searchX(NODE* l, int x) {
	string A;
	for (NODE* p = l; p != NULL; p = p->next) {
		if (x == p->Infor)
		{
			A = "true";
			return A;
		}
	}
	A = "false";
	return A;
}

void PrintList(List l) {
	for (Node* p = l.pHead; p != NULL; p = p->next)
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

Node* CreateNode(int x) {
	Node* p = new Node;
	p->Infor = x;
	p->next = NULL;
	return p;
}

void CreateEmptyList(List& l) {
	l.pHead = l.pTail = NULL;
}

int main() {
	LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	cout << searchX(L.pHead, X);

	return 0;
}
