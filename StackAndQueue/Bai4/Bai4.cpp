#include <iostream>
using namespace std;

struct NODE {
	int info;
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

void createEmptyQueue(queue& q) {
	q.front = NULL;
	q.back = NULL;
}
void enqueue(queue& q, NODE* p) {
	if (q.front == NULL)
	{
		q.front = p;
		q.back = p;
	}
	else {
		q.back->pNext = p;
		q.back = p;
	}
}
int dequeue(queue& q, int& x) {
	if (q.front == NULL)
		return -1;
	x = q.front->info;
	NODE* p = q.front;
	q.front = q.front->pNext;
	if (q.front == NULL)
		q.back = NULL;
	delete p;
	return 0;
}

void createQueue(queue& q) {
	int temp, a[100], dem = 0;
	cin >> temp;
	createEmptyQueue(q);
	while (temp != -1) {
		a[dem++] = temp;
		cin >> temp;
	}
	cout << "output: ";
	if (dem != 0) {
		for (int i = 0; i < dem; i++) {
			if (a[i] == 0) {
				if (q.front != nullptr)
					cout << q.front->info << " ";
				dequeue(q, a[i]);
			}
			else {
				enqueue(q, CreatNode(a[i]));
			}
		}
		if (q.front != nullptr)
			cout << endl << "front: " << q.front->info;
		else
			cout << endl << "front: ";
		if (q.back != nullptr)
			cout << endl << "back: " << q.back->info;
		else
			cout << endl << "back: ";
	}
	else {
		cout << endl << "front: ";
		cout << endl << "back: ";
	}
}

int main() {
	queue q;
	createQueue(q);
	return 0;
}
