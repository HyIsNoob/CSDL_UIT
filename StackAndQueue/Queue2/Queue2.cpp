#include <iostream>
using namespace std;

struct NODE {
	char info;
	NODE* pNext;
};
struct queue {
	NODE* front;
	NODE* back;
};
NODE* CreatNode(int x) {
	NODE* p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;


}
#include <cctype>
#include <cstring>
void createQueue(queue& q);
bool isEmpty(queue q) {
	return q.front == NULL;
}
void Enqueue(queue& q, char x) {
	NODE* p = CreatNode(tolower(x));
	if (isEmpty(q))
		q.front = q.back = p;
	else {
		q.back->pNext = p;
		q.back = p;
	}
}
char Dequeue(queue& q) {
	if (!isEmpty(q)) {
		NODE* pDel = q.front;
		char data = pDel->info;
		q.front = q.front->pNext;
		if (q.front == NULL) {
			q.back = NULL;
		}
		delete pDel;
		return data;
	}
	return '\0';
}
void isPalindrome(queue& q) {
	char str[300];
	cin.getline(str, 300);
	bool lc = true;
	int length = strlen(str);
	for (int i = 0; i < length; i++)
		Enqueue(q, tolower(str[i]));
	for (int i = 0; i < length; i++) {
		char frontChar = Dequeue(q);
		char backChar = tolower(str[length - i - 1]);
		if (frontChar != backChar)
			lc = false;
	}
	if (strlen(str) == 0)
		cout << "Empty" << endl;
	else if (lc)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
void createQueue(queue& q) {
	q.front = q.back = NULL;
	isPalindrome(q);
}


int main() {
	queue q;
	createQueue(q);
	return 0;
}
