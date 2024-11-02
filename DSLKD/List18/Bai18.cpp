#include <cmath>
#include <iostream>

using namespace std;
struct points {
	int x;
	int y;
};
typedef struct points POINTS;
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
void Nhap(LIST& l);
void Xuat(LIST l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
bool RemoveHead(LIST&);

bool RemoveHead(LIST& L) {
	NODE* p;
	if (L.pHead != NULL) {
		p = L.pHead;
		L.pHead = L.pHead->next;
		if (L.pHead == NULL)
			L.pTail = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void Xuat(LIST l) {
	for (NODE* p = l.pHead; p != NULL; p = p->next) {
		cout << "(" << p->Infor << ", ";
		p = p->next;
		cout << p->Infor << ")" << endl;
	}
	if (l.pHead == NULL)
		cout << "Empty List.";
}

void Nhap(LIST& l) {
	int temp, temp1;
	cin >> temp;
	for (int i = 0; i < temp * 2; i++) {
		cin >> temp1;
		AddTail(l, CreateNode(temp1));
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
	LIST points;
	CreateEmptyList(points);
	Nhap(points);

	Xuat(points);

	return 0;
}
