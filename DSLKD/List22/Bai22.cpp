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
NODE* SearchNode(LIST l, int x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void AddAfterQ(LIST& L, NODE*, NODE*);
void Function(NODE*);

void Function(NODE* l) {
	if (l == NULL)
		cout << "Empty List.";
	else {
		while (l != NULL) {
			NODE* lc = CreateNode(-1);
			for (NODE* p = l; p != NULL; p = p->next) {
				if (p->Infor > l->Infor) {
					lc = p;
					if (lc->Infor == l->Infor)
						lc->Infor == -1;
					break;
				}
			}
			cout << l->Infor << " " << lc->Infor << endl;
			l = l->next;
		}
	}
}

void PrintList(LIST l) {
	for (NODE* p = l.pHead; p != NULL; p = p->next)
		cout << p->Infor << " ";
	if (l.pHead == NULL)
		cout << "Empty List";
}

NODE* SearchNode(LIST l, int x) {
	NODE* p = l.pHead;
	while (p != NULL && p->Infor != x)
		p = p->next;
	return p;
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

void AddAfterQ(LIST& L, NODE* p, NODE* Q) {
	if (Q != NULL) {
		p->next = Q->next;
		Q->next = p;
		if (L.pTail == Q)
			L.pTail = p;
	}
	else
		AddHead(L, p);
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

	Function(L.pHead);

	return 0;
}
