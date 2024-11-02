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
#define MAX 300
void createEmptyQueue(queue& q) {
	q.back = q.front = NULL;
}
void enqueue(queue& q, NODE* p) {
	if (q.front == NULL){
		q.front = q.back = p;
	}
	else {
		q.back->pNext = p;
		q.back = p;
	}
}
int dequeue(queue& q, int& x) {
	NODE* temp;
	if (q.front == NULL)
		return -1;
	x = q.front->info;
	temp = q.front;
	q.front = q.front->pNext;
	if (q.front == NULL)
		q.back = NULL;
	delete temp;
	return 0;
}

void createQueue(queue& q) {
	createEmptyQueue(q);
	int temp;
	cin >> temp;
	int a[MAX], k = 0;
	while (temp != -1) {
		if (temp == 0) {
			if (q.front != NULL)
				dequeue(q, a[k++]);
		}
		else
			enqueue(q, CreatNode(temp));
		cin >> temp;
	}
	cout << "output: ";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl;
	if (q.front != NULL) {
		cout << "front: " << q.front->info << endl;
		cout << "back: " << q.back->info << endl;
	}
	else if (q.front == NULL)
		cout << "front: " << endl << "back: ";
}


int main() {
	queue q;
	createQueue(q);
	return 0;
}
