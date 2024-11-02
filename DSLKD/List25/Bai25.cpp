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
void Remove_k_th(LIST&, int);
void RemoveHead(LIST&);

void RemoveHead(LIST& L) {
	NODE* p;
	if (L.pHead != NULL) {
		p = L.pHead;
		L.pHead = L.pHead->next;
		if (L.pHead == NULL)
			L.pTail = NULL;
		delete p;
	}
}

void Remove_k_th(LIST& l, int k) {
	if (l.pHead != NULL) {
		NODE* p;
		NODE* Q = l.pHead;
		int dem = 0;
		for (NODE* p = l.pHead; p != NULL; p = p->next)
			dem++;
		if (dem >= k) {
			if (k == 1)
				RemoveHead(l);
			else {
				for (int i = 2; i < k; i++) {
					Q = Q->next;
				}
				if (Q != NULL) {
					p = Q->next;
					if (p != NULL) {
						if (p == l.pTail)
							l.pTail = Q;
						Q->next = p->next;
						k = p->Infor;
						delete p;
					}
				}
			}
		}
	}
}

void PrintList(LIST l) {
	for (NODE* p = l.pHead; p != NULL; p = p->next)
		cout << p->Infor << " ";
	if (l.pHead == NULL)
		cout << "Empty List.";
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
	int k;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> k;
	Remove_k_th(L, k);
	PrintList(L);

	return 0;
}
