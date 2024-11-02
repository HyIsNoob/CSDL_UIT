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

void CreateEmptyList(LIST&);
NODE* CreateNode(int);
void CreateList(LIST&, int);
void PrintList(LIST);
NODE* SearchNode(LIST, int);
void AddHead(LIST&, NODE*);
void AddTail(LIST&, NODE*);
void Sort(LIST&);
void AddAfterQ(LIST&, NODE*, NODE*);
void AddNode(LIST&);

void PrintList(LIST l) {
	for (NODE* p = l.pHead; p != NULL; p = p->next)
		cout << p->Infor << " ";
	if (l.pHead == NULL)
		cout << "Empty List";
}

void CreateList(LIST& l, int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		AddTail(l, CreateNode(temp));
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

void Sort(LIST& L) {
	NODE* p, * Q, * min;
	p = L.pHead;
	while (p != L.pTail) {
		min = p;
		Q = p->next;
		while (Q != NULL) {
			if (Q->Infor > min->Infor)
				min = Q;
			Q = Q->next;
		}
		if (min != p) swap(min->Infor, p->Infor);
		p = p->next;
	}
	PrintList(L);
	cout << endl;
}

void Input(LIST& l) {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	CreateEmptyList(l);
	CreateList(l, n);
}

NODE* SearchNode(LIST l, int x) {
	NODE* p = l.pHead;
	NODE* after = p->next;
	while (p != NULL) {
		if (x > after->Infor)
			break;
		after = after->next;
		p = p->next;
	}
	return p;
}

void AddNode(LIST& l) {
	int n;
	cout << "Nhap so can them: ";
	cin >> n;
	NODE* p = CreateNode(n);
	AddAfterQ(l, p, SearchNode(l, n));
	PrintList(l);
	cout << endl;
}

int main() {
	List l;
	Input(l);
	Sort(l);
	AddNode(l);
	return 0;
}