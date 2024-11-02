
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateTNODE(int x) {
	TNODE* p = new TNODE();
	if (p == NULL)
		exit(1);
	p->key = x;
	p->pLeft = p->pRight = NULL;
	return p;
}

int Insert(TREE& T, int x) {
	if (T) {
		if (T->key == x)
			return 0;
		if (T->key > x)
			return Insert(T->pLeft, x);
		return Insert(T->pRight, x);
	}
	T = CreateTNODE(x);
	return 1;
}

void CreateTree(TREE& T) {
	int temp;
	cin >> temp;
	while (temp != -1) {
		Insert(T, temp);
		cin >> temp;
	}
}

int Counter(TREE T) {
	if (T == NULL) {
		return 0;
	}

	int leftChildCount = Counter(T->pLeft);
	int rightChildCount = Counter(T->pRight);

	if ((T->pLeft != NULL && T->pRight != NULL)) {
		return 1 + leftChildCount + rightChildCount;
	}

	return leftChildCount + rightChildCount;
}

void CountNode_Have2Child(TREE T, int& count) {
	count = Counter(T);
}

int main() {
	int count = 0;
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	CountNode_Have2Child(T, count);
	cout << count;
	return 0;
}
