#include <iostream>
using namespace std;

struct NODE {
	int infor;
	NODE* pNext;
};
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int);
void CreateEmptyList(LIST&);
void AddHead(LIST&, NODE*);
void AddTail(LIST&, NODE*);
void CreateList(LIST&);
void PrintList(NODE*);
bool isPrime(int);
void AddAfterQ(LIST&, NODE*, NODE*);
void AddAfterPrime(LIST&, int);
void SearchNode(LIST, int);
bool DeleteHead(LIST&);
bool DeleteTail(LIST&);

bool DeleteTail(LIST& l) {
	if (l.pHead == NULL)
		return false;
	if (l.pHead->pNext == NULL) {
		delete l.pHead;
		l.pHead = NULL;
		return true;
	}
	NODE* p = l.pHead;
	while (p->pNext->pNext != NULL)
		p = p->pNext;
	delete p->pNext;
	p->pNext = NULL;
	return true;
}

bool DeleteHead(LIST& l) {
	NODE* p;
	if (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTail == NULL;
		delete p;
		return true;
	}
	return false;
}

void SearchNode(LIST l, int x) {
	NODE* p = l.pHead;
	while (p != NULL && p->infor != x)
		p = p->pNext;
	if (p != NULL)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

void AddAfterPrime(LIST& l, int x) {
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
		if (isPrime(p->infor)) {
			AddAfterQ(l, CreateNode(x), p);
			p = p->pNext;
		}
}

void AddAfterQ(LIST& l, NODE* p, NODE* q) {
	if (q != NULL) {
		p->pNext = q->pNext;
		q->pNext = p;
		if (l.pTail == q)
			l.pTail = p;
	}
	else
		AddTail(l, p);
}

void PrintList(NODE* l) {
	for (NODE* p = l; p != NULL; p = p->pNext)
		cout << p->infor << " ";
	if (l == NULL)
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
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void AddHead(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void CreateEmptyList(LIST& l) {
	l.pHead = l.pTail = NULL;
}

NODE* CreateNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		exit(1);
	p->infor = x;
	p->pNext = NULL;
}

int main() {
	LIST l;
	CreateEmptyList(l);
	CreateList(l);
	PrintList(l.pHead);
	int x;
	cout << endl << "Nhap X:"; cin >> x;
	SearchNode(l, x);
	AddAfterPrime(l, x);
	PrintList(l.pHead);
	DeleteHead(l);
	DeleteTail(l);
	cout << endl;
	PrintList(l.pHead);
	return 0;
}