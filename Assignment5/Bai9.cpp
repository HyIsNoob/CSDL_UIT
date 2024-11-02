#include <iostream>
#include <cmath>
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
void PrintList_Armstrong(LIST l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
bool isArmStrong(int);

void PrintList_Armstrong(LIST l) {
	int flag = 0;
	for (NODE* p = l.pHead; p != NULL; p = p->next) {
		if (isArmStrong(p->Infor)) {
			cout << p->Infor << " ";
			flag = 1;
		}
	}
	if (l.pHead == NULL)
		cout << "Empty List.";
	else if (flag == 0)
		cout << "Không có số armstrong trong mảng.";
}

bool isArmStrong(int number) {
	int originalNumber, remainder, result = 0, n = 0;
	originalNumber = number;
	while (originalNumber != 0) {
		originalNumber /= 10;
		++n;
	}

	originalNumber = number;
	while (originalNumber != 0) {
		remainder = originalNumber % 10;
		result += pow(remainder, n);
		originalNumber /= 10;
	}
	if (result == number && number != 0)
		return true;
	else
		return false;
}

void CreateList(LIST& l) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		AddHead(l, CreateNode(temp));
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
	PrintList_Armstrong(L);

	return 0;
}
