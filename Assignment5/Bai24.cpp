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
void Print_Middle(LIST);

void Print_Middle(LIST l) {
	if (l.pHead != NULL) {
		int dem = 1;
		for (NODE* p = l.pHead; p != NULL; p = p->next) {
			dem++;
		}
		int i = 1;
		NODE* p = l.pHead;
		while (i != dem / 2) {
			p = p->next;
			i++;
		}
		cout << p->Infor;
	}
	else
		cout << "Empty List.";
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
	CreateEmptyList(L);

	CreateList(L);
	Print_Middle(L);

	return 0;
}
