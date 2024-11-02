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
bool isPrime(int x);
void add_after_k_th(LIST, int, int);
NODE* SearchNode(LIST l, int x);
void AddAfterQ(List& L, Node* p, Node* Q);

NODE* SearchNode(LIST l, int x) {
	NODE* p = l.pHead;
	while (p != NULL && p->Infor != x)
		p = p->next;
	return p;
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

void add_after_k_th(LIST l, int Y, int X) {
	int dem = 1;
	for (NODE* p = l.pHead; p != NULL; p = p->next) {
		if (dem == X) {
			AddAfterQ(l, CreateNode(Y), p);
			p = p->next;
		}
		dem++;
	}
}

void PrintList(LIST l) {
	for (NODE* p = l.pHead; p != NULL; p = p->next) {
		cout << p->Infor << " ";
	}
	if (l.pHead == NULL)
		cout << "Empty List.";
}

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
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
	int k, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> k >> Y;
	add_after_k_th(L, Y, k);

	PrintList(L);

	return 0;
}


