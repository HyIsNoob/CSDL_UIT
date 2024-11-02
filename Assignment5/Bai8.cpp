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
void PrintList_Prime(LIST l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
bool isPrime(int x);

void PrintList_Prime(LIST l) {
	int flag = 0;
	for (NODE* p = l.pHead; p != NULL; p = p->next) {
		if (isPrime(p->Infor)) {
			cout << p->Infor << " ";
			flag = 1;
		}
	}
	if (l.pHead == NULL)
		cout << "Empty List.";
	else if (flag == 0)
		cout << "Không có số nguyên tố trong mảng.";
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
	CreateEmptyList(L);

	CreateList(L);
	PrintList_Prime(L);

	return 0;
}