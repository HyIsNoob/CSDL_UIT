#include <iostream>
using namespace std;

#define MAX 100
struct NODE {
	int info;
	NODE* next;
};
struct stack {
	NODE* head;
	NODE* tail;
};
NODE* CreateNode(int x) {
	NODE* p = new NODE;
	p->info = x;
	p->next = NULL;
	return p;
}

void createEmptyStack(stack& s) {
	s.head = NULL;
	s.tail = NULL;
}
void Push(stack& s, NODE* p) {
	if (s.head == NULL)
	{
		s.head = p;
		s.tail = p;
	}
	else {
		p->next = s.head;
		s.head = p;
	}
}
int Pop(stack& s, int& x) {
	if (s.head == NULL)
		return -1;
	x = s.head->info;
	NODE* p = s.head;
	s.head = s.head->next;
	if (s.head == NULL)
		s.tail = NULL;
	delete p;
	return 0;
}

void createStack(stack& s) {
	createEmptyStack(s);
	int x;
	cin >> x;
	while (x != -1) {
		Push(s, CreateNode(x));
		cin >> x;
	}
}

void Testing_Push_Pop_Top_Stack(stack& s) {
	int temp, a[MAX], dem = 0;
	cin >> temp;
	createEmptyStack(s);
	while (temp != -1) {
		a[dem++] = temp;
		cin >> temp;
	}
	cout << "output: ";
	if (dem != 0) {
		for (int i = 0; i < dem; i++) {
			if (a[i] != 0)
				Push(s, CreateNode(a[i]));
			else {
				if (s.head != nullptr)
					cout << s.head->info << " ";
				Pop(s, a[i]);
			}
		}
		if (s.head != nullptr)
			cout << endl << "top: " << s.head->info;
		else
			cout << endl << "top: ";
	}
	else
		cout << endl << "top: ";
}

int main() {
	stack s;
	Testing_Push_Pop_Top_Stack(s);
	return 0;
}
