#include <iostream>
using namespace std;
struct TIME {
	int gio, phut, giay;
};

struct node {
	TIME info;
	node* next;
};

struct List {
	node* head;
	node* tail;
};


node* CreateNode(TIME t) {
	node* p = new node;
	p->info = t;
	p->next = NULL;
	return p;
}
void CreateEmptyList(List& l) {
	l.head = l.tail = NULL;
}
void AddHead(List& l, node* p) {
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		p->next = l.head;
		l.head = p;
	}
}
void Input(TIME& t) {
	cin >> t.gio >> t.phut >> t.giay;
	if (t.giay >= 60) {
		t.giay = t.giay - 60;
		t.phut++;
	}
	if (t.phut >= 60) {
		t.phut = t.phut - 60;
		t.gio++;
	}
	if (t.gio >= 24) {
		t.gio = t.gio - 24;
	}
}
void Output(TIME t) {
	cout << t.gio << "h" << t.phut << "p" << t.giay << "s";
}
void CreateList(List& l) {
	CreateEmptyList(l);
	TIME t;
	int n;
	cin >> n;
	if (n != 0)
		for (int i = 0; i < n; i++) {
			Input(t);
			AddHead(l, CreateNode(t));
		}
}
void PrintList(List l) {
	if (l.head != NULL)
		for (node* p = l.head; p != NULL; p = p->next) {
			Output(p->info);
			cout << endl;
		}
}


int main() {
	List L;
	CreateList(L);
	PrintList(L);
	return 0;
}
