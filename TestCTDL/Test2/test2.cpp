#include <iostream>
#include <string.h>
using namespace std;
struct node {
	int info;
	node* next;
};
struct Queue {
	node* head;
	node* tail;
};
void CreateEmptyQueue(Queue& l)
{
	l.head = NULL;
	l.tail = NULL;
}
node* CreateNode(int x)
{
	node* p = new node();
	if (p == NULL) exit(1);
	p->info = x;
	p->next = NULL;
	return p;
}

void enqueue(Queue& q, node* p) {
	if (q.head == NULL)
	{
		q.head = p;
		q.tail = p;
	}
	else {
		q.tail->next = p;
		q.tail = p;
	}
}
int dequeue(Queue& q, int& x) {
	if (q.head == NULL)
		return -1;
	x = q.head->info;
	node* p = q.head;
	q.head = q.head->next;
	if (q.head == NULL)
		q.tail = NULL;
	delete p;
	return 0;
}
bool isExist(Queue l, int x) {
	if (l.tail != NULL) {
		if (l.tail->info == x)
			return true;
		return false;
	}
	else
		return false;
}
void CreateQueue(Queue& l) {
	string s;
	cin >> s;
	char prev_char = s[0];
	int count = 1;
	string encoded_str = "";

	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == prev_char) {
			count++;
		}
		else {
			encoded_str += to_string(static_cast<int>(prev_char));
			encoded_str += to_string(count);
			enqueue(l, CreateNode(encoded_str));
			prev_char = s[i];
			count = 1;
			encoded_str = "";
		}
	}

	// Handle the last character
	encoded_str += to_string(static_cast<int>(prev_char));
	encoded_str += to_string(count);
	enqueue(q, CreateNode(encoded_str));
}


void PrintQueue(Queue l)
{
	for (node* p = l.head; p != NULL; p = p->next)
		cout << p->info;
}
int main() {
	Queue L;
	CreateEmptyQueue(L);
	CreateQueue(L);
	PrintQueue(L);
	return 0;
}
