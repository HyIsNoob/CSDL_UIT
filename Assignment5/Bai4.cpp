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

void CreateEmptyList(List& l);
Node* CreateNode(int x);
void CreateList(List& l);
void PrintList(List l);
bool isPrime(int x);
void add_after_all_prime(List& l, int x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void AddAfterQ(List& L, Node* p, Node* Q);

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

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

void add_after_all_prime(List& l, int x) {
	for (Node* i = l.pHead; i != NULL; i = i->next) {
		if (isPrime(i->Infor)) {
			AddAfterQ(l, CreateNode(x), i);
			i = i->next;
		}
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


int main() {
	LIST L;
	int Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_all_prime(L, Y);

	PrintList(L);

	return 0;
}
